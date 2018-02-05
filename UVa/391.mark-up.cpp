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

char w[10000];

void print(int i)
{
     printf("%c%c",w[i], w[i + 1]);
}

int main()
{
    freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);

    int s,b,i;    
    s = b = i = 0;
    int f = 0; 
    while(gets(w))
    {              
        //printf("[%s]\n",w);  
        f = 0;         
        for(int i = 0; w[i]; )
        {
            //f = 0;    
            //printf("i = %d - %d\n",i,f);    
            if(w[i] == '\\')
            {
                ++i;
                //printf("here");    
                switch(w[i])
                {
                     case '*':                          
                          f = !f, ++i;                  
                          break;      

                     case 's':
                          //printf("here");
                          if(f){printf("%c%c",w[i - 1], w[i]); i++; break;}
                          //printf("here");
                          ++i;
                          //if(!s)
                          //{
                              //printf("here");
                              while(w[i] && isdigit(w[i])) ++i;
                              if(w[i] && w[i] == '.') ++i;
                              while(w[i] && isdigit(w[i])) ++i;
                              //SP;
                              //printf("%d",i);
                          //}
                          //s = !s;
                          break;

                     case 'b':
                     case 'i':
                          if(f){printf("%c%c",w[i - 1], w[i]); i++; break;}
                          ++i;
                          break;

                     case '\\':
                          if(f){printf("%c",'\\'); break;}
                          else if(isalpha(w[i + 1]))
                             printf("%c%c",w[i], w[i + 1]), i += 2;
                          else 
                             printf("%c%c",w[i - 1], w[i]), i++;
                          break;     
                }    
            }
            else putchar(w[i]), ++i;    
        }
        NL;          
    }
    return 0;
}
