#include "stdafx.h"
#include "define.h"
#include "projectile.h"


Projectile::Projectile()
{
	GetCurrentDirectory(sizeof(path), path);
}


Projectile::~Projectile()
{
}

void Projectile::DrawProjectile(HDC)
{
}

void Projectile::MoveToLine()
{
	m_PositionY += LASERSPEED;
}

