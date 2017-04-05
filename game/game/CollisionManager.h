#pragma once

class Projectile;
class Enemy;

class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();

	void SetPlayerProjectileVector(std::vector<Projectile*>* const);
	void SetEnemyProjectileVector(std::vector<Projectile*>* const);
	void SetEnemyVector(std::vector<Enemy*>* const);

	float CalculateDistance(Projectile, Enemy);

	void updateCollision();

	std::vector<Projectile*>* m_PlayerProjectile;
	std::vector<Projectile*>* m_enemyProjectile;

	std::vector<Enemy*>* m_enemyVector;


};

