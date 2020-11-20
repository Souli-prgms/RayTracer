#include "Image.h"

Image::Image(int width, int height) : m_width(width), m_height(height)
{
	m_pixels = std::vector<Color>(width * height, Color());
}

void Image::setPixel(int i, int j, const Color& pixelColor, int spp)
{
	m_pixels[j * m_width + i] = pixelColor / spp;
}

void Image::exportAsPPM(const std::string& filename)
{
	std::ofstream image;
	image.open(filename);
	image << "P3\n" << m_width << ' ' << m_height << "\n255\n";
	for (int j = 0; j < m_height; j++)
	{
		printProgress(double(j * m_width) / (m_height * m_width));
		for (int i = 0; i < m_width; i++)
		{
			Color pixelColor = m_pixels[j * m_width + i];
			image << static_cast<int>(255.99 * clamp(pixelColor.x(), 0., 1.)) << ' ' << static_cast<int>(255.99 * clamp(pixelColor.y(), 0., 1.)) << ' ' << static_cast<int>(255.99 * clamp(pixelColor.z(), 0., 1.)) << '\n';
		}
	}

	image.close();
}