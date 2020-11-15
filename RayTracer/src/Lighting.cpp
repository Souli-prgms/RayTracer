#include "Lighting.h"

namespace Lighting
{
	Color fresnelApproximation(const Vec3& toEye, const Vec3& halfVec, const Vec3& minVal)
	{
		return minVal + (1. - minVal) * pow(1. - dot(toEye, halfVec), 5.);
	}

	float microfacetDistribution(Vec3 halfVec, Vec3 normal, float roughness)
	{
		float alpha = roughness * roughness;
		float dotNH = dot(normal, halfVec);
		float f = (dotNH * alpha - dotNH) * dotNH + 1.;
		return alpha / (PI * f * f);
	}

	Color sampleLight(const Vec3& pos, const Vec3& normal, const Vec3& toEye, const Vec3& lightPos, const Vec3& lightColor, const Material& mat)
	{
		Color specularContrib(0.), diffuseContrib(0.);

		Color contrib;
		Vec3 toLight = lightPos - pos;
		double dnl = dot(normal, toLight);
		if (dnl <= 0.)
			return contrib;
		
		double toLightLength = toLight.length();
		double ooToLightLength = 1. / toLightLength;
		dnl *= ooToLightLength;
		Vec3 toLightN = toLight * ooToLightLength;
		
		Vec3 hvec = normalize(toLightN + toEye);
		Vec3 f0(0.005);
		Vec3 fresnel = fresnelApproximation(toEye, hvec, f0);
		if (mat.roughness < 1.)
		{
			float D = microfacetDistribution(hvec, normal, mat.roughness);
			specularContrib = fresnel * D;
		}

		diffuseContrib = (1. / PI) * (1. - fresnel) * mat.diffuse;
		contrib = lightColor * (specularContrib + diffuseContrib) * (dnl * ooToLightLength * ooToLightLength);
		return contrib;
	}
}