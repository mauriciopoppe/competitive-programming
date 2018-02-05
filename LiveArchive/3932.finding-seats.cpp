/*
 * FindingSeats.cpp
 *
 *  Created on: Jul 7, 2011
 *      Author: Mauricio
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#define M 301
int dp[M][M];
int sum[M],t[M];
char w[M+2];			//word aux
#define min(a,b) (a<b?a:b)
int main()
{
	int row,col;		//rows and columns
	int group;			//group of people
	int i,j;			//loops
	while(scanf("%d%d%d",&row,&col,&group))
	{
		if(row+col+group==0)
			break;
		gets(w);
		for (i = 0; i < row; ++i) {
			gets(w);
			for (j = 0; j < col; ++j) {
				if(w[j]=='.')dp[i][j]=1;
				else dp[i][j]=0;
			}
		}
		/*for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
				printf("%d ",dp[i][j]);
			printf("\n");
		}*/
		int totalArea=row*col;
		//maximum sum
		for(int z=0;z<row;z++)
		{
            //printf("start %d\n",z);    
			//acc sum
			memset(sum,0,sizeof sum);
			for(int i=z;i<row;i++)
			{
                for(int j=0;j<col;j++)
				{
					sum[j]+=dp[i][j];
                }
                //find min size
                int acc=0,k=0,mn=row*col;
                for(int j=0;j<col;j++)
                {
                    acc+=sum[j];
                    while(k<col && acc>=group)
                    {
                        mn=min(mn,j-k+1);
                        acc-=sum[k++];
                    }
                }
                totalArea=min(totalArea,mn*(i-z+1));
			}
		}
		printf("%d\n",totalArea);
	}
	return 0;
}


