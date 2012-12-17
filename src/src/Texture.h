#ifndef TEXTURE_H
#define TEXTURE_H


#include <string>
#include "Direct3D.h"


class Texture {
	IDirect3DTexture9* mTex;

public:

	Texture() : mTex(0) {}

	virtual ~Texture() {}

	void init(Direct3D& d3d, std::string fn);

	IDirect3DTexture9* Tex();

	void release();
};

#endif