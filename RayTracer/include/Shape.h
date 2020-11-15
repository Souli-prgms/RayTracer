#pragma once

#include "Material.h"
#include "Hit.h"
#include "Ray.h"

class Shape
{
public:
	Shape(Material mat) : m_material(mat) {}
	virtual bool hit(const Ray& r, double tmin, double tmax, Hit& rec) const = 0;
	Material getMaterial() const { return m_material; }

protected:
	Material m_material;
};