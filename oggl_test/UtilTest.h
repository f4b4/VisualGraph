#include "Test.h"

#include <oggl/Types.h>
#include <oggl/Math.h>
#include <oggl/Util.h>

#include <algorithm>
#include <vector>
#include <stdexcept>
#include <iostream>

using namespace oggl;

void UtilTest()
{
	auto c1 = HtmlColorToOpenGlColor("#000000");
	AssertIsEqual<float, 4>(V4(0, 0, 0, 1), c1);
	auto c2 = HtmlColorToOpenGlColor("#FF0080");
	AssertIsEqual<float, 4>(V4(1, 0, 0.502f, 1), c2);
	auto c3 = HtmlColorToOpenGlColor("#ABC");
	AssertIsEqual<float, 4>(V4(0, 0, 0, 1), c3);
}