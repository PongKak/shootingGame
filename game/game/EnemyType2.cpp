#include "stdafx.h"
#include "EnemyType2.h"



EnemyType2::EnemyType2()
{
	WCHAR buffer[8];
	_itow_s(1, buffer, 10);


	wcscpy_s(enemyPath, path);
	wcscat_s(enemyPath, L"/resource/enemy/enemy-");
	wcscat_s(enemyPath, buffer);
	wcscat_s(enemyPath, L".png");

	wcscpy_s(enemyMaskingPath, path);
	wcscat_s(enemyMaskingPath, L"/resource/enemy/enemyMask-");
	wcscat_s(enemyMaskingPath, buffer);
	wcscat_s(enemyMaskingPath, L"mask.png");
}


EnemyType2::~EnemyType2()
{
}


void EnemyType2::DrawEnemy(HWND hWnd,HDC memoryDC)
{

}
void EnemyType2::SetEnemyStatus()
{

}