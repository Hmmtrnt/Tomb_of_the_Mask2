// シーンの基底クラス
#pragma once

class SceneBase
{
public:
	SceneBase();
	virtual ~SceneBase(){}

	virtual void init(){}				// 初期化
	virtual void end(){}				// 終了処理
	virtual SceneBase* update() { return this; }		// 更新処理
	virtual void draw(){}				// 描画

	// フェード関連
	void updateFade();
	void drawFade() const;

	bool isFadingIn() const;	// フェードイン中
	bool isFadingOut() const;	// フェードアウト中
	bool isFading() const { return isFadingIn() || isFadingOut(); }// フェードインorアウト中

	void startFadeOut();		// フェードアウト開始

private:
	// フェード関連処理
	int m_fadeColor;
	int m_fadeBright;
	int m_fadeSpeed;
};