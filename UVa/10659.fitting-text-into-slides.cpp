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
string w;
int x, y;

int lines;
vector<vector<int> > size;
vector<int> par_size;

int rows_per_paragraph(int i, int points)
{
    //a a
    //16 8
    int row = 1, j = 0;
    int col = 0;
    int new_size;
    while(j < par_size[i])
    {
        //try to put it in the row
        if(col == 0)
           new_size = size[i][j] * points;
        else
           new_size = (size[i][j] + 1) * points;
        
        if(col + new_size <= x)
           col += new_size;
        else
        {
           col = 0;
           ++row;
           --j;
        }
        ++j;
    }
    return row;
}

int solve(int points)
{
    //printf("%d %d\n", max_col, max_row);
    if(lines * points > y)
       return 0;
    //can a single word be on a line?
    for(int i = 0; i < lines; ++i)
        for(int j = 0; j < par_size[i]; ++j)
           if(size[i][j] * points > x)
              return 0;
    
    int total_rows = 0;
    for(int i = 0; i < lines; ++i)
       total_rows += rows_per_paragraph(i, points);
    if(total_rows * points <= y)
       return 1;
    return 0;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int cas;
    scanf("%d", &cas);    
    
    while(cas--)
    {
        scanf("%d", &lines);
        getline(cin, w);
        size.clear();
        par_size.clear();
        for(int i = 0; i < lines; ++i)
        {                
            getline(cin, w);
            stringstream ss(w);
            string buf;
            int c = 0;
            size.push_back(vector<int>());
            while(ss >> buf)
            {
                size[i].push_back(buf.size());
                ++c;
            }
            par_size.push_back(c);
        }
        scanf("%d%d", &x, &y);
        
        int i = 28;
        for(; i >= 8; --i)
           if(solve(i))
              break;
        if(i >= 8)
           printf("%d\n", i);
        else
           puts("No solution");
    }
    return 0;
}
