#include "stdafx.h"
#include "define.h"
#include "ProjectileTypeLaser.h"



ProjectileTypeLaser::ProjectileTypeLaser(float x,float y)
{

	m_damage = LASERDAMAGE;
	m_PositionX = x;
	m_PositionY = y;

	m_sizeX = LASERSIZEX;
	m_sizeY = LASERSIZEY;
	speed = LASERSPEED;


	wcscpy_s(projectilePath, path);
	wcscat_s(projectilePath, L"/resource/projectile/laser");
	wcscat_s(projectilePath, L".png");

	wcscpy_s(projectileMaskingPath, path);
	wcscat_s(projectileMaskingPath, L"/resource/projectile/laser_mask");
	wcscat_s(projectileMaskingPath, L".png");


	projectileMasking.Load(projectileMaskingPath);
	projectileImage.Load(projectilePath);
}


ProjectileTypeLaser::~ProjectileTypeLaser()
{
}

void ProjectileTypeLaser::DrawProjectile(HDC memoryDC)
{
	projectileMasking.StretchBlt(memoryDC, m_PositionX - LASERSIZEX/2, m_PositionY - LASERSIZEY/2, LASERSIZEX, LASERSIZEY, 0, 0, 91, 91, SRCAND);
	projectileImage.StretchBlt(memoryDC, m_PositionX - LASERSIZEX/2 , m_PositionY - LASERSIZEY/2, LASERSIZEX, LASERSIZEY, 0, 0, 91, 91, SRCPAINT);

}



