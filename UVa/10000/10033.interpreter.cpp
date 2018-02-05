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

int r[10];
char ram[1000][4];

void init()
{
    memset(r, 0, sizeof r); 
    for(int i = 0; i < 1000; ++i)
       ram[i][0] = ram[i][1] = ram[i][2] = '0',
       ram[i][3] = '\0';      
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int cas;
    char w[500];
    scanf("%d", &cas);
    gets(w);
    gets(w);
    while(cas--)
    {
        init();        
        int k = 0, i;
        while(gets(w) && isdigit(w[0]))
            strcpy(ram[k++], w);
        
        k = 0, i = 0;
        while(strcmp(ram[i], "100"))
        {
            /*printf("ram[%d] = %s\n", i, ram[i]);
            for(int j = 0; j < 10; ++j)
               printf("%d ", r[j]);NL;
            */
            ++k;
            int n = ram[i][0] - '0', 
                x = ram[i][1] - '0', 
                y = ram[i][2] - '0';
            if(n != 0) ++i;            
            switch(n)
            {
                case 2:
                     r[x] = y;
                     break;
                
                case 3:
                     r[x] = (r[x] + y) % 1000;
                     break;
                
                case 4:
                     r[x] = (r[x] * y) % 1000;
                     break;
                
                case 5:
                     r[x] = r[y];
                     break;
                
                case 6:
                     r[x] = (r[x] + r[y]) % 1000;
                     break;
                
                case 7:
                     r[x] = (r[x] * r[y]) % 1000;
                     break;
                
                case 8:
                     int z;
                     sscanf(ram[r[y]], "%d", &z);
                     r[x] = z;
                     break;
                
                case 9:
                     sprintf(ram[r[y]], "%d", r[x]);
                     break;
                
                case 0:
                     if(r[y] != 0)
                        i = r[x];
                     else
                        ++i;
                     break;             
            }                 
            /*for(int j = 0; j < 10; ++j)
               printf("%d ", r[j]);NL;
            SP;*/

        }
        printf("%d\n", k + 1);
        if(cas)NL;
    }
    return 0;
}
