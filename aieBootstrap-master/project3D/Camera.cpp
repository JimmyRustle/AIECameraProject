#include "Camera.h"



Camera::Camera()
{
}

//forward - third row of world position

Camera::~Camera()
{
}

void Camera::SetPerspective(float fov, float aspectRatio, float near, float far)
{
	projectionTransform = glm::perspective(fov, aspectRatio, near, far);
}

void Camera::SetLookAt(const vec3 &from, const vec3 &to, const vec3 &up)
{
	viewTransform = glm::lookAt(from, to, up);
	worldTransform[0][3] = from.x;
	worldTransform[1][3] = from.y;
	worldTransform[2][3] = from.z;
	UpdateProjectionViewTransform();
}

void Camera::SetPosition(const vec3 &pos)
{
	worldTransform[0][3] = pos.x;
	worldTransform[1][3] = pos.y;
	worldTransform[2][3] = pos.z;
	viewTransform = GetView();
}

mat4 Camera::GetWorldTransform()
{
	return worldTransform;
}

mat4 Camera::GetView()
{
	return glm::inverse(worldTransform);
}

mat4 Camera::GetProjection()
{
	return projectionTransform;
}

mat4 Camera::GetProjectionView()
{
	return projectionViewTransform;
}

void Camera::UpdateProjectionViewTransform()
{
	projectionViewTransform = projectionTransform * viewTransform;
}
