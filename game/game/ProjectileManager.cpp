#include "stdafx.h"
#include "ProjectileManager.h"
#include "ProjectileTypeLaser.h"
#include "PlayerCharacter.h"
#include "Enemy.h"
#include "define.h"

ProjectileManager::ProjectileManager()
{
	m_limit = 5;
}


ProjectileManager::~ProjectileManager()
{
}


ProjectileManager* ProjectileManager::instance = nullptr;

void ProjectileManager::createProjectile(int type,float x,float y)
{
	
	switch (type)
		{
		case 0:
		{

			auto* laser = new ProjectileTypeLaser(x, y);
			m_characterProjectile.push_back(laser);
			break;
		}
		case 1:
		{

			auto* laser1 = new ProjectileTypeLaser(x - CHARACTERSIZEX/4, y);
			auto* laser2 = new ProjectileTypeLaser(x + CHARACTERSIZEX/4, y);
			m_characterProjectile.push_back(laser1);
			m_characterProjectile.push_back(laser2);
			break;
		}

	}
	

}

void ProjectileManager::moveProjectile()
{
	for (auto i : m_characterProjectile)
	{
		auto speed = i->speed;
		i->m_PositionY -= speed;
	}

	for (auto i : m_enemyProjectile)
	{
		auto speed = i->speed;
		i->m_PositionY += speed;
	}
}

void ProjectileManager::drawProjectile()
{
	for (auto i : m_characterProjectile)
	{
		i->DrawProjectile(m_memoryDC);
	}

	for (auto i : m_enemyProjectile)
	{
		i->DrawProjectile(m_memoryDC);
	}

}

void ProjectileManager::deleteProjectile()
{

	std::vector<Projectile*>::iterator iter;
	
	for (iter = m_characterProjectile.begin(); iter != m_characterProjectile.end(); ++iter)
	{
		auto projectile = *iter;
		if (projectile->m_PositionY < 0)
		{
			iter = m_characterProjectile.erase(iter);


			if (iter == m_characterProjectile.end())
			{
				break;
			}

		}
	}


	for (auto i : m_enemyProjectile)
	{
		
	}
}

void ProjectileManager::SetElapsedTime(float deltaTime)
{
	for (auto i : m_characterProjectile)
	{
		i->SetElapsedTime(deltaTime);
	}

	for (auto i : m_enemyProjectile)
	{
		i->SetElapsedTime(deltaTime);
	}
}

void ProjectileManager::SetTotalTime(float totalTime)
{
	for (auto i : m_characterProjectile)
	{
		i->SetTotalTime(totalTime);
	}

	for (auto i : m_enemyProjectile)
	{
		i->SetTotalTime(totalTime);
	}
}



ProjectileManager * ProjectileManager::GetInstance()
{

	if (instance == nullptr)
	{
		instance = new ProjectileManager();
	}
	return instance;

}


void ProjectileManager::SetMemoryDC(HDC memoryDC)
{
	m_memoryDC = memoryDC;
}

void ProjectileManager::SetHWnd(HWND hWnd)
{
	this->hWnd = hWnd;
}
