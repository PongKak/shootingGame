#include "stdafx.h"
#include "Enemy.h"
#include "define.h"


Enemy::Enemy()
{
	GetCurrentDirectory(sizeof(path), path);
}


Enemy::~Enemy()
{
}

void Enemy::MoveToLine(float x, float y)
{
	if (m_positionX > x)
	{
		m_positionX -= ENEMYTYPE1MOVESPEED;
		
	}
	else if(m_positionX < x)
	{
		m_positionX += ENEMYTYPE1MOVESPEED;
	}
	else 
	{

	}

	if (m_positionY > y)
	{
		m_positionY -= ENEMYTYPE1MOVESPEED;
	}
	else if(m_positionY < y)
	{
		m_positionY += ENEMYTYPE1MOVESPEED;
	}
	else {

	}
}

void Enemy::SetInitPosition(float x, float y)
{
	m_initPositionX = x;
	m_initPositionY = y;
}

