#include "stdafx.h"
#include "EnemyType1.h"



EnemyType1::EnemyType1(float x, float y)
{
	m_positionX = x;
	m_positionY = y;
	WCHAR buffer[8];
	_itow_s(1, buffer, 10);


	wcscpy_s(enemyPath, path);
	wcscat_s(enemyPath, L"/resource/enemy/enemy-");
	wcscat_s(enemyPath, buffer);
	wcscat_s(enemyPath, L".png");

	wcscpy_s(enemyMaskingPath, path);
	wcscat_s(enemyMaskingPath, L"/resource/enemy/enemyMask-");
	wcscat_s(enemyMaskingPath, buffer);
	wcscat_s(enemyMaskingPath, L".png");


	enemyMasking.Load(enemyMaskingPath);
	enemyImage.Load(enemyPath);
}


EnemyType1::~EnemyType1()
{
	enemyMasking.Destroy();
	enemyImage.Destroy();
}


void EnemyType1::DrawEnemy(HWND hWnd, HDC memoryDC)
{



	if(m_positionX < 1280 && m_positionY <1024)
	{
		enemyMasking.StretchBlt(memoryDC, m_positionX, m_positionY, 50, 50, 0, 0, 288, 288, SRCAND);
		enemyImage.StretchBlt(memoryDC, m_positionX, m_positionY, 50, 50, 0, 0, 288, 288, SRCPAINT);
	}

}

void EnemyType1::SetEnemyStatus()
{

}