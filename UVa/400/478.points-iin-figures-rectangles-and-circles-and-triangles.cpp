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
const double EP=0.000001;
char fig[15];
double v[15][8],px,py;

double area(double x0, double y0, double x1, double y1, double x2, double y2)
{
       return fabs((x1-x0)*(y2-y0)-(x2-x0)*(y1-y0));
}

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

bool checkT(int i)
{
     double total=area(v[i][0],v[i][1],v[i][2],v[i][3],v[i][4],v[i][5]);
     double a1=area(px,py,v[i][2],v[i][3],v[i][4],v[i][5]);
     double a2=area(v[i][0],v[i][1],px,py,v[i][4],v[i][5]);
     double a3=area(v[i][0],v[i][1],v[i][2],v[i][3],px,py);
     
     if( (fabs(total-a1-a2-a3)<=EP) && (a1>EP) && (a2>EP) && (a3>EP))return 1;
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
        else if(c=='c')
             F(i,3)cin>>v[j][i]; 
        else 
             F(i,6)cin>>v[j][i];
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
              else if(fig[i]=='c')
              {
                  if(checkC(i))f=1;
              } 
              else
              {
                  v[i][6]=px;
                  v[i][7]=py;
                  if(checkT(i))f=1;    
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
