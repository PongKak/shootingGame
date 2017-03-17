#include "stdafx.h"
#include "PlayerCharacter.h"
#include "define.h"


PlayerCharacter::PlayerCharacter()
{
	GetCurrentDirectory(sizeof(path), path);
	m_characterX = 590;
	m_characterY = 1024;

}


PlayerCharacter::~PlayerCharacter()
{

}


void PlayerCharacter::LineMoveTo(float x, float y)
{
	m_characterY -= CHARACTERMOVESPEED;

	if (m_characterY <= y)
	{
		m_characterY = y;
		controllable = true;
	}
}

void PlayerCharacter::SetCharacterPosition(float x, float y)
{
	if(controllable == true)
	{
		m_characterX += x * CHARACTERMOVESPEED;
		m_characterY += y * CHARACTERMOVESPEED;
	}

	if (m_characterX < 10)
	{
		m_characterX = 10;
	}
	if (m_characterX > 1170)
	{
		m_characterX = 1170;
	}

	if (m_characterY > 850)
	{
		m_characterY = 850;
	}
	if (m_characterY < 10)
	{
		m_characterY = 10;
	}
}

void PlayerCharacter::SetCharacterDirection(int direction)
{
	m_characterDirection = direction;
}


bool PlayerCharacter::RunningCharacter(HWND hWnd, HDC hdc, HDC memoryDC)
{
	DrawPropella(hWnd, hdc, memoryDC);
	DrawCharacter(hWnd, hdc, memoryDC);
	if (controllable == false)
	{
		LineMoveTo(590, 800);
	}
	return true;
}
bool PlayerCharacter::DrawPropella(HWND hWnd, HDC hdc, HDC memoryDC)
{
	i = (i % 6) + 1;
	WCHAR buffer[8];
	_itow_s(i, buffer, 10);

	
	wcscpy_s(propellaPath, path);
	wcscat_s(propellaPath, L"/resource/propella/");
	wcscat_s(propellaPath, buffer);
	wcscat_s(propellaPath, L".png");

	wcscpy_s(propellaMaskingPath, path);
	wcscat_s(propellaMaskingPath, L"/resource/propella/");
	wcscat_s(propellaMaskingPath, buffer);
	wcscat_s(propellaMaskingPath, L"mask.png");

	
	m_maskingProp.Load(propellaMaskingPath);
	m_propImage.Load(propellaPath);

	m_maskingProp.StretchBlt(memoryDC, m_characterX + 25, m_characterY - 5, 50, 20, 0, 0, 185, 62, SRCAND);
	m_propImage.StretchBlt(memoryDC, m_characterX + 25, m_characterY - 5, 50, 20, 0, 0, 185, 62, SRCPAINT);


	m_maskingProp.Destroy();
	m_propImage.Destroy();


	return true;
}
bool PlayerCharacter::DrawCharacter(HWND hWnd, HDC hdc, HDC memoryDC)
{
	if (controllable == false)
	{
		m_characterDirection = 0;
	}

	
	switch (m_characterDirection)
	{
		case 0:
		{
			wcscpy_s(characterMaskingPath, path);
			wcscat_s(characterMaskingPath, L"/resource/character/no-bank-no-prop-mask.png");

			wcscpy_s(characterImagePath, path);
			wcscat_s(characterImagePath, L"/resource/character/no-bank-no-prop.png");

			break;
		}
		case 1:
		{
			wcscpy_s(characterMaskingPath, path);
			wcscat_s(characterMaskingPath, L"/resource/character/bank-left-no-prop-mask.png");

			wcscpy_s(characterImagePath, path);
			wcscat_s(characterImagePath, L"/resource/character/bank-left-no-prop.png");
			break;
		}
		case 2:
		{
			wcscpy_s(characterMaskingPath, path);
			wcscat_s(characterMaskingPath, L"/resource/character/bank-right-no-prop-mask.png");

			wcscpy_s(characterImagePath, path);
			wcscat_s(characterImagePath, L"/resource/character/bank-right-no-prop.png");
			break;
		}
	}

	
	m_charactermasking.Load(characterMaskingPath);
	m_PlayerCharacterImage.Load(characterImagePath);

	m_charactermasking.StretchBlt(memoryDC, m_characterX, m_characterY, 100, 100, 0, 0, 512, 512, SRCAND);
	m_PlayerCharacterImage.StretchBlt(memoryDC, m_characterX, m_characterY, 100, 100, 0, 0, 512, 512, SRCPAINT);


	m_charactermasking.Destroy();
	m_PlayerCharacterImage.Destroy();




	return true;
}

