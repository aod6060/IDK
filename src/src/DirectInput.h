#ifndef DIRECT_INPUT_H
#define DIRECT_INPUT_H


#include <dinput.h>

class System;

class DirectInput {

	IDirectInput8* mDI;

	IDirectInputDevice8* mKeyboard;

	char mKState[256];

public:

	DirectInput() : mDI(0), mKeyboard(0) {}

	virtual ~DirectInput() {}

	void init(System& sys);

	void update();

	void release();

	bool key_down(int key);


};

#endif