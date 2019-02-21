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

class Game
{
public:
	Scene scene_principale;
	Game();
	~Game();
};

