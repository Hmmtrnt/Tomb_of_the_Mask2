#pragma once
#include "DxLib.h"

// プレイヤーの幅
#define PLAYER_HEIGHT 3		// 縦
#define PLAYER_WIDTH 3		// 横

// エネミーの幅
#define ENEMY_HEIGHT 3		// 縦
#define ENEMY_WIDTH 3		// 横

// ステージの幅
#define STAGE_HEIGHT 15		// 縦
#define STAGE_WIDTH 15		// 横

// ステージの描画する幅
#define DRAW_WIDTH 40

// 描画する位置変更
#define DRAW_POSITION_X 60
#define DRAW_POSITION_Y 50

// ステージ
namespace kStage
{
	// ステージの配列
	// 0:無
	// 5:膨らんだら即死判定
	// 6:即死判定
	// 7:数フレーム後に針が出てゲームオーバーになる判定
	// 8:ゴール
	// 9:壁
	// プロトタイプ用ステージ
	constexpr int stage1[STAGE_HEIGHT][STAGE_WIDTH] = {
		// 1行       6行         11行     
		{9,9,9,9,9,  9,9,9,9,9,  9,9,9,9,9},// 1行
		{9,0,0,8,9,  0,0,0,7,9,  0,0,0,0,9},
		{9,0,9,9,9,  0,9,0,9,9,  0,9,9,0,9},
		{9,0,0,7,9,  0,9,0,9,9,  0,9,9,0,9},
		{9,0,0,0,9,  0,9,0,9,9,  0,9,9,0,9},

		{9,9,9,0,9,  0,9,0,0,0,  0,9,9,0,9},// 6行
		{9,6,0,0,9,  0,9,6,9,9,  9,9,9,0,9},
		{9,6,0,9,9,  0,9,9,9,9,  9,9,0,0,9},
		{9,6,0,9,9,  0,9,9,9,9,  9,9,0,0,9},
		{9,6,0,0,0,  0,9,9,9,9,  9,9,0,9,9},

		{9,9,0,0,0,  0,0,0,0,0,  9,9,0,9,9},// 11行
		{9,6,0,5,0,  0,9,9,0,0,  9,9,0,0,9},
		{9,6,0,0,0,  0,9,9,0,0,  9,0,0,0,9},
		{9,9,0,0,0,  0,0,0,0,0,  9,0,0,0,9},
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
namespace kEnemy
{
	// エネミーの配列
	// 0:無
	// 1:エネミー
	constexpr int enemy[ENEMY_HEIGHT][ENEMY_WIDTH] = {
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
	const int White = GetColor(255, 255, 255);		// 白
}