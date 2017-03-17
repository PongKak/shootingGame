#pragma once
#include "Enemy.h"

class EnemyType2 :	public Enemy
{
public:
	EnemyType2();
	~EnemyType2();


	void DrawEnemy(HWND,HDC);
	void SetEnemyStatus();
};

