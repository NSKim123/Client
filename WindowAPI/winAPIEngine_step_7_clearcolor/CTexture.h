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
	//�޸�DC�� �ϳ� �����, �� ���۶�� �������� ����
};

