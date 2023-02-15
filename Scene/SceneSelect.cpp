#include "SceneSelect.h"
#include "SceneTitle.h"
#include "SceneStage1.h"
#include "SceneStage2.h"
#include "SceneStage3.h"
#include "SceneStage4.h"
#include "SceneStage5.h"
#include "SceneStage6.h"
#include "SceneStage7.h"
#include "SceneStage8.h"
#include "SceneStage9.h"
#include "SceneStage10.h"
#include "SceneStage11.h"
#include "SceneStage12.h"
#include "SceneStage13.h"
#include "SceneStage14.h"
#include "SceneStage15.h"
#include "SceneStage16.h"
#include "SceneStage17.h"
#include "SceneStage18.h"
#include "SceneStage19.h"
#include "SceneStage20.h"
#include "../Util/Pad.h"

SceneSelect::SceneSelect() :
	m_stageSelect(0),
	m_textHandle(-1),
	m_textHandle2(-1),
	m_createStage(0)
{
}

SceneSelect::~SceneSelect()
{
}

void SceneSelect::init()
{
	m_stageSelect = 1;
	m_textHandle = CreateFontToHandle(NULL, 100, 3);
	m_textHandle2 = CreateFontToHandle(NULL, 50, 3);
	m_createStage = 20;
}

void SceneSelect::end()
{
	DeleteFontToHandle(m_textHandle);
	DeleteFontToHandle(m_textHandle2);
}

SceneBase* SceneSelect::update()
{
	//フェード処理
	if (isFading())
	{
		bool isOut = isFadingOut();
		SceneBase::updateFade();
		// フェードアウト終了時にシーン切り替え
		if (!isFading() && isOut && m_stageSelect == 1)		return (new SceneStage1);
		if (!isFading() && isOut && m_stageSelect == 2)		return (new SceneStage2);
		if (!isFading() && isOut && m_stageSelect == 3)		return (new SceneStage3);
		if (!isFading() && isOut && m_stageSelect == 4)		return (new SceneStage4);
		if (!isFading() && isOut && m_stageSelect == 5)		return (new SceneStage5);
		if (!isFading() && isOut && m_stageSelect == 6)		return (new SceneStage6);
		if (!isFading() && isOut && m_stageSelect == 7)		return (new SceneStage7);
		if (!isFading() && isOut && m_stageSelect == 8)		return (new SceneStage8);
		if (!isFading() && isOut && m_stageSelect == 9)		return (new SceneStage9);
		if (!isFading() && isOut && m_stageSelect == 10)	return (new SceneStage10);
		if (!isFading() && isOut && m_stageSelect == 11)	return (new SceneStage11);
		if (!isFading() && isOut && m_stageSelect == 12)	return (new SceneStage12);
		if (!isFading() && isOut && m_stageSelect == 13)	return (new SceneStage13);
		if (!isFading() && isOut && m_stageSelect == 14)	return (new SceneStage14);
		if (!isFading() && isOut && m_stageSelect == 15)	return (new SceneStage15);
		if (!isFading() && isOut && m_stageSelect == 16)	return (new SceneStage16);
		if (!isFading() && isOut && m_stageSelect == 17)	return (new SceneStage17);
		if (!isFading() && isOut && m_stageSelect == 18)	return (new SceneStage18);
		if (!isFading() && isOut && m_stageSelect == 19)	return (new SceneStage19);
		if (!isFading() && isOut && m_stageSelect == 20)	return (new SceneStage20);
	}

	// ステージ選択
	if (Pad::isTrigger(PAD_INPUT_RIGHT) == 1)
	{
		m_stageSelect++;
	}
	else if (Pad::isTrigger(PAD_INPUT_LEFT) == 1)
	{
		m_stageSelect--;
	}
	else if (Pad::isTrigger(PAD_INPUT_Y) == 1)
	{
		m_stageSelect -= 5;
	}
	else if (Pad::isTrigger(PAD_INPUT_Z) == 1)
	{
		m_stageSelect += 5;
	}
	if (m_stageSelect <= 1)
	{
		m_stageSelect = 1;
	}
	else if (m_stageSelect >= m_createStage)
	{
		m_stageSelect = m_createStage;
	}

	// タイトル画面へ戻る
	if (Pad::isTrigger(PAD_INPUT_1))	return (new SceneTitle);

	if (!isFading())
	{
		if (Pad::isTrigger(PAD_INPUT_2))
		{
			// フェードアウト開始
			startFadeOut();
		}
	}
	return this;
}

void SceneSelect::draw()
{
	DrawStringToHandle(300, 180, "ステージ", kColor::White,m_textHandle2 );
	if (m_stageSelect <= 9)
	{
		DrawFormatStringToHandle(380, 240, kColor::White, m_textHandle, "%d", m_stageSelect);
	}
	else
	{
		DrawFormatStringToHandle(360, 240, kColor::White, m_textHandle, "%d", m_stageSelect);
	}
	DrawString(300, 500, "Bボタンでステージを選択", kColor::White);
	DrawFormatString(300, 550, kColor::White, "%dステージまで出来ています\n", m_createStage);
	DrawString(600, 200, "RBボタン＋5", kColor::White);
	DrawFormatStringToHandle(600, 240, kColor::White, m_textHandle, "→");
	if (m_stageSelect != 1)
	{
		DrawString(100, 200, "LBボタンー5", kColor::White);
		DrawFormatStringToHandle(100, 240, kColor::White, m_textHandle, "←");
	}
	SceneBase::drawFade();
}
