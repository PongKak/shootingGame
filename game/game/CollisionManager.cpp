#include "stdafx.h"
#include "CollisionManager.h"
#include "Enemy.h"
#include "EnemyType1.h"
#include "EnemyType2.h"
#include "EnemyBoss.h"
#include "projectile.h"



CollisionManager::CollisionManager()
{
}


CollisionManager::~CollisionManager()
{
}

void CollisionManager::SetPlayerProjectileVector(std::vector<Projectile*>* playerProjectileVector )
{
	m_PlayerProjectile = playerProjectileVector;
}

void CollisionManager::SetEnemyProjectileVector(std::vector<Projectile*>* enemyProjectileVector )
{
	m_enemyProjectile = enemyProjectileVector;
}

void CollisionManager::SetEnemyVector(std::vector<Enemy*>* enemyVector)
{
	m_enemyVector = enemyVector;
}


void CollisionManager::updateCollision()
{
	std::vector<Projectile*>::iterator projectileIter;
	std::vector<Enemy*>::iterator enemyIter;
	
	for (projectileIter = m_PlayerProjectile->begin();projectileIter != m_PlayerProjectile->end();++projectileIter)
	{

		for (enemyIter = m_enemyVector->begin();enemyIter != m_enemyVector->end();++enemyIter)
		{
			auto xDistance = abs((*projectileIter)->m_PositionX - (*enemyIter)->m_positionX);
			auto yDistance = abs((*projectileIter)->m_PositionY - (*enemyIter)->m_positionY);

			if (xDistance < (*enemyIter)->m_sizeX && yDistance < (*enemyIter)->m_sizeY)
			{
				//�߻�ü�� ���� �浹 ���� ��
					//������ ȿ��
				auto damage = (*projectileIter)->m_damage;
				(*enemyIter)->Damaged(damage);

					//�̻��� ����
				projectileIter = m_PlayerProjectile->erase(projectileIter);

				if (projectileIter == m_PlayerProjectile->end())
				{
					break;
				}
				


			}
		}
		if (projectileIter == m_PlayerProjectile->end())
		{
			break;
		}

	}
}
