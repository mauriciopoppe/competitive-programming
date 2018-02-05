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
char base[500];
char key[500];
char first[500];
char str[10000];
char temp[500];
int to_dec(char *w)
{
    return w[2]-'0' + 2 *( w[1]-'0') + 4 * (w[0]-'0');
}

void get_first(char *w, int len)
{
     F(i,len)
     {
        w[i] = getchar();
        //if(w[i] == EOF)
        //  return; 
        if(w[i] == '\n')
          i--;      
     }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    map<string, int> m;
    int c = 1;
    F(k,7)
    {
        string do_not_copy(k+1,'1');
        for(int i = 0; ; ++i)
        {
            memset(base,'0',sizeof base);                
            int j = i, ind = 0;
            while(j > 0) 
            {
                base[ind++] = j%2 + '0';
                j>>=1;
            }
            string w = string(base,base+k+1);
            reverse(w.begin(),w.end());
            if(w == do_not_copy)
                break;
            m[w] = c++;
            //cout << w << endl;
        }      
        
        //SP;
    }
    //SP;
    
    while(gets(first))
    {
        char q;
        //printf("[%s]\n",first);
        while(1)
        {
            get_first(temp, 3);
            int dec = to_dec(temp);
            if(!dec)
                break;
            string wrong = string(dec, '1');
            temp[3] = '\0';
            //printf("[%s] %d\n",temp,dec);
            //SP;
            
            while(1)
            {
                get_first(key,dec);
                key[dec] = '\0';
                //printf("key = %s\n",key);
                //SP;
                string test = string(key, key + dec);
                if(test == wrong)
                   break;
                printf("%c",first[m[test] - 1]);
                //NL;               
            }
            
        }NL;
        gets(first);
    }
    return 0;
}
