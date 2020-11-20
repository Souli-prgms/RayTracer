#include "PathTracer.h"

PathTracer::PathTracer() : m_maxRecursion(4)
{
}

Color PathTracer::li(const Ref<Scene>& scene, const Ray& r) const
{
	Hit rec;
	Color out;
	if (scene->intersect(r, rec))
	{
		const LightList& ligths = scene->getLightList();
		for (const auto& light : ligths)
			out += Lighting::sampleLight(rec.pt, rec.normal, -r.dir(), light->position, light->color, rec.mat);
		out /= scene->nbLights();
	}
	else
		out = scene->backgroundColor(r.dir());

	return out;
}