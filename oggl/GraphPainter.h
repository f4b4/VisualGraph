#pragma once

#include <oggl/Types.h>
#include <oggl/Shader.h>

#include <vector>
#include <map>
#include <algorithm>
#include <memory>
#include <stdexcept>

#include <ogdf/basic/GraphAttributes.h>

namespace oggl {

class GraphPainter
{
public:
	GraphPainter();
	~GraphPainter();

	void SetGraphAttributes(const std::shared_ptr<ogdf::GraphAttributes>& graphAttributes);

	float Scale() const;
	void Scale(float scale);
	void Scale(float scale, oggl::V2 zoomCenter);

	void Initialize();
	void Resize(int width, int height);
	void Paint();

	// bounds of g
	Rect Model() const;

	// 0, 0, Model.width, Model.height
	Rect World() const;

	Rect ScrollableWorld() const;

	// 0, 0, Widget.width, Widget.height
	Rect Canvas() const;

	// view with offsets
	Rect View() const { return m_view; }
	void View(Rect view);

	void ZoomToFit();
	void ZoomToOrignalSize();

private:
	void Reset();

private:
	std::shared_ptr<ogdf::GraphAttributes> m_graphAttributes;

	// layout
	float m_margin;
	V4 m_backgroundColor;
	V4 m_defaultNodeColor;
	V4 m_nodeBorderColor;
	V4 m_edgesColor;

	// OpenGL data
	uint m_nodesVertexBuffer;
	size_t m_nodesVertexCount;
	uint m_nodesIndexBuffer;
	size_t m_nodesIndexCount;
	uint m_nodesBorderIndexBuffer;
	size_t m_nodesBorderIndexCount;
	uint m_edgesVertexBuffer;
	size_t m_edgesVertexCount;

	// canvas size, pixel
	V2 m_canvasSize;
	// view offset, pixel, scrolling
	Rect m_view;

	std::map<std::string, std::shared_ptr<Shader>> m_shaders;
};

}