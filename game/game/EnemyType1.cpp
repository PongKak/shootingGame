#include "stdafx.h"
#include "define.h"
#include "EnemyType1.h"



EnemyType1::EnemyType1(float x, float y)
{
	m_positionX = x;
	m_positionY = y;
	WCHAR buffer[8];
	_itow_s(1, buffer, 10);
	
	m_HP = ENEMY_1_HP;


	auto speed = rand() % 3 + 1;
	m_randomDirection = rand();
	m_speed = ENEMY_1_SPEED * speed;

	m_sizeX = ENEMY_SIZEX;
	m_sizeY = ENEMY_SIZEY;

	wcscpy_s(enemyPath, path);
	wcscat_s(enemyPath, L"/resource/enemy/enemy-");
	wcscat_s(enemyPath, buffer);
	wcscat_s(enemyPath, L".png");

	wcscpy_s(enemyMaskingPath, path);
	wcscat_s(enemyMaskingPath, L"/resource/enemy/enemyMask");
	wcscat_s(enemyMaskingPath, L".png");

	bSrcAlpha = 255;

	enemyMasking.Load(enemyMaskingPath);
	enemyImage.Load(enemyPath);
}


EnemyType1::~EnemyType1()
{
	enemyMasking.Destroy();
	enemyImage.Destroy();
}



void EnemyType1::Moving()
{
	if (m_positionX < 0)
	{
		m_positionX = WINDOWSIZEX;
	}else if (m_positionX > WINDOWSIZEX)
	{
		m_positionX = 0;
	}

	if (m_positionY > 1024)
	{
		m_positionY = 0;
	}



	switch (m_state)
	{
		case 0:
		{
			
			m_positionY += m_elapsedTime * m_speed;
			break;
		}

		case 1:
		{
			if (m_randomDirection % 2 == 0)
			{
				m_positionX += m_elapsedTime * m_speed;
			}
			else
			{
				m_positionX -= m_elapsedTime * m_speed;
			}

			m_positionY += m_elapsedTime * m_speed;
			break;
		}
	}
}
