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
#include<functional>
#include<numeric>
#include<utility>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define MP make_pair
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;

char fig[15];
double v[15][4],px,py;

bool checkR(int i)
{
     if(px>v[i][0] && px<v[i][2]
     && py<v[i][1] && py>v[i][3])return 1;
     return 0;
}

bool checkC(int i)
{
     if((v[i][0]-px)*(v[i][0]-px)+(v[i][1]-py)*(v[i][1]-py)<v[i][2]*v[i][2])return 1;
     return 0;
}

int main()
{
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

    char c,j=0;
    while(cin>>c && c!='*')
    {
        fig[j]=c;                     
        if(c=='r')
             F(i,4)cin>>v[j][i];    
        else
             F(i,3)cin>>v[j][i]; 
        ++j;                    
    }

    int count,f,cas=1;
    while(1)
    {                      
         cin>>px>>py;
         //cout<<px<<" "<<py<<endl;
         //system("pause");
         if(px==9999.9 && py==9999.9)break;
         count=0;
         F(i,j)
         {
              f=0; 
              if(fig[i]=='r')
              {
                  if(checkR(i))f=1;           
              }
              else
              {
                  if(checkC(i))f=1;
              } 
              if(f)
              {
                   ++count;
                   printf("Point %d is contained in figure %d\n",cas,i+1);
              }
         }
         if(!count)
            printf("Point %d is not contained in any figure\n",cas);         
         ++cas;
    }
    return 0;
}
