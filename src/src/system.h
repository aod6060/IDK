#ifndef SYSTEM_H
#define SYSTEM_H


// Just adding some standard header files
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
// These are platform includes
#include <Windows.h>
#include "Direct3D.h"
#include "CustomVertex.h"
#include "Entity.h"
#include "Texture.h"
#include "DirectInput.h"
#include "Rect.h"

/*
	This is a wrapper for the window, direct3d9, and directinput8. I debating for sound fx I should use OpenAL or DirectSound just to
	keep it with in the same style
*/

#define FlToDw(f) (*((DWORD*)&f))

class System {
protected:
	HWND mHwnd;
	HINSTANCE mHin;
	int mWidth;
	int mHeight;
	std::string cap;
	int cmd;

	Direct3D d3d;
	DirectInput di;

	void init_window();
public:

	System() {}

	virtual ~System() {}

	void init(std::string cap, int width, int height, HINSTANCE hin, int cmd);

	void loop();

	void release();

	HWND Handler() { return mHwnd; } // Returns window handler
	HINSTANCE Instance() { return mHin; } // Returns window instance 

	int Width() { return mWidth; }
	int Height() { return mHeight; }

	// Virtuals functions for the class
	virtual void init_game() {}

	virtual void render_game() {}

	virtual void update_game(float dt) {}

	virtual void release_game() {}
};

#endif