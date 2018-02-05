/*
 * GalouIsBack.cpp
 *
 *  Created on: Jul 7, 2011
 *      Author: Mauricio
 */


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#define M 101
char g[M][M];
int dis[M][M];
bool blocked[M][M];
int dx[]={-1,-1,0,0,1,1},dy[]={0,1,-1,1,-1,0};
int ini[M*M][2];
int row,col;
bool isBlocked;
bool check(int &x, int &y)
{
	if(x>=0 && x<row && y>=0 && y<col)return true;
	return false;
}

void print()
{
	for (int i = 0; i < row; ++i) {
    	for (int j = 0; j < col; ++j) {
            printf("%d ",dis[i][j]);
            }printf("\n");
            }
}
void bfs(int how, int x, int y)
{
	//printf("%d %d\n",x,y);
	//system("pause");
	if(isBlocked)return;
	dis[x][y]=how;
	int nhow=3-how;
	for(int i=0;i<6;i++)
	{
		int sx=x+dx[i], sy=y+dy[i];
		if(check(sx,sy) && g[sx][sy]=='*')
		{
			if(!dis[sx][sy])
			{
				bfs(nhow,sx,sy);
			}
			else if(dis[sx][sy]==how){isBlocked=1;return;}
			//print();
			//system("pause");
		}
	}
}

void block(int x, int y)
{
	blocked[x][y]=1;
	for(int i=0;i<6;i++)
	{
		int sx=x+dx[i], sy=y+dy[i];
		if(check(sx,sy) && g[sx][sy]=='*' && !blocked[sx][sy])
		{
			block(sx,sy);
		}
	}
}
int main()
{
	while(scanf("%d%d",&row,&col))
	{          
		memset(blocked,0,sizeof blocked);
		memset(dis,0,sizeof dis);
		int k=0;
		if(row==0 && col==0)break;
		gets(g[0]);
		for (int i = 0; i < row; ++i) {
			gets(g[i]);
			for (int j = 0; j < col; ++j) {
				if(g[i][j]=='I')
					ini[k][0]=i,
					ini[k++][1]=j,
					g[i][j]='*';
			}
		}
		//for(int i=0;i<row;i++)
        //   printf("%s\n",g[i]);
        //printf("1");
		//system("pause");
		//dfs
		for(int i=0;i<k;i++)
		{                
			isBlocked=0;
			int x=ini[i][0],y=ini[i][1];
			if(blocked[x][y])continue;
			bfs(1,x,y);
			//printf("dfs %d %d\n",i,isBlocked);
			if(isBlocked)
				block(x,y);
		}
		//system("pause");
		//print
		printf("\n");
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if(g[i][j]=='.')printf(".");
			    else if(blocked[i][j])printf("B");
				else
				{
					if(dis[i][j]==1)printf("(");
					else if(dis[i][j]==2)printf(")");
					else printf("F");
				}
			}
			printf("\n");
		}
	}
	return 0;
}
