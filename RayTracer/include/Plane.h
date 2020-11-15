#pragma once

#include "Shape.h"

class Plane : public Shape
{
public:
	Plane(Material mat) : Shape(mat) {}
	virtual bool hit(const Ray& r, double tmin, double tmax, Hit& rec) const override;
};