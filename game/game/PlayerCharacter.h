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
	

	bool RunningCharacter();
	bool DrawPropella();
	bool DrawCharacter();


	void SetMemoryDC(HDC);
	void SetHWnd(HWND);


	bool controllable = false;
	float m_characterX;
	float m_characterY;
	int i = 0;
	float m_elapsedTime = 0;
	float m_totalTime = 0;

	int m_characterDirection = 0;

	int type = 0;


	CImage m_charactermasking[3];
	CImage m_PlayerCharacterImage[3];
	CImage m_maskingProp[6];
	CImage m_propImage[6];

	WCHAR path[256];


	std::vector<WCHAR*> m_imagePathVector;
	std::vector<WCHAR*> m_maskPathVector;

	WCHAR propellaMaskingPath[256];
	WCHAR propellaPath[256];

	HDC m_memoryDC;
	HWND hWnd;
};

