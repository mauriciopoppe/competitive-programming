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
typedef unsigned int UI;
UI v[100];
map<UI,int> m;
int main()
{
    int j=0;
    v[0]=1;
    v[1]=2;
    m[v[0]]=j++;
    m[v[1]]=j++;
    for(int i=2;v[i-1]<2147483647;i++)
    {
         v[i]=v[i-1]+v[i-2];
         m[v[i]]=i;   
    }
    
    int t,c[110];
    char dec[110];
    scanf("%d",&t);
    while(t--)
    {
          fill(dec,dec+110,' ');    
          int x;
          j=0;
          scanf("%d",&x);
          int max=-1;
          for(int i=0;i<x;i++)
          {
              scanf("%d",&c[i]);          
              if(c[i]>max)max=c[i];
          }
          
          dec[m[max]+1]='\0';
          string s;
          getchar();
          getline(cin,s);
          int size=s.size();
          j=0;
          for(int i=0;i<x;i++)
          {
               while(!isupper(s[j]))j++;
                    dec[m[c[i]]]=s[j++];        
          }
          
          printf("%s\n",dec);              
    }
    return 0;
}
