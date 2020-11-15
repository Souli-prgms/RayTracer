#include "Sphere.h"

bool Sphere::hit(const Ray& r, double tmin, double tmax, Hit& rec) const
{
	Vec3 oc = r.origin() - m_center;
	double a = r.dir().squaredLength();
	double b = 2. * dot(oc, r.dir());
	double c = oc.squaredLength() - m_radius * m_radius;
	double disc = b * b - 4. * a * c;

	if (disc >= 0.)
	{
		double alpha = (-b - sqrt(disc)) / (2. * a);
		if (tmin < alpha < tmax) 
		{
			rec.t = alpha;
			rec.pt = r.at(alpha);
			rec.normal = normalize(rec.pt - m_center);
			return true;
		}
	}

	return false;
}