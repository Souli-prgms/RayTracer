#pragma once

#include "Material.h"

namespace Lighting
{
	Color fresnelApproximation(const Vec3& toEye, const Vec3& halfVec, const Vec3& minVal);
	float microfacetDistribution(Vec3 halfVec, Vec3 normal, float roughness);
	Color sampleLight(const Vec3& pos, const Vec3& normal, const Vec3& toEye, const Vec3& lightPos, const Vec3& lightColor, const Material& mat);
	Color unreal(const Color& color);
}