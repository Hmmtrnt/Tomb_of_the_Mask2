#include "SceneSelect.h"
#include "SceneTitle.h"
#include "SceneStage1.h"
//#include "SceneStage2.h"
//#include "SceneStage3.h"
//#include "SceneStage4.h"
#include "SceneStage5.h"
//#include "SceneStage6.h"
//#include "SceneStage7.h"
//#include "SceneStage8.h"
//#include "SceneStage9.h"
#include "SceneStage10.h"
//#include "SceneStage11.h"
//#include "SceneStage12.h"
//#include "SceneStage13.h"
//#include "SceneStage14.h"
#include "SceneStage15.h"
//#include "SceneStage16.h"
//#include "SceneStage17.h"
//#include "SceneStage18.h"
//#include "SceneStage19.h"
#include "SceneStage20.h"
#include "../Object/Back.h"
#include "../Util/Pad.h"

namespace
{
	// BGMの音量
	constexpr int kVolumeBgm = 100;
}

SceneSelect::SceneSelect() :
	m_textHandle(0),
	m_textHandle2(0),
	m_createStage(0),
	m_stageNum(0),
	m_stageNumText(0),
	m_selectPos(0),
	m_cursorX(0),
	m_cursorY(0),
	m_cursorPosX(0),
	m_cursorPosY(0),
	m_cursorPosW(0),
	m_cursorPosH(0),
	m_stageH1(0),
	m_stageH2(0),
	m_stageH3(0),
	m_stageH4(0),
	m_stageH5(0),
	m_stageH6(0),
	m_stageH7(0),
	m_stageH8(0),
	m_stageH9(0),
	m_stageH10(0),
	m_stageH11(0),
	m_stageH12(0),
	m_stageH13(0),
	m_stageH14(0),
	m_stageH15(0),
	m_stageH16(0),
	m_stageH17(0),
	m_stageH18(0),
	m_stageH19(0),
	m_stageH20(0),
	m_centerStageH(0),
	m_starEmpty(0),
	m_starYellow(0),
	m_starRed(0),
	m_cursorSound(-1),
	m_decideSound(-1),
	m_backGroundSound(-1), 
	m_playSound(false),
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
	m_textHandle = CreateFontToHandle("Silver", 100, -1, -1);
	m_textHandle2 = CreateFontToHandle("Silver", 50, -1, -1);
	m_createStage = 20;
	m_stageNum = 20;
	m_stageNumText = 0;
	m_selectPos = 0;
	m_cursorX = 1;
	m_cursorY = 1;
	m_cursorPosX = 910;
	m_cursorPosY = 60;
	m_cursorPosW = m_cursorPosX + 160;
	m_cursorPosH = m_cursorPosY + 190;

	m_stageH1 = draw::MyLoadGraph("data/stage/stage1.png");
	m_stageH2 = draw::MyLoadGraph("data/stage/stage2.png");
	m_stageH3 = draw::MyLoadGraph("data/stage/stage3.png");
	m_stageH4 = draw::MyLoadGraph("data/stage/stage4.png");
	m_stageH5 = draw::MyLoadGraph("data/stage/stage5.png");
	m_stageH6 = draw::MyLoadGraph("data/stage/stage6.png");
	m_stageH7 = draw::MyLoadGraph("data/stage/stage7.png");
	m_stageH8 = draw::MyLoadGraph("data/stage/stage8.png");
	m_stageH9 = draw::MyLoadGraph("data/stage/stage9.png");
	m_stageH10 = draw::MyLoadGraph("data/stage/stage10.png");
	m_stageH11 = draw::MyLoadGraph("data/stage/stage11.png");
	m_stageH12 = draw::MyLoadGraph("data/stage/stage12.png");
	m_stageH13 = draw::MyLoadGraph("data/stage/stage13.png");
	m_stageH14 = draw::MyLoadGraph("data/stage/stage14.png");
	m_stageH15 = draw::MyLoadGraph("data/stage/stage15.png");
	m_stageH16 = draw::MyLoadGraph("data/stage/stage16.png");
	m_stageH17 = draw::MyLoadGraph("data/stage/stage17.png");
	m_stageH18 = draw::MyLoadGraph("data/stage/stage18.png");
	m_stageH19 = draw::MyLoadGraph("data/stage/stage19.png");
	m_stageH20 = draw::MyLoadGraph("data/stage/stage20.png");

	m_starEmpty = draw::MyLoadGraph("data/starEmpty.png");
	m_starYellow = draw::MyLoadGraph("data/starYellow.png");
	m_starRed = draw::MyLoadGraph("data/starRed.png");

	m_cursorSound = LoadSoundMem("sound/cursorSound.mp3");
	m_decideSound = LoadSoundMem("sound/decideSound.mp3");
	m_backGroundSound = LoadSoundMem("sound/Selectbgm.mp3");

	m_pushTitle = false;
	m_playSound = false;

	ChangeVolumeSoundMem(kVolumeBgm, m_backGroundSound);

	m_pBack->init();
}

