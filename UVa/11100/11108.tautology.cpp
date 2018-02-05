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
char w[150];
char L[10];
bool in[10];
int len, good;
bool value[10];

int solve()
{
	stack<int> s;
	int v1, v2;
	for(int i = len - 1; i >= 0; --i)
	{
		if(islower(w[i]))
		   s.push(value[w[i] - 'p']);
		else
		{
			switch(w[i])
			{
				case 'K':
					v2 = s.top();
					s.pop();
					v1 = s.top();
					s.pop();
					s.push(v2 & v1);
					break;
					
				case 'A':
					v2 = s.top();
					s.pop();
					v1 = s.top();
					s.pop();
					s.push(v2 | v1);					
					break;
					
				case 'N':
					v1 = s.top();
					s.pop();
					s.push(!v1);
					break;
					
				case 'C':
					v2 = s.top();
					s.pop();
					v1 = s.top();
					s.pop();
					s.push(!v2 | v1);					
					break;
					
				case 'E':
					v2 = s.top();
					s.pop();
					v1 = s.top();
					s.pop();
					s.push(v2 == v1);					
					break;
			}
		}
	}
	return s.top();
}

int main()
{	
	while(gets(w) && strcmp(w, "0"))
	{
		//count total number of Ls
		memset(in, 0, sizeof in);
		int var = 0;
		len = strlen(w);
		for(int i = 0; w[i]; ++i)
			if(islower(w[i]) && !in[w[i] - 'p'])
				in[w[i] - 'p'] = 1,
				L[var++] = w[i];
		
		int total_permutations = 1 << var;
		good = 1;
		for(int i = 0; i < total_permutations && good; ++i)
		{
			memset(value, 0, sizeof value);
			//printf("%d\n", i);
			for(int j = 0; j < var; ++j)				
				if(i & (1 << j))
				//{
					//printf(">> %c\n", L[j]);
					value[L[j] - 'p'] = 1;
				//}
					
			//for(int j = 0; j < var; ++j)
			//	printf("[%c]%d ", L[j], value[j]);NL;
			
			good &= solve();
		}
		if(good) puts("tautology");
		else puts("not");
	}
	return 0;
}
