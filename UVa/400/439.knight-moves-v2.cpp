#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define M 9
using namespace std;

int val[M][M],dx[]={-2,-2,-1,1,-1,1,2,2},dy[]={-1,1,2,2,-2,-2,-1,1},x,y;
bool d[M][M];

bool check(int &i, int &j)
{
     if(i>=0 && j>=0 && j<8 && i<8)return true;
     return false;
}

int main()
{
    string w,w2;
    int x1,y1,x2,y2;
    while(cin>>w>>w2)
    {
         memset(val,-1,sizeof(val));
         memset(d,0,sizeof(d));         
         
         x1=w[0]-'a';
         y1=w[1]-'1';
         x2=w2[0]-'a';
         y2=w2[1]-'1';
         //printf("%d %d %d %d\n",x1,y1,x2,y2);
                  
         queue<pair<int,int> > q;
         pair<int,int> p;
         p=make_pair(x1,y1);
         q.push(p);
         val[x1][y1]=0;
         d[x1][y1]=1;            
         
         while(!q.empty())
         {
              p=q.front();
              q.pop();            
              for(int k=0;k<8;k++)
              {
                  x=p.first+dx[k];
                  y=p.second+dy[k];
                  
                  if(check(x,y) && !d[x][y])
                  {
                      d[x][y]=1;
                      val[x][y]=val[p.first][p.second]+1;
                      q.push(make_pair(x,y));                           
                  }    
              }            
         }            
         
         end:
         printf("To get from %s to %s takes %d knight moves.\n",w.c_str(),w2.c_str(),val[x2][y2]);    
    }
    
    return 0;
}
