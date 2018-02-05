/*
 * Author: mauricio
 * Date: Mar 11, 2012
 * Problem: 1262 - Password.cpp
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
char first[6][6], second[6][6];
int n;
set<char> words[5];

char key[6], ans[6];
int word_k;

int find_word()
{
	for(int j = 0; j < 5; ++j)
	{
		int i;
		for(i = 0; i < 6; ++i)
			if(second[i][j] == key[j])
				break;
		if(i == 6)
			return 0;
	}
	return 1;
}

void bt(int k)
{
	if(word_k == n)
		return;
	if(k == 5)
	{
		if(find_word())
		{
			++word_k;
			if(word_k == n)
				memcpy(ans, key, sizeof key);
		}
	}
	else
	{
		TR(words[k], it)
		{
			key[k] = *it;
			bt(k + 1);
		}
	}
}

int main()
{
	int cas;
	key[5] = '\0';
	scanf("%d", &cas);
	while(cas--)
	{
		scanf("%d", &n);
		for(int i = 0; i < 6; ++i)
			scanf("%s", first[i]);
		for(int i = 0; i < 6; ++i)
			scanf("%s", second[i]);

		//sort the words
		int total_words = 1;
		for(int j = 0; j < 5; ++j)
		{
			words[j].clear();
			for(int i = 0; i < 6; ++i)
				words[j].insert(first[i][j]);
			total_words *= words[j].size();
		}

		/*for(int i = 0; i < 5; ++i)
		{
			TR(words[i], it)
				printf("%c ", *it);
			NL;
		}
		printf("%d\n", total_words);*/
		if(n > total_words)
		{
			puts("NO");
			continue;
		}

		word_k = 0;
		bt(0);
		key[5] = '\0';
		if(word_k == n)
			printf("%s\n", ans);
		else
			puts("NO");
	}
	return 0;
}
