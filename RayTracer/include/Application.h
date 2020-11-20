#pragma once

#include "Core.h"

#include "Image.h"
#include "Camera.h"
#include "Plane.h"
#include "Sphere.h"
#include "PathTracer.h"
#include "Log.h"

class Application
{
public:
	Application(int width, int height, int spp);

	void render();
	void saveImage(const std::string& filepath);
	Ref<Scene> getScene() const { return m_scene; }

private:
	Ref<PathTracer> m_integrator;
	Ref<Scene> m_scene;
	Ref<Camera> m_cam;
	Ref<Image> m_image;

	int m_spp;
};