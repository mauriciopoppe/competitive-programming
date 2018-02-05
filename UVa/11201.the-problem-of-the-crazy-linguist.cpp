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

int letter[256];
char w[10], current[10];
int len;

char vowel[] = {"aeiou"};
char consonant[] = {"bcdfghjklmnpqrstvwxyz"};
double value[] = {12.53, 1.42, 4.68, 5.86, 13.68, 0.69, 1.01, 0.70, 6.25, 0.44, 0.00, 4.97, 3.15,
					6.71, 8.68, 2.51, 0.88, 6.87, 7.98, 4.63, 3.93, 0.90, 0.02, 0.22, 0.90, 0.52};
int total;

double sum;

double get_value(char *w)
{
	w[len] = '\0';
	//printf(">> [%s]\n", w);
	double t = 0;
	for(int i = 0; i < len; ++i)
		t += (i + 1) * value[w[i] - 'a'];
	return t;
}

void bt(int k)
{
	if(k == len)
		sum += get_value(current),
		total++;
		
	else
	{
		if(k & 1)
		{
			for(int i = 0; i < 5; ++i)
				if(letter[vowel[i]])
				{
					letter[vowel[i]]--;
					current[k] = vowel[i];
					bt(k + 1);
					letter[vowel[i]]++;
				}
		}
		else
		{
			for(int i = 0; i < 21; ++i)
				if(letter[consonant[i]])
				{
					letter[consonant[i]]--;
					current[k] = consonant[i];
					bt(k + 1);
					letter[consonant[i]]++;
				}
		}
	}
}


int main()
{	
	int cas;
	scanf("%d", &cas);
	gets(w);
	while(cas--)
	{
		gets(w);
		len = strlen(w);
		fill(letter, letter + 256, 2);
		letter[w[0]]--;
		current[0] = w[0];
		
		//reset sum
		sum = 0;
		//total number of words
		total = 0;
		bt(1);
		
		if(sum / (double)total > get_value(w))
			puts("below");
		else
			puts("above or equal");
	}
	return 0;
}
