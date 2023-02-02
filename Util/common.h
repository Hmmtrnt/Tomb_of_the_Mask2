#pragma once
#include "DxLib.h"
#include "DrawFunctions.h"

// プレイヤーの幅
#define PLAYER_HEIGHT 3		// 縦
#define PLAYER_WIDTH 3		// 横

// エネミーの幅
#define SHOT_HEIGHT 3		// 縦
#define SHOT_WIDTH 3		// 横

// ステージの幅
#define STAGE_HEIGHT 15		// 縦
#define STAGE_WIDTH 15		// 横

// 背景の幅
#define BACK_HEIGHT 22		// 縦
#define BACK_WIDTH 25		// 横

// ステージの描画する幅
#define DRAW_WIDTH 40

// 背景の描画する幅
#define DRAW_BACK_WIDTH 32

// 描画する位置変更
#define DRAW_POSITION_X 60
#define DRAW_POSITION_Y 50

// 円周率(仮)
#define PI    3.1415926535897932384626433832795f

// 背景
namespace kBack
{
	constexpr int backs[BACK_HEIGHT][BACK_WIDTH] = {
		// 1行	    6行        11行       16行       21行     
		{0,0,0,0,0, 1,0,0,0,0, 0,0,0,0,1, 0,1,1,0,0, 1,1,0,0,0},// 1行
		{0,0,0,0,0, 0,1,0,0,0, 0,1,0,1,0, 1,0,0,0,0, 0,0,1,0,0},
		{0,0,1,0,0, 0,0,1,0,1, 0,0,0,0,0, 0,0,0,0,1, 0,0,1,1,1},
		{0,0,0,0,0, 0,0,0,0,0, 1,0,1,0,0, 0,1,0,1,0, 1,0,0,0,0},
		{1,0,0,0,0, 1,0,1,0,0, 0,1,0,0,0, 0,0,1,0,0, 0,1,0,0,0},

		{0,0,0,1,1, 0,0,0,0,0, 1,0,0,0,1, 0,0,0,0,0, 0,0,1,0,0},// 6行
		{0,0,0,1,0, 1,0,0,0,1, 0,0,0,0,1, 0,0,0,1,0, 1,0,0,0,0},
		{0,0,0,0,0, 0,0,1,0,0, 0,0,0,1,0, 1,0,0,0,0, 0,1,0,0,1},
		{0,0,0,1,0, 0,1,0,1,0, 0,0,1,0,0, 0,1,1,0,1, 0,0,0,1,0},
		{0,0,0,0,0, 0,0,0,0,1, 1,0,0,0,0, 0,0,0,0,0, 1,1,1,0,0},

		{0,1,0,0,0, 0,0,0,1,0, 0,1,1,0,1, 0,0,0,1,1, 0,0,0,0,0},// 11行
		{0,0,0,0,0, 0,0,1,1,0, 0,0,0,0,0, 1,1,0,0,0, 0,1,1,1,1},
		{0,0,0,0,0, 1,1,0,1,0, 1,0,0,0,0, 0,1,1,0,0, 0,0,0,1,0},
		{0,1,0,1,0, 0,0,0,0,1, 0,0,0,0,0, 0,0,0,0,0, 1,0,1,0,0},
		{0,0,0,0,0, 0,1,0,0,0, 0,0,0,1,1, 1,0,0,1,0, 1,0,0,0,0},

		{1,0,0,0,0, 0,0,0,0,0, 1,0,0,0,0, 0,1,0,0,0, 0,0,0,0,0},// 16行
		{0,0,0,0,0, 1,0,0,0,0, 0,0,0,1,1, 1,0,1,0,1, 0,0,0,0,0},
		{0,0,0,1,0, 0,1,1,0,1, 0,0,1,0,0, 0,0,0,0,0, 1,1,1,0,0},
		{0,0,0,0,0, 1,0,0,0,0, 0,0,0,0,0, 0,0,0,1,0, 1,0,1,0,1},
		{1,0,0,1,0, 0,1,0,0,0, 0,0,1,0,0, 0,1,0,0,0, 0,0,0,1,0},

		{0,0,0,0,0, 0,0,1,1,0, 1,0,0,0,0, 1,0,0,0,1, 0,0,1,0,0},// 21行
		{0,0,0,0,0, 1,0,0,0,0, 0,0,1,0,1, 0,0,0,1,0, 0,0,0,0,1},
		
	};
}

// ステージ
namespace kStage
{
	// ステージの配列
	// 0:無
	// 4:弾発射開始位置
	// 5:膨らんだら即死判定
	// 6:即死判定
	// 7:数フレーム後に針が出てゲームオーバーになる判定
	// 8:ゴール
	// 9:壁
	// プロトタイプ用ステージ
	constexpr int stageP[STAGE_HEIGHT][STAGE_WIDTH] = {
		// 1行       6行         11行     
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},// 1行
		{9,0,0,8,9,  0,0,0,7,9,  0,0,0,0,9},
		{9,0,9,9,9,  0,9,0,9,9,  0,9,9,0,9},
		{9,0,0,7,9,  0,9,0,9,9,  0,9,9,0,9},
		{9,0,0,0,9,  0,9,0,9,9,  0,9,9,0,9},

