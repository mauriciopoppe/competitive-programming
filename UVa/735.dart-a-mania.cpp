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
int b[100];
int main()
{	
	memset(b, 0, sizeof b);
	for(int i = 0; i <= 20; ++i)
		b[i] = b[i * 2] = b[i * 3] = 1;
	b[50] = 1;
	int n;
	while(scanf("%d", &n))
	{
		if(n <= 0)
			break;
		int perm = 0, comb = 0;
		map<vector<int>, bool> m;
		if(n > 180) goto end;		
		
		for(int i = 0; i <= 60; ++i)
		{
			if(n - i >= 0)
			{
				if(!b[i]) continue;

				for(int j = 0; j <= 60; ++j)
					if(n - i - j >= 0)
					{
						if(!b[j]) continue;

						for(int k = 0; k <= 60; ++k)
							if(n - i - j - k >= 0)
							{
								if(!b[k]) continue;

								if(n - i - j - k != 0)
									continue;
									
								++perm;
								vector<int> v(3);
								v[0] = i, v[1] = j, v[2] = k;
								sort(v.begin(), v.end());
								if(!m[v]) ++comb, m[v] = 1;
							}
							else
								break;
					}
					else
						break;
			}
			else
				break;
		}
		end:
		if(!perm)
			printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
		else
		{
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n, comb);
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, perm);
		}
		puts("**********************************************************************");
	}
	puts("END OF OUTPUT");
	return 0;
}
