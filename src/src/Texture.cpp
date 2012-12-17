#include "Texture.h"

void Texture::init(Direct3D& d3d, std::string fn) {
	D3DXCreateTextureFromFile(d3d.Device(), fn.c_str(), &this->mTex);
}

IDirect3DTexture9* Texture::Tex() {
	return this->mTex;
}

void Texture::release() {
	if(mTex) {
		mTex->Release();
		mTex = 0;
	}
}