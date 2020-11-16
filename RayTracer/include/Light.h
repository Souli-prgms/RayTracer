#pragma once

#include "Vec3.h"

struct Light 
{
	Pt3 position;
	Color color;

	Light(Pt3 pos, Color col) : position(pos), color(col) {}
};