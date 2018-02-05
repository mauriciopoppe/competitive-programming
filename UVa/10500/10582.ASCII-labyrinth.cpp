/*
 * Author: mauricio
 * Date: Mar 9, 2012
 * Problem: 10582 - ASCII Labyrinth.cpp
 */
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<stack>
#include<sstream>
#include<utility>
#include<numeric>
#include<functional>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define MP make_pair
#define NL printf("\n")
#define SP system("pause")
#define IMAX 2147483647
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;
typedef pair<int, int> pii;

#define LEFT 1
#define UP 2
#define RIGHT 3
#define DOWN 4

int dx[] = {0, 0, -1, 0, 1}, dy[] = {0, -1, 0, 1, 0};

struct cell{
	int pipe[2];
} m[15][15];

int row, col;
int total = 0;
char board[100][100];
int type[15][15];
bool taken[15][15];
/*
 *	type = 1 (-)
 *	type = 2 (|)
 */
void reset()
{
	for(int i = 0; i < 15; ++i)
		for(int j = 0; j < 15; ++j)
			m[i][j].pipe[0] = m[i][j].pipe[1] = 0,
			board[i][j] = 0, taken[i][j] = 0;
}

void print()
{
	for(int i = 1; i <= row; ++i)
	{
		for(int j = 1; j <= col; ++j)
		{
			char x='-', y='-';
			if(m[i][j].pipe[0] == 1) x = 'L';
			if(m[i][j].pipe[1] == 1) y = 'L';
			if(m[i][j].pipe[0] == 2) x = 'U';
			if(m[i][j].pipe[1] == 2) y = 'U';
			if(m[i][j].pipe[0] == 3) x = 'R';
			if(m[i][j].pipe[1] == 3) y = 'R';
			if(m[i][j].pipe[0] == 4) x = 'D';
			if(m[i][j].pipe[1] == 4) y = 'D';
			printf("[%c,%c] ", x, y);
		}
		NL;
	}
}

void readInput()
{
	gets(board[0]);
	for(int i = 0; i < row; ++i)
		for(int j = 0; j < 4; ++j)
			gets(board[i * 4 + j]);
	gets(board[99]);
	int row_index = 2;
	for(int i = 1; i <= row; ++i)
	{
		int col_index = 1;
		for(int j = 1; j <= col; ++j)
		{
			if(board[row_index][col_index] == '*')
			{
				m[i][j].pipe[0] = LEFT;
				if(board[row_index + 1][col_index + 1] == '*')
					m[i][j].pipe[1] = DOWN,
					type[i][j] = 1;
				else
					m[i][j].pipe[1] = RIGHT,
					type[i][j] = 2;
			}
			col_index += 4;
		}
		row_index += 4;
	}
}

void find_next(int &target, int n)
{
	target += n;
	if(target > 4)
		target -= 4;
}

void bt(int from_x, int from_y, int to_x, int to_y)
{
	//gets(board[99]);
	//print();
	//NL;
	if(taken[to_x][to_y])
		return;
	if(to_x <= 0 || to_y <= 0)
		return;
	if(to_x == row + 1)
	{
		if(to_y == col)
			total++;
		return;
	}
	if(to_y == col + 1)
	{
		if(to_x == row)
			total++;
		return;
	}

	else
	{
		//determine where it's coming from
		int where = 0;
		if(from_x == to_x - 1)
			where = UP;
		else if(from_x == to_x + 1)
			where = DOWN;
		else if(from_y == to_y - 1)
			where = LEFT;
		else
			where = RIGHT;
		//printf("where = %d %d\n", where, type[to_x][to_y]);
		if(type[to_x][to_y] == 1) // (L)
		{
			for(int i = 0; i < 4; ++i)
			{
				//rotate the symbol
				find_next(m[to_x][to_y].pipe[0], 1);
				find_next(m[to_x][to_y].pipe[1], 1);
				if(m[to_x][to_y].pipe[0] == where)
				{
					int other = m[to_x][to_y].pipe[1];
					taken[to_x][to_y] = 1;
					bt(to_x, to_y, to_x + dx[other], to_y + dy[other]);
					taken[to_x][to_y] = 0;
				}
				if(m[to_x][to_y].pipe[1] == where)
				{
					int other = m[to_x][to_y].pipe[0];
					taken[to_x][to_y] = 1;
					bt(to_x, to_y, to_x + dx[other], to_y + dy[other]);
					taken[to_x][to_y] = 0;
				}
			}
		}
		else if(type[to_x][to_y] == 2)
		{
			for(int i = 0; i < 2; ++i)
			{
				//rotate the symbol
				find_next(m[to_x][to_y].pipe[0], 1);
				find_next(m[to_x][to_y].pipe[1], 1);
				//printf("%d %d\n", m[to_x][to_y].pipe[0], m[to_x][to_y].pipe[1]);
				if(m[to_x][to_y].pipe[0] == where)
				{
					int other = m[to_x][to_y].pipe[1];
					taken[to_x][to_y] = 1;
					bt(to_x, to_y, to_x + dx[other], to_y + dy[other]);
					taken[to_x][to_y] = 0;
				}
				if(m[to_x][to_y].pipe[1] == where)
				{
					int other = m[to_x][to_y].pipe[0];
					taken[to_x][to_y] = 1;
					bt(to_x, to_y, to_x + dx[other], to_y + dy[other]);
					taken[to_x][to_y] = 0;
				}
			}
		}
	}
}

int main()
{
	int cas;
	scanf("%d", &cas);
	while(cas--)
	{
		reset();
		scanf("%d%d", &row, &col);
		readInput();
		/*for(int i = 1; i <= row; ++i)
		{
			for(int j = 1; j <= col; ++j)
				printf("[%d,%d] ", m[i][j].pipe[0], m[i][j].pipe[1]);
			NL;
		}*/
		total = 0;
		bt(1, 0, 1, 1);
		//printf("start 2\n");
		bt(0, 1, 1, 1);
		printf("Number of solutions: %d\n", total);
	}
	return 0;
}
