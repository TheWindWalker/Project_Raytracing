#pragma once
#include <vector>
#include "LightSource.h"
#include "Object.h"
#include "Materials.h"
#include "Camera.h"

using namespace std;

class Scene
{
public:
	vector<Materials> materials_tab;
	vector<Object> objects_tab;
	vector<LightSource> lightsources_tab;
	vector<Camera> camera_tab;

	Scene();

	~Scene();

	Materials get_materials();
	Object get_objects();
	LightSource get_lightsources();
	Camera get_camera();

	void set_materials_list(vector<Materials> materials_list);
	void set_object_list(vector<Object> object_list);
	void set_lightsources_list(vector<LightSource> light_list);
	void set_camera_list(vector<Camera> camera_list);

	void add_materials(Materials materials);
	void add_object(Object object);
	void add_lightsources(LightSource lightsource);
	void add_camera(Camera camera);

};

