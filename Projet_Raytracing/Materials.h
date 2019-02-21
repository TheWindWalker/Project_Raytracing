#ifndef MAT
#define MAT

class Materials
{
public:
	int red, green, blue, reflection;
	Materials();
	Materials(int material_red, int material_green, int material_blue, int material_reflection);
	~Materials();
	
};

#endif