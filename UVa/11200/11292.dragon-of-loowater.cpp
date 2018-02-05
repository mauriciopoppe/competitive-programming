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

int main()
{
    int h,k,t;
    vector<int> a,b;
    while(scanf("%d%d",&h,&k) && h && k)
    {
           a.clear();
           b.clear();
           for(int i=0;i<h;i++)
           {
                 scanf("%d",&t);
                 a.push_back(t);                   
           }                                             
           
           for(int i=0;i<k;i++)
           {
                 scanf("%d",&t);
                 b.push_back(t);                   
           }
           
           sort(a.begin(),a.end());                   
           sort(b.begin(),b.end());
           
           int tc=0,i=0,j=0;
           while(1)
           {
                   if(b[j]>=a[i])
                         tc+=b[j],i++;
                   j++;        
                   if(i==h || j==k)break;
           }
           
           if(j==k && i!=h)printf("Loowater is doomed!\n");
           else printf("%d\n",tc);
           
    }
    return 0;
}
