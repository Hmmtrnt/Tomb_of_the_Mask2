#include "GameManager.h"
#include "../Object/Player.h"
#include "../Object/Stage.h"


GameManager::GameManager() :
	colL(0),
	colR(0),
	colUp(0),
	colDown(0)
{
	m_pPlayer = new Player;
	m_pStage = new Stage;
}

GameManager::~GameManager()
{
	delete m_pPlayer;
	delete m_pStage;
}

void GameManager::init()
{
	m_pPlayer->init();
	m_pStage->init();
}

void GameManager::end()
{
	m_pPlayer->end();
	m_pStage->end();
}

void GameManager::update()
{
	collision();
	m_pPlayer->operation(colL, colR, colUp, colDown);
	m_pPlayer->update();
	m_pStage->update();
}

void GameManager::draw()
{
	m_pStage->draw();
	m_pPlayer->draw();
}

void GameManager::collision()
{
	collisionR();
	collisionL();
	collisionUP();
	collisionBottom();
}

// ----------------------------------------------
// 当たり判定
// ----------------------------------------------

// 右
void GameManager::collisionR()
{
	colR = false;
	for (int y = 0; y < PLAYER_HEIGHT; y++)
	{
		for (int x = 0; x < PLAYER_WIDTH; x++)
		{
			if (m_pPlayer->m_player[y][x] != 0)
			{
				if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x + 1)] != 0)
				{
					colR = true;
					printfDx("右\n");
					//m_pPlayer->m_speedX = 0;
				}
			}
		}
	}
}

// 左
void GameManager::collisionL()
{
	colL = false;
	for (int y = 0; y < PLAYER_HEIGHT; y++)
	{
		for (int x = 0; x < PLAYER_WIDTH; x++)
		{
			if (m_pPlayer->m_player[y][x] != 0)
			{
				if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x - 1)] != 0)
				{
					colL = true;
					printfDx("左\n");
					//m_pPlayer->m_speedX = 0;
				}
			}
		}
	}
}

// 上
void GameManager::collisionUP()
{
	colUp = false;
	for (int y = 0; y < PLAYER_HEIGHT; y++)
	{
		for (int x = 0; x < PLAYER_WIDTH; x++)
		{
			if (m_pPlayer->m_player[y][x] != 0)
			{
				if (m_pStage->m_stage[m_pPlayer->m_posY + (y - 1)][m_pPlayer->m_posX + x] != 0)
				{
					colUp = true;
					printfDx("上\n");
					//m_pPlayer->m_speedY = 0;
				}
			}
		}
	}
}

// 下
void GameManager::collisionBottom()
{
	colDown = false;
	for (int y = 0; y < PLAYER_HEIGHT; y++)
	{
		for (int x = 0; x < PLAYER_WIDTH; x++)
		{
			if (m_pPlayer->m_player[y][x] != 0)
			{
				if (m_pStage->m_stage[m_pPlayer->m_posY + (y + 1)][m_pPlayer->m_posX + x] != 0)
				{
					colDown = true;
					printfDx("下\n");
					//m_pPlayer->m_speedY = 0;
				}
			}
		}
	}
}
