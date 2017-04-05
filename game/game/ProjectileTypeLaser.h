#pragma once
#include "projectile.h"

class ProjectileTypeLaser : public Projectile
{
public:
	ProjectileTypeLaser(float,float);
	~ProjectileTypeLaser();

	virtual void DrawProjectile(HDC);
	
};

