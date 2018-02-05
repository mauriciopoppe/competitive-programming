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

int place[20000];

int main()
{
    
    freopen("in3.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    
    int x,aux,c;
    cin>>x;
    for(int j=0;j<x;j++)
    {
         if(j)printf("\n");   
         int n,t,m;
         string p;
         
         cin>>n>>t>>m;
         queue<ferry> l,r;
         for(int k=0;k<m;k++)
         {
             cin>>aux>>p;
             if(p[0]=='l' || p[0]=='L')l.push(ferry(aux,k));
             else r.push(ferry(aux,k));
         }          
         
         int nt;
         if(l.empty() && r.empty())continue;
         else if(l.empty())nt=r.front().t;
         else if(r.empty())nt=l.front().t;
         else nt=min(l.front().t,r.front().t);
         
         int f=0,g=0;
         while(1)
         {
              //load left            
              ll:
              //printf("left - %d\n",nt);   
              //system("pause");
              c=0;
              f=0;
              while(!l.empty() && l.front().t<=nt)
              {
                   place[l.front().n]=nt+t;            
                   l.pop();
                   c++;           
                   if(c==n)break;
                   f=1;
              }
              if(r.empty() && l.empty())break;
              if(f)nt+=t;
              else
              {  
                   if(r.empty()){nt=l.front().t;goto ll;}
                   else if(l.empty())nt=r.front().t+t;
                   else 
                   {
                        if(l.front().t<=r.front().t)
                        {
                             nt=l.front().t;
                             goto ll;                                                 
                        }  
                        else nt=r.front().t+t;
                   }
              }
              
              
              //load right
              lr:
              //printf("right - %d\n",nt);   
              //system("pause");
              c=0;
              f=0;
              while(!r.empty() && r.front().t<=nt)
              {
                   place[r.front().n]=nt+t;            
                   r.pop();
                   c++;       
                   if(c==n)break;    
                   f=1;
              }   
              if(r.empty() && l.empty())break;        
              if(f)nt+=t;
              else
              {  
                   //move to min
                   if(l.empty()){nt=r.front().t;goto lr;}
                   else if(r.empty())nt=l.front().t+t;
                   else 
                   {
                        if(r.front().t<=l.front().t)
                        {
                             nt=r.front().t;
                             goto lr;                                                 
                        }  
                        else nt=l.front().t+t;
                   }
              }

         }
         for(int i=0;i<m;i++)
            printf("%d\n",place[i]);
         
    }
    return 0;
}