void SceneSelect::end()
{
	DeleteFontToHandle(m_textHandle);
	DeleteFontToHandle(m_textHandle2);
	DeleteGraph(m_stageH1);
	DeleteGraph(m_stageH2);
	DeleteGraph(m_stageH3);
	DeleteGraph(m_stageH4);
	DeleteGraph(m_stageH5);
	DeleteGraph(m_stageH6);
	DeleteGraph(m_stageH7);
	DeleteGraph(m_stageH8);
	DeleteGraph(m_stageH9);
	DeleteGraph(m_stageH10);
	DeleteGraph(m_stageH11);
	DeleteGraph(m_stageH12);
	DeleteGraph(m_stageH13);
	DeleteGraph(m_stageH14);
	DeleteGraph(m_stageH15);
	DeleteGraph(m_stageH16);
	DeleteGraph(m_stageH17);
	DeleteGraph(m_stageH18);
	DeleteGraph(m_stageH19);
	DeleteGraph(m_stageH20);

	DeleteGraph(m_starEmpty);
	DeleteGraph(m_starYellow);
	DeleteGraph(m_starRed);

	DeleteSoundMem(m_cursorSound);
	DeleteSoundMem(m_decideSound);
	DeleteSoundMem(m_backGroundSound);

	m_pBack->end();
}

