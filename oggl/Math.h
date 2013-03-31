// Calc.h
#pragma once

#include <oggl/Types.h>

#include <array>

namespace oggl {

M4 Project(Rect lhs, Rect rhs);
M4 CreateOrtho2DMatrix(Rect visibleView);

// view (visible area in pixel) -> OpenGL normalized coords
inline M4 CreateOrtho2DMatrix(Rect visibleView)
{
	return Project(visibleView, Rect(-1.f, 1.f, 1.f, -1.f));
}

// project 2D coords
// lhs, rhs (left, top, right, bottom)
// lhs: source coordinate system
// rhs: destination coordinate system
//
//   rhs.Width                                         lhs.Right * rhs.Width
//  -----------       0            0      rhs.Right - -----------------------
//   lhs.Width                                               lhs.Width
//  
//               rhs.HeightLH                        lhs.Top * rhs.HeightLH
//       0      --------------     0      rhs.Top - ------------------------
//               lhs.HeightLH                             lhs.HeightLH
//  	       
//       0            0            1                    0
//  	       		           
//       0            0            0                    1
//  
inline M4 Project(Rect lhs, Rect rhs)
{
	return M4(
		rhs.Width()/lhs.Width(), 0.f, 0.f, rhs.Right()-lhs.Right()*rhs.Width()/lhs.Width(),
		0.f, rhs.HeightLH()/lhs.HeightLH(), 0.f, rhs.Top()-lhs.Top()*rhs.HeightLH()/lhs.HeightLH(),
		0.f, 0.f, 1.f, 0.f,
		0.f, 0.f, 0.f, 1.f);
}

// linear projection
//
//  b2 - a2     x2 - a2
// --------- = ---------
//  b1 - a1     x1 - a1
//
inline float LinearProjection(float x1, float a1, float b1, float a2, float b2)
{
	return a2 + (b2 - a2) / (b1 - a1) * (x1 - a1);
}

}
