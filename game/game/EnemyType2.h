#pragma once
#include "Enemy.h"

class EnemyType2 :	public Enemy
{
public:
	EnemyType2(float x, float y);
	~EnemyType2();


	float xDirection;

	virtual void Moving();

	void SetEnemyStatus();
};

