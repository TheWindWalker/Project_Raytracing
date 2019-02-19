#include "Camera.h"
#include "vec3.h"
#include <math.h>
Camera::Camera()
{

}
Camera::Camera(vec3 pos, vec3 dir) // /!\ axeverti doit être orthogonal à dir
{
	float r = norm(dir);
	float cosTheta = dir.z / r;
	float sinTheta = sqrt(pow(dir.x, 2) + pow(dir.y, 2)) / r;
	float cosPhi = dir.z / (r*sinTheta);
	float sinPhi = dir.y / (r*sinTheta);
	horiz = normalize(vec3(-sinPhi, cosPhi, 0));
	verti = normalize(vec3(cosTheta*cosPhi, cosTheta*sinPhi, -sinPhi));
	position = pos;
	direction = normalize(dir);
	poscentre = vec3(add3(pos, prod(direction, focale)));

}
Camera::~Camera()
{
}

vec3 Camera::createRay(int pixX, int pixY) {
	vec3 horizontal = add3(poscentre, prod(horiz, (pixX - sizex / 2)));
	vec3 vertical = add3(poscentre, prod(verti, (pixY - sizey / 2)));
	vec3 point = add3(horizontal, vertical); //coordonnées du centre du pixel dont on cherche la valeur
	vec3 ray = dif3(point, position); //vecteur direction du rayon
	return ray;
}
