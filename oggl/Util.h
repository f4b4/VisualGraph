// Util.h

#pragma once

#include <oggl/DebugStream.h>
#include <oggl/Types.h>

#include <algorithm>
#include <utility>
#include <random>
#include <memory>
#include <cmath>

#include <ogdf/basic/GraphAttributes.h>

namespace oggl {

    const float g_defaultZValue = 0.0f;
    const float g_defaultWValue = 1.0f;
    const float g_defaultAValue = 1.0f;

    const float PI = 3.141592654f;

    extern std::mt19937 g_randomEngine;

    void Dump(const std::shared_ptr<ogdf::GraphAttributes>& graphAttributes);

    const char* ToString(const ogdf::Graph::NodeType& nodeType);
    const char* ToString(const ogdf::Graph::EdgeType& edgeType);
    const char* ToString(const ogdf::GraphAttributes::EdgeStyle& edgeStyle);
    const char* ToString(const ogdf::GraphAttributes::EdgeArrow& edgeArrow);

    const char* NodeShapeToString(int nodeShape);
    V4 HtmlColorToOpenGlColor(const char* color);
    V4 RandomColor();
    void RandomHtmlColor(std::array<char, 8>& buf);
    V4 ToLightColor(V4 color);
    V4 RgbToHsv(V4 rgb);
    V4 HsvToRgb(V4 hsv);

    // for_each for nodes and edges
    template<class TIter, class TFunc>
    void for_each(TIter first, TFunc func)
    {
        for (; first; first = first->succ())
            func(first);
    }

    inline void Dump(const std::shared_ptr<ogdf::GraphAttributes>& graphAttributes)
    {
        const auto attrSep = ", ";
        const auto propSep = "; ";
        const auto lineSep = "\n";

        const ogdf::DRect& bounds = graphAttributes->boundingBox();

        auto& s = oggl::dout;

        s << "Graph ------------------------------------" << lineSep
            << "numberOfNodes=" << graphAttributes->constGraph().numberOfNodes() << attrSep
            << "numberOfEdges=" << graphAttributes->constGraph().numberOfEdges() << lineSep
            ;

        s << "bounds="
            << bounds.p1().m_x << attrSep << bounds.p1().m_y << attrSep
            << bounds.p2().m_x << attrSep << bounds.p2().m_y << lineSep
            ;

        for_each(graphAttributes->constGraph().firstNode(), [&](const ogdf::node& item)
        {
            s << "Node ------------------------------------" << lineSep
                << "index=" << item->index() << propSep << "indeg=" << item->indeg() << propSep << "outdeg=" << item->outdeg() << lineSep
                << "colorNode=" << graphAttributes->colorNode(item).cstr() << lineSep
                << "labelNode=" << graphAttributes->labelNode(item).cstr() << lineSep
                << "type=" << ToString(graphAttributes->type(item)) << lineSep
                << "shapeNode=" << NodeShapeToString(graphAttributes->shapeNode(item)) << lineSep
                ;
        });

        for_each(graphAttributes->constGraph().firstEdge(), [&](const ogdf::edge& item)
        {
            s << "Edge ------------------------------------" << lineSep
                << "index=" << item->index() << lineSep
                << "colorEdge=" << graphAttributes->colorEdge(item).cstr() << lineSep
                << "labelEdge=" << graphAttributes->labelEdge(item).cstr() << lineSep
                << "styleEdge=" << ToString(graphAttributes->styleEdge(item)) << lineSep
                << "type=" << ToString(graphAttributes->type(item)) << lineSep
                << "arrowEdge=" << ToString(graphAttributes->arrowEdge(item)) << lineSep
                ;
        });


        s.flush();
    }

    inline const char* ToString(const ogdf::Graph::NodeType& nodeType)
    {
        switch (nodeType)
        {
        case ogdf::Graph::vertex: return "vertex";
        case ogdf::Graph::dummy: return "dummy";
        case ogdf::Graph::generalizationMerger: return "generalizationMerger";
        case ogdf::Graph::generalizationExpander: return "generalizationExpander";
        case ogdf::Graph::highDegreeExpander: return "highDegreeExpander";
        case ogdf::Graph::lowDegreeExpander: return "lowDegreeExpander";
        case ogdf::Graph::associationClass: return "associationClass";
        default: return "unknown";
        }
    }

    inline const char* ToString(const ogdf::Graph::EdgeType& edgeType)
    {
        switch (edgeType)
        {
        case ogdf::Graph::association: return "association";
        case ogdf::Graph::generalization: return "generalization";
        case ogdf::Graph::dependency: return "dependency";
        default: return "unknown";
        }
    }

    inline const char* ToString(const ogdf::GraphAttributes::EdgeStyle& edgeStyle)
    {
        // The line styles are preliminary the same as in QT.
        switch (edgeStyle)
        {
        case ogdf::GraphAttributes::esNoPen: return "esNoPen";
        case ogdf::GraphAttributes::esSolid: return "esSolid";
        case ogdf::GraphAttributes::esDash: return "esDash";
        case ogdf::GraphAttributes::esDot: return "esDot";
        case ogdf::GraphAttributes::esDashdot: return "esDashdot";
        case ogdf::GraphAttributes::esDashdotdot: return "esDashdotdot";
        default: return "unknown";
        }
    }

    inline const char* ToString(const ogdf::GraphAttributes::EdgeArrow& edgeArrow)
    {
        switch (edgeArrow)
        {
        case ogdf::GraphAttributes::none: return "none";
        case ogdf::GraphAttributes::last: return "last";
        case ogdf::GraphAttributes::first: return "first";
        case ogdf::GraphAttributes::both: return "both";
        case ogdf::GraphAttributes::undefined: return "undefined";
        default: return "unknown";
        }
    }

