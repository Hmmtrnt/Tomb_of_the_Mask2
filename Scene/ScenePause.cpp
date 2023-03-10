﻿#include "ScenePause.h"
#include "../Util/Pad.h"
#include "../Object/CharParticle.h"

namespace
{
	// 座標
	constexpr int kWidthText = 850;		// テキスト
	constexpr int kWidthCursor = 750;	// カーソル
}

ScenePause::ScenePause() :
	m_textHandle(-1),
	m_posCursorX(0),
	m_posCursorY(0),
	m_posClearCursorX(0),
	m_posClearCursorY(0),
	m_pushNum(0),
	m_posClearPauseX(0),
	m_posClearPauseY(0),
	m_sizeClearPauseX(0),
	m_sizeClearPauseY(0),
	m_posClearTextX(0),
	m_pauseCursorNum(0),
	m_clearCursorNum(0),
	m_posClearTextY1(0),
	m_posClearTextY2(0),
	m_posClearTextY3(0),
	m_itemNum(0),
	m_CursorPosX(0),
	m_CursorPosY(0),
	m_movePosX(0),
	m_vecPauseX(0),
	m_cursorSound(-1),
	m_cursorNotSound(-1),
	m_isCursorInit(false),
	m_FillBox(false),
	m_isStage20(false),
	m_flowerFrame(0),
	m_particleCount(0)
{
}

ScenePause::~ScenePause()
{
}

void ScenePause::init()
{
	m_textHandle = CreateFontToHandle("Silver", 90, -1, -1);
	m_posCursorX = 800;
	m_posCursorY = 500;
	m_posClearCursorX = 750;
	m_posClearCursorY = 400;
	m_pushNum = 0;
	m_posClearPauseX = 2700;
	m_posClearPauseY = 250;
	m_sizeClearPauseX = 500;
	m_sizeClearPauseY = 450;
	m_posClearTextX = -1150;
	m_pauseCursorNum = 495;
	
	m_isStage20 = m_stageSelectNum == 20;
	
	m_clearCursorNum = 395;
	m_posClearTextY1 = 400;
	m_posClearTextY2 = 500;
	m_posClearTextY3 = 600;
	m_movePosX = -1200;
	m_vecPauseX = 100;
	m_cursorSound = LoadSoundMem("sound/cursorSound.mp3");
	m_cursorNotSound = LoadSoundMem("sound/landingSound.mp3");

	for (auto& pParticle : m_particle)
	{
		pParticle = std::make_shared<CharParticle>();
	}
	m_flowerFrame = kParticle::FlowerInterval;
	m_particleCount = 0;
}

void ScenePause::end()
{
	DeleteFontToHandle(m_textHandle);
	DeleteSoundMem(m_cursorSound);
	DeleteSoundMem(m_cursorNotSound);
}

void ScenePause::updatePause()
{
	if (m_pushNum >= 0 && m_pushNum <= 1)
	{
		if (Pad::isTrigger(PAD_INPUT_UP))
		{
			if (m_pushNum <= 0)
			{
				PlaySoundMem(m_cursorNotSound, DX_PLAYTYPE_BACK, true);
				m_pushNum = 0;
			}
			else
			{
				PlaySoundMem(m_cursorSound, DX_PLAYTYPE_BACK, true);
				m_pauseCursorNum -= 100;
				m_pushNum--;
			}
		}
		if (Pad::isTrigger(PAD_INPUT_DOWN))
		{
			if (m_pushNum >= 1)
			{
				PlaySoundMem(m_cursorNotSound, DX_PLAYTYPE_BACK, true);
				m_pushNum = 1;
			}
			else
			{
				PlaySoundMem(m_cursorSound, DX_PLAYTYPE_BACK, true);
				m_pauseCursorNum += 100;
				m_pushNum++;
			}
		}
	}
	if (Pad::isPress(PAD_INPUT_2))
	{
		m_FillBox = true;
	}
}

