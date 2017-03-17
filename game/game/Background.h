#pragma once
class Background
{
public:
	Background(HWND hWnd);
	~Background();


	bool DrawBackground(HWND,HDC,HDC,HDC, HBITMAP);
	bool MoveBackground();
	bool RunningBackground(HWND, HDC, HDC, HDC,HBITMAP);





	HBITMAP m_hBitmapBackground;

	WCHAR path[256];
	WCHAR backgroundImagePath[256];
	CImage backgroundImage;

};



