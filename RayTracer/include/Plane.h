#pragma once

#include "Shape.h"

class Plane : public Shape
{
public:
	Plane(Material mat) : Shape(mat) {}
	Plane(Pt3 point, Vec3 normal, Material mat) : Shape(mat), m_point(point), m_normal(normalize(normal)) {}
	virtual bool hit(const Ray& r, double tmin, double tmax, Hit& rec) const override;

private:
	Pt3 m_point;
	Vec3 m_normal;
};