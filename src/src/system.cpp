#include "system.h"

static HRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {

	switch(msg) {
	case WM_DESTROY:
		DestroyWindow(hwnd);
		PostQuitMessage(0);
		return 0;
	case WM_QUIT:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, msg, wp, lp);
}

void System::init(std::string cap, int width, int height, HINSTANCE hin, int cmd) {
	srand(time(0));
	
	this->cap = cap;
	this->mWidth = width;
	this->mHeight = height;
	this->mHin = hin;
	this->cmd = cmd;

	this->init_window();

	this->d3d.init(*this);

	this->init_game();
}

void System::loop() {

	MSG msg;

	ZeroMemory(&msg, sizeof(MSG));


	__int64 cps = 0;
	QueryPerformanceFrequency((LARGE_INTEGER*)&cps);
	float spc = 1.0f / (float)cps;

	__int64 pts = 0;
	QueryPerformanceCounter((LARGE_INTEGER*)&pts);

	while(msg.message != WM_QUIT) {
		
		if(PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		} else {

			__int64 cts = 0;
			QueryPerformanceCounter((LARGE_INTEGER*)&cts);
			float dt = (cts - pts) * spc;

			this->update_game(dt);

			this->render_game();


			pts = cts;
		}
	}


}

void System::release() {
	this->release_game();

	this->d3d.release();

}

void System::init_window() {
	WNDCLASS wc;

	ZeroMemory(&wc, sizeof(WNDCLASS));

	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hInstance = mHin;
	wc.lpfnWndProc = ::WndProc;
	wc.lpszClassName = "_SYS_PROC_";
	wc.lpszMenuName = 0;
	wc.style = CS_VREDRAW | CS_HREDRAW;

	RegisterClass(&wc);

	mHwnd = CreateWindow(wc.lpszClassName,
		cap.c_str(),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		this->mWidth,
		this->mHeight,
		0,
		0,
		mHin,
		0);

	ShowWindow(mHwnd, cmd);
	UpdateWindow(mHwnd);
}