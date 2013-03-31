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

void CalcTest1();
void CalcTest2();
void CalcTest3();
void CalcTest4();
void CalcTest5();
void ProjectTest(Rect matrix1, Rect matrix2, std::vector<V2> pointPairs);
void TestScaling(const Rect& model, const Rect& canvas, float scale, const Rect& expected);

void CalcTest()
{
	CalcTest1();
	CalcTest2();
	CalcTest3();
	CalcTest4();
	CalcTest5();
}

void CalcTest1()
{
	Rect m1(0, 400, 400, 0);
	Rect m2(0, 0, 40, 40);

	std::vector<V2> pointPairs;

	pointPairs.push_back(V2(150.f,50.f));
	pointPairs.push_back(V2(15.f,35.f));

	pointPairs.push_back(V2(300,350));
	pointPairs.push_back(V2(30,5));

	ProjectTest(m1, m2, pointPairs);
}

void CalcTest2()
{
	Rect m1(0, 0, 400, 400);
	Rect m2(-1, 1, 1, -1);

	std::vector<V2> pointPairs;

	pointPairs.push_back(V2(0.f,400.f));
	pointPairs.push_back(V2(-1.f,-1.f));

	pointPairs.push_back(V2(100.f,300.f));
	pointPairs.push_back(V2(-0.5f,-0.5f));

	pointPairs.push_back(V2(200.f,200.f));
	pointPairs.push_back(V2(0.f, 0.f));

	pointPairs.push_back(V2(300.f,100.f));
	pointPairs.push_back(V2(0.5f, 0.5f));

	pointPairs.push_back(V2(400.f,0.f));
	pointPairs.push_back(V2(1.f, 1.f));

	ProjectTest(m1, m2, pointPairs);
}

void CalcTest3()
{
	Rect m1(100, 100, 900, 900);
	Rect m2(-1, 1, 1, -1);

	std::vector<V2> pointPairs;

	pointPairs.push_back(V2(100.f, 900.f));
	pointPairs.push_back(V2(-1.f,-1.f));

	pointPairs.push_back(V2(300.f, 700.f));
	pointPairs.push_back(V2(-0.5f,-0.5f));

	pointPairs.push_back(V2(500.f, 500.f));
	pointPairs.push_back(V2(0.f, 0.f));

	pointPairs.push_back(V2(700.f, 300.f));
	pointPairs.push_back(V2(0.5f, 0.5f));

	pointPairs.push_back(V2(900.f, 100.f));
	pointPairs.push_back(V2(1.f, 1.f));

	ProjectTest(m1, m2, pointPairs);
}

void CalcTest4()
{
	Rect coord1(400, 0, 80, 1);
	Rect coord2(0, 0, 400, 1);
	Rect coord3(-1, 1, 1, -1);

	M4 m1_2 = Project(coord1, coord2);
	M4 m2_3 = Project(coord2, coord3);
	M4 m1_3 = Project(coord1, coord3);

	M4 m1_3_a = m1_2 * m2_3;
	M4 m1_3_b = m2_3 * m1_2;

}

void CalcTest5()
{
	Rect model(0, 0, 30, 30);
	Rect canvas(0, 0, 80, 60);

	V4 centerCanvas(canvas.Width()/2, canvas.Height()/2, 0, 1);
	V4 centerModel(model.Width()/2, model.Height()/2, 0, 1);

	float scale1 = 1;
	Rect result1(-25, -15, 55, 45);

	float scale2 = 2;
	Rect result2(-5, 0, 35, 30);

	float scale3 = 4;
	Rect result3(5, 7.5, 25, 22.5);

	TestScaling(model, canvas, scale1, result1);
	TestScaling(model, canvas, scale2, result2);
	TestScaling(model, canvas, scale3, result3);
}

void TestScaling(const Rect& model, const Rect& canvas, float scale, const Rect& expected)
{
	Rect view;
	view.Left(model.Width()/2 - canvas.Width()/2/scale);
	view.Top(model.Height()/2 - canvas.Height()/2/scale);
	view.Right(model.Width()/2 + canvas.Width()/2/scale);
	view.Bottom(model.Height()/2 + canvas.Height()/2/scale);
	AssertIsEqual(expected, view);
}

void ProjectTest(Rect matrix1, Rect matrix2, std::vector<V2> pointPairs)
{
	// 1. project from R1 -> R2
	M4 m1_2 = Project(matrix1, matrix2);
	M4 m2_1 = Project(matrix2, matrix1);

	for (size_t i = 0; i < pointPairs.size(); i += 2)
	{
		V4 p1(pointPairs[i][0], pointPairs[i][1], 0, 1);
		V4 p2(pointPairs[i+1][0], pointPairs[i+1][1], 0, 1);

		V4 p1_a = m2_1 * p2;
		V4 p2_a = m1_2 * p1;

		AssertIsEqual(p1, p1_a);
		AssertIsEqual(p2, p2_a);
	}
}