    inline const char* NodeShapeToString(int nodeShape)
    {
        if (ogdf::GraphAttributes::rectangle == nodeShape) return "rectangle";
        if (ogdf::GraphAttributes::oval == nodeShape) return "oval";
        return "unknown";
    }

    inline int CharToInt(char c)
    {
        if ('0' <= c && c <= '9') return c - '0';
        if ('A' <= c && c <= 'F') return c - 'A' + 10;
        if ('a' <= c && c <= 'f') return c - 'a' + 10;
        return 0xF;
    }

    inline char IntToChar(int val)
    {
        if (val <= 9) return (char) ('0' + val);
        if (val <= 15) return (char) ('A' + val - 10);
        throw std::runtime_error("IntToChar: invalid val.");
    }

    inline void IntToChar(char* buf, int val)
    {
        buf[0] = IntToChar(val >> 4 & 0xF);
        buf[1] = IntToChar(val & 0xF);
    }

    inline V4 HtmlColorToOpenGlColor(const char* color)
    {
        const V4 defaultColor(0, 0, 0, g_defaultAValue);
        if (strlen(color) != 7) return defaultColor;

        V4 colorGl;
        colorGl[0] = (float)((CharToInt(color[1]) << 4) + CharToInt(color[2])) / 255.f;
        colorGl[1] = (float)((CharToInt(color[3]) << 4) + CharToInt(color[4])) / 255.f;
        colorGl[2] = (float)((CharToInt(color[5]) << 4) + CharToInt(color[6])) / 255.f;
        colorGl[3] = g_defaultAValue;

        return colorGl;
    }

    inline V4 RandomColor()
    {
        std::uniform_real_distribution<float> dH(0, 360);
        std::uniform_real_distribution<float> dS(0.5f, 1.0f);
        std::uniform_real_distribution<float> dV(0.8f, 1.0f);
        V4 hsv(dH(g_randomEngine), dS(g_randomEngine), dV(g_randomEngine), g_defaultAValue);
        return HsvToRgb(hsv);
    }

    inline void RandomHtmlColor(std::array<char, 8>& buf)
    {
        auto c = RandomColor();
        buf[0] = '#';
        buf[7] = 0;
        IntToChar(&buf[1], (int)(c[0] * 255.f));
        IntToChar(&buf[3], (int)(c[1] * 255.f));
        IntToChar(&buf[5], (int)(c[2] * 255.f));
    }

    inline V4 ToLightColor(V4 color)
    {
        V4 hsv = RgbToHsv(color);
        const float facS = 0.3f;
        const float facH = 1.5f;
        hsv[1] = std::min(hsv[1] * facS, 1.f);
        hsv[2] = std::min(hsv[2] * facH, 1.f);

        return HsvToRgb(hsv);
    }

    // r, g, b: [0.f - 1.f]
    // h:       [0.f - 360.f]
    // s, v:    [0.f - 1.f]
    // http://en.literateprograms.org/RGB_to_HSV_color_space_conversion_%28C%29
    inline V4 RgbToHsv(V4 rgb)
    {
        float r = rgb[0];
        float g = rgb[1];
        float b = rgb[2];

        // find min and max RGB value
        float min = std::min(r, std::min(g, b));
        float max = std::max(r, std::max(g, b));

        // compute value
        float v = max;
        if (v == 0.f) return V4(0, 0, 0, g_defaultAValue); // black

        // normalize value to 1
        r /= v;
        g /= v;
        b /= v;
        min = std::min(r, std::min(g, b));
        max = std::max(r, std::max(g, b));

        // compute saturation
        float s = max - min;
        if (s == 0.f) return V4(0, 0, v, g_defaultAValue); // grey

        // normalize saturation to 1
        r = (r - min) / (max - min);
        g = (g - min) / (max - min);
        b = (b - min) / (max - min);
        min = std::min(r, std::min(g, b));
        max = std::max(r, std::max(g, b));

        // compute hue
        float h;
        if (max == r)
        {
            h = 0.f + 60.f * (g - b);
            if (h < 0.f) h += 360.f;
        }
        else if (max == g)
            h = 120.f + 60.f * (b - r);
        else
            h = 240.f + 60.f * (r - g);

        return V4(h, s, v, g_defaultAValue);
    }

    // r, g, b: [0.f - 1.f]
    // h:       [0.f - 360.f]
    // s, v:    [0.f - 1.f]
    // http://en.wikipedia.org/wiki/HSL_and_HSV
    inline V4 HsvToRgb(V4 hsv)
    {
        float h = hsv[0];
        float s = hsv[1];
        float v = hsv[2];

        float c = v * s;
        float h1 = h / 60.f;
        float h_mod2 = h1 - (((int)h1) / 2)*2.f;
        float x = c * (1.f - std::abs(h_mod2 - 1));

        float r1, g1, b1;

        if (h < 60.f)
        {
            r1 = c; g1 = x; b1 = 0;
        }
        else if (h < 120.f)
        {
            r1 = x; g1 = c; b1 = 0;
        }
        else if (h < 180.f)
        {
            r1 = 0; g1 = c; b1 = x;
        }
        else if (h < 240.f)
        {
            r1 = 0; g1 = x; b1 = c;
        }
        else if (h < 300.f)
        {
            r1 = x; g1 = 0; b1 = c;
        }
        else
        {
            r1 = c; g1 = 0; b1 = x;
        }

        float m = v - c;

        return V4(r1 + m, g1 + m, b1 + m, g_defaultAValue);
    }

}