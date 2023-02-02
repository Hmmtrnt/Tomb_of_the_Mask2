// ステージ2
#pragma once
#include "SceneBase.h"
#include "../Util/common.h"

class GameManager;

class SceneStage2 : public SceneBase
{
public:
	SceneStage2();
	virtual ~SceneStage2();

	virtual void init();			// 初期化
	virtual void end();				// 終了
	virtual SceneBase* update();	// 更新
	virtual void draw();			// 描画

private:
	// ゲームマネージャーポインタ
	GameManager* m_pManager;

	// フレームカウント
	int m_frameCount;
};

