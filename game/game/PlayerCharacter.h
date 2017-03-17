#pragma once
class PlayerCharacter
{
public:
	PlayerCharacter();
	~PlayerCharacter();

	void LineMoveTo(float x, float y);
	void SetCharacterPosition(float, float);
	void SetCharacterDirection(int);
	
	inline void SetElapsedTime(float deltaTime) { m_elapsedTime = deltaTime; }
	inline void SetTotalTime(float totalTime) { m_totalTime = totalTime; }

	bool RunningCharacter(HWND hWnd, HDC hdc, HDC memoryDC);
	bool DrawPropella(HWND hWnd, HDC hdc, HDC memoryDC);
	bool DrawCharacter(HWND hWnd, HDC hdc, HDC memoryDC);
	


	bool controllable = false;
	float m_characterX;
	float m_characterY;
	int i = 0;
	float m_elapsedTime = 0;
	float m_totalTime = 0;

	int m_characterDirection = 0;

	CImage m_charactermasking;
	CImage m_PlayerCharacterImage;
	CImage m_maskingProp;
	CImage m_propImage;

	WCHAR path[256];
	WCHAR characterImagePath[256];
	WCHAR characterMaskingPath[256];

	WCHAR propellaMaskingPath[256];
	WCHAR propellaPath[256];
	
};

