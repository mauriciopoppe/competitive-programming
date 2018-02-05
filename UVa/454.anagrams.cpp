#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<map>
#include<set>
#include<cctype>
using namespace std;
map<char,int> m;
void init()
{
     for(int i=0;i<27;i++)
     {
          m[char('A'+i)]=2*i;
          m[char('a'+i)]=2*i+1;     
     }
}

int cmp(char a,char b )
{
   return m[a]<m[b];
} 

int main()
{   
    init();
    int c;
    char w[100];
    scanf("%d",&c);
    while(c--)
    {
         scanf("%s",w);
         int size=strlen(w);
         sort(w,w+size,cmp);
         do
         {
             printf("%s\n",w);
         }while(next_permutation(w,w+size,cmp));                   
    }
    return 0;
}
