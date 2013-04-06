// GraphPainter.cpp

#include <oggl/GraphPainter.h>

#include <oggl/Types.h>
#include <oggl/Math.h>
#include <oggl/Util.h>
#include <oggl/GraphPainter.h>
#include <oggl/ShaderCode.h>

#include <array>
#include <vector>
#include <string>

#include <glload/gl_3_3_comp.hpp>
#include <glload/gll.hpp>

namespace oggl {

typedef struct
{
	float XYZW[4];
	float RGBA[4];
} Vertex;

Vertex CreateVertex(float x, float y, float z, V4 color)
{
	Vertex v;
	v.XYZW[0] = x;
	v.XYZW[1] = y;
	v.XYZW[2] = z;
	v.XYZW[3] = 1;
	v.RGBA[0] = color[0];
	v.RGBA[1] = color[1];
	v.RGBA[2] = color[2];
	v.RGBA[3] = color[3];
	return v;
}

GraphPainter::GraphPainter()
	: m_margin(20)
	, m_backgroundColor(1, 1, 1, g_defaultAValue)
	, m_defaultNodeColor(0.8f, 0.8f, 0.8f, g_defaultAValue)
	, m_nodeBorderColor(0, 0, 0, 1)
	, m_edgesColor(0, 0, 0, 1)
	, m_nodesVertexBuffer(0)
	, m_nodesIndexBuffer(0)
	, m_nodesBorderIndexBuffer(0)
	, m_edgesVertexBuffer(0)
{
	m_canvasSize[0] = 0;
	m_canvasSize[1] = 0;
}

GraphPainter::~GraphPainter() 
{
	Reset();
}

void GraphPainter::Reset()
{
    if (m_nodesVertexBuffer) gl::DeleteBuffers(1, &m_nodesVertexBuffer);
    if (m_nodesIndexBuffer) gl::DeleteBuffers(1, &m_nodesIndexBuffer);
    if (m_nodesBorderIndexBuffer) gl::DeleteBuffers(1, &m_nodesBorderIndexBuffer);
    if (m_edgesVertexBuffer) gl::DeleteBuffers(1, &m_edgesVertexBuffer);

	m_nodesVertexBuffer = 0;
	m_nodesIndexBuffer = 0;
	m_nodesBorderIndexBuffer = 0;
	m_edgesVertexBuffer = 0;
}

void GraphPainter::SetGraphAttributes(const std::shared_ptr<ogdf::GraphAttributes>& graphAttributes)
{
	Reset();

	m_graphAttributes = graphAttributes;
    if (!m_graphAttributes) return;

	// nodes
	std::vector<Vertex> nodesVectorVec;
	std::vector<uint> nodesIndexVec;
	std::vector<uint> nodesBorderIndexVec;

    size_t i = 0;
	for_each(m_graphAttributes->constGraph().firstNode(), [&](const ogdf::node& item) 
	{ 
		float x1 = (float) (m_graphAttributes->x(item) - m_graphAttributes->width(item)/2.0);
		float x2 = (float) (m_graphAttributes->x(item) + m_graphAttributes->width(item)/2.0);
		float y1 = (float) (m_graphAttributes->y(item) - m_graphAttributes->height(item)/2.0);
		float y2 = (float) (m_graphAttributes->y(item) + m_graphAttributes->height(item)/2.0);


		V4 color;
		if (ogdf::GraphAttributes::nodeColor & m_graphAttributes->attributes())
			color = HtmlColorToOpenGlColor(m_graphAttributes->colorNode(item).cstr());
		else
			color = m_defaultNodeColor;
		V4 lightColor = ToLightColor(color);

		// vertices
		nodesVectorVec.push_back(CreateVertex(x1, y1, 0.f, lightColor));
		nodesVectorVec.push_back(CreateVertex(x1, y2, 0.f, color));
		nodesVectorVec.push_back(CreateVertex(x2, y2, 0.f, color));
		nodesVectorVec.push_back(CreateVertex(x2, y1, 0.f, lightColor));

		// indices
		nodesIndexVec.push_back(i+0);
		nodesIndexVec.push_back(i+1);
		nodesIndexVec.push_back(i+3);
		nodesIndexVec.push_back(i+1);
		nodesIndexVec.push_back(i+2);
		nodesIndexVec.push_back(i+3);

		nodesBorderIndexVec.push_back(i+0);
		nodesBorderIndexVec.push_back(i+1);
		nodesBorderIndexVec.push_back(i+1);
		nodesBorderIndexVec.push_back(i+2);
		nodesBorderIndexVec.push_back(i+2);
		nodesBorderIndexVec.push_back(i+3);
		nodesBorderIndexVec.push_back(i+3);
		nodesBorderIndexVec.push_back(i+0);

		i += 4;
	});

	m_nodesVertexCount = nodesVectorVec.size();
	m_nodesIndexCount = nodesIndexVec.size();
	m_nodesBorderIndexCount = nodesBorderIndexVec.size();

    gl::GenBuffers(1, &m_nodesVertexBuffer);
    gl::BindBuffer(gl::GL_ARRAY_BUFFER, m_nodesVertexBuffer);
    gl::BufferData(gl::GL_ARRAY_BUFFER, sizeof(Vertex) * m_nodesVertexCount, nodesVectorVec.data(), gl::GL_STATIC_DRAW);
    gl::BindBuffer(gl::GL_ARRAY_BUFFER, 0);

    gl::GenBuffers(1, &m_nodesIndexBuffer);
    gl::BindBuffer(gl::GL_ELEMENT_ARRAY_BUFFER, m_nodesIndexBuffer);
    gl::BufferData(gl::GL_ELEMENT_ARRAY_BUFFER, sizeof(uint) * m_nodesIndexCount, nodesIndexVec.data(), gl::GL_STATIC_DRAW);
	gl::BindBuffer(gl::GL_ELEMENT_ARRAY_BUFFER, 0);

	gl::GenBuffers(1, &m_nodesBorderIndexBuffer);
	gl::BindBuffer(gl::GL_ELEMENT_ARRAY_BUFFER, m_nodesBorderIndexBuffer);
	gl::BufferData(gl::GL_ELEMENT_ARRAY_BUFFER, sizeof(uint) * m_nodesBorderIndexCount, nodesBorderIndexVec.data(), gl::GL_STATIC_DRAW);
	gl::BindBuffer(gl::GL_ELEMENT_ARRAY_BUFFER, 0);

	// edges
	std::vector<float> linesVertexVec;
	linesVertexVec.clear();
	for_each(m_graphAttributes->constGraph().firstEdge(), [&](const ogdf::edge& item) 
	{
		linesVertexVec.push_back((float)m_graphAttributes->x(item->source()));
		linesVertexVec.push_back((float)m_graphAttributes->y(item->source()));
		linesVertexVec.push_back(g_defaultZValue);
		linesVertexVec.push_back(g_defaultWValue);

		auto line = m_graphAttributes->bends(item);

		for (auto iter = line.begin(); iter != line.end(); ++iter)
		{
			linesVertexVec.push_back((float)(*iter).m_x);
			linesVertexVec.push_back((float)(*iter).m_y);
			linesVertexVec.push_back(g_defaultZValue);
			linesVertexVec.push_back(g_defaultWValue);

			linesVertexVec.push_back((float)(*iter).m_x);
			linesVertexVec.push_back((float)(*iter).m_y);
			linesVertexVec.push_back(g_defaultZValue);
			linesVertexVec.push_back(g_defaultWValue);
		}

		linesVertexVec.push_back((float)m_graphAttributes->x(item->target()));
		linesVertexVec.push_back((float)m_graphAttributes->y(item->target()));
		linesVertexVec.push_back(g_defaultZValue);
		linesVertexVec.push_back(g_defaultWValue);
	});

	m_edgesVertexCount = linesVertexVec.size() / 4;

	gl::GenBuffers(1, &m_edgesVertexBuffer);
	gl::BindBuffer(gl::GL_ARRAY_BUFFER, m_edgesVertexBuffer);
	gl::BufferData(gl::GL_ARRAY_BUFFER, sizeof(float) * linesVertexVec.size(), linesVertexVec.data(), gl::GL_STATIC_DRAW);
	gl::BindBuffer(gl::GL_ARRAY_BUFFER, 0);
}

void GraphPainter::Initialize()
{
	// glload-initialize
    if (glload::LoadFunctions() == glload::LS_LOAD_FAILED)
	{
	}

	m_shaders["default"] = std::make_shared<Shader>(g_defaultVertexShader, g_defaultFragmentShader);
	m_shaders["nodesBorder"] = std::make_shared<Shader>(g_nodesBorderVertexShader, g_defaultFragmentShader);
}

void GraphPainter::Resize(int width, int height)
{
	m_canvasSize[0] = (float)width;
	m_canvasSize[1] = (float)height;

	////////////////////////////////////////////////////////////////////////////////////////////////
	// init-ortho
	// http://stackoverflow.com/questions/5877728/want-an-opengl-2d-example-vc-draw-a-rectangle

	// Set up the orthographic projection
	gl::MatrixMode(gl::GL_PROJECTION);
	gl::LoadIdentity();
	gl::Ortho(0, width, height, 0, -1, 1);

	// Back to the modelview so we can draw stuff 
	gl::MatrixMode(gl::GL_MODELVIEW);
	gl::LoadIdentity();

	//Clear the screen and depth buffer
	gl::Clear(gl::GL_COLOR_BUFFER_BIT); 
	////////////////////////////////////////////////////////////////////////////////////////////////

	// This sets up the viewport so that the coordinates (0, 0) are at the top left of the window
	gl::Viewport(0, 0, width, height);
}

void GraphPainter::Paint()
{
	gl::ClearColor(m_backgroundColor[0], m_backgroundColor[1], m_backgroundColor[2], m_backgroundColor[3]);
	gl::Clear(gl::GL_COLOR_BUFFER_BIT|gl::GL_DEPTH_BUFFER_BIT);

	if (m_graphAttributes)
	{
		Rect view = View();
		M4 projMatrix = CreateOrtho2DMatrix(view);

#ifdef _DEBUG
		dout << "GraphPainter::Paint(): " << "view=" << view << std::endl;
#endif

		// edges
		const auto& edgesShader = m_shaders["nodesBorder"];
		edgesShader->Use(true);

		edgesShader->Set("projMatrix", projMatrix);
		edgesShader->Set("color", m_edgesColor);

		gl::BindBuffer(gl::GL_ARRAY_BUFFER, m_edgesVertexBuffer);
		gl::EnableVertexAttribArray(0);
		gl::VertexAttribPointer(0, 4, gl::GL_FLOAT, gl::GL_FALSE, 0, 0);
		gl::DrawArrays(gl::GL_LINES, 0, m_edgesVertexCount * 4);
		gl::DisableVertexAttribArray(0);

		edgesShader->Use(false);

		// nodes
		const auto& nodesShader = m_shaders["default"];
		nodesShader->Use(true);

		nodesShader->Set("projMatrix", projMatrix);

		gl::BindBuffer(gl::GL_ARRAY_BUFFER, m_nodesVertexBuffer);
		gl::BindBuffer(gl::GL_ELEMENT_ARRAY_BUFFER, m_nodesIndexBuffer);

		gl::EnableVertexAttribArray(0);
		gl::VertexAttribPointer(0, 4, gl::GL_FLOAT, gl::GL_FALSE, sizeof(Vertex), 0);
		gl::EnableVertexAttribArray(1);
        gl::VertexAttribPointer(1, 4, gl::GL_FLOAT, gl::GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(float)*4));

        gl::DrawElements(gl::GL_TRIANGLES, m_nodesIndexCount, gl::GL_UNSIGNED_INT, NULL);

		gl::DisableVertexAttribArray(0);
		gl::DisableVertexAttribArray(1);

		nodesShader->Use(false);

		// nodes border
		gl::BindBuffer(gl::GL_ELEMENT_ARRAY_BUFFER, m_nodesBorderIndexBuffer);

		const auto& nodesBorderShader = m_shaders["nodesBorder"];
		nodesBorderShader->Use(true);

		nodesBorderShader->Set("projMatrix", projMatrix);
		nodesBorderShader->Set("color", m_nodeBorderColor);

		gl::EnableVertexAttribArray(0);
		gl::VertexAttribPointer(0, 4, gl::GL_FLOAT, gl::GL_FALSE, sizeof(Vertex), 0);

		gl::DrawElements(gl::GL_LINES, m_nodesBorderIndexCount, gl::GL_UNSIGNED_INT, NULL);

		gl::DisableVertexAttribArray(0);

		nodesBorderShader->Use(false);
	}
}

