#ifndef DIRECT3D_H
#define DIRECT3D_H


#include <d3d9.h>
#include <d3dx9.h>

class System;

class Direct3D {
	IDirect3D9* mD3D;
	IDirect3DDevice9* mDev;

	D3DPRESENT_PARAMETERS mPP;

public:

	void init(System& sys);

	IDirect3DDevice9* Device();

	void release();
};

#endif