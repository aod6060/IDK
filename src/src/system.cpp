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
	this->cap = cap;
	this->mWidth = width;
	this->mHeight = height;
	this->mHin = hin;
	this->cmd = cmd;

	this->init_window();

	this->init_demo();
}

void System::loop() {

	MSG msg;

	ZeroMemory(&msg, sizeof(MSG));

	while(msg.message != WM_QUIT) {
		
		if(PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		} else {

			this->update_demo(0.0f);

			this->render_demo();
		}
	}


}

void System::release() {
	this->release_demo();
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