#pragma once

#include "Vec3.h"

class Image
{
public:
	Image(int width, int height);

	int width() const { return m_width; }
	int height() const { return m_height; }

	void exportAsPPM(const std::string& filename);

	void setPixel(int i, int j, const Color& pixelColor);

private:
	int m_width, m_height;
	std::vector<Color> m_pixels;
};