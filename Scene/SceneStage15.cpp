#include "SceneStage15.h"
#include "SceneSelect.h"
#include "../Util/GameManager.h"

SceneStage15::SceneStage15() :
	m_frameCount(0),
	m_posX(0),
	m_posY(0),
	m_frameX(0),
	m_frameY(0)
{
	m_pManager = new GameManager;
}

SceneStage15::~SceneStage15()
{
	delete m_pManager;
}

void SceneStage15::init()
{
	m_frameCount = 90;
	m_posX = 1;
	m_posY = 1;
	m_frameX = 40;
	m_frameY = 40;

	m_pManager->initManager(m_posX, m_posY, m_frameX, m_frameY,
		kStage::stage15, kVariable::StageWidth, kVariable::StageWidth);
}

void SceneStage15::end()
{
	m_pManager->end();
}

SceneBase* SceneStage15::update()
{
	m_pManager->updateNoShot();

	if (m_pManager->GetPushPause() == 1)
	{
	}
	else if (m_pManager->GetPushPause() == 2)
	{
		return(new SceneSelect);
	}
	else if (m_pManager->GetPushPause() == 3)
	{
		return(new SceneStage15);
	}

	if (m_pManager->GameOver)
	{
		m_frameCount--;

		if (m_frameCount <= 0)
		{
			return(new SceneSelect);
		}
	}
	if (m_pManager->GameClear)
	{
		return(new SceneSelect);
	}

	return this;
}

void SceneStage15::draw()
{
	m_pManager->draw();
}