#include<iostream>
#include<cstdlib>
#include<cmath>
#include<map>
#include<vector>
#include<sstream>
using namespace std;

struct bound{
       int l,u;
       bound(int a,int b){l=a;u=b;}
       };

int main()
{
    int n,r,b,d,s,l,u;
    string name;
    cin>>n>>r;
    map<string,vector<int> > m;
    for(int i=0;i<n;i++)
    {
         cin>>name>>b>>s>>d;
         vector<int> v(d+1);
         vector<bound> vb(d+1,bound(0,0));
         v[d]=s;
         
         for(int j=1;j<=d;j++)
         {
             cin>>l>>u;
             vb[j]=bound(l,u);    
         }       
         
         //printf("%d %d %d %d\n",vb[0].l,vb[0].u,vb[1].l,vb[1].u);
         
         for(int j=d; j>1 ;j--)
            {
                 int t=(v[j]*(vb[j].u-vb[j].l+1));
                 v[j-1]=t;        
            }
            
         int sum=0;
         for(int j=d;j>=1;j--)
             sum+=v[j]*vb[j].l;    
         
         v[0]=b-sum;
         m[name]=v;
    }
    
    for(int i=0;i<r;i++)
    {
        cin>>name;
        if(m.find(name)==m.end())continue;
        stringstream res;
        res<<name;
        res<<"[";
        int total=m[name][0],aux;
        for(int j=1;j<=m[name].size()-1;j++)        
        {  
             cin>>aux;
             if(j!=1)res<<", ";
             res<<aux;
             total+=(aux*m[name][j]);                    
        }    
        res<<"]";
        cout<<res.str();
        printf(" = %d\n",total);
    }
    
    return 0;
}
