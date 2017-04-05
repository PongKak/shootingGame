#include "stdafx.h"
#include "define.h"
#include "EnemyBoss.h"
#include "EnemyType1.h"
#include "EnemyType2.h"



EnemyBoss::EnemyBoss()
{

	m_bossState = 0;
	m_positionX = WINDOWSIZEX / 2;
	m_positionY = 0;
	bSrcAlpha = 255;

	movable = false;
	m_elapsedAttackTime = 0;
	
	m_HP = ENEMY_BOSS_HP;
	m_pAttackEnemy = nullptr;

	auto speed = rand() % 3 + 1;
	auto random = rand() % 2;
	if (random == 0)
	{
		m_randomDirection = -1;
	}
	else 
	{
		m_randomDirection = 1;
	}

	m_speed = ENEMY_BOSS_SPEED * speed;

	m_sizeX = ENEMY_BOSS_SIZEX;
	m_sizeY = ENEMY_BOSS_SIZEY;

	m_stateSizeX[0] = ENEMY_BOSS_SIZEX;
	m_stateSizeY[0] = ENEMY_BOSS_SIZEY;

	m_stateSizeX[1] = 0;
	m_stateSizeY[1] = 0;

	m_stateSizeX[2] = 0;
	m_stateSizeY[2] = 0;


	WCHAR buffer[8];
	WCHAR buffer2[8];
	WCHAR buffer3[8];
	_itow_s(1, buffer, 10);
	_itow_s(2, buffer2, 10);
	_itow_s(3, buffer3, 10);
	

	wcscpy_s(enemyPath, path);
	wcscat_s(enemyPath, L"/resource/enemy/enemy-");
	wcscat_s(enemyPath, buffer);
	wcscat_s(enemyPath, L".png");


	wcscpy_s(enemyPath2, path);
	wcscat_s(enemyPath2, L"/resource/enemy/enemy-");
	wcscat_s(enemyPath2, buffer2);
	wcscat_s(enemyPath2, L".png");

	
	wcscpy_s(enemyPath3, path);
	wcscat_s(enemyPath3, L"/resource/enemy/enemy-");
	wcscat_s(enemyPath3, buffer3);
	wcscat_s(enemyPath3, L".png");


	wcscpy_s(enemyMaskingPath, path);
	wcscat_s(enemyMaskingPath, L"/resource/enemy/enemyMask");
	wcscat_s(enemyMaskingPath, L".png");




	enemyMasking[0].Load(enemyMaskingPath);
	enemyImage[0].Load(enemyPath);

	enemyMasking[1].Load(enemyMaskingPath);
	enemyImage[1].Load(enemyPath2);

	enemyMasking[2].Load(enemyMaskingPath);
	enemyImage[2].Load(enemyPath3);



}


EnemyBoss::~EnemyBoss()
{

}

void EnemyBoss::DrawEnemy(HDC memoryDC)
{
	for (auto i = 0; i < 3; ++i)
	{
		if (i == m_bossState)
		{
			enemyMasking[i].StretchBlt(memoryDC, m_positionX - m_stateSizeX[i] / 2, m_positionY - m_stateSizeY[i] / 2, m_stateSizeX[i], m_stateSizeY[i], 0, 0, ENEMY_IMAGESIZEX, ENEMY_IMAGESIZEY, SRCAND);
			enemyImage[i].StretchBlt(memoryDC, m_positionX - m_stateSizeX[i] / 2, m_positionY - m_stateSizeY[i] / 2, m_stateSizeX[i], m_stateSizeY[i], 0, 0, ENEMY_IMAGESIZEX, ENEMY_IMAGESIZEY, SRCPAINT);

		}
		else
		{
			enemyMasking[i].StretchBlt(memoryDC, m_positionX - m_stateSizeX[i] / 2, m_positionY - m_stateSizeY[i] / 2, m_stateSizeX[i], m_stateSizeY[i], 0, 0, ENEMY_IMAGESIZEX, ENEMY_IMAGESIZEY, SRCAND);
			enemyImage[i].StretchBlt(memoryDC, m_positionX - m_stateSizeX[i] / 2, m_positionY - m_stateSizeY[i] / 2, m_stateSizeX[i], m_stateSizeY[i], 0, 0, ENEMY_IMAGESIZEX, ENEMY_IMAGESIZEY, SRCPAINT);

		}
	}

}






void EnemyBoss::Damaged(float damage)
{
	if(movable == true)
	{
		m_HP -= damage;

		switch (m_bossState)
		{
			case 0:
			{
				m_stateSizeX[1] += ENEMY_BOSS_SIZEX / ((ENEMY_BOSS_HP / LASERDAMAGE) / 3);
				m_stateSizeY[1] += ENEMY_BOSS_SIZEY / ((ENEMY_BOSS_HP / LASERDAMAGE) / 3);

				if (m_stateSizeX[1] >= ENEMY_BOSS_SIZEX)
				{
					m_stateSizeX[1] = ENEMY_BOSS_SIZEX;
					m_stateSizeY[1] = ENEMY_BOSS_SIZEY;
					m_bossState = 1;
				}
				break;
			}
			case 1:
			{
				m_stateSizeX[2] += ENEMY_BOSS_SIZEX / ((ENEMY_BOSS_HP / LASERDAMAGE) / 3);
				m_stateSizeY[2] += ENEMY_BOSS_SIZEY / ((ENEMY_BOSS_HP / LASERDAMAGE) / 3);

				if (m_stateSizeX[2] >= ENEMY_BOSS_SIZEX)
				{
					m_stateSizeX[2] = ENEMY_BOSS_SIZEX;
					m_stateSizeY[2] = ENEMY_BOSS_SIZEY;
					m_bossState = 2;
				}
				break;
			}

		}
	}
	
	


}





void EnemyBoss::Moving()
{
	if (movable == false)
	{
		m_positionY += m_elapsedTime*m_speed;
		if (m_positionY >= 100)
		{
			movable = true;
		}

	}
	else
	{
		switch (m_bossState)
		{
			case 0:
			{
				if (m_positionX < 50)
				{
					m_positionX = 50;
					m_randomDirection *= -1;
				}
				if (m_positionX > WINDOWSIZEX - 50)
				{
					m_positionX = WINDOWSIZEX - 50;
					m_randomDirection *= -1;
				}

				m_positionX += m_elapsedTime*ENEMY_BOSS_SPEED*m_randomDirection;

				//Attack();
				break;
			}
			case 1:
			{
				if (m_positionX < 50)
				{
					m_positionX = 50;
					m_randomDirection *= -1;
				}
				if (m_positionX > WINDOWSIZEX - 50)
				{
					m_positionX = WINDOWSIZEX - 50;
					m_randomDirection *= -1;
				}

				m_positionX += m_elapsedTime*ENEMY_BOSS_SPEED*1.5*m_randomDirection;

				break;
			}
			case 2:
			{
				break;
			}

		}



	}
}

void EnemyBoss::Attack()
{
	switch (m_bossState)
	{
		case 0:
		{
			if(m_elapsedAttackTime > 0.5)
			{
				auto enemy = new EnemyType1(m_positionX, m_characterY);
				m_elapsedAttackTime = 0;
				enemy->~EnemyType1();
			}
			else
			{
				m_elapsedAttackTime += m_elapsedTime;
			}
			break;
		}
		case 1:
		{
			break;

		}
	}
}