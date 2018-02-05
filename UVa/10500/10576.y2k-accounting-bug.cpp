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
int post[2];
int v[5000][12], size;
int t[12];
void bt(int k)
{
	if(k == 12)
		memcpy(v[size++], t, 48);
	else
	{
		t[k] = 1;
		bt(k + 1);
		t[k] = 0;
		bt(k + 1);
	}
}

int main()
{
	size = 0;
	bt(0);
	while(scanf("%d%d", &post[0], &post[1]) != EOF)
	{
		int mx = -1;
		post[1] = -post[1];
		for(int i = 0; i < size; ++i)
		{
			for(int j = 0; j < 12; ++j)
				t[j] = post[v[i][j]];
			
			int deficit = 1;
			for(int j = 0; j <= 7 && deficit; ++j)
			{
				int sum = 0;
				for(int k = j; k < j + 5; ++k)
					sum += t[k];
				deficit &= sum < 0;
			}
			
			if(!deficit) continue;
			
			int total = 0;
			for(int j = 0; j < 12; ++j)
				total += t[j];
			
			mx = max(mx, total);
		}
		if(mx <= 0)
			puts("Deficit");
		else
			printf("%d\n", mx);
	}
	return 0;
}
