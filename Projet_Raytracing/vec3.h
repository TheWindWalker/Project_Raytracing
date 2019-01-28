#pragma once
class vec3
{
private:
	float x;
	float y;
	float z;

public:
	vec3();
	vec3(float coordx, float coordy, float coordz);
	~vec3();

	float getx();
	float gety();
	float getz();
};

vec3 add3(vec3 a, vec3 b);
vec3 dif3(vec3 a, vec3 b);
vec3 prod(vec3 vec, float a);
float prodScal(vec3 a, vec3 b);
vec3 prodVect(vec3 a, vec3 b);
float norm(vec3 vec);
vec3 reflexion(vec3 norm, vec3 vec);