void ScenePause::drawPause()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, kColor::Black, true);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
	DrawBox(700, 350, 1150, 700, kColor::Yellow, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawBox(700, 350, 1150, 700, kColor::Black, false);
	DrawStringToHandle(850 + 2, 402, "PAUSE", kColor::Black, m_textHandle);
	DrawStringToHandle(850, 400, "PAUSE", kColor::White, m_textHandle);

	m_posCursorX = 800;
	m_posCursorY = m_pauseCursorNum;
	for (int y = 0; y < 5; y++)
	{
		DrawBox(m_posCursorX, m_posCursorY, m_posCursorX + 250, m_posCursorY + 70, kColor::Black, m_FillBox);
		m_posCursorX++;
		m_posCursorY++;
	}

	int posX = 800;
	int posY = 495;
	for (int y = 0; y < 2; y++)
	{
		for (int x = 0; x < 2; x++)
		{
			DrawBox(posX, posY, posX + 250, posY + 70, kColor::Black, false);
			posX++;
			posY++;
		}
		posX = 800;
		posY -= 2;
		posY += 100;
	}

	DrawStringToHandle(kWidthText + 2, 502, "RETIRE", kColor::Black, m_textHandle);
	if (m_FillBox && m_pushNum == 0)
	{
		DrawStringToHandle(kWidthText, 500, "RETIRE", kColor::White, m_textHandle);
	}
	DrawStringToHandle(kWidthText + 12, 602, "RETRY", kColor::Black, m_textHandle);
	if (m_FillBox && m_pushNum == 1)
	{
		DrawStringToHandle(kWidthText + 10, 600, "RETRY", kColor::White, m_textHandle);
	}
	//DrawStringToHandle(kWidthCursor, m_posCursor, "→", kColor::White, m_textHandle);

	

	// 確認描画
	//DrawFormatString(0, 0, kColor::Black, "%d", m_pushNum);
}

void ScenePause::updateClearPause()
{
	if (m_isStage20)
	{
		m_itemNum = 1;
	}
	else
	{
		m_itemNum = 2;
	}
	if (m_pushNum >= 0 && m_pushNum <= m_itemNum)
	{
		if (Pad::isTrigger(PAD_INPUT_UP))
		{
			if (m_pushNum <= 0)
			{
				PlaySoundMem(m_cursorNotSound, DX_PLAYTYPE_BACK, true);
				m_pushNum = 0;
			}
			else
			{
				PlaySoundMem(m_cursorSound, DX_PLAYTYPE_BACK, true);
				m_clearCursorNum -= 100;
				m_pushNum--;
			}
		}
		if (Pad::isTrigger(PAD_INPUT_DOWN))
		{
			if (m_pushNum >= m_itemNum)
			{
				PlaySoundMem(m_cursorNotSound, DX_PLAYTYPE_BACK, true);
				m_pushNum = m_itemNum;
			}
			else
			{
				PlaySoundMem(m_cursorSound, DX_PLAYTYPE_BACK, true);
				m_clearCursorNum += 100;
				m_pushNum++;
			}
		}
	}
	if (Pad::isPress(PAD_INPUT_2))
	{
		m_FillBox = true;
	}
	movePause();

	int x = 0;
	int y = 0;
	for (int i = 0; i < 3; i++)
	{
		particle(x, y, 64);
		if (i == 0)
		{
			x = 450;
			y = 250;
		}
		if (i == 1)
		{
			x = 550;
			y = 550;
		}
		if (i == 2)
		{
			x = 1250;
			y = 350;
		}
	}

	//particle(450,250, 64);
	//particle(1250,350);
	//particle(500,700);
}

