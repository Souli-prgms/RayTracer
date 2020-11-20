#pragma once

#include "Light.h"
#include "Lighting.h"
#include "Shape.h"

typedef std::vector<Ref<Light>> LightList;
typedef std::vector<Ref<Shape>> ShapeList;

class Scene
{
public:
	Scene();
	~Scene();

	void addObject(Ref<Shape> object);
	void addLight(Ref<Light> light);
	int nbLights() const { return m_lights.size(); }
	bool intersect(const Ray& r, Hit& rec);
	Color backgroundColor(const Vec3& dir) const;
	const LightList& getLightList() const { return m_lights; }
	const ShapeList& getShapeList() const { return m_objects; }

private:
	ShapeList m_objects;
	LightList m_lights;
};