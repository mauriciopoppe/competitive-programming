#include<iostream>
#include<queue>
#include<map>
#define rH(r) t=uu.g[r][0],uu.g[r][0]=uu.g[r][1],uu.g[r][1]=uu.g[r][2],uu.g[r][2]=t
#define rV(c) t=uu.g[2][c],uu.g[2][c]=uu.g[1][c],uu.g[1][c]=uu.g[0][c],uu.g[0][c]=t
using namespace std;

struct state{
       int g[3][3];
       }vv,uu;

int getHash()
{
    int x=0;
    for(int i=0;i<3;i++)
      for(int j=0;j<3;j++)
        x=x*10+uu.g[i][j];
    return x;
}

void getValue(int val)
{
    for(int i=2;i>=0;i--)
      for(int j=2;j>=0;j--)
      {
          vv.g[i][j]=val%10;
          val/=10;    
      }
}

int main()
{
     //freopen("in.txt","r",stdin);
     //freopen("out.txt","w",stdout);
     map<int,int> par;
     map<int,string> path;
     char V[3],H[3];
     V[2]=H[2]='\0';
     V[0]='V';
     H[0]='H';
     
     queue<int> q;
     int h=123456789,u,v,t;
     q.push(h);
     par[h]=-1;
     
     while(!q.empty())
     {             
         v=q.front();
         q.pop();
         getValue(v);
         
         /*
         printf("\n@@@@@\n");
         print(vv);
         printf("@@@@@\n\n");
         system("pause");
         */
         
         //gen horizontal states
         
         for(int k=0;k<3;k++)
         {
              uu=vv;   
              rH(k);
              h=getHash();
              if(!par[h])
              {
                  par[h]=v;
                  H[1]=char(k+'1');
                  path[h]=string(H);
                  q.push(h);    
              }
         }
         
         //gen vertical states
         for(int k=0;k<3;k++)
         {
              uu=vv;   
              rV(k);
              h=getHash();
              if(!par[h])
              {    
                  par[h]=v;
                  V[1]=char(k+'1');
                  path[h]=string(V);
                  q.push(h);    
              }
         }
                           
     }           
     //printf("end");       
     while(scanf("%d%",&uu.g[0][0]) && uu.g[0][0])
     {                                
         scanf("%d%d",&uu.g[0][1],&uu.g[0][2]);
         for(int i=1;i<3;i++)
             for(int j=0;j<3;j++)
                scanf("%d",&uu.g[i][j]);
         //print(uu);
         int h=getHash();
         if(par[h])
         {   
             string w="";
             while(par[h]!=-1)
             {
                  w+=path[h];
                  h=par[h];   
             }
             printf("%d %s\n",w.size()/2,w.c_str());
         }
         else printf("Not solvable\n");
     }
}
