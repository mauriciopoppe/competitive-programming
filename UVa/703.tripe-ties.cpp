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
int v[150][150];
int ans[1000000][3];				

int main()
{	
	int n;
	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				scanf("%d", &v[i][j]);
		
		int size = 0;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
			{
				if(v[i][j])			//check win
				{
					for(int k = 0; k < n; ++k)
						if(v[j][k] && v[k][i])
						{
							if((i < j && j < k) ||
							   (i > j && j > k))
							   ans[size][0] = i + 1,
							   ans[size][1] = j + 1,
							   ans[size++][2] = k + 1;
							   
						}
				}
				else if(v[j][i] == 0 && v[i][j] == 0)//check tie
				{
					for(int k = 0; k < n; ++k)
						if(v[j][k] == 0 && v[k][j] == 0 &&
						   v[k][i] == 0 && v[i][k] == 0)
						{
							if((i < j && j < k))
							   ans[size][0] = i + 1,
							   ans[size][1] = j + 1,
							   ans[size++][2] = k + 1;							   
						}
				}
			}
		printf("%d\n", size);
		for(int i = 0; i < size; ++i)
			printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
	}
	return 0;
}
