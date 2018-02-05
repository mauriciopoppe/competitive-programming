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
int deposit[30];
int flow[30];
char w[500000];
char dep[30];
int total_water, n;

void kill_spaces()
{
     char t[500000];
     int j = 0;
     for(int i = 0;w[i];++i)
       if(!isspace(w[i]))
         t[j++] = w[i];
     t[j] = '\0';
     memcpy(w,t,sizeof t);
}


void print(int &i)
{
    printf("%3d",i++);
    for(int j = 0; j < n; ++j)
       printf(" %3d",deposit[j]);
    NL;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);    
    while(gets(w))
    {
        int i;          
        kill_spaces();
        sscanf(w,"%*c%*c%d",&n);
        
        gets(w);
        kill_spaces();
        char *ptr = strtok(w,";");
        i = total_water = 0;
        while(ptr)
        {
             sscanf(ptr,"%c%*c%d",&dep[i],&deposit[i]);
             total_water += deposit[i++];
             ptr = strtok(NULL, ";");
        }
        
        gets(w);
        kill_spaces();
        char *ptr2 = strtok(w,";");
        i = 0;
        
        while(ptr2)
        {
             sscanf(ptr2,"%*c%*c%d",&flow[i++]);         
             ptr2 = strtok(NULL, ";");
        }
        
        printf("%3c",'t');
        for(int i = 0; i < n; ++i)
           printf(" %3c", dep[i]);
        NL;
        int spaces = (n + 1) * 4 - 1;
        for(int i = 0; i < spaces; ++i)
           printf("-");
        NL;   
        
        i = 0;
        print(i);
        while(deposit[n - 1] != total_water)
        {                                                    
             for(int j = n - 2; j >= 0; j--)
             {
                 if(flow[j] <= deposit[j])
                 {
                     deposit[j + 1] += flow[j];
                     deposit[j] -= flow[j];
                 }
                 else
                 {
                     deposit[j + 1] += deposit[j];
                     deposit[j] = 0;
                 }
             }
             print(i);     
        }
    }
    return 0;
}
