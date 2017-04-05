#pragma once
class Projectile

{
public:
	Projectile();
	virtual ~Projectile();

	virtual void DrawProjectile(HDC);
	void MoveToLine();

	inline void SetElapsedTime(float deltaTime) { m_elapsedTime = deltaTime; }
	inline void SetTotalTime(float totalTime) { m_totalTime = totalTime; }


	float m_PositionX;
	float m_PositionY;
	float m_sizeX;
	float m_sizeY;
	float speed;
	bool isCollision = false;
	float m_elapsedTime = 0;
	float m_totalTime = 0;
	float m_damage;

	CImage projectileImage;
	CImage projectileMasking;
	WCHAR path[256];
	WCHAR projectilePath[256];
	WCHAR projectileMaskingPath[256];



};

