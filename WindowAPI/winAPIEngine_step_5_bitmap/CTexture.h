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
	void UnloadTexture();
};

