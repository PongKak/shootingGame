#include "stdafx.h"
#include "define.h"
#include "EnemyType2.h"



EnemyType2::EnemyType2(float x,float y)
{


	m_positionX = x;
	m_positionY = y;


	WCHAR buffer[8];
	_itow_s(2, buffer, 10);



	m_HP = ENEMY_2_HP;


	auto speed = rand() % 3 + 1;
	m_speed = ENEMY_2_SPEED * speed;

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


EnemyType2::~EnemyType2()
{

}




void EnemyType2::Moving()
{
	if (m_positionX < 0)
	{
		m_positionX = WINDOWSIZEX;
	}
	else if (m_positionX > WINDOWSIZEX)
	{
		m_positionX = 0;
	}

	if (m_positionY > 1024)
	{
		m_positionY = 0;
	}


	m_positionY += m_elapsedTime * m_speed;

	if (m_positionY < m_characterY)
	{

		auto distanceX = m_characterX - m_positionX;

		if (abs(distanceX) > 100)
		{

			xDirection = distanceX / abs(distanceX);
			m_positionX += m_elapsedTime * m_speed * xDirection;
		}
		else
		{
			m_positionX += m_elapsedTime * m_speed * xDirection;
		}
	}
	else
	{
		m_positionX += m_elapsedTime * m_speed * xDirection;
	}

}

void EnemyType2::SetEnemyStatus()
{
}
