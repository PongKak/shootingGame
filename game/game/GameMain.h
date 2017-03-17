#pragma once

class Background;
class PlayerCharacter;
class Enemy;

class GameMain
{
public:
	GameMain(HWND);
	~GameMain();
	
	bool CreateGame(HWND);
	bool RunningGame(HWND);
	bool ExitGame(HWND);


	bool background_process(HWND);
	bool character_process(HWND);
	bool projectile_process(HWND);
	bool enemy_process(HWND);

	void KeyInput(HWND hWnd);
	



	HDC m_hdc;
	HDC m_memoryDC;
	HDC m_imageDC;

	HBITMAP m_memoryBItmap;


	//CImage m_masking;
	//CImage m_PlayerCharacterImage;

	Background* m_pBackground;
	PlayerCharacter* m_pPlayerCharacter;

	std::vector<Enemy*> enemyVector;
};

