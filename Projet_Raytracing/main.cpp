#include <iostream>
#include <string>
#include "../FreeImage/FreeImage.h"
#include "SDL.h"
#include <time.h>
#include <chrono>
#include <thread>

/*Include our classes*/
#include "game.h"

/*Definition for image*/
#define WIDTH 500
#define HEIGHT 500
#define BitsPerPixel 24
/*Definition for processing*/
#define DEBUG 1 //For printing debug cout
#define DEBUG_IMAGE 0 //for printing debug_image (random color)
#define PRINT_WINDOWS 1 //for printing to screen the image

//FreeImage_Save(FIF_PNG, bitmap, "export.png", 0); //Export an image to a file

/** Initialise a SDL window and return a pointer to it. */
SDL_Window *get_sdl_window(int width, int height) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL couldn't initialise: %s.\n"<< SDL_GetError() <<"\n";
		exit(5);
	}

	SDL_Window *sdl_window;
	sdl_window = SDL_CreateWindow("Raytracing",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width,
		height,
		SDL_WINDOW_BORDERLESS);

	return sdl_window;
}

/*Return the surface painted with the image*/
SDL_Surface* get_surface_image(FIBITMAP *image)
{
	//Assign the image to the surface
	// Loaded image is upside down, so flip it. for compatibility with SDL
	FreeImage_FlipVertical(image);

	SDL_Surface *sdl_surface = SDL_CreateRGBSurfaceFrom(
		FreeImage_GetBits(image),
		FreeImage_GetWidth(image),
		FreeImage_GetHeight(image),
		FreeImage_GetBPP(image),
		FreeImage_GetPitch(image),
		FreeImage_GetRedMask(image),
		FreeImage_GetGreenMask(image),
		FreeImage_GetBlueMask(image),
		0
	);

	if (sdl_surface == NULL) {
		std::cout << "Failed to create surface: %s\n" << SDL_GetError() << "\n";
		exit(4);
	}
	return sdl_surface;
}


void fill_image(FIBITMAP *image)
{
	RGBQUAD color;
	if (!image)
	{
		std::cout << "Error No image, fill_image()\n";
		exit(404);
	}
	//Draws a gradient from blue to green:
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			color.rgbRed = 0;
			color.rgbGreen = (double)i / WIDTH * 255.0;
			color.rgbBlue = (double)j / HEIGHT * 255.0;
			FreeImage_SetPixelColor(image, i, j, &color);
		}
	}
}
void random_image(FIBITMAP *image)
{
	RGBQUAD color;
	if (!image)
	{
		std::cout << "Error No image, fill_image()\n";
		exit(1);
	}
	//Draws a gradient from blue to green:
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			color.rgbRed = rand() % 255;
			color.rgbGreen = rand() % 255;
			color.rgbBlue = rand() % 255;
			FreeImage_SetPixelColor(image, i, j, &color);
		}
	}
}
void generate_image(FIBITMAP *image)
{
	//Example code
	RGBQUAD color;//color of one pixel RGB+alpha
	if (!image)
	{
		std::cout << "Error No image, fill_image()\n";
		exit(1);
	}
	//Do stuff from here

	//Example Draws the image totaly white:
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			color.rgbRed = 255;
			color.rgbGreen = 255;
			color.rgbBlue = 255;
			//Assign the color to the pixel
			FreeImage_SetPixelColor(image, i, j, &color);
		}
	}
	//Do stuff to here
	

}
void render_windows()
{
	/*The bitmap will be generated by our software*/
	FIBITMAP *bitmap = FreeImage_Allocate(WIDTH, HEIGHT, BitsPerPixel);
	fill_image(bitmap); //Fill image with black (first image only)
	
	//Create a windows with the same width and height
	SDL_Window* sdl_window = get_sdl_window(WIDTH, HEIGHT);
	SDL_Surface* sdl_surface = get_surface_image(bitmap);
	SDL_Renderer* renderer = SDL_CreateRenderer(sdl_window, -1, 0);
	if (renderer == NULL) {
		std::cout << "Failed to render: %s\n" << SDL_GetError() << "\n";
		exit(1);
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, sdl_surface);
	if (texture == NULL) {
		std::cout << "Failed to load image\n";
		exit(1);
	}

	int keypressed = 0;
	SDL_Event e;
	while (!keypressed) {
		/*Create an pause in the thread for not going too crazy on cpu with the while*/
		std::this_thread::sleep_for(std::chrono::milliseconds(16));//Pause pour ne rendre que environ 60 fps

		/*Generate a new image with the old(We use the old image that we erase with new data*/
		if (DEBUG_IMAGE == 1)//Random image generated for debugging
		{
			random_image(bitmap); //Fill image with random colors
		}
		else//Generate the true image with the scene
		{
			generate_image(bitmap);
		}

		/*If print_windows=1 then we print the image to the screen (disabled for testing just code not image render) #Soso tu met sur 1*/
		if (PRINT_WINDOWS == 1)
		{
			//Clean the renderer
			SDL_RenderClear(renderer);

			//Render the image in a surface
			sdl_surface = get_surface_image(bitmap);

			//Create a texture with the surface and fill the renderer
			texture = SDL_CreateTextureFromSurface(renderer, sdl_surface);
			if (texture == NULL) {
				std::cout << "Failed to load image\n";
				exit(1);
			}
			//Copy the texture into the renderer
			SDL_RenderCopy(renderer, texture, NULL, NULL);
			//Render the renderer in the window
			SDL_RenderPresent(renderer);
		}
		while (SDL_PollEvent(&e)) {
			//std::cout << "Key pressed: " << e.type << "\n";
			if (e.type == SDL_KEYDOWN) {
				keypressed = 1;
			}
		}
	}

	//Wait for a key press
	//event_loop();//Old

	//Unloading from memory and clean quit
	FreeImage_Unload(bitmap);	
	SDL_FreeSurface(sdl_surface);
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(sdl_window);

	
	
}

vec3 objectVisible(Scene scene,vec3 camRay, vec3 camPos) {
	vector<Object> objectList = scene.get_objects();
	int numberObject = objectList.size();
	vec3 point = vec3(-1, -1, -1);
	vec3 closerPoint = vec3(999, 999, 999);
	for (int i = 0; i < numberObject; i++) {
		point = objectList[i].intersect(camRay, camPos);
		if (!(point.x == point.y == point.z == -1) && norm(dif3(point, camPos)) < norm(dif3(closerPoint, camPos))) { //si on trouve un point d'intersection et qu'il est plus proche de la camera
			closerPoint = point;
		}
	}
	return closerPoint;
}

bool objectEnlighted(Scene scene, vec3 point) {
	vector<LightSource> lightList = scene.get_lightsources();
	int numberLight = lightList.size();
	vector<Object> objectList = scene.get_objects();
	int numberObject = objectList.size();
	bool enlighted = true;
	int lightReceive = 0;
	for (int i = 0; i < numberLight; i++) {
		vec3 shadowRay = lightList[i].shadowray(point);
		enlighted = true;
		lightReceive += 1;
		for (int j = 0; j < numberObject; j++) {
			vec3 newpoint = objectList[i].intersect(shadowRay, point);
			if (!(newpoint.x == newpoint.y == newpoint.z == -1) && enlighted) {
				enlighted = false;
				lightReceive -= 1;
			}
		}
	}
	if (lightReceive > 0)
		return true;
	else
		return false;
}

int main(int argc, char* argv[])
{	
	srand(time(NULL));
	render_windows(); // Affiche une fenetre avec l'image generee (boucle attendant une pression sur une touche)
	return 0;
}