#include <iostream>
#define MAX 110
int a[MAX],b[MAX];
int lcs[MAX][MAX];
using namespace std;

int main()
{
    int t1,t2,c=1;
    while(cin>>t1>>t2)
    {
         if(t1+t2==0)break;
         for(int i=0;i<t1;i++)
             {cin>>a[i];lcs[i][0]=0;}
         for(int i=0;i<t2;i++)
             {cin>>b[i];lcs[0][i]=0;}
         
         for(int i=0;i<t1;i++)
            for(int j=0;j<t2;j++)
            {
                if(a[i]==b[j])lcs[i+1][j+1]=lcs[i][j]+1;       
                else
                    lcs[i+1][j+1]=lcs[i][j+1]>=lcs[i+1][j]?lcs[i][j+1]:lcs[i+1][j];
            }          
         printf("Twin Towers #%d\n",c++);
         printf("Number of Tiles : %d\n",lcs[t1][t2]);
         printf("\n");
    }    
}
