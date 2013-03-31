// Test.h
#pragma once

#include <oggl/Types.h>

#include <stdexcept>
#include <iostream>

template<typename T>
void AssertIsEqual(T expected, T value)
{
	if (expected != value)
		throw std::runtime_error("is not equal");
}

template<typename T>
void AssertIsEqual(T expected, T value, T epsilon)
{
	float delta = expected - value;

	if (delta < 0.f && delta < -epsilon ||
		delta > 0.f && delta > epsilon)
		throw std::runtime_error("is not equal");
}

template<>
void AssertIsEqual(float expected, float value)
{
	const float epsilon = 0.0001f;
	AssertIsEqual(expected, value, epsilon);
}

template<typename T, size_t SIZE>
void AssertIsEqual(std::array<T, SIZE> expected, std::array<T, SIZE> value)
{
	for (int i = 0; i < SIZE; i++)
		AssertIsEqual(expected[i], value[i]);
}

template<typename T, size_t SIZE>
void AssertIsEqual(std::array<T, SIZE> expected, std::array<T, SIZE> value, T epsilon)
{
	for (int i = 0; i < SIZE; i++)
		AssertIsEqual(expected[i], value[i], epsilon);
}

