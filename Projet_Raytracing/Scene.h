#ifndef SCENE
#define SCENE

#include <iostream>
#include <string>
#include <vector>
#include "LightSource.h"
#include "Object.h"
#include "Materials.h"
#include "Camera.h"

using namespace std;

class Scene
{
private:
	int id_scene = 0;
	string scene_name = "This scene has no name!";

public:
	vector<Materials> materials_tab;
	vector<Object*> objects_tab;
	vector<LightSource> lightsources_tab;
	vector<Camera> camera_tab;

	Scene();

	~Scene();


#pragma region Adders_Getters_Setters
	void add_materials(Materials materials);
	void add_object(Object* object);
	void add_lightsources(LightSource lightsource);
	void add_camera(Camera camera);

	int get_scene_id();
	void set_scene_id(int id);
	string get_scene_name();
	void set_scene_name(string name);

	vector<Materials> get_materials();
	vector<Object*> get_objects();
	vector<LightSource> get_lightsources();
	vector<Camera> get_camera();

	void set_materials_list(vector<Materials> materials_list);
	void set_object_list(vector<Object*> object_list);
	void set_lightsources_list(vector<LightSource> light_list);
	void set_camera_list(vector<Camera> camera_list);
#pragma endregion
};

#endif