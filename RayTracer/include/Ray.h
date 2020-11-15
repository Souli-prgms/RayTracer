#pragma once

#include "Vec3.h"

class Ray
{
public:
	Ray() {}
	Ray(const Pt3& origin, const Vec3& dir) : m_origin(origin), m_dir(dir) {}

	Pt3 origin() const { return m_origin; }
	Vec3 dir() const { return m_dir; }

	Pt3 at(double t) const { return m_origin + t * m_dir; }

private:
	Pt3 m_origin;
	Vec3 m_dir;
};
