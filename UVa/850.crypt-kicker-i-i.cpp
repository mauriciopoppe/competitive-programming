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
char base[150];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int cas;
    int n;
    int ind;
    string w;
    scanf("%d",&cas);
    string original = "the quick brown fox jumps over the lazy dog";
    getchar();
    gets(base);
    while(cas--)
    {
        vector<string> words;
        vector<vector<int> > num;
        n = 0;        
        while(getline(cin,w) && w.size())
        {
             words.push_back(w);
             stringstream ss(w);
             string buf;
             num.push_back(vector<int>());
             while(ss>>buf)
                num[n].push_back(buf.size());
             ++n;                
        }
        int sol = 0;
        F(i,n)
        {
           if(num[i].size() == 9
             && num[i][0] == 3       
             && num[i][1] == 5           
             && num[i][2] == 5           
             && num[i][3] == 3           
             && num[i][4] == 5           
             && num[i][5] == 4           
             && num[i][6] == 3           
             && num[i][7] == 4           
             && num[i][8] == 3)
             {
                int size = words[i].size();
                memset(base,'-',sizeof base);
                int j;
                for(j = 0; j < size; j++)
                   if(isalpha(words[i][j]))
                   {
                      if(base[words[i][j]] == '-' ||
                         base[words[i][j]] == original[j])
                      {
                         base[words[i][j]] = original[j];
                      }
                      else
                         break;
                   }
                 if(j == size)               
                    sol++;
             }
        }
        end:
        if(sol != 1)
           printf("No solution.\n");
        else
        {
            F(i,n)
            {
               int size = words[i].size();   
               F(j,size)
                 if(isalpha(words[i][j]))
                   putchar(base[words[i][j]]);
                 else putchar(' ');
               NL;
            }
        }
        if(cas)
           NL;
    }
    return 0;
}
