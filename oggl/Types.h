#pragma once

#include <array>
#include <string>
#include <ostream>

using namespace std;

namespace oggl {

typedef unsigned int uint;

class V2 : public std::array<float, 2>
{
public:
	V2() {}

	V2(float a0, float a1)
	{
		at(0) = a0;
		at(1) = a1;
	}
};

class V4 : public std::array<float, 4>
{
public:
	V4()
	{
		at(0) = 0;
		at(1) = 0;
		at(2) = 0;
		at(3) = 0;
	}

	V4(float a0, float a1, float a2, float a3)
	{
		at(0) = a0;
		at(1) = a1;
		at(2) = a2;
		at(3) = a3;
	}

};

inline std::ostream& operator<< (std::ostream& stream, const V4& vec)
{
    stream << "(" << vec[0] << ", " << vec[1] << ", " << vec[2] << ", " << vec[3] << ")";
	return stream;
}

class Rect : public V4
{
public:
	Rect() : V4(0,0,0,0) {}

	Rect(float a0, float a1, float a2, float a3)
		: V4(a0, a1, a2, a3)
	{
	}

	float Left()   const   { return at(0); }
	float Top()    const   { return at(1); }
	float Right()  const   { return at(2); }
	float Bottom() const   { return at(3); }
	float Width()  const   { return Right() - Left(); }
	float Height() const   { return Bottom() - Top(); }

	void Left(float val)   { at(0) = val; }
	void Top(float val)    { at(1) = val; }
	void Right(float val)  { at(2) = val; }
	void Bottom(float val) { at(3) = val; }

	void Scale(float scale)
	{
		at(0) *= scale;
		at(1) *= scale;
		at(2) *= scale;
		at(3) *= scale;
	}

	void Translate(const V2& vec)
	{
		at(0) += vec[0];
		at(1) += vec[1];
		at(2) += vec[0];
		at(3) += vec[1];
	}

	// left handed, OpenGL normalized device coordinates l=-1, r=1, t=1, b=-1, n=-1, f=1
	float HeightLH() { return Top() - Bottom(); }
};

// row-major
class M4
{
	std::array<float, 16> m_ar;

public:
	M4(
		float x0, float y0, float z0, float w0,
		float x1, float y1, float z1, float w1,
		float x2, float y2, float z2, float w2,
		float x3, float y3, float z3, float w3)
	{
		m_ar[ 0] = x0; m_ar[ 1] = y0; m_ar[ 2] = z0; m_ar[ 3] = w0; 
		m_ar[ 4] = x1; m_ar[ 5] = y1; m_ar[ 6] = z1; m_ar[ 7] = w1; 
		m_ar[ 8] = x2; m_ar[ 9] = y2; m_ar[10] = z2; m_ar[11] = w2; 
		m_ar[12] = x3; m_ar[13] = y3; m_ar[14] = z3; m_ar[15] = w3; 
	}

	float operator[](size_t index) const { return m_ar[index]; }

	V4 operator*(const V4& rhs) const
	{
		return V4(
			m_ar[ 0]*rhs[0] + m_ar[ 1]*rhs[1] + m_ar[ 2]*rhs[2] + m_ar[ 3]*rhs[3],
			m_ar[ 4]*rhs[0] + m_ar[ 5]*rhs[1] + m_ar[ 6]*rhs[2] + m_ar[ 7]*rhs[3],
			m_ar[ 8]*rhs[0] + m_ar[ 9]*rhs[1] + m_ar[10]*rhs[2] + m_ar[11]*rhs[3],
			m_ar[12]*rhs[0] + m_ar[13]*rhs[1] + m_ar[14]*rhs[2] + m_ar[15]*rhs[3]);
	}

	M4 operator*(const M4& n) const
	{
		return M4(
			m_ar[ 0]*n[0] + m_ar[ 1]*n[4] + m_ar[ 2]*n[ 8] + m_ar[ 3]*n[12], 
			m_ar[ 0]*n[1] + m_ar[ 1]*n[5] + m_ar[ 2]*n[ 9] + m_ar[ 3]*n[13],   
			m_ar[ 0]*n[2] + m_ar[ 1]*n[6] + m_ar[ 2]*n[10] + m_ar[ 3]*n[14],   
			m_ar[ 0]*n[3] + m_ar[ 1]*n[7] + m_ar[ 2]*n[11] + m_ar[ 3]*n[15],
			m_ar[ 4]*n[0] + m_ar[ 5]*n[4] + m_ar[ 6]*n[ 8] + m_ar[ 7]*n[12],   
			m_ar[ 4]*n[1] + m_ar[ 5]*n[5] + m_ar[ 6]*n[ 9] + m_ar[ 7]*n[13],   
			m_ar[ 4]*n[2] + m_ar[ 5]*n[6] + m_ar[ 6]*n[10] + m_ar[ 7]*n[14],   
			m_ar[ 4]*n[3] + m_ar[ 5]*n[7] + m_ar[ 6]*n[11] + m_ar[ 7]*n[15],
			m_ar[ 8]*n[0] + m_ar[ 9]*n[4] + m_ar[10]*n[ 8] + m_ar[11]*n[12],  
			m_ar[ 8]*n[1] + m_ar[ 9]*n[5] + m_ar[10]*n[ 9] + m_ar[11]*n[13],  
			m_ar[ 8]*n[2] + m_ar[ 9]*n[6] + m_ar[10]*n[10] + m_ar[11]*n[14],  
			m_ar[ 8]*n[3] + m_ar[ 9]*n[7] + m_ar[10]*n[11] + m_ar[11]*n[15],
			m_ar[12]*n[0] + m_ar[13]*n[4] + m_ar[14]*n[ 8] + m_ar[15]*n[12],  
			m_ar[12]*n[1] + m_ar[13]*n[5] + m_ar[14]*n[ 9] + m_ar[15]*n[13],  
			m_ar[12]*n[2] + m_ar[13]*n[6] + m_ar[14]*n[10] + m_ar[15]*n[14],  
			m_ar[12]*n[3] + m_ar[13]*n[7] + m_ar[14]*n[11] + m_ar[15]*n[15]);
	}

	// row-major -> col-major
	std::array<float, 16> Transpose() const
	{
        std::array<float, 16> ar = {{
			m_ar[0], m_ar[4], m_ar[ 8],  m_ar[12],
			m_ar[1], m_ar[5], m_ar[ 9],  m_ar[13],
			m_ar[2], m_ar[6], m_ar[10],  m_ar[14],
            m_ar[3], m_ar[7], m_ar[11],  m_ar[15]}};
		return ar;
	}

};

inline M4 Identity()
{
	return M4(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
}

}
