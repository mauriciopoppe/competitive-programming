#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#include<cctype>
using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    vector<string> a,b;
    int n,cc=0;
    while(scanf("%d",&n)!=EOF)
    {
         if(cc)printf("\n");
         cc++;                     
         map<int,char> m;                     
         a.resize(n);
         b.resize(n);
         for(int i=0;i<n;i++)
            cin>>a[i];                                               
         for(int i=0;i<n;i++)
            cin>>b[i];
         
         int i=0;
         for(;i<n;i++)
         {
             //printf("[%d] [%c] [%c]\n",i,a[i][0],b[i][0]);         
             if(isalpha(a[i][0]) && isalpha(b[i][0]))
                {if(a[i][0]!=b[i][0])break;}
             else if(isalpha(a[i][0]))
             {
                 int x,t;
                 sscanf(b[i].c_str(),"%d",&x);
                 m[x]=a[i][0];
                 for(int j=i+1;j<n;j++)
                 {
                       if(a[j]==b[i])
                          a[j]=a[i];
                       if(b[j]==b[i])
                          b[j]=a[i];
                 }                                 
             }
             else if(isalpha(b[i][0]))
             {
                 int x,t;
                 sscanf(a[i].c_str(),"%d",&x);
                 m[x]=b[i][0];
                 //printf("here");
                 for(int j=i+1;j<n;j++)
                 {
                       if(a[j]==a[i])
                          a[j]=b[i];
                       if(b[j]==a[i])
                          b[j]=b[i];
                 }                                 
             }
             //for(int k=0;k<n;k++)cout<<a[k]<<" ";cout<<endl;
             //for(int k=0;k<n;k++)cout<<b[k]<<" ";cout<<endl;
             
         }
                   
         if(i!=n)printf("NO\n");
         else
         {
             printf("YES\n");
             for(map<int,char>::iterator it=m.begin();it!=m.end();it++)
                 printf("%d %c\n",it->first,it->second);    
         }                                                 
    }
    return 0;
}
