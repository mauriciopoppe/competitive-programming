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

int f[110][4];
char w[5000];
int size;
map<int, bool> m;
int solve(int t, int number)
{
	if(m[number]) return 9999;
	m[number] = 1;
	for(int i = 0; i < size; ++i)
		if(f[i][0] == number && t >= f[i][1] && t <= f[i][1] + f[i][2])
			return solve(t, f[i][3]);
	return number;
}

int main()
{	
	int cas;
	puts("CALL FORWARDING OUTPUT");
	scanf("%d", &cas);
	gets(w);
	for(int z = 0; z < cas; ++z)
	{
		size = 0;
		while(gets(w) && strcmp(w, "0000"))
		{
			char *ptr = strtok(w, " ");
			for(int i = 0; i < 4; ++i)
			{
				f[size][i] = atoi(ptr);
				ptr = strtok(NULL, " ");
			}
			++size;
		}
		printf("SYSTEM %d\n", z + 1);
		while(gets(w) && strcmp(w, "9000"))
		{
			int t, number;
			char *ptr = strtok(w, " ");
			t = atoi(ptr);
			ptr = strtok(NULL, " ");
			number = atoi(ptr);
			m.clear();
			printf("AT %04d CALL TO %04d RINGS %04d\n", t, number, solve(t, number));
		}
	}
	puts("END OF OUTPUT");
	return 0;
}
