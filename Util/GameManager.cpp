#include "GameManager.h"
#include "../Object/Player.h"
#include "../Object/Enemy.h"
#include "../Object/Stage.h"

GameManager::GameManager() :
	m_gimmickFrame(0),
	m_shrink(0),
	m_inflate(0),
	m_GameOverCount(0),
	GameOver(0),
	GameClear(0),
	colNextFlag(0),
	colFlagL(0),
	colFlagR(0),
	colFlagUp(0),
	colFlagBottom(0),
	colL(0),
	colR(0),
	colUp(0),
	colBottom(0),
	colNL(0),
	colNR(0),
	colNUp(0),
	colNBottom(0)

{
	m_pPlayer = new Player;
	m_pEnemy = new Enemy;
	m_pStage = new Stage;
}

GameManager::~GameManager()
{
	delete m_pPlayer;
	delete m_pEnemy;
	delete m_pStage;
}

void GameManager::init()
{
	m_gimmickFrame = 0;
	m_shrink = 60;
	m_inflate = 60;
	m_GameOverCount = 30;
	GameOver = false;
	GameClear = false;
	colFlagL = false;
	colFlagR = false;
	colFlagUp = false;
	colFlagBottom = false;
	colL = false;
	colR = false;
	colUp = false;
	colBottom = false;
	colNL = false;
	colNR = false;
	colNUp = false;
	colNBottom = false;

	m_pPlayer->init();
	m_pEnemy->init();
	m_pStage->init();
}

void GameManager::end()
{
	m_pPlayer->end();
	m_pEnemy->end();
	m_pStage->end();
}

void GameManager::update()
{
	collision();
	colEnemy();
	
	if (colFlagL || colFlagR || colFlagUp || colFlagBottom)
	{
		m_GameOverCount--;
		if (m_GameOverCount <= 0)
		{
			m_GameOverCount = 0;
			if (m_GameOverCount == 0)
			{
				GameOver = true;
			}
		}
	}
	if (!colFlagL && !colFlagR && !colFlagUp && !colFlagBottom)
	{
		m_GameOverCount = 30;
	}

	if (!GameOver)
	{
		m_pPlayer->operation(colL, colR, colUp, colBottom);
	}
	else if (GameOver)
	{
		m_pPlayer->m_speedX = 0;
		m_pPlayer->m_speedY = 0;
		printfDx("GameOver\n");
	}

	if (GameClear)
	{
		m_pPlayer->m_speedX = 0;
		m_pPlayer->m_speedY = 0;
		printfDx("GameClear\n");
	}
	
	//m_pEnemy->operation(colNL, colNR, colNUp, colNBottom);

	m_pPlayer->update();
	m_pEnemy->update();
	m_pEnemy->moveWidth(colNL, colNR);
	//m_pEnemy->moveHeight(colNUp, colNBottom);
	m_pStage->update();

	
}

void GameManager::draw()
{
	m_pEnemy->draw();
	m_pStage->draw();
	m_pPlayer->draw();
	//printfDx("%d\n", m_GameOverCount);
}

void GameManager::collision()
{
	collisionR();
	collisionL();
	collisionUP();
	collisionBottom();
	collisionEnemy();
	collisionGameOver();
	collisionGameClear();
}

// ----------------------------------------------
// 当たり判定
// ----------------------------------------------

// **********************************************
// プレイヤー
// **********************************************

// 右
void GameManager::collisionR()
{
	for (int y = 0; y < PLAYER_HEIGHT; y++)
	{
		for (int x = 0; x < PLAYER_WIDTH; x++)
		{
			if (m_pPlayer->m_player[y][x] != 0)
			{
				if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x + 1)] == 8)
				{
					colR = false;
				}
				else if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x + 1)] == 6)
				{
					colR = false;
				}
				else if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x + 1)] != 0)
				{
					colR = true;
				}
				else
				{
					colR = false;
				}
			}
		}
	}
}

// 左
void GameManager::collisionL()
{
	for (int y = 0; y < PLAYER_HEIGHT; y++)
	{
		for (int x = 0; x < PLAYER_WIDTH; x++)
		{
			if (m_pPlayer->m_player[y][x] != 0)
			{
				if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x - 1)] == 8)
				{
					colL = false;
				}
				else if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x - 1)] == 6)
				{
					colL = false;
				}
				else if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x - 1)] != 0)
				{
					colL = true; 
				}
				else
				{
					colL = false;
				}
			}
		}
	}
}

