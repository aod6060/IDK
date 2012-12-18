#include "system.h"

void DirectInput::init(System& sys) {

	DirectInput8Create(
		sys.Instance(),
		0x0800,
		IID_IDirectInput8,
		(void**)&this->mDI,
		0);

	mDI->CreateDevice(GUID_SysKeyboard, &this->mKeyboard, 0);

	mKeyboard->SetDataFormat(&c_dfDIKeyboard);

	mKeyboard->SetCooperativeLevel(sys.Handler(), DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);

	mKeyboard->Acquire();
}

void DirectInput::update() {


	HRESULT hr = mKeyboard->GetDeviceState(256, this->mKState);

	if(FAILED(hr)) {
		mKeyboard->Acquire();
	}
}

void DirectInput::release() {

	if(this->mKeyboard) {
		mKeyboard->Unacquire();
		mKeyboard->Release();
		mKeyboard = 0;
	}

	if(this->mDI) {
		mDI->Release();
		mDI = 0;
	}


}

bool DirectInput::key_down(int key) {
	return (this->mKState[key] & 0x80)? true : false;
}

