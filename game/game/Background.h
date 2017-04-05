#pragma once
class Background
{
public:
	Background(HWND hWnd);
	~Background();


	bool DrawBackground(HWND,HDC,HDC,HDC, HBITMAP);
	bool MoveBackground();
	bool RunningBackground(HWND, HDC, HDC, HDC,HBITMAP);
	inline void SetElapsedTime(float deltaTime) { m_elapsedTime = deltaTime; }
	inline void SetTotalTime(float totalTime) { m_totalTime = totalTime; }


	void SetMemoryDC(HDC);
	void SetHWnd(HWND);

	float m_elapsedTime = 0;
	float m_totalTime = 0;



	HBITMAP m_hBitmapBackground;

	WCHAR path[256];
	WCHAR backgroundImagePath[256];
	CImage backgroundImage;


	HDC m_memoryDC;
	HWND hWnd;
};



