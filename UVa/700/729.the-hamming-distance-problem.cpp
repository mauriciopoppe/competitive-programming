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

int n,h;
string res="";           
               
void bt(int c, bitset<16> b)
{
     //if(b.count()>h)return;
     if(c==n)
     {
          if(b.count()==h)
          {
               for(int i=0;i<n;i++)
                  res+=(char)(b[i]+'0');
               printf("%s\n",res.c_str());           
          }
          else return;        
     }     
     else
     {
         b[c]=0;
         bt(c+1,b);
         b[c]=1;
         bt(c+1,b);
     }
}

int main()
{
    int t;
    scanf("%d",&t);
    bitset<16> b;
    for(int q=0;q<t;q++)
    {
         if(q)printf("\n");     
         b.reset();     
         scanf("%d %d",&n,&h);
         bt(0,b);                             
    }
    return 0;
}
