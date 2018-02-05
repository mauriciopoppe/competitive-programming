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
#define M 35
vector<string> w(15);
int s[M],ind,end;
int k;

void bt(int c, int n, string x)
{
     if(c==end)
        printf("%s\n",x.c_str());
     for(int i=n;i<k;i++)
     {
         string y=x;
         if(y=="")y+=w[i];
         else y+=", "+w[i];
         bt(c+1,i+1,y);    
     }  
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int cas,from[2];
    string z,buf;
    scanf("%d",&cas);
    getchar();
    getline(cin,z);
    F(t,cas)
    {
         if(t)NL;   
         getline(cin,z);
         if(z[0]!='*')
         {      
             stringstream ss(z);
             ind=0;
             while(ss>>buf)
                  from[ind++]=atoi(buf.c_str());
             if(ind==1)from[1]=from[0];
             ind=0;
             for(int i=from[0];i<=from[1];i++)
                s[ind++]=i;
         }
         
         k=0;
         while(getline(cin,buf) && buf.size())
              w[k++]=buf;
         
         if(z[0]=='*')
         {
             ind=0;
             for(int i=1;i<=k;i++)         
                s[ind++]=i;
         }
         F(i,ind)
         {
             printf("Size %d\n",s[i]);
             end=s[i];    
             string x="";
             bt(0,0,x);
             NL;
         }
    }
    return 0;
}
