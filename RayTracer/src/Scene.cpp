#include "Scene.h"

Scene::Scene()
{

}

Scene::~Scene()
{

}

Color Scene::render(const Ray& r)
{
	auto skyColor = [](const Vec3& dir)
	{
		Vec3 topCol(0.1, 0.1, 0.4);
		Vec3 horizonCol = 0.56 * Vec3(0.4, 0.6, 0.8);
		return 0.3 * mix<Color>(horizonCol, topCol, clamp(dir.z(), 0., 1.));
	};

	Color out = skyColor(r.dir());
	double tmin = 0., tmax = INF;
	Hit rec, trec;
	Material mat;
	Pt3 lightPos(1., 1., 0.);
	Color lightColor(10.);

	for (const auto& object : m_objects)
	{
		if (object->hit(r, tmin, tmax, trec))
		{
			rec = trec;
			tmax = rec.t;
			mat = object->getMaterial();
		}
	}

	if (tmax < INF)
		out = Lighting::sampleLight(rec.pt, rec.normal, -r.dir(), lightPos, lightColor, mat);

	return out;
}

void Scene::add(Ref<Shape> object)
{
	m_objects.push_back(object);
}