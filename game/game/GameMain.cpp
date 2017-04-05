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
#include "ProjectileManager.h"
#include "CollisionManager.h"
#include "EnemyManager.h"

GameMain::GameMain(HWND hWnd)
{

	m_pBackground = new Background(hWnd);
	m_pPlayerCharacter = new PlayerCharacter();
	m_pProjectileManager = ProjectileManager::GetInstance();
	m_pCollisionManager = new CollisionManager();
	m_pEnemyManager = new EnemyManager();

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

	m_pEnemyManager->CreateEnemy();

	m_pCollisionManager->SetPlayerProjectileVector(&m_pProjectileManager->m_characterProjectile);
	m_pCollisionManager->SetEnemyProjectileVector(&m_pProjectileManager->m_enemyProjectile);
	m_pCollisionManager->SetEnemyVector(&m_pEnemyManager->m_enemyVector);

	SetMemoryDCToOther();
	SetHWndToOther(hWnd);



	m_time->Init();

	return true;
}


bool GameMain::RunningGame(HWND hWnd)
{
	
	Time_Process();
	
	if (m_accumulateElapsedTime == 0)
	{
		KeyInput(hWnd);

		Background_process(hWnd);

		Character_process(hWnd);

		Projectile_process(hWnd);

		Collision_process();

		Enemy_process(hWnd);




		BitBlt(m_hdc, 0, 0, 1280, 1024, m_memoryDC, 0, 0, SRCCOPY);

	}
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
	
	m_pPlayerCharacter->RunningCharacter();

	return true;
}

bool GameMain::Projectile_process(HWND hWnd)
{
	m_pProjectileManager->moveProjectile();
	m_pProjectileManager->drawProjectile();
	m_pProjectileManager->deleteProjectile();
	return true;
}

bool GameMain::Enemy_process(HWND hWnd)
{
	m_pEnemyManager->CreateEnemy();
	m_pEnemyManager->SetCharacterPosition(m_pPlayerCharacter->m_characterX, m_pPlayerCharacter->m_characterY);
	m_pEnemyManager->MoveEnemy();
	m_pEnemyManager->DrawEnemy();
	m_pEnemyManager->DeleteEnemy();

	if (m_pEnemyManager->m_numofDeadType1 == 40)
	{
		m_pPlayerCharacter->type = 1;
		m_pProjectileManager->m_limit = 10;
	}

	m_pEnemyManager->AfterDead();

	return true;
}

bool GameMain::Collision_process()
{
	m_pCollisionManager->updateCollision();
	return true;
}

bool GameMain::Time_Process()
{
	m_time->ProcessTime();

	m_elapsedTime = m_time->GetElapsedTime();
	m_accumulateElapsedTime += m_elapsedTime;
	
	if (m_accumulateElapsedTime >= 0.016)
	{

		m_totalTime += m_accumulateElapsedTime;


		m_pBackground->SetElapsedTime(m_accumulateElapsedTime);
		m_pBackground->SetTotalTime(m_totalTime);

		m_pPlayerCharacter->SetElapsedTime(m_accumulateElapsedTime);
		m_pPlayerCharacter->SetTotalTime(m_totalTime);

		m_pProjectileManager->SetElapsedTime(m_accumulateElapsedTime);
		m_pProjectileManager->SetTotalTime(m_totalTime);
		
		m_pEnemyManager->SetTime(m_accumulateElapsedTime, m_totalTime);

		m_accumulateElapsedTime = 0;
	}
	return true;
}

bool GameMain::Shoot()
{
	if (shootTime + 0.1 < m_totalTime)
	{

		auto numberOfCharacterProjectile = m_pProjectileManager->m_characterProjectile.size();

		if (numberOfCharacterProjectile >= m_pProjectileManager->m_limit)
		{
			return false;
		}


		auto type = m_pPlayerCharacter->type;
		auto x = m_pPlayerCharacter->m_characterX;
		auto y = m_pPlayerCharacter->m_characterY - CHARACTERSIZEY/2;

		m_pProjectileManager->createProjectile(type, x, y);
		shootTime = m_totalTime;
	}
	return false;
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

	if (byKey['Z'] & HOLDKEY)
	{
		Shoot();
	}
	

}

void GameMain::SetHWndToOther(HWND hWnd)
{
	m_pBackground->SetHWnd(hWnd);
	m_pPlayerCharacter->SetHWnd(hWnd);
	m_pProjectileManager->SetHWnd(hWnd);
	m_pEnemyManager->SetHWnd(hWnd);


}

void GameMain::SetMemoryDCToOther()
{
	m_pBackground->SetMemoryDC(m_memoryDC);
	m_pPlayerCharacter->SetMemoryDC(m_memoryDC);
	m_pProjectileManager->SetMemoryDC(m_memoryDC);
	m_pEnemyManager->SetMemoryDC(m_memoryDC);


}



