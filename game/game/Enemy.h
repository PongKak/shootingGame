#pragma once

class Projectile;

class Enemy
{
public:
	Enemy();
	virtual ~Enemy();

	virtual void DrawEnemy(HDC);
	virtual void DrawDeadEnemy(HDC);
	virtual void Moving();
	virtual void Damaged(float);

	void SetEnemyStatus(int);
	void MoveLineToCharacter(Enemy*);
	void SetInitPosition(float x, float y);
	void SetHP(float);


	inline void SetElapsedTime(float deltaTime) { m_elapsedTime = deltaTime; }
	inline void SetTotalTime(float totalTime) { m_totalTime = totalTime; }

	int m_type;

	float m_initPositionX;
	float m_initPositionY;
	float m_positionX;
	float m_positionY;
	float m_characterX;
	float m_characterY;
	float m_sizeX;
	float m_sizeY;
	float m_HP;
	float m_speed;
	int bSrcAlpha;
	int m_state;
	int m_randomDirection;
	

	float m_elapsedTime;
	float m_totalTime;

	CImage enemyImage;
	CImage enemyMasking;
	WCHAR path[256];
	WCHAR enemyPath[256];
	WCHAR enemyMaskingPath[256];


};

