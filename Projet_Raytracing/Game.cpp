#include "Game.h"

Game::Game()
{
	scene_principale;
	vector<Object*> object_list;
	for (int i = 0; i < 10; i++)
	{
		object_list.push_back(new Sphere());
		object_list.push_back(new Cube());
	}
	
	//object_list[0]->affiche();
	//object_list[1]->affiche();

	for (int i = 0; i < object_list.size(); ++i)
	{
		delete object_list[i];
		object_list[i] = 0; // On met le pointeur à zéro
	}
}


Game::~Game()
{
}
