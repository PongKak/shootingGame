#include "stdafx.h"
#include "define.h"
#include "EnemyManager.h"
#include "EnemyType1.h"
#include "EnemyType2.h"
#include "EnemyBoss.h"

EnemyManager::EnemyManager()
{
	m_numofDeadType1 = 0;
	m_numofDeadType2 = 0;
}


EnemyManager::~EnemyManager()
{
}

void EnemyManager::CreateEnemy()
{

	if (m_numofDeadType1 < 15)
	{
		if (m_enemyVector.size() < 20)
		{

			auto x = rand() % 1000 + 100;
			auto y = 0;

			auto enemy = new EnemyType1(x, y);
			m_enemyVector.push_back(enemy);

		}
	}
	else if(m_numofDeadType1 < 35)
	{
		if (m_enemyVector.size() < 40)
		{
			auto x = rand() % 1000 + 100;
			auto y = 0;

			auto enemy = new EnemyType1(x, y);

			enemy->SetHP(4);
			enemy->SetEnemyStatus(1);
		
			m_enemyVector.push_back(enemy);

		}


	}
	else if(m_numofDeadType1 < 60)
	{

		if (m_enemyVector.size() < 30)
		{

			auto x1 = rand() % 1000 + 100;
			auto x2 = rand() % 1000 + 100;
			auto x3 = rand() % 1000 + 100;
			auto y = 0;

			
			auto enemy1 = new EnemyType1(x1, y);
			auto enemy2 = new EnemyType1(x2, y);
			auto enemy3 = new EnemyType2(x3, y);

			m_enemyVector.push_back(enemy1);
			m_enemyVector.push_back(enemy2);
			m_enemyVector.push_back(enemy3);
		}
	}
	else if (m_enemyVector.size() == 0 )
	{
		auto boss = new EnemyBoss();
		m_enemyVector.push_back(boss);
	}


}

void EnemyManager::MoveEnemy()
{
	for (auto i : m_enemyVector)
	{
		i->Moving();

		if (EnemyBoss* boss = dynamic_cast<EnemyBoss*>(i))
		{
			if (((EnemyBoss*)i)->m_pAttackEnemy != nullptr)
			{
				m_enemyVector.push_back(((EnemyBoss*)i)->m_pAttackEnemy);
				break;
			}
		}
	}
}


void EnemyManager::DrawEnemy()
{
	for (auto i : m_enemyVector)
	{
		i->DrawEnemy(m_memoryDC);
	}

	for (auto i : m_deadEnemyVector)
	{
		i->DrawDeadEnemy(m_memoryDC);
	}
}

void EnemyManager::DeleteEnemy()
{
	std::vector<Enemy*>::iterator enemyIter;
	for (enemyIter = m_enemyVector.begin(); enemyIter != m_enemyVector.end(); ++enemyIter)
	{
		if ((*enemyIter)->m_HP <= 0)
		{
			
			if (EnemyType1* type1 = dynamic_cast<EnemyType1*>(*enemyIter))
			{
				++m_numofDeadType1;
			}

			m_deadEnemyVector.push_back(*enemyIter);
			enemyIter = m_enemyVector.erase(enemyIter);

			if (enemyIter == m_enemyVector.end())
			{
				break;
			}
		}
	}

}

void EnemyManager::AfterDead()
{
	
	for (auto deadIter = m_deadEnemyVector.begin(); deadIter != m_deadEnemyVector.end(); ++deadIter)
	{
		(*deadIter)->m_sizeX *= 1.05;
		(*deadIter)->m_sizeY *= 1.05;
		(*deadIter)->bSrcAlpha *= 0.9;

		if ((*deadIter)->m_sizeX >= ENEMY_SIZEX*3)
		{
			deadIter = m_deadEnemyVector.erase(deadIter);

			if (deadIter == m_deadEnemyVector.end())
			{
				break;
			}
		}

	}


}

void EnemyManager::SetCharacterPosition(float x, float y)
{
	
	for (auto i : m_enemyVector)
	{
		i->m_characterX = x;
		i->m_characterY = y;
	}

}

void EnemyManager::SetTime(float elapsedTime, float totalTime)
{
	for (auto i : m_enemyVector)
	{
		i->SetElapsedTime(elapsedTime);
		i->SetTotalTime(totalTime);
	}
}


