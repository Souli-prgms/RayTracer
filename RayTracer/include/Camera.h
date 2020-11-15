#pragma once

#include"Ray.h"

class Camera
{
public:
	Camera(Pt3 origin, double viewportWidth, double viewportHeight, double focalLength);
	Ray constructRay(double u, double v);

private:
	Pt3 m_origin, m_horizontal, m_vertical, m_lowerLeftCorner;
	double m_viewportHeight, m_viewportWidth, m_focalLength;
};