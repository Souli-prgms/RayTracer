#include "Scene.h"

Scene::Scene()
{

}

Scene::~Scene()
{

}

bool Scene::intersect(const Ray& r, Hit& rec)
{
	double tmin = 0., tmax = INF;
	Hit trec;
	for (const auto& object : m_objects)
	{
		if (object->hit(r, tmin, tmax, trec))
		{
			rec = trec;
			rec.mat = object->getMaterial();
			tmax = trec.t;
		}
	}

	return tmax < INF;
}

Color Scene::render(const Ray& r)
{
	auto skyColor = [](const Vec3& dir)
	{
		Color topCol(0.1, 0.1, 0.4);
		Color horizonCol = 0.56 * Color(0.4, 0.6, 0.8);
		return 0.3 * mix<Color>(horizonCol, topCol, clamp(dir.z(), 0., 1.));
	};
	
	Hit rec;
	Color out;
	if (intersect(r, rec))
	{
		for (const auto& light : m_lights)
			out += Lighting::sampleLight(rec.pt, rec.normal, -r.dir(), light->position, light->color, rec.mat);
		out /= nbLights();
	}
	else
		out = skyColor(r.dir());

	return out;
}

void Scene::addObject(Ref<Shape> object)
{
	m_objects.push_back(object);
}

void Scene::addLight(Ref<Light> object)
{
	m_lights.push_back(object);
}