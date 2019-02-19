#ifndef SCENE
#define SCENE

#include <vector>
#include "LightSource.h"
#include "Object.h"
#include "Materials.h"

using namespace std;

class Scene
{
public:
	vector<Materials> materials_tab;
	vector<Object> objects_tab;
	vector<LightSource> lightsources_tab;
	Scene();
	~Scene();
};

#endif