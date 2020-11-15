#include "Plane.h"

bool Plane::hit(const Ray& r, double tmin, double tmax, Hit& rec) const
{
	if (r.dir().z() * r.origin().z() >= 0.)
		return false;

	double alpha = -r.origin().z() / r.dir().z();
	if (tmin < alpha < tmax)
	{
		rec.t = alpha;
		rec.pt = r.at(alpha);
		rec.normal = Vec3(0, 0, 1);
		return true;
	}

	return false;
}