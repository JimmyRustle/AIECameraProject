#pragma once
#include "Camera.h"
#include <iostream>


class FlyCamera : public Camera
{
public:
	FlyCamera();
	~FlyCamera();

	void Update(GLFWwindow *window, float deltaTime);

	void SetSpeed(float speed);

private:
	float speed;
	vec3 up;
};

