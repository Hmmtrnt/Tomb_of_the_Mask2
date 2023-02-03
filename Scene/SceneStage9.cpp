#include "SceneStage9.h"
#include "SceneSelect.h"
#include "../Util/GameManager.h"

SceneStage9::SceneStage9() :
	m_frameCount(0)
{
	m_pManager = new GameManager;
}

SceneStage9::~SceneStage9()
{
	delete m_pManager;
}

void SceneStage9::init()
{
	m_frameCount = 90;
	m_pManager->init9();
}

void SceneStage9::end()
{
	m_pManager->end();
}

SceneBase* SceneStage9::update()
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
		return(new SceneStage9);
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

void SceneStage9::draw()
{
	m_pManager->draw();
}