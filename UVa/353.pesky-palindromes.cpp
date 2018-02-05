#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<map>
#include<set>
using namespace std;
char w[90];
int len;
bool isp(int b, int e)
{
     for(;b<e;b++,e--)
        if(tolower(w[b])!=tolower(w[e]))return false;
     return true;
}

bitset<26> b;
int main()
{
    map<string, int> m;
    string t;
    while(scanf("%s",w)!=EOF)
    {                   
          b.reset();
          m.clear();
          len=strlen(w);
          for(int i=0;i<len;i++)
              b[tolower(w[i])-'a']=1;          
          int np=b.count();
          for(int i=1;i<len;i++)
             for(int j=0;j<len-i;j++)
             {
                 t=string(w+j,w+j+i);    
                 if(isp(j,j+i) && !m[t])
                   ++np,++m[t];
             }
          printf("The string \'%s\' contains %d palindromes.\n",w,np);                                            
    }
    return 0;
}