// 上
void GameManager::collisionUP()
{
	for (int y = 0; y < PLAYER_HEIGHT; y++)
	{
		for (int x = 0; x < PLAYER_WIDTH; x++)
		{
			if (m_pPlayer->m_player[y][x] != 0)
			{
				if (m_pStage->m_stage[m_pPlayer->m_posY + (y - 1)][m_pPlayer->m_posX + x] == 8)
				{
					colUp = false;
				}
				else if (m_pStage->m_stage[m_pPlayer->m_posY + (y - 1)][m_pPlayer->m_posX + x] == 6)
				{
					colUp = false;
				}
				else if (m_pStage->m_stage[m_pPlayer->m_posY + (y - 1)][m_pPlayer->m_posX + x] != 0)
				{
					colUp = true; 
				}
				else
				{
					colUp = false;
				}
			}
		}
	}
}

// 下
void GameManager::collisionBottom()
{
	for (int y = 0; y < PLAYER_HEIGHT; y++)
	{
		for (int x = 0; x < PLAYER_WIDTH; x++)
		{
			if (m_pPlayer->m_player[y][x] != 0)
			{
				if (m_pStage->m_stage[m_pPlayer->m_posY + (y + 1)][m_pPlayer->m_posX + x] == 8)
				{
					colBottom = false;
				}
				else if (m_pStage->m_stage[m_pPlayer->m_posY + (y + 1)][m_pPlayer->m_posX + x] == 6)
				{
					colBottom = false;
				}
				else if (m_pStage->m_stage[m_pPlayer->m_posY + (y + 1)][m_pPlayer->m_posX + x] != 0)
				{
					colBottom = true;
				}
				else
				{
					colBottom = false;
				}
			}
		}
	}
}

// ギミック5:膨らんだら即死判定
void GameManager::collisionBulge()
{
	EnemyElasticity();
	if (m_gimmickFrame > m_inflate)
	{
		for (int y = 0; y < PLAYER_HEIGHT; y++)
		{
			for (int x = 0; x < PLAYER_WIDTH; x++)
			{
				if (m_pPlayer->m_player[y][x] != 0)
				{
					// 右
					if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x + 1)] == 5)
					{
						GameOver = true;
					}
					// 左
					if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x - 1)] == 5)
					{
						GameOver = true;
					}
					// 上
					if (m_pStage->m_stage[m_pPlayer->m_posY + (y - 1)][m_pPlayer->m_posX + x] == 5)
					{
						GameOver = true;
					}
					// 下
					if (m_pStage->m_stage[m_pPlayer->m_posY + (y + 1)][m_pPlayer->m_posX + (x - 1)] == 5)
					{
						GameOver = true;
					}
					// 右上
					if (m_pStage->m_stage[m_pPlayer->m_posY + (y - 1)][m_pPlayer->m_posX + (x + 1)] == 5)
					{
						GameOver = true;
					}
					// 左上
					if (m_pStage->m_stage[m_pPlayer->m_posY + (y - 1)][m_pPlayer->m_posX + (x - 1)] == 5)
					{
						GameOver = true;
					}
					// 右下
					if (m_pStage->m_stage[m_pPlayer->m_posY + (y + 1)][m_pPlayer->m_posX + (x + 1)] == 5)
					{
						GameOver = true;
					}
					// 左下
					if (m_pStage->m_stage[m_pPlayer->m_posY + (y - 1)][m_pPlayer->m_posX + (x - 1)] == 5)
					{
						GameOver = true;
					}
				}
			}
		}
		//printfDx("当たり判定有り\n");
	}
}

// ギミック7:数フレーム後に針が出てゲームオーバーになる判定
void GameManager::collisionTimeLag()
{
	for (int y = 0; y < PLAYER_HEIGHT; y++)
	{
		for (int x = 0; x < PLAYER_WIDTH; x++)
		{
			if (m_pPlayer->m_player[y][x] != 0)
			{
				// 右
				if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x + 1)] == 7)
				{
					colFlagR = true;
				}
				else if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x + 1)] != 7)
				{
					colFlagR = false;
				}
				// 左
				if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x - 1)] == 7)
				{
					colFlagL = true;
				}
				else if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + (x - 1)] != 7)
				{
					colFlagL = false;
				}
				// 上
				if (m_pStage->m_stage[m_pPlayer->m_posY + (y - 1)][m_pPlayer->m_posX + x] == 7)
				{
					colFlagUp = true;
				}
				else if (m_pStage->m_stage[m_pPlayer->m_posY + (y - 1)][m_pPlayer->m_posX + x] != 7)
				{
					colFlagUp = false;
				}
				// 下
				if (m_pStage->m_stage[m_pPlayer->m_posY + (y + 1)][m_pPlayer->m_posX + x] == 7)
				{
					colFlagBottom = true;
				}
				else if (m_pStage->m_stage[m_pPlayer->m_posY + (y + 1)][m_pPlayer->m_posX + x] != 7)
				{
					colFlagBottom = false;
				}
			}
		}
	}
}

