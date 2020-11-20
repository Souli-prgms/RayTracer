#include "PathTracer.h"

PathTracer::PathTracer() : m_maxRecursion(4)
{
}

Color PathTracer::li(const Ref<Scene>& scene, const Ray& r) const
{
	Color radiance(0.);

	if (r.recursionLevel() >= m_maxRecursion)
		return radiance;

	Hit rec;
	if (scene->intersect(r, rec))
	{
		const LightList& ligths = scene->getLightList();
		for (const auto& light : ligths)
		{
			Vec3 toLight = light->position - rec.pt;
			Ray shadowRay(rec.pt + rec.normal * 1e-4, normalize(toLight), 0);
			Hit shadowRec;
			scene->intersect(shadowRay, shadowRec);
			if (shadowRec.t >= toLight.length())
				radiance += Lighting::sampleLight(rec.pt, rec.normal, -r.dir(), light->position, light->color, rec.mat);
		}
		radiance /= scene->nbLights();
	}
	else
		radiance = scene->backgroundColor(r.dir());

	return Lighting::unreal(radiance);
}