SceneBase* SceneSelect::update()
{
	// BGM再生
	if (!m_playSound)
	{
		PlaySoundMem(m_backGroundSound, DX_PLAYTYPE_BACK, true);
		m_playSound = true;
	}
	// BGM流れなくなったらループするようにする
	if (CheckSoundMem(m_backGroundSound) == 0)
	{
		m_playSound = false;
	}

	//フェード処理
	if (isFading())
	{
		bool isOut = isFadingOut();
		SceneBase::updateFade();
		if (!isFading() && isOut && m_pushTitle)		return (new SceneTitle);
		if (!isFading() && isOut)
		{
			if (m_cursorY == 1)
			{
				if (m_cursorX == 1)	return(new SceneStage1);
				/*if (m_cursorX == 2) return(new SceneStage2);
				if (m_cursorX == 3) return(new SceneStage3);
				if (m_cursorX == 4) return(new SceneStage4);*/
				if (m_cursorX == 5) return(new SceneStage5);
			}
			if (m_cursorY == 2)
			{
				/*if (m_cursorX == 1)	return(new SceneStage6);
				if (m_cursorX == 2) return(new SceneStage7);
				if (m_cursorX == 3) return(new SceneStage8);
				if (m_cursorX == 4) return(new SceneStage9);*/
				if (m_cursorX == 5) return(new SceneStage10);
			}
			if (m_cursorY == 3)
			{
				/*if (m_cursorX == 1)	return(new SceneStage11);
				if (m_cursorX == 2) return(new SceneStage12);
				if (m_cursorX == 3) return(new SceneStage13);
				if (m_cursorX == 4) return(new SceneStage14);*/
				if (m_cursorX == 5) return(new SceneStage15);
			}
			if (m_cursorY == 4)
			{
				/*if (m_cursorX == 1)	return(new SceneStage16);
				if (m_cursorX == 2) return(new SceneStage17);
				if (m_cursorX == 3) return(new SceneStage18);
				if (m_cursorX == 4) return(new SceneStage19);*/
				if (m_cursorX == 5) return(new SceneStage20);
			}
		}
	}

	

	// ステージ選択
	int cursorSpeed = 10;

	if (Pad::isTrigger(PAD_INPUT_RIGHT))
	{
		m_cursorX++;
		PlaySoundMem(m_cursorSound, DX_PLAYTYPE_BACK, true);
	}
	if (Pad::isTrigger(PAD_INPUT_LEFT))
	{
		m_cursorX--;
		PlaySoundMem(m_cursorSound, DX_PLAYTYPE_BACK, true);
	}
	if (Pad::isTrigger(PAD_INPUT_UP))
	{
		m_cursorY--;
		PlaySoundMem(m_cursorSound, DX_PLAYTYPE_BACK, true);
	}
	if (Pad::isTrigger(PAD_INPUT_DOWN))
	{
		m_cursorY++;
		PlaySoundMem(m_cursorSound, DX_PLAYTYPE_BACK, true);
	}
	if (m_cursorX <= 0)
	{
		m_cursorX = 5;
		m_cursorY--;
	}
	if (m_cursorX >= 6)
	{
		m_cursorX = 1;
		m_cursorY++;
	}
	if (m_cursorY <= 0)
	{
		m_cursorY = 4;
	}
	if (m_cursorY >= 5)
	{
		m_cursorY = 1;
	}

	// カーソル移動
	m_cursorPosX = (180 * (m_cursorX - 1)) + 910;
	m_cursorPosW = m_cursorPosX + 160;
	m_cursorPosY = (210 * (m_cursorY - 1)) + 60;
	m_cursorPosH = m_cursorPosY + 190;

	if (m_cursorY == 1)
	{
		if (m_cursorX == 1)	m_centerStageH = m_stageH1;
		if (m_cursorX == 2) m_centerStageH = m_stageH2;
		if (m_cursorX == 3) m_centerStageH = m_stageH3;
		if (m_cursorX == 4) m_centerStageH = m_stageH4;
		if (m_cursorX == 5) m_centerStageH = m_stageH5;
	}
	if (m_cursorY == 2)
	{
		if (m_cursorX == 1)	m_centerStageH = m_stageH6;
		if (m_cursorX == 2) m_centerStageH = m_stageH7;
		if (m_cursorX == 3) m_centerStageH = m_stageH8;
		if (m_cursorX == 4) m_centerStageH = m_stageH9;
		if (m_cursorX == 5) m_centerStageH = m_stageH10;
	}
	if (m_cursorY == 3)
	{
		if (m_cursorX == 1)	m_centerStageH = m_stageH11;
		if (m_cursorX == 2) m_centerStageH = m_stageH12;
		if (m_cursorX == 3) m_centerStageH = m_stageH13;
		if (m_cursorX == 4) m_centerStageH = m_stageH14;
		if (m_cursorX == 5) m_centerStageH = m_stageH15;
	}
	if (m_cursorY == 4)
	{
		if (m_cursorX == 1)	m_centerStageH = m_stageH16;
		if (m_cursorX == 2) m_centerStageH = m_stageH17;
		if (m_cursorX == 3) m_centerStageH = m_stageH18;
		if (m_cursorX == 4) m_centerStageH = m_stageH19;
		if (m_cursorX == 5) m_centerStageH = m_stageH20;
	}

	if (Pad::isTrigger(PAD_INPUT_1))	m_pushTitle = true;

	if (!isFading())
	{
		if (Pad::isTrigger(PAD_INPUT_2) || Pad::isTrigger(PAD_INPUT_1))
		{
			PlaySoundMem(m_decideSound, DX_PLAYTYPE_BACK, true);
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
	// セレクトステージ
	DrawBox(900, 50, 1800, 900, kColor::Black, true);
	// センターステージ
	DrawBox(100, 100, 800, 750, kColor::Black, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

	DrawStringToHandle(300, 900, "Bボタンでステージを選択", kColor::White, m_textHandle2);

	int itemX = 0;
	int itemY = 60;
	int itemW = 200;
	int itemH = 250;

	int imageWidth = 910;				// 枠の横幅
	int Width = 180;					// 横幅
	int lineHeight = 210;				// 列ごとの縦幅
	int linePosH = itemY + lineHeight;	// 列ごとの縦座標
	int Height = itemH + lineHeight;	// 縦幅

	DrawExtendGraph(imageWidth + (Width * 0), itemY, (imageWidth + (Width * 0)) + 160, itemH, m_stageH1, true);
	DrawExtendGraph(imageWidth + (Width * 1), itemY, (imageWidth + (Width * 1)) + 160, itemH, m_stageH2, true);
	DrawExtendGraph(imageWidth + (Width * 2), itemY, (imageWidth + (Width * 2)) + 160, itemH, m_stageH3, true);
	DrawExtendGraph(imageWidth + (Width * 3), itemY, (imageWidth + (Width * 3)) + 160, itemH, m_stageH4, true);
	DrawExtendGraph(imageWidth + (Width * 4), itemY, (imageWidth + (Width * 4)) + 160, itemH, m_stageH5, true);
	DrawExtendGraph(imageWidth + (Width * 0), linePosH, (imageWidth + (Width * 0)) + 160, Height, m_stageH6, true);
	DrawExtendGraph(imageWidth + (Width * 1), linePosH, (imageWidth + (Width * 1)) + 160, Height, m_stageH7, true);
	DrawExtendGraph(imageWidth + (Width * 2), linePosH, (imageWidth + (Width * 2)) + 160, Height, m_stageH8, true);
	DrawExtendGraph(imageWidth + (Width * 3), linePosH, (imageWidth + (Width * 3)) + 160, Height, m_stageH9, true);
	DrawExtendGraph(imageWidth + (Width * 4), linePosH, (imageWidth + (Width * 4)) + 160, Height, m_stageH10, true);
	DrawExtendGraph(imageWidth + (Width * 0), linePosH + lineHeight, (imageWidth + (Width * 0)) + 160, Height + lineHeight, m_stageH11, true);
	DrawExtendGraph(imageWidth + (Width * 1), linePosH + lineHeight, (imageWidth + (Width * 1)) + 160, Height + lineHeight, m_stageH12, true);
	DrawExtendGraph(imageWidth + (Width * 2), linePosH + lineHeight, (imageWidth + (Width * 2)) + 160, Height + lineHeight, m_stageH13, true);
	DrawExtendGraph(imageWidth + (Width * 3), linePosH + lineHeight, (imageWidth + (Width * 3)) + 160, Height + lineHeight, m_stageH14, true);
	DrawExtendGraph(imageWidth + (Width * 4), linePosH + lineHeight, (imageWidth + (Width * 4)) + 160, Height + lineHeight, m_stageH15, true);
	DrawExtendGraph(imageWidth + (Width * 0), linePosH + lineHeight + lineHeight, (imageWidth + (Width * 0)) + 160, Height + lineHeight + lineHeight, m_stageH16, true);
	DrawExtendGraph(imageWidth + (Width * 1), linePosH + lineHeight + lineHeight, (imageWidth + (Width * 1)) + 160, Height + lineHeight + lineHeight, m_stageH17, true);
	DrawExtendGraph(imageWidth + (Width * 2), linePosH + lineHeight + lineHeight, (imageWidth + (Width * 2)) + 160, Height + lineHeight + lineHeight, m_stageH18, true);
	DrawExtendGraph(imageWidth + (Width * 3), linePosH + lineHeight + lineHeight, (imageWidth + (Width * 3)) + 160, Height + lineHeight + lineHeight, m_stageH19, true);
	DrawExtendGraph(imageWidth + (Width * 4), linePosH + lineHeight + lineHeight, (imageWidth + (Width * 4)) + 160, Height + lineHeight + lineHeight, m_stageH20, true);

	// ステージ数の初期化
	m_stageNumText = 0;
	// 枠の描画　
	for (int y = 0; y < m_stageNum; y++)
	{
			m_stageNumText++;
		
		// ずれる
		itemX = imageWidth + (Width * y);
		if (y > 4)
		{
			itemY = linePosH;
			itemH = Height;
			itemX = imageWidth + (Width * (y - 5));
		}
		if (y > 9)
		{
			itemY = linePosH + lineHeight;
			itemH = Height + lineHeight;
			itemX = imageWidth + (Width * (y - 10));
		}
		if (y > 14)
		{
			itemY = linePosH + lineHeight + lineHeight;
			itemH = Height + lineHeight + lineHeight;
			itemX = imageWidth + (Width * (y - 15));
		}
		// 枠の描画
		DrawBox(itemX, itemY, itemX + 160, itemH, kColor::White, false);
		DrawFormatStringToHandle(itemX + 7, itemY + 152, kColor::Black, m_textHandle2, "%dステージ", m_stageNumText);
		DrawFormatStringToHandle(itemX + 5, itemY + 150, kColor::White, m_textHandle2, "%dステージ", m_stageNumText);
	}
	// テキストの描画
	//for (int y = 0; y < m_stageNum; y++)
	//{
	//	m_stageNumText++;
	//	// ずれる
	//	itemX = imageWidth + (Width * y);
	//	if (y > 4)
	//	{
	//		itemY = linePosH;
	//		itemX = imageWidth + (Width * (y - 5));
	//	}
	//	if (y > 9)
	//	{
	//		itemY = linePosH + lineHeight;
	//		itemX = imageWidth + (Width * (y - 10));
	//	}
	//	if (y > 14)
	//	{
	//		itemY = linePosH + lineHeight + lineHeight;
	//		itemX = imageWidth + (Width * (y - 15));
	//	}
	//	
	//	//m_stageNumText++;
	//}

	// カーソル表示
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawBox(m_cursorPosX, m_cursorPosY, m_cursorPosW, m_cursorPosH, kColor::Yellow, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	// 選ばれているステージが表示される
	DrawExtendGraph(120, 120, 780, 730, m_centerStageH, true);
	DrawBox(120, 120, 780, 730, kColor::White, false);
	//DrawGraph(0, 0, m_starEmpty, true);

	difficultyDraw();

	SceneBase::drawFade();
}

// 難易度表示
void SceneSelect::difficultyDraw()
{
	draw::MyDrawRectRotaGraph(250, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starEmpty, true, false);
	draw::MyDrawRectRotaGraph(350, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starEmpty, true, false);
	draw::MyDrawRectRotaGraph(450, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starEmpty, true, false);
	draw::MyDrawRectRotaGraph(550, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starEmpty, true, false);
	draw::MyDrawRectRotaGraph(650, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starEmpty, true, false);

	if (m_cursorY == 1)
	{
		if (m_cursorX == 1)
		{
			draw::MyDrawRectRotaGraph(250, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
		}
		if (m_cursorX == 2)
		{
			draw::MyDrawRectRotaGraph(250, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
		}
		if (m_cursorX == 3)
		{
			draw::MyDrawRectRotaGraph(250, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
		}
		if (m_cursorX == 4)
		{
			draw::MyDrawRectRotaGraph(250, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(350, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
		}
		if (m_cursorX == 5)
		{
			draw::MyDrawRectRotaGraph(250, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(350, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
		}
	}
	if (m_cursorY == 2)
	{
		if (m_cursorX == 1)
		{
			draw::MyDrawRectRotaGraph(250, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
		}
		if (m_cursorX == 2)
		{
			draw::MyDrawRectRotaGraph(250, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(350, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
		}
		if (m_cursorX == 3)
		{
			draw::MyDrawRectRotaGraph(250, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(350, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
		}
		if (m_cursorX == 4)
		{
			draw::MyDrawRectRotaGraph(250, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(350, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(450, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
		}
		if (m_cursorX == 5)
		{
			draw::MyDrawRectRotaGraph(250, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(350, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(450, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
		}
	}
	if (m_cursorY == 3)
	{
		if (m_cursorX == 1)
		{
			draw::MyDrawRectRotaGraph(250, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(350, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
		}
		if (m_cursorX == 2)
		{
			draw::MyDrawRectRotaGraph(250, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(350, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(450, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
		}
		if (m_cursorX == 3)
		{
			draw::MyDrawRectRotaGraph(250, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(350, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(450, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(550, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
		}
		if (m_cursorX == 4)
		{
			draw::MyDrawRectRotaGraph(250, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(350, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(450, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(550, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
		}
		if (m_cursorX == 5)
		{
			draw::MyDrawRectRotaGraph(250, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(350, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(450, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(550, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(650, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
		}
	}
	if (m_cursorY == 4)
	{
		if (m_cursorX == 1)
		{
			draw::MyDrawRectRotaGraph(250, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(350, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(450, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
		}
		if (m_cursorX == 2)
		{
			draw::MyDrawRectRotaGraph(250, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(350, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(450, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(550, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(650, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
		}
		if (m_cursorX == 3)
		{
			draw::MyDrawRectRotaGraph(250, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(350, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(450, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(550, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(650, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
		}
		if (m_cursorX == 4)
		{
			draw::MyDrawRectRotaGraph(250, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(350, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(450, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(550, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(650, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(750, 50, 0, 0, 32, 32, 2.5f, 0.0f, m_starRed, true, false);
		}
		if (m_cursorX == 5)
		{
			draw::MyDrawRectRotaGraph(250, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(350, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(450, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(550, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(650, 50, 0, 0, 32, 32, 2.0f, 0.0f, m_starYellow, true, false);
			draw::MyDrawRectRotaGraph(750, 50, 0, 0, 32, 32, 2.5f, 0.0f, m_starRed, true, false);
		}
	}
}