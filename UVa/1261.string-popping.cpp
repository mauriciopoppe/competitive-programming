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
string w;
struct st{
	int n;
	char c;
};

vector<st> v;

void print()
{
	int size = v.size();
	TR(v, it)
	   printf("%d[%c] ", it->n, it->c);NL;
	SP;
}

int valid;
void bt()
{
	if(valid) return;
	int size = v.size();
	if(size == 1) valid = 1;
	else
	{
		for(int i = 1; i < size - 1 && !valid; ++i)
		{
			if(v[i].n >= 2)
			{
				//grab left and right siblings
				st L = {v[i - 1].n, v[i - 1].c};
				st R = {v[i + 1].n, v[i + 1].c};
				st erased = v[i];

				if(L.c == R.c)
				{
					st M = {L.n + R.n, L.c};
					v.erase(v.begin() + i - 1, v.begin() + i + 2);
					v.insert(v.begin() + i - 1, M);
					//print();
					bt();					
					v.erase(v.begin() + i - 1);
					v.insert(v.begin() + i - 1, L);
					v.insert(v.begin() + i, erased);
					v.insert(v.begin() + i + 1, R);
					//puts("AFTER");
					//print();
				}
				else
				{					
					v.erase(v.begin() + i);
					//print();
					bt();
					v.insert(v.begin() + i, erased);
					//puts("AFTER");
					//print();
				}
			}
		}
	}
}

int main()
{	
	string w;
	int cas;
	scanf("%d", &cas);
	while(cas--)
	{
		cin >> w;
		
		//struct initializer
		st sequence = {1, w[0]};
		st dummy = {1, 'c'};
		
		v.clear();
		v.push_back(dummy);
		
		int size = w.size();
		for(int i = 1; i < size; ++i)
		{
			if(w[i] == sequence.c)
				++sequence.n;
			else
			{
				v.push_back(sequence);
				sequence.n = 1;
				sequence.c = w[i];
			}
		}
		v.push_back(sequence);
		v.push_back(dummy);
		valid = 0;
		bt();
		printf("%d\n", valid);
	}
	return 0;
}
