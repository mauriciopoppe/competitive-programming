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
map<char, bool> mark;

string parse(string w)
{
     for(int i = 0; w[i]; ++i)
     {
         if(isalpha(w[i])) w[i] = tolower(w[i]);
         else if(mark[w[i]]) w[i] = ' ';            
     }
     return w;
}

int main()
{
    mark[','] = 1;
    mark['.'] = 1;
    mark[':'] = 1;
    mark[';'] = 1;
    mark['!'] = 1;
    mark['?'] = 1;
    mark['"'] = 1;
    mark['('] = 1;
    mark[')'] = 1;

    string line, w;
    getline(cin, line);
    while(line != "****END_OF_INPUT****")
    {
         if(line == "****END_OF_TEXT****")
         {
             puts("0 0.0 0");
             getline(cin, line);
             continue;
         }
         line = parse(line);
         while(getline(cin, w) && w != "****END_OF_TEXT****")
              line += " " + parse(w);
         
         //solve text
         stringstream ss(line);
         string buf;
         map<string, int> words;
         int total_words = 0;
         puts("{");
         while(ss >> buf)
         {
             printf("[%s]\n", buf.c_str());     
             ++total_words;
             ++words[buf];
         }
         puts("}");
         
         if(total_words == 0)
         {
              puts("0 0.0 0");
              getline(cin, line);
              continue;
         }
                  
         double Et = 1.0 / (double)total_words;
         double sum = 0;
         double log_n = log10(total_words);
         TR(words, it)
            sum += (double)it->second * (log_n - log10(it->second));
         Et *= sum;
         printf("%d %.1lf %d\n", total_words, Et, (int)(Et / log_n * 100.0));
         getline(cin, line);
    }
    return 0;
}
