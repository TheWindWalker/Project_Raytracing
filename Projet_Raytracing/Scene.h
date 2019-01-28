#pragma once
#include <vector>
#include "LightSource.h"
#include "Object.h"
#include "Materials.h"

using namespace std;

class Scene
{
public:
	vector<Materials> materials_tab;
	vector<Object> materials_tab;
	vector<LightSource> materials_tab;
	int sizex, sizey;
	Scene();
	~Scene();
};