// bounds of graph
Rect GraphPainter::Model() const
{
	if (!m_graphAttributes) return Rect();

	const ogdf::DRect& bounds = m_graphAttributes->boundingBox();

	return Rect(
		(float) bounds.p1().m_x, // left
		(float) bounds.p1().m_y, // top
		(float) bounds.p2().m_x, // right
		(float) bounds.p2().m_y); // bottom
}

// model with margin
Rect GraphPainter::World() const
{
	Rect model = Model();
	return Rect(
		model.Left() - m_margin, 
		model.Top() - m_margin, 
		model.Right() + m_margin, 
		model.Bottom() + m_margin);
}

Rect GraphPainter::ScrollableWorld() const
{
	auto world = World();
	auto view = View();

	return Rect(
		std::min(world.Left(), view.Left()), 
		std::min(world.Top(), view.Top()), 
		std::max(world.Right(), view.Right()), 
		std::max(world.Bottom(), view.Bottom()));
}

void GraphPainter::View(Rect view) 
{ 
	m_view = view;

#ifdef _DEBUG
	dout << "View(view): " << m_view << std::endl;
#endif
}

// 0, 0, Widget.width, Widget.height
Rect GraphPainter::Canvas() const
{
	return Rect(0.f, 0.f, m_canvasSize[0], m_canvasSize[1]);
}

