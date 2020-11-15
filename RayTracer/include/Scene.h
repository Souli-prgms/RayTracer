#pragma once

#include "Lighting.h"
#include "Shape.h"

class Scene
{
public:
	Scene();
	~Scene();

	Color render(const Ray& r);
	void add(Ref<Shape> object);

private:
	std::vector<Ref<Shape>> m_objects;
};