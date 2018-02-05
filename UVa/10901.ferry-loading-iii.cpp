#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<queue>
using namespace std;

struct ferry{
       int t,n;
       ferry(int a, int b){t=a;n=b;}
       };

int place[10010];

int main()
{
    
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
    
    
    int x,aux,c;
    cin>>x;
    for(int j=0;j<x;j++)
    {
         int n,t,m;
         string p;
         cin>>n>>t>>m;
         queue<ferry> l,r;
         for(int k=0;k<m;k++)
         {
             cin>>aux>>p;
             if(p=="left")l.push(ferry(aux,k));
             else r.push(ferry(aux,k));
         }          
         
         int nt;
         if(l.empty() && r.empty())continue;
         else if(l.empty())nt=r.front().t;
         else if(r.empty())nt=l.front().t;
         else nt=min(l.front().t,r.front().t);
         
         while(1)
         {
              //load left            
              ll:
              c=0;
              while(!l.empty() && l.front().t<=nt && c<n)
              {
                   place[l.front().n]=nt+t;            
                   l.pop();
                   c++;           
              }
              
              if(l.empty() && r.empty())break;
              else if(r.empty())
              {
                   if(l.front().t<=nt+t)nt+=2*t;
                   else nt=l.front().t+t; 
                   goto ll;
              }
              else if(l.empty())
              {
                   if(r.front().t<=nt+t)nt+=t;
                   else nt=r.front().t;
              }
              else
              {
                   if(r.front().t<=nt+t)nt+=t;
                   // stay if there's a high value on the right
                   else if(l.front().t<r.front().t){nt=l.front().t+t;goto ll;}
                   else
                        nt=(r.front().t);
              }
              
              //load right
              lr:
              c=0;
              while(!r.empty() && r.front().t<=nt && c<n)
              {
                   place[r.front().n]=nt+t;            
                   r.pop();
                   c++;           
              }           
    
              if(l.empty() && r.empty())break;
              else if(l.empty())
              {
                   if(r.front().t<=nt+t)nt+=2*t;
                   else nt=r.front().t+t; 
                   goto lr;
              }
              else if(r.empty())
              {
                   if(l.front().t<=nt+t)nt+=t;
                   else nt=l.front().t;
              }
              else 
              {
                   if(l.front().t<=nt+t)nt+=t;
                   // stay if there's a high value on the right
                   else if(r.front().t<l.front().t){nt=r.front().t+t;goto lr;}
                   else
                        nt=(l.front().t);
              }

         }
         for(int i=0;i<m;i++)
            printf("%d\n",place[i]);
         printf("%d\n");
    }
    return 0;
}
