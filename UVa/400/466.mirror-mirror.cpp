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
#define M 11

char ori[M][M],cpy[M][M],t,temp[M][M];

void flip()
{
     for(int i=t-1,j=0;i>=0;i--,j++)
        strcpy(temp[j],cpy[i]);
           
     F(i,t)
        strcpy(cpy[i],temp[i]);
     /*printf("\n");   
     F(i,t)
       printf("%s\n",cpy[i]);   */
}

int r90()
{
    int x,y;
    //printf("%d\n",t);
    int i=0,j=0;
    for(i=0,y=t-1;i<t;i++,y--)    
       for(j=0,x=0;j<t;j++,x++)
          //{printf("%d,%d  %d,%d\n",i,j,x,y);
          if(ori[i][j]!=cpy[x][y])goto end;
          //}
    end:
        if(i==t && j==t)return 1;
        return 0;    
}

int r180()
{
    int x,y;
    int i=0,j=0;
    for(i=0,x=t-1;i<t;i++,x--)    
       for(j=0,y=t-1;j<t;j++,y--)
          if(ori[i][j]!=cpy[x][y])goto end;
    end:
        if(i==t && j==t)return 1;
        return 0;    
}

int r270()
{
    int x,y;
    int i=0,j=0;
    for(i=0,y=0;i<t;i++,y++)    
       for(j=0,x=t-1;j<t;j++,x--)
          if(ori[i][j]!=cpy[x][y])goto end;
    end:
        if(i==t && j==t)return 1;
        return 0;   
}

int equals()
{
    int x,y;
    int i=0,j=0;
    for(i=0,x=0;i<t;i++,x++)    
       for(j=0,y=0;j<t;j++,y++)
          if(ori[i][j]!=cpy[x][y])goto end;
    end:
        if(i==t && j==t)return 1;
        return 0;    
}

int check()
{
    //rotate 90 deg
    if(equals())return 0;
    if(r90())return 1;
    if(r180())return 2;
    if(r270())return 3;
    flip();
    if(equals())return 4;
    if(r90())return 7;
    if(r180())return 6;
    if(r270())return 5;
    return 8;
}

int main()
{
    int cas=1;
    while(scanf("%d",&t)!=EOF)
    {
        F(i,t)scanf("%s%s",ori[i],cpy[i]);
        printf("Pattern %d was ",cas++);

        int r=check();
        if(!r)printf("preserved.\n");
        else if(r==1)printf("rotated 90 degrees.\n");
        else if(r==2)printf("rotated 180 degrees.\n");
        else if(r==3)printf("rotated 270 degrees.\n");
        else if(r==4)printf("reflected vertically.\n");
        else if(r==5)printf("reflected vertically and rotated 90 degrees.\n");
        else if(r==6)printf("reflected vertically and rotated 180 degrees.\n");
        else if(r==7)printf("reflected vertically and rotated 270 degrees.\n");
        else if(r==8)printf("improperly transformed.\n");
    }
    return 0;
}
