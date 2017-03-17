#include "stdafx.h"
#include "Background.h"
#include "resource.h"


Background::Background(HWND hWnd)
{

	m_hBitmapBackground = LoadBitmap((HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), MAKEINTRESOURCE(IDB_BITMAP1));
	
	
}


Background::~Background()
{
}




bool Background::DrawBackground(HWND hWnd,HDC hdc, HDC imageDC, HDC memoryDC,HBITMAP memoryBitmap)
{

	HBITMAP oldBitmap = (HBITMAP)SelectObject(memoryDC, memoryBitmap);
	
	SelectObject(imageDC, m_hBitmapBackground);

	
	BitBlt(memoryDC, 0, 0, 1280, 1024, imageDC, 0, 0, SRCCOPY);
	
	//SelectObject(hdc, oldBitmap);

	return true;
}



bool Background::MoveBackground()
{
	
	return true;
}

bool Background::RunningBackground(HWND hWnd, HDC hdc, HDC imageDC,  HDC memoryDC,HBITMAP memoryBitmap)
{
	MoveBackground();
	DrawBackground(hWnd, hdc, imageDC, memoryDC, memoryBitmap);
	return true;
}

