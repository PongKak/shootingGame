#pragma once

class Enemy
{
public:
	Enemy();
	~Enemy();

	virtual void DrawEnemy(HWND,HDC) = 0;
	virtual void SetEnemyStatus() = 0;

	void MoveToLine(float x,float y);
	void SetInitPosition(float x, float y);

	int m_type;

	float m_initPositionX;
	float m_initPositionY;
	float m_positionX;
	float m_positionY;


	CImage enemyImage;
	CImage enemyMasking;
	WCHAR path[256];
	WCHAR enemyPath[256];
	WCHAR enemyMaskingPath[256];

};

