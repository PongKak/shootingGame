#pragma once

class Background;
class PlayerCharacter;
class Enemy;
class myTime;

class GameMain
{
public:
	GameMain(HWND);
	~GameMain();
	
	bool CreateGame(HWND);
	bool RunningGame(HWND);
	bool ExitGame(HWND);


	bool Background_process(HWND);
	bool Character_process(HWND);
	bool Projectile_process(HWND);
	bool Enemy_process(HWND);
	bool Time_Process();

	void KeyInput(HWND hWnd);
	
	
	inline float GetElapsedTime() { return m_elapsedTime; }
	inline float GetTotalTime() { return m_totalTime; }



	float m_elapsedTime = 0;
	float m_totalTime = 0;
	HDC m_hdc = nullptr;
	HDC m_memoryDC = nullptr;
	HDC m_imageDC = nullptr;
	HBITMAP m_memoryBItmap = nullptr;

	Background* m_pBackground;
	PlayerCharacter* m_pPlayerCharacter;
	myTime* m_time;

	std::vector<Enemy*> enemyVector;
	
};

