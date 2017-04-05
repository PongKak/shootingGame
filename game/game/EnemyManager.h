#pragma once

class Enemy;

class EnemyManager
{
public:
	EnemyManager();
	~EnemyManager();

	void CreateEnemy();
	void MoveEnemy();
	void DrawEnemy();
	void DeleteEnemy();
	void AfterDead();
	void SetCharacterPosition(float ,float);

	inline void SetMemoryDC(HDC memoryDC) { m_memoryDC = memoryDC; };
	inline void SetHWnd(HWND hWnd) { this->hWnd = hWnd; };
	void SetTime(float,float);


	HWND hWnd;
	HDC m_memoryDC;

	int m_numofDeadType1;
	int m_numofDeadType2;
	int m_numofDeadType3;



	std::vector<Enemy*> m_enemyVector;
	std::vector<Enemy*> m_deadEnemyVector;
};

