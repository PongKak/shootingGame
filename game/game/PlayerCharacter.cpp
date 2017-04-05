#include "stdafx.h"
#include "PlayerCharacter.h"
#include "define.h"


PlayerCharacter::PlayerCharacter()
{
	GetCurrentDirectory(sizeof(path), path);
	m_characterX = 590;
	m_characterY = 1024;

	
	// Ä³¸¯ÅÍ ¸öÅë
	for (auto i = 0; i < 3; ++i)
	{
		WCHAR characterImagePath[256];
		WCHAR characterMaskingPath[256];

		switch (i)
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

		m_PlayerCharacterImage[i].Load(characterImagePath);
		m_charactermasking[i].Load(characterMaskingPath);


	}

	//ÇÁ·ÎÆç·¯
	for (auto i = 0; i < 6; ++i)
	{
		WCHAR buffer[8];
		_itow_s(i+1, buffer, 10);


		wcscpy_s(propellaPath, path);
		wcscat_s(propellaPath, L"/resource/propella/");
		wcscat_s(propellaPath, buffer);
		wcscat_s(propellaPath, L".png");

		wcscpy_s(propellaMaskingPath, path);
		wcscat_s(propellaMaskingPath, L"/resource/propella/");
		wcscat_s(propellaMaskingPath, buffer);
		wcscat_s(propellaMaskingPath, L"mask.png");


		m_maskingProp[i].Load(propellaMaskingPath);
		m_propImage[i].Load(propellaPath);

	}


}


PlayerCharacter::~PlayerCharacter()
{
	for ( auto i = 0; i < 3; ++i)
	{
		m_charactermasking[i].Destroy();
		m_PlayerCharacterImage[i].Destroy();
	}
	for (auto i : m_charactermasking)
	{
		i.Destroy();
	}

	for (auto i : m_PlayerCharacterImage)
	{
		i.Destroy();
	}

	for (auto i = 0; i < 6; ++i)
	{
		m_maskingProp[i].Destroy();
		m_propImage[i].Destroy();
	}
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




bool PlayerCharacter::RunningCharacter()
{
	DrawPropella();
	DrawCharacter();
	if (controllable == false)
	{
		LineMoveTo(590, 800);
	}
	return true;
}
bool PlayerCharacter::DrawPropella()
{
	i = (i + 1) % 6;

	m_maskingProp[i].StretchBlt(m_memoryDC, m_characterX - PROPELLERSIZEX / 2, m_characterY - PROPELLERSIZEY / 2 - 50, PROPELLERSIZEX, PROPELLERSIZEY, 0, 0, PROPELLERIMAGESIZEX, PROPELLERIMAGESIZEY, SRCAND);
	m_propImage[i].StretchBlt(m_memoryDC, m_characterX - PROPELLERSIZEX / 2, m_characterY - PROPELLERSIZEY / 2 - 50, PROPELLERSIZEX, PROPELLERSIZEY, 0, 0, PROPELLERIMAGESIZEX, PROPELLERIMAGESIZEY, SRCPAINT);

	return true;
}


bool PlayerCharacter::DrawCharacter()
{
	if (controllable == false)
	{
		m_characterDirection = 0;
	}

	m_charactermasking[m_characterDirection].StretchBlt(m_memoryDC, m_characterX - CHARACTERSIZEX / 2, m_characterY - CHARACTERSIZEY / 2, CHARACTERSIZEX, CHARACTERSIZEY, 0, 0, CHARACTERIMAGESIZEX, CHARACTERIMAGESIZEY, SRCAND);
	m_PlayerCharacterImage[m_characterDirection].StretchBlt(m_memoryDC, m_characterX - CHARACTERSIZEX / 2, m_characterY - CHARACTERSIZEY / 2, CHARACTERSIZEX, CHARACTERSIZEY, 0, 0, CHARACTERIMAGESIZEX, CHARACTERIMAGESIZEY, SRCPAINT);





	return true;
}



void PlayerCharacter::SetMemoryDC(HDC memoryDC)
{
	m_memoryDC = memoryDC;
}

void PlayerCharacter::SetHWnd(HWND hWnd)
{
	this->hWnd = hWnd;
}

