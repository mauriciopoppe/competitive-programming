#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
using namespace std;

int wallS[4][2],wallE[4][2],x,y;
int dx[]={-1,0,0,1},dy[]={0,-1,1,0};
int val[7][7];
char par[7][7],ans[50];

void invert(int j)
{    
     j--;
     for(int i=0;i<j;i++,j--)
         swap(ans[i],ans[j]);
}

void move(int &i, int &j, char &c)
{
     if(c=='N')j++;
     else if(c=='E')i--;
     else if(c=='W')i++;
     else j--;
}

char getP(int &a, int &b, int &x, int &y)
{
    if(a==x)
    {
        if(b<y)return 'S';
        else return 'N';    
    }
    else
    {
        if(a<x)return 'E';
        else return 'W';
    } 
}

bool check(int &x, int &y)
{
     if(x>=1 && y>=1 && x<7 && y<7)return true;
     return false;
}

bool thereIsNoWall(int a, int b, int x, int y)
{
     int mn,mx;
     
     for(int i=0;i<3;i++)
     {
         if(wallS[i][1]==wallE[i][1])
         {
              mx=b,mn=y;
              if(b<y)swap(mn,mx);                       
              if(mn==wallS[i][1] && mn+1==mx && 
               x>=min(wallS[i][0],wallE[i][0])+1 && x<=max(wallE[i][0],wallS[i][0]))return false;                       
         }    
         else
         {
              mx=a,mn=x;
              if(a<x)swap(mn,mx);                       
              if(mn==wallS[i][0] && mn+1==mx && 
              y>=min(wallS[i][1],wallE[i][1])+1 && y<=max(wallS[i][1],wallE[i][1]))return false;       
         }    
     }     
     return true;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int sx,sy,ex,ey;
    while(scanf("%d%d",&sx,&sy) && sx && sy)
    {
         scanf("%d%d",&ex,&ey);
         for(int i=0;i<3;i++)
              scanf("%d%d%d%d",&wallS[i][0],&wallS[i][1],&wallE[i][0],&wallE[i][1]);
         
         memset(par,'A',sizeof(par));
         memset(val,0,sizeof(val));
         queue<int> qx,qy;
         
         qx.push(sx);
         qy.push(sy);
         val[sx][sy]=1;
         //printf("%d\n",val[ex][ey]);
         while(!qx.empty())
         {
              int a=qx.front(),b=qy.front();
              //printf("\n[%d %d]\n",a,b);
              qx.pop();
              qy.pop();
              for(int k=0;k<4;k++)
              {
                  x=a+dx[k];            
                  y=b+dy[k];
                  //printf("%d %d\n",x,y);
                  if(check(x,y) && thereIsNoWall(a,b,x,y) && !val[x][y])
                  {
                       //printf("IN %d %d\n",x,y);         
                       val[x][y]=val[a][b]+1;
                       par[x][y]=getP(a,b,x,y);
                       qx.push(x);         
                       qy.push(y);
                  }                  
              }    
              if(val[ex][ey])break;
              //system("pause");
         }
         
         if(val[ex][ey])
         {
             int j=0;
             while(par[ex][ey]!='A')
             {
                  ans[j++]=par[ex][ey];
                  move(ex,ey,par[ex][ey]);                  
             }
             invert(j);
             ans[j]='\0';
             printf("%s\n",ans);       
         }                
         else printf("No Exit\n"); 
    }
    return 0;
}
