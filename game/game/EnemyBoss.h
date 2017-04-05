#pragma once
#include "Enemy.h"
#include "String"

class EnemyBoss : public Enemy
{
public:


	virtual void DrawEnemy(HDC);
	virtual void Moving();
	virtual void Damaged(float);
	
	void Attack();
	void AfterAttack();

	void MoveLineToPoint(Enemy* enemy);

	

	WCHAR enemyPath[256];
	WCHAR enemyPath2[256];
	WCHAR enemyPath3[256];

	WCHAR enemyMaskingPath[256];


	float m_stateSizeX[3];
	float m_stateSizeY[3];

	CImage enemyMasking[3];
	CImage enemyImage[3];


	bool movable;
	int m_bossState;
	float m_elapsedAttackTime;

	Enemy* m_pAttackEnemy;

	//std::vector<Enemy*> AttackVector;
	EnemyBoss();
	~EnemyBoss();
};

