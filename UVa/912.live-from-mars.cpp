#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<cctype>
using namespace std;
int par[1000000],size[1000000];

int find(int n)
{
    if(par[n]==n)return n;
    else return find(par[n]); 
}

void uf(int a, int b)
{
     int x=find(a),y=find(b);
     if(size[x]>=size[y])
     {
          size[x]+=size[y];
          par[y]=x;                                 
     }
     else
     {
          size[y]+=size[x];
          par[x]=y;                                 
     }     
}

int main()
{
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

    vector<string> a,b;
    int n,cc=0;
    while(scanf("%d",&n)!=EOF)
    {
         if(cc)printf("\n");
         ++cc;                                       
         map<int,char> m2;
         set<int> c;
         a.resize(n);
         b.resize(n);
         
         for(int i=0;i<n;i++)                     
            cin>>a[i];
         for(int i=0;i<n;i++)                     
         {
            cin>>b[i];
            par[i]=i;
            size[i]=1;
         }
         
         int f=0;
         for(int i=0;i<n;i++)
         {
             if(isalpha(a[i][0]) && isalpha(b[i][0]))
                {if(a[i][0]!=b[i][0]){f=1;break;}}
             else if(isalpha(a[i][0]))
             {
                  int x;
                  sscanf(b[i].c_str(),"%d",&x);
                  if(m2.find(find(x))==m2.end())m2[x]=a[i][0];
                  else if(m2[find(x)]!=a[i][0]){f=1;break;}
             }
             else if(isalpha(b[i][0]))
             {
                  int x;
                  sscanf(a[i].c_str(),"%d",&x);
                  if(m2.find(find(x))==m2.end())m2[x]=b[i][0];
                  else if(m2[find(x)]!=b[i][0]){f=1;break;}
             }
             else
             {
                  int x,y;
                  sscanf(a[i].c_str(),"%d",&x);
                  sscanf(b[i].c_str(),"%d",&y);
                  
                  map<int,char>::iterator i,j;
                  i=m2.find(find(x));
                  j=m2.find(find(y));
                  
                  if(i!=m2.end() && j!=m2.end() && i!=j){f=1;break;}
                  c.insert(x);
                  c.insert(y);
                  uf(x,y);                  
             }          
         }    
         
         if(f){printf("NO\n");continue;}
         
         int len=c.size();
         for(set<int>::iterator it=c.begin();it!=c.end();it++)    
         {
             if(m2.find(*it)!=m2.end())continue;
             else
             {
                 int x=find(*it);
                 if(x==*it)continue;
                 if(m2.find(x)!=m2.end())m2[*it]=m2[x];    
             }
         }
         
         printf("YES\n");
         for(map<int,char>::iterator it=m2.begin();it!=m2.end();it++)
            printf("%d %c\n",it->first,it->second);
         
    }
    
    return 0;
}
