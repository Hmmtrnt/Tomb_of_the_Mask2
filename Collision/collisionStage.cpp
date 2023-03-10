#include "collisionStage.h"
#include "../Object/Player.h"
#include "../Object/Stage.h"

collisionStage::collisionStage()/* :
	colR(false),
	colL(false),
	colUp(false),
	colBottom(false)*/
{
}

collisionStage::~collisionStage()
{
}

void collisionStage::collision(bool colR, bool colL, bool colUp, bool colBottom,
	const int player[][kVariable::PlayerWidth], int playerWidth,
	int posY, int posX, 
	const int stage[][kVariable::StageWidth])
{
	collisionR(colR, player, playerWidth, posY, posX, stage);
	collisionL(colL, player, playerWidth, posY, posX, stage);
	collisionUP(colUp, player, playerWidth, posY, posX, stage);
	collisionBottom(colBottom, player, playerWidth, posY, posX, stage);
}

void collisionStage::collisionR(bool colR, 
	const int player[][kVariable::PlayerWidth], int playerWidth,
	int posY, int posX,
	const int stage[][kVariable::StageWidth])
{
	for (int y = 0; y < playerWidth; y++)
	{
		for (int x = 0; x < playerWidth; x++)
		{
			if (player[y][x] != 0)
			{
				if (stage[posY + y][posX + (x + 1)] == 8)
				{
					colR = false;
				}
				else if (stage[posY + y][posX + (x + 1)] == 6)
				{
					colR = false;
				}
				else if (stage[posY + y][posX + (x + 1)] != 0)
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

void collisionStage::collisionL(bool colL,
	const int player[][kVariable::PlayerWidth], int playerWidth,
	int posY, int posX,
	const int stage[][kVariable::StageWidth])
{
	for (int y = 0; y < playerWidth; y++)
	{
		for (int x = 0; x < playerWidth; x++)
		{
			if (player[y][x] != 0)
			{
				if (stage[posY + y][posX + (x - 1)] == 8)
				{
					colL = false;
				}
				else if (stage[posY + y][posX + (x - 1)] == 6)
				{
					colL = false;
				}
				else if (stage[posY + y][posX + (x - 1)] != 0)
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

void collisionStage::collisionUP(bool colUp,
	const int player[][kVariable::PlayerWidth], int playerWidth,
	int posY, int posX,
	const int stage[][kVariable::StageWidth])
{
	for (int y = 0; y < playerWidth; y++)
	{
		for (int x = 0; x < playerWidth; x++)
		{
			if (player[y][x] != 0)
			{
				if (stage[posY + (y - 1)][posX + x] == 8)
				{
					colUp = false;
				}
				else if (stage[posY + (y - 1)][posX + x] == 6)
				{
					colUp = false;
				}
				else if (stage[posY + (y - 1)][posX + x] != 0)
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

void collisionStage::collisionBottom(bool colBottom,
	const int player[][kVariable::PlayerWidth], int playerWidth,
	int posY, int posX,
	const int stage[][kVariable::StageWidth])
{
	for (int y = 0; y < playerWidth; y++)
	{
		for (int x = 0; x < playerWidth; x++)
		{
			if (player[y][x] != 0)
			{
				if (stage[posY + (y + 1)][posX + x] == 8)
				{
					colBottom = false;
				}
				else if (stage[posY + (y + 1)][posX + x] == 6)
				{
					colBottom = false;
				}
				else if (stage[posY + (y + 1)][posX + x] != 0)
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
