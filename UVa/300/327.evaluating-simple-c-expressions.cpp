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
char line[115];
char str[115];
bool present[26];
int value[26];

void init()
{
     F(i,26)
        value[i] = i + 1;
}

int main()
{
    while(gets(line))
    {
        char c;             
        int j = 0;
        for(int i =0; line[i]; ++i)
            if(!isspace(line[i]))
               str[j++] = line[i];
        str[j] = str[j + 1] = '\0';
        init();
        memset(present,0,sizeof present);
        int val = 0;
        
        c = '+';
        for(int i = 0; str[i]; )
        {
            if(i)
                c = str[i++]; 
            
            if(isalpha(str[i]))
            {
               present[str[i] - 'a'] = 1;
               //check second char                
               if(i + 2 < j && !isalpha(str[i + 2]))      
               {               
                   if(str[i + 1] == str[i + 2])
                   {
                      //printf("here");      
                      if(str[i + 1] == '-')
                            val += value[str[i] - 'a']-- * (c=='-'?-1:1);
                      else
                            val += value[str[i] - 'a']++ * (c=='-'?-1:1);
                      //printf("here"); 
                      i += 3;
                   }
                   else
                      val += value[str[i] - 'a'] * (c=='-'?-1:1), ++i;
               }
               else
                  val += value[str[i] - 'a'] * (c=='-'?-1:1), ++i;
            }
            else
            {
                if(str[i] == '-') 
                   val += --value[str[i + 2] - 'a'] * (c=='-'?-1:1);
                else
                   val += ++value[str[i + 2] - 'a'] * (c=='-'?-1:1);
                present[str[i + 2] - 'a'] = 1;           
                i += 3;
            }    
        }
        printf("Expression: %s\n",line);
        printf("    value = %d\n",val);
        F(i,26)
           if(present[i])
              printf("%5c = %d\n",i+'a',value[i]);
    }
    return 0;
}
