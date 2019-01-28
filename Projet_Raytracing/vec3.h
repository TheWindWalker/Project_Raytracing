#pragma once
class vec3
{
public:
	float x;
	float y;
	float z;


	vec3();
	vec3(float coordx, float coordy, float coordz);
	~vec3();

};

vec3 add3(vec3 a, vec3 b);
vec3 dif3(vec3 a, vec3 b);
vec3 prod(vec3 vec, float a);
float prodScal(vec3 a, vec3 b);
vec3 prodVect(vec3 a, vec3 b);
float norm(vec3 vec);
vec3 reflexion(vec3 norm, vec3 vec);
vec3 normalize(vec3 vec);



