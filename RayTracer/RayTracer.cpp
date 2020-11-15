#include "Core.h"

#include "Image.h"
#include "Camera.h"
#include "Sphere.h"
#include "Plane.h"
#include "Lighting.h"
#include "Scene.h"

int main()
{
	// Image
	const double aspectRatio = 16. / 9.;
	const int imgWidth = 1280;
	const int imgHeight = imgWidth / aspectRatio;
	Image image(imgWidth, imgHeight);

	// Camera
	const double viewportHeight = 2.;
	Camera cam(Pt3(0.), viewportHeight * aspectRatio, viewportHeight, 1.);

	// Scene
	Scene scene;
	scene.add(createRef<Plane>(Material(0.6 * Vec3(0.05, 0.1, 0.3), 0.08)));
	scene.add(createRef<Sphere>(Pt3(0., 0., -1.), 0.5, Material(Color(0.), 0.5)));

	// Render
	for (int j = 0; j < imgHeight; j++)
	{
		printProgress(double(j * imgWidth) / (imgHeight * imgWidth));
		#pragma omp parallel for
		for (int i = 0; i < imgWidth; i++)
		{
			Ray r = cam.constructRay(double(i) / (imgWidth - 1), double(imgHeight - 1 - j) / (imgHeight - 1));
			image.setPixel(i, j, scene.render(r));
		}
	}
		
	// Save image
	image.exportAsPPM("sample.ppm");
}
