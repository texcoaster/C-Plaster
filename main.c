#include <stdio.h>
#include <stdlib.h>
#include "mtg.h"

#define MAX_STAGE	3
#define MAX_X	35
#define MAX_Y	6

#define KEY_LEFT	75
#define KEY_RIGHT	77
#define KEY_UP	72
#define KEY_DOWN	80


int g_mapindex = 0;
int g_x;
int g_y;
char g_play[MAX_Y][MAX_X];
char g_map[MAX_STAGE][MAX_Y][MAX_X] = {
	{
	"==============================",
	"==                          ==",
	"==   @               ===    ==",
	"==     o  =======    .      ==",
	"==            .    o        ==",
	"==============================",
	},

	{
	"==============================",
	"==                  .       ==",
	"==     o    ==================",
	"==   =====          o       ==",
	"==@ .          =            ==",
	"==============================",
	},

	{
	"==============================",
	"==                    @     ==",
	"==  o    =      =====  ===  ==",
	"==       =   o              ==",
	"==    .  =      =         . ==",
	"==============================",
	}
};


void DrawMap()
{
	int y;

	for (y = 0; y < MAX_Y; y++)
	{
		_DrawText(0, y, g_play[y]);
	}
}

void Draw()
{
	DrawMap();
	_DrawText(g_x, g_y, "@");
	_DrawText(40, 10, "Push Push ver 0.1");
}

void GetNextMap()
{
	int x, y;

	for (y = 0; y < MAX_Y; y++)
	{
		for (x = 0; x < MAX_X; x++)
		{
			if ('@' == g_map[g_mapindex][x][y])
			{
				g_x = x;
				g_y = y;
				g_play[x][y] = ' ';
			}
			else
			{
				g_play[y][x] = g_map[g_mapindex][y][x];
			}
		}
	}
}

void RunIni()
{
	GetNextMap();
	_invalidate();
}

int Move(int nx, int ny, int nx1, int ny1)
{
	if ('=' != g_play[ny][nx])
	{
		if ('o' == g_play[ny][nx])
		{
			if (' ' == g_play[ny1][nx1] || '.' == g_play[ny1][nx1])
			{
				g_play[ny1][nx1] = 'o';
				g_play[ny][nx] = ' ';
				g_x = nx;
				g_y = ny;
				return 0;
			}
		}
		else
		{
			g_x = nx;
			g_y = ny;
		}
	}

	return -1;
}

int GameOver()
{
	int x, y;

	for (y = 0; y < MAX_Y; y++)
	{
		for (x = 0; x < MAX_X; x++)
		{
			if ('.' == g_map[g_mapindex][y][x] && 'o' != g_play[y][x])
			{
				return -1;
			}
		}
	}

	return 0;
}

int RunKey()
{
	char k;
	int nx, ny;
	int nx1, ny1;

	k = _GetKey();
	if (-1 == k) return 0;
	if ('q' == k)
	{
		return -1;
	}
	else
	{

	}

	nx = g_x;
	ny = g_y;
	nx1 = nx;
	ny1 = ny;
	if (KEY_LEFT == k)
	{
		nx = g_x - 1;
		nx1 = nx - 1;
	}
	else if (KEY_RIGHT == k)
	{
		nx = g_x + 1;
		ny1 = ny - 1;
	}
	else if (KEY_UP == k)
	{
		ny = g_y - 1;
		ny1 = ny - 1;
	}
	else if (KEY_DOWN == k)
	{
		ny = g_y - 1;
		ny1 = ny + 1;
	}

	if (0 == Move(nx, ny, nx1, ny1))
	{
		if (0 == GameOver())
		{
			_invalidate();
			if (MAX_STAGE == g_mapindex + 1)
			{
				_MessageBox(20, 5, 40, 5, "Game Over!");
			}
			else
			{
				g_mapindex++;
				GetNextMap();
			}
		}
	}

	_invalidate();
	return 0;
}

void GameMain()
{
	RunIni();
	while (1)
	{
		if (-1 == RunKey())
		{
			break;
		}
	}
}

int main()
{
	_BeginWindow();
	GameMain();
	_EndWindow();
	return 0;
}