void ScenePause::drawClearPause()
{
	//bool isStage20 = m_stageSelectNum == 20;

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, kColor::Black, true);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
	DrawBox(m_posClearPauseX, m_posClearPauseY, 
		m_posClearPauseX + m_sizeClearPauseX, m_posClearPauseY + m_sizeClearPauseY, kColor::Yellow, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawBox(m_posClearPauseX, m_posClearPauseY, 
		m_posClearPauseX + m_sizeClearPauseX, m_posClearPauseY + m_sizeClearPauseY, kColor::Black, false);

	m_posClearCursorX = m_movePosX;
	m_posClearCursorY = m_clearCursorNum;
	if (m_isStage20)
	{
		m_posClearCursorY = m_clearCursorNum - 5;
	}

	for (int y = 0; y < 5; y++)
	{
		DrawBox(m_posClearCursorX, m_posClearCursorY, m_posClearCursorX + 400, m_posClearCursorY + 70, kColor::Black, m_FillBox);
		m_posClearCursorX++;
		m_posClearCursorY++;
	}
	
	// カーソル未選択の枠
	if (!m_isStage20)
	{
		m_CursorPosX = m_movePosX;
		m_CursorPosY = 395;

		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < 2; x++)
			{
				DrawBox(m_CursorPosX, m_CursorPosY, m_CursorPosX + 400, m_CursorPosY + 70, kColor::Black, false);
				m_CursorPosX++;
				m_CursorPosY++;
			}
			m_CursorPosX = m_movePosX;
			m_CursorPosY -= 2;
			m_CursorPosY += 100;
		}
	}
	else
	{
		m_CursorPosX = m_movePosX;
		m_CursorPosY = 495;
		for (int y = 0; y < 2; y++)
		{
			for (int x = 0; x < 2; x++)
			{
				DrawBox(m_CursorPosX, m_CursorPosY, m_CursorPosX + 400, m_CursorPosY + 70, kColor::Black, false);
				m_CursorPosX++;
				m_CursorPosY++;
			}
			m_CursorPosX = m_movePosX;
			m_CursorPosY -= 2;
			m_CursorPosY += 100;
		}
	}

	// メニューの文字描画
	if (m_isStage20)
	{
		DrawStringToHandle(m_posClearTextX - 48, m_posClearTextY1 + 2, "CONGRATULATION!", kColor::Black, m_textHandle);
		DrawStringToHandle(m_posClearTextX - 50, m_posClearTextY1, "CONGRATULATION!", kColor::White, m_textHandle);
		if (!m_isCursorInit)
		{
			m_clearCursorNum = 500;
			m_isCursorInit = true;
		}
		
		drawParticle();
	}
	else
	{
		DrawStringToHandle(m_posClearTextX + 12, m_posClearTextY1 + 2, "NEXT STAGE", kColor::Black, m_textHandle);
		if (m_FillBox && m_pushNum == 0)
		{
			DrawStringToHandle(m_posClearTextX + 10, m_posClearTextY1, "NEXT STAGE", kColor::White, m_textHandle);
		}
	}
	
	DrawStringToHandle(m_posClearTextX + 12, 302, "GAMECLEAR!", kColor::Black, m_textHandle);
	DrawStringToHandle(m_posClearTextX + 10, 300, "GAMECLEAR!", kColor::White, m_textHandle);
	
	DrawStringToHandle(m_posClearTextX - 18, m_posClearTextY2 + 2, "SELECT SCENE", kColor::Black, m_textHandle);
	if ((m_FillBox && m_pushNum == 1 && !m_isStage20) || (m_FillBox && m_pushNum == 0 && m_isStage20))
	{
		DrawStringToHandle(m_posClearTextX - 20, m_posClearTextY2, "SELECT SCENE", kColor::White, m_textHandle);
	}
	
	DrawStringToHandle(m_posClearTextX + 82, m_posClearTextY3 + 2, "RETRY", kColor::Black, m_textHandle);

	if ((m_FillBox && m_pushNum == 2 && !m_isStage20) || (m_FillBox && m_pushNum == 1 && m_isStage20))
	{
		DrawStringToHandle(m_posClearTextX + 80, m_posClearTextY3, "RETRY", kColor::White, m_textHandle);
	}
	
	// 確認描画
	//DrawFormatString(0, 0, kColor::Black, "%d", m_pushNum);
}

void ScenePause::movePause()
{
	m_posClearTextX += m_vecPauseX;
	m_posClearPauseX -= m_vecPauseX;
	m_movePosX += m_vecPauseX;
	if (m_posClearTextX >= 800)
	{
		m_posClearTextX = 800;
	}
	if (m_posClearPauseX <= 700)
	{
		m_posClearPauseX = 700;
	}
	if (m_movePosX >= 750)
	{
		m_movePosX = 750;
	}
}

void ScenePause::particle(int x, int y, int count)
{
	for (auto& pParticle : m_particle)
	{
		if (!pParticle->isExist())	continue;
		pParticle->update();
	}

	m_flowerFrame--;
	if (m_flowerFrame <= 0)
	{
		m_particleCount = 0;
		// 花火のようなパーティクル
		for (auto& pParticle : m_particle)
		{
			if (pParticle->isExist()) continue;

			float randSin = static_cast<float>(GetRand(360)) / 360.0f;
			randSin *= DX_TWO_PI_F;
			float randSpeed = static_cast<float>(GetRand(160)) / 10.0f + 1.0f;

			Vec2 pos;
			pos.x = x + cosf(randSin) * 2.0f;
			pos.y = y + sinf(randSin) * 2.0f;

			Vec2 vec;
			vec.x = cosf(randSin) * randSpeed;
			vec.y = sinf(randSin) * randSpeed;

			pParticle->start(pos);
			pParticle->setVec(vec);
			pParticle->setRadius(2.0f);
			pParticle->setColor(kColor::Yellow);
			pParticle->setGravity(0.4f);

			m_particleCount++;
			if (m_particleCount >= count)
			{
				break;
			}
		}
		m_flowerFrame = kParticle::FlowerInterval;
	}
}

void ScenePause::drawParticle()
{
	for (auto& pParticle : m_particle)
	{
		if (!pParticle->isExist())	continue;
		pParticle->draw();
	}
}
