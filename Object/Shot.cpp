#include "Shot.h"
#include "../Util/Pad.h"


namespace
{
	constexpr float kShotSize = 1.7f;
	constexpr int kVec = kVariable::DrawWidth;
}

Shot::Shot() :
	m_handle(0),
	m_rota(0.0f),
	m_speedX(0),
	m_speedY(0),
	m_speedX2(0),
	m_speedY2(0),
	m_speedX3(0),
	m_frameCount(0)
{

}

Shot::~Shot()
{
}

// 初期化(実験用)
void Shot::init()
{
	m_handle = draw::MyLoadGraph("data/arrow4.png");

	m_rota = 0;

	m_speedX = 0;
	m_speedY = 0;
	m_speedX2 = 0;
	m_speedY2 = 0;
	m_speedX3 = 0;

	m_frameCount = 60;
}

void Shot::end()
{
	DeleteGraph(m_handle);
}

void Shot::update()
{

}

void Shot::drawR(int& posX, int& posY)
{
	if (m_speedX == kVec)
	{
		m_rota = PI / 2;
		draw::MyDrawRectRotaGraph(posX + (kVariable::DrawWidth / 2), posY + (kVariable::DrawWidth / 2),
			0, 0,
			40, 40,
			kShotSize, m_rota,
			m_handle, true, false);
	}
}

void Shot::drawL(int& posX, int& posY)
{
	if (m_speedX2 == -kVec)
	{
		m_rota = PI / -2;
		draw::MyDrawRectRotaGraph(posX + (kVariable::DrawWidth / 2), posY + (kVariable::DrawWidth / 2),
			0, 0,
			40, 40,
			kShotSize, m_rota,
			m_handle, true, false);
	}
}

void Shot::drawU(int& posX, int& posY)
{
	if (m_speedY == -kVec)
	{
		m_rota = 0;
		draw::MyDrawRectRotaGraph(posX + (kVariable::DrawWidth / 2), posY + (kVariable::DrawWidth / 2),
			0, 0,
			40, 40,
			kShotSize, m_rota,
			m_handle, true, false);
	}
}

void Shot::drawB(int& posX, int& posY)
{
	if (m_speedY2 == kVec)
	{
		m_rota = PI / 1;
		draw::MyDrawRectRotaGraph(posX + (kVariable::DrawWidth / 2), posY + (kVariable::DrawWidth / 2),
			0, 0,
			40, 40,
			kShotSize, m_rota,
			m_handle, true, false);
	}
}

void Shot::drawR2(int& posX, int& posY)
{
	if (m_speedX3 == kVec)
	{
		m_rota = PI / 2;
		draw::MyDrawRectRotaGraph(posX + (kVariable::DrawWidth / 2), posY + (kVariable::DrawWidth / 2),
			0, 0,
			40, 40,
			kShotSize, m_rota,
			m_handle, true, false);
	}
}

void Shot::drawL2(int& posX, int& posY)
{
	if (m_speedX2 == -kVec)
	{
		m_rota = PI / -2;
		draw::MyDrawRectRotaGraph(posX + (kVariable::DrawWidth / 2), posY + (kVariable::DrawWidth / 2),
			0, 0,
			40, 40,
			kShotSize, m_rota,
			m_handle, true, false);
	}
}

void Shot::shotRight(int &posX, int &stagePosX)
{
	m_frameCount--;

	posX += m_speedX;

	if (stagePosX <= posX)
	{
		m_speedX = 0;
	}
	else
	{
		m_speedX = kVec;
	}
	if (m_frameCount <= 0)
	{
		m_frameCount = 0;
		init();
	}
}

void Shot::shotLeft(int &posX, int &stagePosX)
{
	m_frameCount--;

	posX += m_speedX2;

	if (stagePosX >= posX &&m_frameCount > 0)
	{
		m_speedX2 = 0;
	}
	else
	{
		m_speedX2 = -kVec;
	}
	if (m_frameCount <= 0)
	{
		m_frameCount = 0;
		init();
	}
}

void Shot::shotUp(int &posY, int &stagePosY)
{
	m_frameCount--;

	posY += m_speedY;

	if (stagePosY >= posY && m_frameCount > 0)
	{
		m_speedY = 0;
	}
	else
	{
		m_speedY = -kVec;
	}
	if (m_frameCount <= 0)
	{
		m_frameCount = 0;
		init();
	}
}

void Shot::shotBottom(int &posY, int &stagePosY)
{
	m_frameCount--;

	posY += m_speedY2;

	if (stagePosY <= posY && m_frameCount > 0)
	{
		m_speedY2 = 0;
	}
	else
	{
		m_speedY2 = kVec;
	}
	if (m_frameCount <= 0)
	{
		m_frameCount = 0;
		init();
	}
}

void Shot::shotRight2(int& posX, int& stagePosX)
{
	m_frameCount--;

	posX += m_speedX3;

	if (stagePosX <= posX)
	{
		m_speedX3 = 0;
	}
	else
	{
		m_speedX3 = kVec;
	}
	if (m_frameCount <= 0)
	{
		m_frameCount = 0;
		init();
	}
}

void Shot::shotLeft2(int& posX, int& stagePosX)
{
	m_frameCount--;

	posX += m_speedX4;

	if (stagePosX >= posX && m_frameCount > 0)
	{
		m_speedX4 = 0;
	}
	else
	{
		m_speedX4 = -kVec;
	}
	if (m_frameCount <= 0)
	{
		m_frameCount = 0;
		init();
	}
}
