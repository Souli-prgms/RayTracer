#include "Application.h"

int main()
{
	const int width = 1280, height = 720;
	Scope<Application> app = createScope<Application>(width, height);
	
	// Scene
	Ref<Scene> scene = app->getScene();
	scene->addObject(createRef<Plane>(Pt3(0, -1., -1.), Vec3(0., 1., 0.), Material(0.6 * Color(0.05, 0.1, 0.3), 0.08)));
	scene->addObject(createRef<Sphere>(Pt3(0., 0., -1.), 0.5, Material(Color(0.), 0.005)));

	scene->addLight(createRef<Light>(Pt3(2., 0., 0.), Color(100.)));
	scene->addLight(createRef<Light>(Pt3(-2., 0., 0.), Color(100.)));

	// Rendering
	app->render();
	app->saveImage("sample.ppm");
}
