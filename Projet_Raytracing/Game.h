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
	Scene scene_principale;

	/*Constructeur et destructeur*/
	Game();
	~Game();

	/*Fonctions de la classe*/
};

