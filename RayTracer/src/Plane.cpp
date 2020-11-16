#include "Plane.h"

bool Plane::hit(const Ray& r, double tmin, double tmax, Hit& rec) const
{	
	double denom = dot(m_normal, r.dir());
	if (abs(denom) > 1e-6)
	{
		double alpha = dot(m_point - r.origin(), m_normal) / denom;
		if (alpha > tmin && alpha < tmax)
		{
			rec.t = alpha;
			rec.pt = r.at(rec.t);
			rec.normal = m_normal;
			return true;
		}
	}
	return false;
}