float GraphPainter::Scale() const
{ 
	oggl::Rect view = View();
	oggl::Rect canvas = Canvas();

	if (view.Height() == 0 || view.Width() == 0 || canvas.Height() == 0)
		return 1;

	float viewRatio = view.Width() / view.Height();
	float canvasRatio = canvas.Width() / canvas.Height();

	if (viewRatio > canvasRatio)
		return canvas.Width() / view.Width();
	else 
		return canvas.Height() / view.Height();
}

void GraphPainter::Scale(float scale) 
{
	oggl::Rect canvas = Canvas();
	Scale(scale, oggl::V2(canvas.Width()/2, canvas.Height()/2));
}

void GraphPainter::Scale(float scale, oggl::V2 zoomCenter)
{
	auto canvas = Canvas();
	const auto& curView = View();

	oggl::M4 proj = Project(canvas, curView);
	oggl::V4 zoomCenterCanvas(zoomCenter[0], zoomCenter[1], 0, 1);
	oggl::V4 zoomCenterView = proj * zoomCenterCanvas;

	Rect view;
	view.Left(zoomCenterView[0] - zoomCenterCanvas[0]/scale);
	view.Top(zoomCenterView[1] - zoomCenterCanvas[1]/scale);
	view.Right(view.Left() + canvas.Width()/scale);
	view.Bottom(view.Top() + canvas.Height()/scale);

	View(view);
}

