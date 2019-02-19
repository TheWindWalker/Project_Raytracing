#ifndef CAM
#define CAM

#include "vec3.h"
class Camera
{
	public:
	vec3 position, direction;
	float focale = 1;
	int sizex = 600, sizey = 400;
	vec3 poscentre;
	vec3 verti; //axe vertical dans la scene 3D du plan sur lequel l'image sera projetée
	vec3 horiz; //axe horizontal dans la scene 3D du plan sur lequel l'image sera projetée
	Camera();
	Camera(vec3 pos, vec3 dir);
	~Camera();

	private:

};

#endif