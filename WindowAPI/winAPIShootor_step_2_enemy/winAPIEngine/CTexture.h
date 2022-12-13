#pragma once

#include <windows.h>

class CTexture
{
private:
	HBITMAP mhBitmap;	
	HBITMAP mhOldBitmap;

	//���� �� ������ ������ �ǵ��ߴ�.
public:
	BITMAP mBitmapInfo;
	HDC mhDCMem;

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