		{9,9,0,0,9,  0,9,0,0,0,  0,9,9,0,9},// 6行
		{9,9,0,0,9,  0,9,6,9,9,  9,9,9,0,9},
		{9,9,0,0,9,  0,9,9,9,9,  9,7,0,0,9},
		{9,9,0,0,9,  0,9,9,9,9,  9,9,0,0,9},
		{9,9,0,0,0,  0,9,9,9,9,  9,9,0,9,9},

		{9,9,0,5,0,  0,0,0,0,0,  9,9,0,9,9},// 11行
		{9,9,0,0,0,  0,7,0,0,0,  9,9,0,0,9},
		{9,9,0,0,0,  0,0,0,0,0,  9,0,0,0,9},
		{9,4,0,0,0,  0,0,0,0,0,  9,0,0,0,9},
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},
	};

	// ステージ１
	// 8:ゴール
	// 9:壁
	constexpr int stage1[STAGE_HEIGHT][STAGE_WIDTH] = {
		// 1行		 6行		 11行
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},// 1行
		{9,9,9,9,9,  9,0,0,0,0,  0,0,0,9,9},
		{9,9,9,9,9,  9,0,9,9,9,  9,9,0,9,9},
		{9,9,9,9,9,  9,0,9,9,9,  9,9,0,9,9},
		{9,9,9,9,9,  9,0,9,9,9,  9,9,0,9,9},

		{9,9,9,9,9,  9,0,9,9,9,  9,9,0,9,9},// 6行
		{9,9,0,0,0,  0,0,0,0,0,  0,9,0,9,9},
		{9,9,0,9,9,  9,0,0,0,0,  0,9,0,9,9},
		{9,9,0,9,9,  9,0,9,9,0,  0,9,0,9,9},
		{9,9,8,9,9,  9,0,0,0,0,  0,9,0,9,9},

		{9,9,9,9,9,  9,9,9,9,9,  9,9,0,9,9},// 11行
		{9,9,9,9,9,  9,9,9,9,9,  9,9,0,9,9},
		{9,0,0,0,0,  0,0,0,0,0,  0,0,0,9,9},
		{9,0,0,0,9,  9,9,9,9,9,  9,9,9,9,9},
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},
	};

	// ステージ２
	// 6:即死判定
	// 8:ゴール
	// 9:壁
	constexpr int stage2[STAGE_HEIGHT][STAGE_WIDTH] = {
		// 1行		 6行		 11行
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},// 1行
		{9,0,0,0,0,  0,0,0,0,0,  0,0,0,0,9},
		{9,0,0,0,6,  6,6,6,6,6,  6,6,6,0,9},
		{9,0,0,0,9,  9,9,9,9,9,  9,9,9,0,9},
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,0,9},

		{9,9,9,9,9,  9,9,9,0,9,  6,6,6,0,9},// 6行
		{9,8,0,0,0,  0,0,9,0,9,  0,0,0,0,9},
		{9,9,9,9,9,  9,0,9,0,9,  0,0,0,0,9},
		{9,9,6,0,0,  0,0,9,9,9,  0,9,9,9,9},
		{9,9,9,0,0,  0,0,9,9,0,  0,9,9,9,9},

		{9,9,9,0,9,  9,0,9,9,0,  9,9,9,6,9},// 11行
		{9,9,9,0,0,  0,0,0,9,0,  0,0,0,0,9},
		{9,9,9,9,9,  9,9,0,9,9,  9,9,6,0,9},
		{9,9,9,9,9,  9,9,0,0,0,  0,0,0,0,9},
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},
	};

}

// プレイヤー
namespace kPlayer
{
	// プレイヤーの配列
	// 0:無
	// 1:プレイヤー
	constexpr int playr[PLAYER_HEIGHT][PLAYER_WIDTH] = {
		{0,0,0},
		{0,1,0},
		{0,0,0},
	};
}

// エネミー
namespace kShot
{
	// エネミーの配列
	// 0:無
	// 1:エネミー
	constexpr int shot[SHOT_HEIGHT][SHOT_WIDTH] = {
		{0,0,0},
		{0,1,0},
		{0,0,0},
	};
}

// 色
namespace kColor
{
	const int Black = GetColor(0, 0, 0);			// 黒
	const int Red = GetColor(255, 0, 0);			// 赤
	const int Peach = GetColor(255, 0, 255);		// 桃
	const int Green = GetColor(0, 255, 0);			// 緑
	const int Blue = GetColor(0, 0, 255);			// 青
	const int LightBlue = GetColor(0, 255, 255);	// 水
	const int Yellow = GetColor(255, 255, 0);		// 黄
	const int YellowGreen = GetColor(154, 205, 50);	// 黄緑
	const int White = GetColor(255, 255, 255);		// 白
}