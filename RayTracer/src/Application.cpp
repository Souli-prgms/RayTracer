#include "Application.h"

Application::Application(int width, int height, int spp) : m_spp(spp)
{
	Log::init();
	LOG_INFO("Rendering image with size: {0}, {1}", width, height);

	m_scene = createRef<Scene>();
	m_image = createRef<Image>(width, height);
	m_integrator = createRef<PathTracer>();
	
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
			Color col;
			for (int s = 0; s < m_spp; s++)
			{
				Ray r = m_cam->constructRay(double(i + random()) / (width - 1), double(height - 1 - (j + random())) / (height - 1));
				col += m_integrator->li(m_scene, r);
			}
			m_image->setPixel(i, j, col, m_spp);
		}
	}
	std::cout << "\n" << std::endl;
}

void Application::saveImage(const std::string& filepath)
{
	LOG_INFO("Saving image...");
	m_image->exportAsPPM(filepath);
}