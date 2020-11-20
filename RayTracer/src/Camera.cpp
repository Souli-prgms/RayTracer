#include "Camera.h"

Camera::Camera(Pt3 origin, double viewportWidth, double viewportHeight, double focalLength) : m_origin(origin), m_viewportWidth(viewportWidth), m_viewportHeight(viewportHeight), m_focalLength(focalLength)
{
	m_horizontal = Pt3(m_viewportWidth, 0, 0);
	m_vertical = Pt3(0, m_viewportHeight, 0);
	m_lowerLeftCorner = m_origin - m_horizontal / 2 - m_vertical / 2 - Vec3(0, 0, m_focalLength);
}

Ray Camera::constructRay(double u, double v)
{
	return Ray(m_origin, m_lowerLeftCorner + u * m_horizontal + v * m_vertical - m_origin, 0);
}