#pragma once

class Projectile;


class ProjectileManager
{
private:
	ProjectileManager();
	~ProjectileManager();

	static ProjectileManager* instance;

public:
	
	void createProjectile(int ,float,float);
	void moveProjectile();
	void drawProjectile();
	void deleteProjectile();
	void SetElapsedTime(float deltaTime);
	void SetTotalTime(float totalTime);

	int m_limit;

	static ProjectileManager* GetInstance();

	void SetMemoryDC(HDC memoryDC);

	void SetHWnd(HWND hWnd);


	HWND hWnd;
	HDC m_memoryDC;

	std::vector<Projectile*> m_characterProjectile;
	std::vector<Projectile*> m_enemyProjectile;
};


