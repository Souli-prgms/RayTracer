#pragma once

#include "Light.h"
#include "Lighting.h"
#include "Shape.h"

class Scene
{
public:
	Scene();
	~Scene();

	Color render(const Ray& r);
	void addObject(Ref<Shape> object);
	void addLight(Ref<Light> light);
	int nbLights() const { return m_lights.size(); }

private:
	bool intersect(const Ray& r, Hit& rec);

	std::vector<Ref<Shape>> m_objects;
	std::vector<Ref<Light>> m_lights;
};