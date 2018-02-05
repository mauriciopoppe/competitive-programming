#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<functional>
using namespace std;

int c[]={128,256,512,1024,2048,4096};
int v[12];

int main()
{
    int n;
    int q=0;
    char w[3];
    vector<string> va;
    while(scanf("%d",&n) && n)
    {
        if(q)printf("\n");                 
        q++;
        for(int i=0;i<n;i++)
           scanf("%d",&v[i]);
        
        int t=c[n-7];
        for(int i=0;i<t;i++)
        {
              bitset<12> b(i);
              //printf("%d\n",b.count());
              if(b.count()==6)
              {    
                   string res=b.to_string<char,char_traits<char>,allocator<char> >();
                   string a="";
                   for(int i=res.size()-1;i>=0;i--)
                     a+=res[i];
                   //cout<<a<<endl;
                   va.push_back(a);
              }
        }
        
        sort(va.begin(),va.end(),greater_equal<string>());
        
        for(int i=0;i<va.size();i++)
        {
           int j=0;
           for(;j<n;j++)
                if(va[i][j]-'0'){printf("%d",v[j]);break;}
           j++;
           for(;j<n;j++)
                if(va[i][j]-'0'){printf(" %d",v[j]);}
           printf("\n");
        }               
        va.clear();
    }
    return 0;
}
