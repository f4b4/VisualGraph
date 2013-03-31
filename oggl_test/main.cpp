// main.cpp
#include "CalcTest.h"
#include "UtilTest.h"
#include "ColorTest.h"

#include <oggl/Types.h>
#include <oggl/Math.h>
#include <oggl/Util.h>

#include <stdexcept>
#include <iostream>

using namespace oggl;

int main()
{
	try
	{
		ColorTest();
		CalcTest();
		UtilTest();
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
		return 1;
	}


	return 0;
}