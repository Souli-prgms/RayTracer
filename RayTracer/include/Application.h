#pragma once

#include "Core.h"

#include "Image.h"
#include "Camera.h"
#include "Sphere.h"
#include "Plane.h"
#include "Lighting.h"
#include "Scene.h"

class Application
{
public:
	Application(int width, int height);

	void render();
	void saveImage(const std::string& filepath);
	Ref<Scene> getScene() const { return m_scene; }

private:
	Ref<Scene> m_scene;
	Ref<Camera> m_cam;
	Ref<Image> m_image;
};