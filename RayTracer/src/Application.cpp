#include "Application.h"

Application::Application(int width, int height)
{
	m_scene = createRef<Scene>();
	m_image = createRef<Image>(width, height);
	
	const double viewportHeight = 2.;
	m_cam = createRef<Camera>(Pt3(0.), double(viewportHeight * width) / height, viewportHeight, 1.);
}

void Application::render()
{
	int width = m_image->width(), height = m_image->height();

	for (int j = 0; j < height; j++)
	{
		printProgress(double(j * width) / (height * width));
		#pragma omp parallel for
		for (int i = 0; i < width; i++)
		{
			Ray r = m_cam->constructRay(double(i) / (width - 1), double(height - 1 - j) / (height - 1));
			m_image->setPixel(i, j, m_scene->render(r));
		}
	}
}

void Application::saveImage(const std::string& filepath)
{
	m_image->exportAsPPM(filepath);
}