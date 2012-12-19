#include "Camera.h"


void Camera::render(Direct3D& d3d) {
	D3DXMATRIX W;

	D3DXMatrixTranslation(&W, -(pos.x-320.0f), -(pos.y-240), -pos.z);

	d3d.Device()->SetTransform(D3DTS_VIEW, &W);
}