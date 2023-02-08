#include "Stage.h"

Stage::Stage() :
	m_gimmickFrame(0),
	m_shrink(0),
	m_inflate(0),
	m_handleWall(0),
	m_handleTrap(0),
	m_handleSmallNeedle(0),
	m_handleGoal(0),
	m_verX(0),
	m_verY(0),
	m_idxGoalX(0),
	m_idxGoalY(0),
	m_GoalFrame(0),
	m_drawGoalFirst(0),
	m_drawGoalSecond(0)
{
	for (int y = 0; y < kVariable::StageWidth; y++)
	{
		for (int x = 0; x < kVariable::StageWidth; x++)
		{
			m_stage[y][x] = 0;
			m_pStage[y][x] = 0;
		}
	}
}

Stage::~Stage()
{
}

void Stage::initCommon()
{
	m_gimmickFrame = 0;
	m_shrink = 40;
	m_inflate = 40;
	// ステージハンドル
	m_handleWall = draw::MyLoadGraph("data/tileset/inca_front.png");
	m_handleTrap = draw::MyLoadGraph("data/Textures-16.png");
	m_handleSmallNeedle = draw::MyLoadGraph("data/smallneedle.png");
	m_handleGoal = draw::MyLoadGraph("data/goal1.png");

	// ステージ切り取り
	m_verX = 0;
	m_verY = 0;

	m_idxGoalX = 0;
	m_idxGoalY = 0;

	m_GoalFrame = 0;
	m_drawGoalFirst = 30;
	m_drawGoalSecond = 30;
}

// ダブルポインタ
void Stage::initStage(const int stage[][kVariable::StageWidth], int stageHeight, int stageWidth)
{
	initCommon();
	for (int y = 0; y < stageHeight; y++)
	{
		for (int x = 0; x < stageWidth; x++)
		{
			m_stage[y][x] = stage[y][x];
		}
	}
}

void Stage::initP()
{
	initCommon();
	for (int y = 0; y < kVariable::StageWidth; y++)
	{
		for (int x = 0; x < kVariable::StageWidth; x++)
		{
			m_stage[y][x] = kStage::stageP[y][x];
		}
	}
}

void Stage::end()
{
	DeleteGraph(m_handleWall);
}

void Stage::update()
{
	// ギミックの描画変更処理
	m_gimmickFrame++;
	if (m_gimmickFrame >= m_shrink + m_inflate)
	{
		m_gimmickFrame = 0;
	}

	// ゴールの描画変更処理
	m_GoalFrame++;
	if (m_GoalFrame >= m_drawGoalFirst + m_drawGoalSecond)
	{
		m_GoalFrame = 0;
	}
}

void Stage::draw()
{
	for (int y = 0; y < kVariable::StageWidth; y++)
	{
		for (int x = 0; x < kVariable::StageWidth; x++)
		{
			stageDraw(x, y);
		}
	}
	// 変数確認用描画
	//DrawFormatString(600, 200, kColor::Red, "m_gimmickFrame:%d", m_gimmickFrame);
	//DrawFormatString(600, 250, kColor::Red, "m_inflate:%d", m_inflate);
}

