// ステージ6
#pragma once
#include "SceneBase.h"
#include "../Util/common.h"

class GameManager;
class Back;

class SceneStage6 : public SceneBase
{
public:
	SceneStage6();
	virtual ~SceneStage6();

	virtual void init();			// 初期化
	virtual void end();				// 終了
	virtual SceneBase* update();	// 更新
	virtual void draw();			// 描画

private:
	// ポインタ
	GameManager* m_pManager;	// ゲームマネージャー
	Back* m_pBack;				// 背景

	// フレームカウント
	int m_frameCount;
	// キャラの座標
	int m_posX;				// X座標
	int m_posY;				// Y座標
	// キャラの移動フレーム
	int m_frameX;			// X座標
	int m_frameY;			// Y座標

	// ヘルプを押したかの真偽
	bool m_pushHelp;
};

