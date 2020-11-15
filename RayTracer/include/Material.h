#pragma once

#include "Vec3.h"

struct Material
{
	Color diffuse;
	double roughness;

	Material(Color col, double a) : diffuse(col), roughness(a) {}
	Material() {}
};