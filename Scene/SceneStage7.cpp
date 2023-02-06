#include "SceneStage7.h"
#include "SceneSelect.h"
#include "../Util/GameManager.h"

SceneStage7::SceneStage7() :
	m_frameCount(0),
	m_posX(0),
	m_posY(0),
	m_frameX(0),
	m_frameY(0)
{
	m_pManager = new GameManager;
}

SceneStage7::~SceneStage7()
{
	delete m_pManager;
}

void SceneStage7::init()
{
	m_frameCount = 90;
	m_posX = 10;
	m_posY = 12;
	m_frameX = 400;
	m_frameY = 480;

	m_pManager->init7(m_posX, m_posY, m_frameX, m_frameY);
}

void SceneStage7::end()
{
	m_pManager->end();
}

SceneBase* SceneStage7::update()
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
		return(new SceneStage7);
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

void SceneStage7::draw()
{
	m_pManager->draw();
}
