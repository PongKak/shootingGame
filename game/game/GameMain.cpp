#include "stdafx.h"
#include "GameMain.h"
#include "resource.h"
#include "Background.h"
#include "PlayerCharacter.h"
#include "define.h"
#include "Enemy.h"
#include "EnemyType1.h"
#include "EnemyType2.h"
#include "time.h"

GameMain::GameMain(HWND hWnd)
{

	m_pBackground = new Background(hWnd);
	m_pPlayerCharacter = new PlayerCharacter();
	m_time = new myTime();
}


GameMain::~GameMain()
{
}


bool GameMain::CreateGame(HWND hWnd)
{

	m_hdc = GetDC(hWnd);

	
	m_memoryDC = CreateCompatibleDC(m_hdc);
	m_imageDC = CreateCompatibleDC(m_hdc);
	m_memoryBItmap = CreateCompatibleBitmap(m_hdc, 1280, 1024);



	//enemy
	for (int i = 0; i < 3; i++)
	{
		Enemy* enemy_Type1 = new EnemyType1(500 + i*50, i*50);
		enemyVector.push_back(enemy_Type1);

	}
	
	m_time->Init();

	return true;
}


bool GameMain::RunningGame(HWND hWnd)
{
	
	Time_Process();
	
	KeyInput(hWnd);

	Background_process(hWnd);

	Character_process(hWnd);
	
	Projectile_process(hWnd);

	Enemy_process(hWnd);


	BitBlt(m_hdc, 0, 0, 1280, 1024, m_memoryDC, 0, 0, SRCCOPY);

	
	return true;
}


bool GameMain::ExitGame(HWND hWnd)
{

	DeleteDC(m_imageDC);
	DeleteDC(m_memoryDC);

	ReleaseDC(hWnd, m_hdc);


	return 0;
}

bool GameMain::Background_process(HWND hWnd)
{
	m_pBackground->RunningBackground(hWnd, m_hdc, m_imageDC, m_memoryDC, m_memoryBItmap);
	return true;
}

bool GameMain::Character_process(HWND hWnd)
{
	m_pPlayerCharacter->RunningCharacter(hWnd, m_hdc, m_memoryDC);
	return true;
}

bool GameMain::Projectile_process(HWND hWnd)
{


	return true;
}

bool GameMain::Enemy_process(HWND hWnd)
{
	if(m_totalTime >= 3)
	{ 
		for(int i=0;i < (int)enemyVector.size();i++)
		{
			Enemy* enemy1 = enemyVector[i];
			enemy1->DrawEnemy(hWnd, m_memoryDC);
			enemy1->MoveToLine(1280, 600);
		}
	}
	return true;
}

bool GameMain::Time_Process()
{
	m_time->ProcessTime();

	m_elapsedTime = m_time->GetElapsedTime();
	m_totalTime += m_elapsedTime;

	return true;
}


void GameMain::KeyInput(HWND hWnd)
{
	static	BYTE	byOldKey[256] = { 0 };
	BYTE	byKey[256];

	if (GetKeyboardState(byKey))
	{
		for (int i = 0; i < 256; i++)
		{
			if (byKey[i] & 0x80)
			{
				if (!byOldKey[i])
				{
					byOldKey[i] = 1;
					byKey[i] |= 0x40;
				}
			}
			else
			{
				if (byOldKey[i])
				{
					byOldKey[i] = 0;
					byKey[i] = 0x20;
				}
				else
					byKey[i] = 0x10;
			}
		}
	}


	if (byKey[VK_UP] & HOLDKEY)
	{
		m_pPlayerCharacter->SetCharacterPosition(0, -1);
	}
	else if (byKey[VK_DOWN] & HOLDKEY)
	{
		m_pPlayerCharacter->SetCharacterPosition(0, 1);
	}

	if (byKey[VK_LEFT] & HOLDKEY)
	{
		m_pPlayerCharacter->SetCharacterDirection(1);
		m_pPlayerCharacter->SetCharacterPosition(-1, 0);
			}
	else if (byKey[VK_RIGHT] & HOLDKEY)
	{
		m_pPlayerCharacter->SetCharacterDirection(2);
		m_pPlayerCharacter->SetCharacterPosition(1, 0);

	}
	else
	{
		m_pPlayerCharacter->SetCharacterDirection(0);
	}

	if (byKey[VK_SPACE] & PUSHKEY || byKey[VK_SPACE] & HOLDKEY)
	{

	}
	

}



