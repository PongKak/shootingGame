#include "stdafx.h"
#include "Enemy.h"
#include "define.h"


Enemy::Enemy()
{
	GetCurrentDirectory(sizeof(path), path);
	m_elapsedTime = 0;
	m_totalTime = 0;
	m_state = 0;
}


Enemy::~Enemy()
{
}

void Enemy::DrawEnemy(HDC memoryDC)
{

	enemyMasking.StretchBlt(memoryDC, m_positionX - m_sizeX / 2, m_positionY - m_sizeY / 2, m_sizeX, m_sizeY, 0, 0, ENEMY_IMAGESIZEX, ENEMY_IMAGESIZEY, SRCAND);
	enemyImage.StretchBlt(memoryDC, m_positionX - m_sizeX / 2, m_positionY - m_sizeY / 2, m_sizeX, m_sizeY, 0, 0, ENEMY_IMAGESIZEX, ENEMY_IMAGESIZEY, SRCPAINT);


}

void Enemy::DrawDeadEnemy(HDC memoryDC)
{
	enemyMasking.StretchBlt(memoryDC, m_positionX - m_sizeX / 2, m_positionY - m_sizeY / 2, m_sizeX, m_sizeY, 0, 0, ENEMY_IMAGESIZEX, ENEMY_IMAGESIZEY, SRCAND);
	enemyImage.StretchBlt(memoryDC, m_positionX - m_sizeX / 2, m_positionY - m_sizeY / 2, m_sizeX, m_sizeY, 0, 0, ENEMY_IMAGESIZEX, ENEMY_IMAGESIZEY, SRCPAINT);
}



void Enemy::Moving()
{
}

void Enemy::SetEnemyStatus(int state)
{
	m_state = state;
}


void Enemy::SetInitPosition(float x, float y)
{
	m_initPositionX = x;
	m_initPositionY = y;
}

void Enemy::SetHP(float hp)
{
	m_HP = hp;
}

void Enemy::Damaged(float damage)
{
	m_HP -= damage;
	m_sizeX += damage;
	m_sizeY += damage;
}




void Enemy::MoveLineToCharacter(Enemy* enemy)
{
	auto distance = sqrt((enemy->m_positionX - enemy->m_characterX)*(enemy->m_positionX - enemy->m_characterX) + (enemy->m_positionY - enemy->m_characterY)*(enemy->m_positionY - enemy->m_characterY));
	enemy->m_positionX += m_elapsedTime* m_speed * (enemy->m_characterX - enemy->m_positionX) / distance;
	enemy->m_positionY += m_elapsedTime* m_speed * (enemy->m_characterY - enemy->m_positionY) / distance;

}
