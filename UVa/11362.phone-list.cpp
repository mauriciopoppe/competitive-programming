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
    int t,x;
    string s;
    scanf("%d",&t);
    while(t--)
    {
         scanf("%d",&x);
         vector<string>  v;
         while(x--){cin>>s;v.push_back(s);}
         sort(v.begin(),v.end());
         int f=1;
         for(int i=0;i<v.size()-1;i++)
             if(v[i+1].size()>=v[i].size())
               if(equal(v[i+1].begin(),v[i+1].begin()+v[i].size(),v[i].begin())){f=0;break;}
         if(f)printf("YES\n");
         else printf("NO\n");
    }
    return 0;
}
