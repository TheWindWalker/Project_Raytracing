#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../FreeImage/FreeImage.h"
#include <time.h>
#include <chrono>
#include <thread>
#include "Object.h"
#include "Camera.h"
#include "Scene.h"
#include "Sphere.h"
#include "Cube.h"
#include "vec3.h"
#include "vec4.h"

class Game
{
public:
	/*Variables*/
	vector<Camera> cam_list{
		Camera(vec3(2.0f,1.0f,0.0f),vec3(0.0f,0.0f,0.0f))
	};
	vector<LightSource> light_list{
		LightSource(255,255,255, vec3(0.0f, 0.0f, 0.0f))
	};
	vector<Materials> materials_list{
		Materials(123,123,123,0),
		Materials(55,22,33,0),
		Materials(88,11,99,0),
		Materials(255,0,0,0),
		Materials(0,255,0,0),
		Materials(0,0,255,0)
	};
	vector<Object*> objects_list{
		new Sphere(1.0f,1.0f,1.0f,0.25f),
		new Sphere(5.0f,2.0f,3.5f,0.25f)
	};
	Scene scene_principale = Scene(
		cam_list,
		light_list,
		materials_list,
		objects_list
	);

	/*Constructeur et destructeur*/
	Game();
	~Game();

	/*Fonctions de la classe*/
};

