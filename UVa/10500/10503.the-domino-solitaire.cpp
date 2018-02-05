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
typedef pair<int, int> pii;

int n, dominos;
vector<pii> d;
vector<pii> start_end;
vector<bool> taken;
vector<pii> inside;
int flag = 0;
int size;

void bt(int k)
{
	/*for(int i = 0; i < k * 4; ++i)
		printf(" ");
	for(int i = 0; i < inside.size(); ++i)
		printf("(%d,%d) ", inside[i].first, inside[i].second);NL;*/
	
	if(flag) return;
	if(k == n)
		flag |= inside[k].second == start_end[1].first;
	else
	{
		for(int i = 1; i < size - 1 && !flag; ++i)
		{
			//printf(">>(%d,%d)\n", d[i].first, d[i].second);
			if(!taken[i] && d[i].first == inside[k].second)
			{
				taken[i] = 1;
				inside.push_back(d[i]);
				bt(k + 1);
				taken[i] = 0;
				inside.erase(inside.begin() + k + 1);
			}
			
			//rotate
			if(!taken[i] && d[i].second == inside[k].second)
			{
				taken[i] = 1;
				
				//flip				
				inside.push_back(d[i]);
				swap(inside[k + 1].first, inside[k + 1].second);
				
				bt(k + 1);
				taken[i] = 0;
				inside.erase(inside.begin() + k + 1);
			}
		}
	}
}

int main()
{	
	int x, y;
	while(scanf("%d", &n) && n)
	{
		scanf("%d", &dominos);
		//clear
		d.clear();
		start_end.clear();
		taken.clear();
		
		//resize
		d.resize(dominos);
		start_end.resize(2);
		taken.resize(dominos + 2);
		fill(ALL(taken), 0);
		
		for(int i = 0; i < 2; ++i)
			scanf("%d%d", &start_end[i].first, &start_end[i].second);
		for(int i = 0; i < dominos; ++i)
			scanf("%d%d", &d[i].first, &d[i].second);
		d.insert(d.begin(), start_end[0]);
		d.insert(d.begin() + dominos + 1, start_end[1]);
		
		/*puts("MAIN");
		for(int i = 0; i < d.size(); ++i)
			printf("(%d,%d) ", d[i].first, d[i].second);NL;
		puts("END");*/

		size = dominos + 2;
		flag = 0;
		inside.clear();
		inside.push_back(start_end[0]);
		bt(0);
		
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}
