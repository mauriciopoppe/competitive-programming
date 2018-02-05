#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define M 1000000
#define INF 2000000
using namespace std;

int v3[M][2],v1[M][2],s3,s1;

int main()
{
    char w[M];
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        s3=s1=0;                      
        for(int i=0;i<n;i++)
        {
            scanf("%s",w);
            for(int j=0;j<n;j++)
            {
                 if(w[j]=='1')v1[s1][0]=i,v1[s1++][1]=j;   
                 else if(w[j]=='3')v3[s3][0]=i,v3[s3++][1]=j;
            }    
        }                      
        
        int mx=0,mn=INF;
        for(int i=0;i<s1;i++)
        {   
            mn=INF;
            for(int j=0;j<s3;j++)
               mn<?=(abs(v1[i][0]-v3[j][0])+abs(v1[i][1]-v3[j][1]));
            mx>?=mn;
        }
        printf("%d\n",mx);                      
    }
    return 0;
}
