#pragma once

#include "Shape.h"

class Sphere : public Shape
{
public:
	Sphere(Material mat) : Shape(mat) {}
	Sphere(Pt3 center, double radius, Material mat) : Shape(mat), m_center(center), m_radius(radius) {}
	virtual bool hit(const Ray& r, double tmin, double tmax, Hit& rec) const override;

private:
	Pt3 m_center;
	double m_radius;
};