// 敵
void GameManager::collisionEnemy()
{
	if (m_pPlayer->m_posX == m_pEnemy->m_posX && m_pPlayer->m_posY == m_pEnemy->m_posY)
	{
		GameOver = true;
	}

}

// ゲームオーバー
void GameManager::collisionGameOver()
{
	collisionBulge();
	collisionTimeLag();
	for (int y = 0; y < PLAYER_HEIGHT; y++)
	{
		for (int x = 0; x < PLAYER_WIDTH; x++)
		{
			if (m_pPlayer->m_player[y][x] != 0)
			{
				// ギミック6:即死判定
				if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + x] == 6)
				{
					GameOver = true;
				}
			}
		}
	}
}

// ゲームクリア
void GameManager::collisionGameClear()
{
	for (int y = 0; y < PLAYER_HEIGHT; y++)
	{
		for (int x = 0; x < PLAYER_WIDTH; x++)
		{
			if (m_pPlayer->m_player[y][x] != 0)
			{
				if (m_pStage->m_stage[m_pPlayer->m_posY + y][m_pPlayer->m_posX + x] == 8)
				{
					GameClear = true;
				}
			}
		}
	}
}

// **********************************************
// エネミー
// **********************************************
// 全体
void GameManager::colEnemy()
{
	colEnemyR();
	colEnemyL();
	//colEnemyUP();
	//colEnemyBottom();
}

// 右
void GameManager::colEnemyR()
{
	for (int y = 0; y < ENEMY_HEIGHT; y++)
	{
		for (int x = 0; x < ENEMY_WIDTH; x++)
		{
			if (m_pEnemy->m_enemy[y][x] != 0)
			{
				if (m_pStage->m_stage[m_pEnemy->m_posY + y][m_pEnemy->m_posX + (x + 1)] != 0)
				{
					m_pEnemy->m_frameX = -20;
					colNR = true;
				}
				else
				{
					colNR = false;
				}
			}
		}
	}
}

// 左
void GameManager::colEnemyL()
{
	for (int y = 0; y < ENEMY_HEIGHT; y++)
	{
		for (int x = 0; x < ENEMY_WIDTH; x++)
		{
			if (m_pEnemy->m_enemy[y][x] != 0)
			{
				if (m_pStage->m_stage[m_pEnemy->m_posY + y][m_pEnemy->m_posX + (x - 1)] != 0)
				{
					colNL = true;
				}
				else
				{
					colNL = false;
				}
			}
		}
	}
}

// 上
void GameManager::colEnemyUP()
{
	for (int y = 0; y < ENEMY_HEIGHT; y++)
	{
		for (int x = 0; x < ENEMY_WIDTH; x++)
		{
			if (m_pEnemy->m_enemy[y][x] != 0)
			{
				if (m_pStage->m_stage[m_pEnemy->m_posY + (y - 1)][m_pEnemy->m_posX + x] != 0)
				{
					//m_pEnemy->m_frameY = 520;
					colNUp = true;
				}
				else
				{
					colNUp = false;
				}
			}
		}
	}
}

// 下
void GameManager::colEnemyBottom()
{
	for (int y = 0; y < ENEMY_HEIGHT; y++)
	{
		for (int x = 0; x < ENEMY_WIDTH; x++)
		{
			if (m_pEnemy->m_enemy[y][x] != 0)
			{
				if (m_pStage->m_stage[m_pEnemy->m_posY + (y + 1)][m_pEnemy->m_posX + x] != 0)
				{
					colNBottom = true;
				}
				else
				{
					colNBottom = false;
				}
			}
		}
	}
}

void GameManager::EnemyElasticity()
{
	// ギミックの当たり判定変更処理
	m_gimmickFrame++;
	if (m_gimmickFrame >= m_shrink + m_inflate)
	{
		m_gimmickFrame = 0;
	}
}
