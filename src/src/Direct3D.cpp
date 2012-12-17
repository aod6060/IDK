#include "system.h"

void Direct3D::init(System& sys) {

	// This is were the game will init its self


	this->mD3D = Direct3DCreate9(D3D_SDK_VERSION);

	D3DCAPS9 caps;

	mD3D->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps);

	int proc = 0;

	if(caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT) {
		proc = D3DCREATE_HARDWARE_VERTEXPROCESSING;
	} else {
		proc = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
	}

	ZeroMemory(&mPP, sizeof(D3DPRESENT_PARAMETERS));

	mPP.AutoDepthStencilFormat = D3DFMT_D24S8;
	mPP.BackBufferCount = 1;
	mPP.BackBufferFormat = D3DFMT_A8R8G8B8;
	mPP.BackBufferHeight = sys.Height();
	mPP.BackBufferWidth = sys.Width();
	mPP.EnableAutoDepthStencil = true;
	mPP.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	mPP.hDeviceWindow = sys.Handler();
	mPP.MultiSampleType = D3DMULTISAMPLE_NONE;
	mPP.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
	mPP.SwapEffect = D3DSWAPEFFECT_DISCARD;
	mPP.Windowed = true;

	mD3D->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		sys.Handler(),
		proc,
		&mPP,
		&mDev);

}

IDirect3DDevice9* Direct3D::Device() {
	return mDev;
}

void Direct3D::release() {


	if(this->mDev) {
		this->mDev->Release();
		mDev = 0;
	}

	if(this->mD3D) {
		mD3D->Release();
		mD3D = 0;
	}


}