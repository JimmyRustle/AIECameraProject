#include "FlyCamera.h"


FlyCamera::FlyCamera()
{
}


FlyCamera::~FlyCamera()
{
}



void FlyCamera::Update(GLFWwindow *window, float deltaTime)
{

	vec3 currentPos(worldTransform[0][3], worldTransform[1][3], worldTransform[2][3]);
	vec3 forward(worldTransform[2][0], worldTransform[2][1], worldTransform[2][2]);
	
	
	
}



void FlyCamera::SetSpeed(float speed)
{
	this->speed = speed;
}
