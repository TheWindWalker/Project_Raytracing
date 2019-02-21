#include "Game.h"

Game::Game()
{
	/*Debugging purpose, first try to use scene as full software*/
	//We already have one scene in memory !
	//We manually have put all data before testing with files for storing informations

	//Generate All camera
	vector<Camera> cam_list{
		Camera(vec3(2.0f,1.0f,0.0f),vec3(0.0f,0.0f,0.0f))
	};
	scene_principale.set_camera_list(cam_list);

	//Generate All Lights
	vector<LightSource> light_list{
		LightSource(255,255,255, vec3(0.0f, 0.0f, 0.0f))
	};
	scene_principale.set_lightsources_list(light_list);

	//Generate All Materials
	vector<Materials> materials_list{
		Materials(123,123,123,0),
		Materials(55,22,33,0),
		Materials(88,11,99,0),
		Materials(255,0,0,0),
		Materials(0,255,0,0),
		Materials(0,0,255,0)
	};
	scene_principale.set_materials_list(materials_list);

	//Generate All objects
	vector<Object*> objects_list{
		new Sphere(1.0f,1.0f,1.0f,0.25f),
		new Sphere(5.0f,2.0f,3.5f,0.25f)
	};
	scene_principale.set_object_list(objects_list);

}


Game::~Game()
{
}
