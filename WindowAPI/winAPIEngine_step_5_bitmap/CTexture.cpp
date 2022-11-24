#include "CTexture.h"


CTexture::CTexture()
	: mhDCMem(nullptr), mhBitmap(nullptr), mhOldBitmap(nullptr)
{
	memset(&mBitmapInfo, 0, sizeof(BITMAP));
}
CTexture::~CTexture()
{
    UnloadTexture();
}

bool CTexture::LoadTexture(HINSTANCE hInst, HDC hDC, LPCWSTR tFileName)
{
    mhDCMem = CreateCompatibleDC(hDC);   //<-- memory dc�� �����.

    mhBitmap = (HBITMAP)LoadImage(hInst, tFileName,
        IMAGE_BITMAP,
        0, 0,
        LR_LOADFROMFILE);   //<-- LR~ Load Resource


    mhOldBitmap = (HBITMAP)SelectObject(mhDCMem, mhBitmap);

    //��Ʈ�� ������ ������
    mBitmapInfo;
    GetObject(mhBitmap, sizeof(mBitmapInfo), &mBitmapInfo);

	return true;
}
void CTexture::UnloadTexture()
{
    SelectObject(mhDCMem, mhOldBitmap);   //������ ����ϴ� ��Ʈ������ ������ �ǵ�����.
    DeleteObject(mhBitmap);

    DeleteDC(mhDCMem);
}