void Stage::stageDraw(int x, int y)
{
	if (m_stage[y][x] == 0)
	{
	}
	else if (m_stage[y][x] == 4)
	{
		m_verX = 1;
		m_verY = 0;
		draw::MyDrawRectRotaGraph((x * kVariable::DrawWidth) + (kVariable::DrawWidth / 2), 
			(y * kVariable::DrawWidth) + (kVariable::DrawWidth / 2),
			m_verX * 32, m_verY * 32,
			32, 32,
			1.3f, 0.0f,
			m_handleWall, true, false);

	}
	else if (m_stage[y][x] == 5)
	{
		if (m_gimmickFrame < m_shrink)
		{
			m_verX = 3;
			m_verY = 0;
			draw::MyDrawRectRotaGraph((x * kVariable::DrawWidth) + (kVariable::DrawWidth / 2), 
				(y * kVariable::DrawWidth) + (kVariable::DrawWidth / 2),
				m_verX * 32, m_verY * 32,
				32, 32,
				1.3f, 0.0f,
				m_handleWall, true, false);

		}
		if (m_gimmickFrame > m_inflate)
		{
			m_verX = 2;
			m_verY = 0;
			draw::MyDrawRectRotaGraph((x * kVariable::DrawWidth) + (kVariable::DrawWidth / 2), 
				(y * kVariable::DrawWidth) + (kVariable::DrawWidth / 2),
				m_verX * 32, m_verY * 32,
				32, 32,
				3.6f, 0.0f,
				m_handleWall, true, false);

		}
	}
	else if (m_stage[y][x] == 6)
	{
		m_verX = 13;
		m_verY = 13;
		draw::MyDrawRectRotaGraph((x * kVariable::DrawWidth) + (kVariable::DrawWidth / 2), 
			(y * kVariable::DrawWidth) + (kVariable::DrawWidth / 2),
			m_verX * 16, m_verY * 16,
			16, 16,
			2.5f, 0.0f,
			m_handleTrap, true, false);


	}
	else if (m_stage[y][x] == 7)
	{
		m_verX = 0;
		m_verY = 0;
		draw::MyDrawRectRotaGraph((x * kVariable::DrawWidth) + (kVariable::DrawWidth / 2), 
			(y * kVariable::DrawWidth) + (kVariable::DrawWidth / 2),
			m_verX * 32, m_verY * 32,
			32, 32,
			1.3f, 0.0f,
			m_handleWall, true, false);
		needleDraw(x, y);
	}
	else if (m_stage[y][x] == 8)
	{
		if (m_GoalFrame < m_drawGoalFirst)
		{
			m_idxGoalX = 0;
			m_idxGoalY = 0;
		}
		if (m_GoalFrame > m_drawGoalSecond)
		{
			m_idxGoalX = 1;
			m_idxGoalY = 0;
		}
		draw::MyDrawRectRotaGraph((x * kVariable::DrawWidth) + (kVariable::DrawWidth / 2),
			(y * kVariable::DrawWidth) + (kVariable::DrawWidth / 2),
			m_idxGoalX * 40, m_idxGoalY * 40,
			40, 40,
			1.0f, 0.0f,
			m_handleGoal, true, false);

	}
	else if (m_stage[y][x] == 9)
	{
		m_verX = 4;
		m_verY = 0;
		draw::MyDrawRectRotaGraph((x * kVariable::DrawWidth) + (kVariable::DrawWidth / 2), 
			(y * kVariable::DrawWidth) + (kVariable::DrawWidth / 2),
			m_verX * 32, m_verY * 32,
			32, 32,
			1.3f, 0.0f,
			m_handleWall, true, false);

	}
}

void Stage::needleDraw(int x, int y)
{
	// 右
	draw::MyDrawRectRotaGraph(((x + 1) * kVariable::DrawWidth) + (kVariable::DrawWidth / 2), 
		(y * kVariable::DrawWidth) + (kVariable::DrawWidth / 2),
		0, 0,
		40, 40,
		1.0f, PI / 2,
		m_handleSmallNeedle, true, false);
	// 左
	if (m_stage[y][x - 1] == 0)
	{
		draw::MyDrawRectRotaGraph(((x - 1) * kVariable::DrawWidth) + (kVariable::DrawWidth / 2), 
			(y * kVariable::DrawWidth) + (kVariable::DrawWidth / 2),
			0, 0,
			40, 40,
			1.0f, PI / -2,
			m_handleSmallNeedle, true, false);
	}
	// 上
	if (m_stage[y - 1][x] == 0)
	{
		draw::MyDrawRectRotaGraph((x * kVariable::DrawWidth) + (kVariable::DrawWidth / 2), 
			((y - 1) * kVariable::DrawWidth) + (kVariable::DrawWidth / 2),
			0, 0,
			40, 40,
			1.0f, 0.0f,
			m_handleSmallNeedle, true, false);
	}
	// 下
	draw::MyDrawRectRotaGraph((x * kVariable::DrawWidth) + (kVariable::DrawWidth / 2), 
		((y + 1) * kVariable::DrawWidth) + (kVariable::DrawWidth / 2),
		0, 0,
		40, 40,
		1.0f, PI / 1,
		m_handleSmallNeedle, true, false);
}
