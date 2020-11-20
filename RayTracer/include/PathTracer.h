#pragma once

#include "Scene.h"
#include "Lighting.h"

class PathTracer
{
public:
	PathTracer();

	Color li(const Ref<Scene>& scene, const Ray& r) const;

private:
	int m_maxRecursion;
};