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
int n, p;
vector<string> words;
vector<string> speech;
vector<vector<string> > avoid;
map<string, int> already_in_speech;
map<string, int> word_to_number;

bool cmp(const string &a, const string &b)
{
	int s1 = a.size(), s2 = b.size();
	if(s1 != s2) return s1 > s2;
	return a < b;
}

int check_word(string &w)
{
	int k = word_to_number[w];
	TR(avoid[k], it)
		if(already_in_speech[*it])
			return 0;
	return 1;
}

void bt(int k, int size)
{
	if(size == p)
	{
		for(int i = 0; i < size; ++i)
		{
			if(i)putchar(' ');
			printf("%s", speech[i].c_str());
		}
		NL;
	}
	else
	{
		for(int i = k; i < n; ++i)
		{
			if(check_word(words[i]))
			{
				already_in_speech[words[i]] = 1;
				speech.push_back(words[i]);
				bt(i + 1, size + 1);
				already_in_speech.erase(words[i]);
				speech.erase(speech.begin() + size);		
			}
		}
	}
}

int main()
{	
	int cas, q;
	string w, x, y;
	scanf("%d", &cas);
	for(int z = 0; z < cas; ++z)
	{
		scanf("%d%d%d", &n, &q, &p);
		set<string> st;
		for(int i = 0; i < n; ++i)
		{
			cin >> w;
			for(int j = 0; w[j]; ++j)
				w[j] = toupper(w[j]);
			st.insert(w);
		}
		vector<string> temp(ALL(st));
		words = temp;
		sort(ALL(words), cmp);
		
		//fix the new size
		n = words.size();
		
		//map a word to a number
		word_to_number.clear();
		for(int i = 0; i < n; ++i)
			word_to_number[words[i]] = i;
		
		//clear these avoid helpers
		avoid.clear();
		avoid.resize(words.size());
		for(int i = 0; i < q; ++i)
		{
			cin >> x >> y;
			for(int j = 0; x[j]; ++j)
				x[j] = toupper(x[j]);
			for(int j = 0; y[j]; ++j)
				y[j] = toupper(y[j]);
			avoid[word_to_number[x]].push_back(y);
			avoid[word_to_number[y]].push_back(x);
		}
		
		speech.clear();
		already_in_speech.clear();
		printf("Set %d:\n", z + 1);
		bt(0, 0);
		NL;
	}
	return 0;
}
