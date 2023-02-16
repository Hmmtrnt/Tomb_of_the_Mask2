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
#include "../Object/Back.h"
#include "../Util/Pad.h"

namespace
{
	constexpr int kItemX = 100;
	constexpr int kItemY = 50;
}

SceneSelect::SceneSelect() :
	m_stageSelect(0),
	m_textHandle(-1),
	m_textHandle2(-1),
	m_createStage(0),
	m_stageNum(0),
	m_stageNum2(0),
	m_selectPos(0),
	m_pushTitle(false)
{
	m_pBack = new Back;
}

SceneSelect::~SceneSelect()
{
	delete m_pBack;
}

void SceneSelect::init()
{
	// リソースの読み込み
	LPCSTR font_path = "Font/Silver.ttf";// 読み込むフォントファイルのパス
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0)
	{

	}
	else
	{
		// フォント読み込みエラー処理
		MessageBox(NULL, "フォント読み込み失敗", "", MB_OK);
	}
	m_stageSelect = 1;
	m_textHandle = CreateFontToHandle("Silver", 100, -1, -1);
	m_textHandle2 = CreateFontToHandle("Silver", 50, -1, -1);
	m_createStage = 20;
	m_stageNum = 20;
	m_selectPos = 0;
	m_pushTitle = false;
	m_pBack->init();
}

void SceneSelect::end()
{
	DeleteFontToHandle(m_textHandle);
	DeleteFontToHandle(m_textHandle2);
	m_pBack->end();
}

SceneBase* SceneSelect::update()
{
	//フェード処理
	if (isFading())
	{
		bool isOut = isFadingOut();
		SceneBase::updateFade();
		// フェードアウト終了時にシーン切り替え
		if (!isFading() && isOut && m_pushTitle)			return (new SceneTitle);
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

	if (Pad::isTrigger(PAD_INPUT_1))	m_pushTitle = true;

	if (!isFading())
	{
		if (Pad::isTrigger(PAD_INPUT_2) || Pad::isTrigger(PAD_INPUT_1))
		{
			// フェードアウト開始
			startFadeOut();
		}
	}
	return this;
}

void SceneSelect::draw()
{
	m_pBack->draw();

	SetDrawBlendMode(DX_BLENDMODE_MULA, 100);
	DrawBox(900, 50, 1800, 900, kColor::Black, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

	//DrawStringToHandle(300, 180, "ステージ", kColor::White,m_textHandle2 );
	/*if (m_stageSelect <= 9)
	{
		DrawFormatStringToHandle(380, 240, kColor::White, m_textHandle, "%d", m_stageSelect);
	}
	else
	{
		DrawFormatStringToHandle(360, 240, kColor::White, m_textHandle, "%d", m_stageSelect);
	}*/

	DrawFormatString(0, 0, kColor::White, "%d", m_stageSelect);

	DrawStringToHandle(300, 850, "Bボタンでステージを選択", kColor::White, m_textHandle2);
	//DrawFormatStringToHandle(750, 850, kColor::White, m_textHandle2, "%dステージまで出来ます\n", m_createStage);

	int itemX = 0;
	int itemY = 60;
	int itemW = 200;
	int itemH = 250;

	int test0 = 910;
	int test1 = 180;
	int test4 = 210;
	int test2 = itemY + test4;
	int test3 = itemH + test4;

	for (int y = 0; y < m_stageNum; y++)
	{
		// ずれる
		itemX = test0 + (test1 * y);
		if (y > 4)
		{
			itemY = test2;
			itemH = test3;
			itemX = test0 + (test1 * (y - 5));
		}
		if (y > 9)
		{
			itemY = test2 + test4;
			itemH = test3 + test4;
			itemX = test0 + (test1 * (y - 10));
		}
		if (y > 14)
		{
			itemY = test2 + test4 + test4;
			itemH = test3 + test4 + test4;
			itemX = test0 + (test1 * (y - 15));
		}
		// 枠の描画
		DrawBox(itemX, itemY, itemX + 160, itemH, kColor::White, false);
	}

	//DrawBox(500, 100, 600, 200, kColor::White, false);

	/*DrawStringToHandle(600, 200, "RBボタン＋5", kColor::White, m_textHandle2);
	DrawFormatStringToHandle(600, 240, kColor::White, m_textHandle, "→");
	if (m_stageSelect != 1)
	{
		DrawStringToHandle(100, 200, "LBボタンー5", kColor::White, m_textHandle2);
		DrawFormatStringToHandle(100, 240, kColor::White, m_textHandle, "←");
	}*/
	SceneBase::drawFade();
}
