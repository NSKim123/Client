#pragma once

#include <windows.h>

class CTexture
{
public:
	HBITMAP mhBitmap;
	HDC mhDCMem;
	HBITMAP mhOldBitmap;
	BITMAP mBitmapInfo;

public:
	CTexture();
	~CTexture();

	bool LoadTexture(HINSTANCE hInst, HDC hDC, LPCWSTR tFileName);

private:
	void UnloadTexture();

public:
	bool CreateBackBuffer(HINSTANCE hIns, HDC hDC);
	//메모리DC를 하나 만들고, 백 버퍼라는 개념으로 삼자
};

