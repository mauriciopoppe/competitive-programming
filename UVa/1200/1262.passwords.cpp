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
vector<string> v,s;
int len;
    
void print(string &w, int p, string x)    
{
     if(p==len)
         printf("%s\n",x.c_str());
     else
     {
         if(w[p]=='#')
         {
              for(int i=0;i<v.size();i++)
              {   
                  string t=x;     
                  x+=v[i];
                  print(w,p+1,x);        
                  x=t;
              }
         }   
         else
             for(int i=0;i<10;i++)
             {
                  x+=(char)(i+'0');
                  print(w,p+1,x);
                  x.erase(x.size()-1,1);   
             }        
     }     
}
    
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    string w,x;
    int m,n;
    
    while(scanf("%d",&m)!=EOF)
    {    
        v.clear();
        s.clear();  
        for(int i=0;i<m;i++)
        {   cin>>w;v.push_back(w);}
        
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {   cin>>w;s.push_back(w);}
        
        for(int i=0;i<n;i++)
        {
            printf("--\n");    
            len=s[i].size();     
            x="";
            print(s[i],0,x);    
        }
    }
    
    return 0;
}
