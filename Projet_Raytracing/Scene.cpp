#include "Scene.h"
#include "Camera.h"
#include "LightSource.h"
#include "object.h"
#include "Materials.h"

/*Constructor*/
Scene::Scene(){
}

/*Destructor*/
Scene::~Scene(){
}

/*General getters setters*/
int Scene::get_scene_id() {
	return id_scene;
}
void Scene::set_scene_id(int id) {
	id_scene = id;
}
string Scene::get_scene_name() {
	return scene_name;
}
void Scene::set_scene_name(string name) {
	scene_name = name;
}
/*Getters of vectors*/
#pragma region Get_Vectors_Data
vector<Materials> Scene::get_materials(){
	return materials_tab;
}
vector<Object*> Scene::get_objects(){
	return objects_tab;
}
vector<LightSource> Scene::get_lightsources(){
	return lightsources_tab;
}
vector<Camera> Scene::get_camera(){
	return camera_tab;
}
#pragma endregion

/*Set directly the whole vector of objects*/
#pragma region Set_Vectors_data
void Scene::set_materials_list(vector<Materials> materials_list) {
	materials_tab = materials_list;
}
void Scene::set_object_list(vector<Object*> object_list) {
	objects_tab = object_list;
}
void Scene::set_lightsources_list(vector<LightSource> light_list) {
	lightsources_tab = light_list;
}
void Scene::set_camera_list(vector<Camera> camera_list) {
	camera_tab = camera_list;
}
#pragma endregion

/*Add one object to the vectors*/
#pragma region Add_Object_Vectors
void Scene::add_materials(Materials materials) {
	materials_tab.push_back(materials);
}
void Scene::add_object(Object* object) {
	objects_tab.push_back(object);
}
void Scene::add_lightsources(LightSource lightsource) {
	lightsources_tab.push_back(lightsource);
}
void Scene::add_camera(Camera camera) {
	camera_tab.push_back(camera);
}
#pragma endregion
