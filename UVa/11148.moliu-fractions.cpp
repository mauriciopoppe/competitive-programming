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
char w[5000];
typedef pair<int,int> pii;

vector<pii> get_numbers()
{
    vector<pii> num;
    int x,y,z;
    char str[500];
    int size = strlen(w);
    w[size] = w[size + 1] = '\0';
    for(int i = 0; w[i]; ++i)
    {
        if(isdigit(w[i]))
        {
            int j = 0;
            while(w[i] && (isdigit(w[i]) || w[i] == '/' || w[i] == '-'))
               str[j++] = w[i++];
            str[j] = '\0';
            if(strchr(str,'-'))
            {
                sscanf(str,"%d-%d/%d",&z,&x,&y);
                num.push_back(pii(y * z + x, y)); 
            }
            else if(strchr(str,'/'))
            {
                sscanf(str,"%d/%d",&x,&y);
                num.push_back(pii(x, y));                  
            }
            else
            {
                sscanf(str,"%d",&x);
                num.push_back(pii(x, 1));                                  
            }
            //printf("z");
        }    
    }
    return num;
}

int main()
{
    int cas;
    scanf("%d",&cas);
    getchar();
    while(cas--)
    {
        gets(w);
        //printf("[%s]\n",w);
        
        vector<pii> number = get_numbers();
        int size = number.size();
        //printf("%d\n",size);
        pii x = number[0];
        /*TR(number, it)
           printf("%d %d\n",it->first,it->second);*/
        for(int i = 1;i < size; ++i)
        {
            x.first *= number[i].first;
            x.second *= number[i].second;
        }
        int g = __gcd(x.first, x.second);
        if(g > 1)
           x.first /= g, x.second /= g;        
        if(x.second != 1 && x.first > x.second)
            printf("%d-%d/%d\n",x.first / x.second, x.first % x.second, x.second);
        else if(x.second != 1)
            printf("%d/%d\n",x.first, x.second);
        else printf("%d\n",x.first);
    }
    return 0;
}
