#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define INF -10000
using namespace std;

int dp[1000][1000],rs[1000];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    char w[1000];
    int n,len,j,xlen=0;
    scanf("%d",&n);
    getchar();
    getchar();
    for(int q=0;q<n;q++)
    {
        if(q)printf("\n");    
        int i=0;      
        
        while(gets(w))
        {                           
             len=strlen(w);
             if(!len)break;   
             xlen=len;          
             for(int j=0;j<len;j++)
                if(w[j]=='1')dp[i][j]=1;
                else dp[i][j]=INF;
             ++i;                      
        }    
        
        
        int j=xlen,S=INF,s,t;      
    
        for(int z=0;z<i;z++)
        {
            memset(rs,0,4*j);        
            for(int x=z;x<i;x++)
            {
                s=INF;
                t=0;
                for(int k=0;k<j;k++)
                {
                    rs[k]+=dp[x][k];
                    t+=rs[k];
                    if(t>s)s=t;
                    if(t<0)t=0;            
                }    
                if(s>S)S=s;
            }    
        }
        if(S!=INF)printf("%d\n",S);
        else printf("0\n");
                    
    }
    return 0;
}
