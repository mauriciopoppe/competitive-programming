#include<stdio.h>
#include<stdlib.h>
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
int board[5][5];
int temp[5];
int best[5];

int calc()
{
	int sum = 0;
	for(int i = 0; i < 5; ++i)
			for(int j = 0; j < 5; ++j)
				if(board[i][j])
				{
					int mn = 1000000000;
					for(int k = 0; k < 5; ++k)
					{
						int row = temp[k] / 5;
						int col = temp[k] % 5;		
						mn= min(mn, (abs(i - row) + abs(j - col)) * board[i][j]);
					}
					sum += mn;
				}			
	return sum;
}

int main()
{	
	int cas, n, x, y, people;
	scanf("%d", &cas);
	while(cas--)		
	{
		scanf("%d", &n);
		
		memset(board, 0, sizeof board);
		int mn = 1000000000;
		for(int i = 0; i < n; ++i)
			scanf("%d%d%d", &x, &y, &people),
			board[x][y] = people;
		for(temp[0] = 0; temp[0] < 25; ++temp[0])
			for(temp[1] = temp[0] + 1; temp[1] < 25; ++temp[1])
				for(temp[2] = temp[1] + 1; temp[2] < 25; ++temp[2])
					for(temp[3] = temp[2] + 1; temp[3] < 25; ++temp[3])
						for(temp[4] = temp[3] + 1; temp[4] < 25; ++temp[4])
						{
							int sum = calc();
							if(sum < mn)
							{
								mn = sum;
								for(int x = 0; x < 5; ++x)
									best[x] = temp[x];
							}
						}
		for(int i = 0; i < 5; ++i)
		{
			if(i)putchar(' ');
			printf("%d", best[i]);
		}
		NL;
								
	}	
	return 0;
}
