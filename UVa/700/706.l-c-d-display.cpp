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
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;
/*
         -  0
       1| |2
         -  3 
       4| |5
         -  6 
*/
char m[10][7]={
       '-','|','|',' ','|','|','-',                       //0
       ' ',' ','|',' ',' ','|',' ',                       //1
       '-',' ','|','-','|',' ','-',                       //2
       '-',' ','|','-',' ','|','-',                       //3
       ' ','|','|','-',' ','|',' ',                       //4
       '-','|',' ','-',' ','|','-',                       //5
       '-','|',' ','-','|','|','-',                       //6
       '-',' ','|',' ',' ','|',' ',                       //7
       '-','|','|','-','|','|','-',                       //8
       '-','|','|','-',' ','|','-'                        //9
     };

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int a;
    string b;
    char w[5001];
    while(cin>>a>>b)
    {
        if(a==0 && b=="0")break;
        int size=b.size();
        int ind;
        for(int i=0;i<2*a+3;i++)
        {
            ind=0;    
            for(int k=0;k<size;k++)
            {                  
                if(k)w[ind++]=' ';                 
                int n=b[k]-'0';
                for(int j=0;j<a+2;j++)
                {
                     //up
                     if(i==0)
                     {
                          if(!j || j==a+1)w[ind++]=' ';
                          else w[ind++]=m[n][0];
                     }                     
                     //mid up
                     else if(i>0 && i<a+1)
                     {
                          if(!j)w[ind++]=m[n][1];
                          else if(j==a+1)w[ind++]=m[n][2];
                          else w[ind++]=' ';
                     }   
                     //mid
                     else if(i==a+1)
                     {
                          if(!j || j==a+1)w[ind++]=' ';
                          else w[ind++]=m[n][3];
                     }
                     //mid down
                     else if(i>a+1 && i<2*a+2)
                     {
                          if(!j)w[ind++]=m[n][4];
                          else if(j==a+1)w[ind++]=m[n][5];
                          else w[ind++]=' ';
                     }
                     //down
                     else
                     {
                          if(!j || j==a+1)w[ind++]=' ';
                          else w[ind++]=m[n][6];
                     }
                }
            }
            w[ind]='\0';
            printf("%s\n",w);
        }            
        NL;
    }
    return 0;
}
