#pragma once
#include "Enemy.h"


class EnemyType1 :	public Enemy
{
public:
	EnemyType1(float x,float y);
	~EnemyType1();


	virtual void Moving();

};

