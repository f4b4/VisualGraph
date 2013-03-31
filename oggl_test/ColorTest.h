// CalcTest.h
#pragma once

#include "Test.h"

#include <oggl/Types.h>
#include <oggl/Math.h>
#include <oggl/Util.h>

#include <algorithm>
#include <vector>
#include <stdexcept>
#include <iostream>

using namespace oggl;

void ColorTest1();
void Test(V4 rgb, V4 hsv);
void Test(int r, int g, int b, int h, int s, int v);

void ColorTest()
{
	ColorTest1();
}

void ColorTest1()
{
	Test(0, 0, 0, 0, 0, 0);
	Test(255, 255, 255, 0, 0, 100);
	Test(0, 255, 255, 180, 100, 100);
	Test(0, 255, 80, 139, 100, 100);
	Test(252, 255, 178, 62, 30, 100);
	Test(75, 119, 86, 135, 37, 47);
	Test(255, 214, 204, 12, 20, 100);
	Test(84, 71, 56, 33, 33, 33);
}

void Test(V4 rgb, V4 hsv)
{
	V4 hsv1 = RgbToHsv(rgb);
	AssertIsEqual(hsv[0], hsv1[0], 0.9f);
	AssertIsEqual(hsv[1], hsv1[1], 0.01f);
	AssertIsEqual(hsv[2], hsv1[2], 0.01f);
	AssertIsEqual(hsv[3], hsv1[3], 0.01f);

	V4 rgb1 = HsvToRgb(hsv);
	AssertIsEqual(rgb, rgb1, 0.01f);
}

// Paint.NET
// r,g, b: [0, 255]
// h:      [0, 360]
// s, v:   [0, 100]
void Test(int r, int g, int b, int h, int s, int v)
{
	Test(V4(r/255.f, g/255.f, b/255.f, 1.f),
		V4(h, s/100.f, v/100.f, 1.f));
}