float WorldCanvasScale(const oggl::Rect& world, const oggl::Rect& canvas)
{ 
	if (world.Height() == 0 || world.Width() == 0 || canvas.Height() == 0)
		return 1;

	float worldRatio = world.Width() / world.Height();
	float canvasRatio = canvas.Width() / canvas.Height();

	if (worldRatio > canvasRatio)
		return canvas.Width() / world.Width();
	else 
		return canvas.Height() / world.Height();
}

void GraphPainter::ZoomToFit()
{
	// show whole graph
	auto world = World();
	auto canvas = Canvas();

	float scale = WorldCanvasScale(world, canvas);

	float viewWidth = canvas.Width() / scale;
	float viewHeight = canvas.Height() / scale;

	Rect view;
	view[0] = -(viewWidth - world.Width()) / 2 + world.Left();
	view[1] = -(viewHeight - world.Height()) / 2 + world.Top();
	view[2] = view[0] + viewWidth;
	view[3] = view[1] + viewHeight;

	View(view);

#ifdef _DEBUG
	dout << "ZoomToFit: " << "scale=" << scale << ", View=" << View() << std::endl;
#endif
}

void GraphPainter::ZoomToOrignalSize()
{
	auto world = World();
	auto canvas = Canvas();

	float scale = 1.f;

	float viewWidth = canvas.Width() / scale;
	float viewHeight = canvas.Height() / scale;

	Rect view;
	view[0] = -(viewWidth - world.Width()) / 2 + world.Left();
	view[1] = -(viewHeight - world.Height()) / 2 + world.Top();
	view[2] = view[0] + viewWidth;
	view[3] = view[1] + viewHeight;

	View(view);

#ifdef _DEBUG
    dout << "ZoomToOrignalSize: " << "scale=" << scale << ", View=" << View() << std::endl;
#endif
}
}
