#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
using namespace std;

int st[4100000],x,y;
char a[1050000],w[55];

void update(int n, int b, int e)
{
     if(b==e)
     {    if(a[b]=='1')st[n]=1;
          else st[n]=0;  
     }          
     else
     {
         int m=((b+e)>>1);
         if(m>=x)update(2*n,b,m);
         if(m<y)update(2*n+1,m+1,e);    
         st[n]=st[2*n]+st[2*n+1];
     }     
}

void build(int n, int b, int e)
{
     if(b==e)
     {
         if(a[b]=='1')st[n]=1;
         else st[n]=0;  
     }          
     else
     {
         int m=((b+e)>>1);
         build(2*n,b,m);
         build(2*n+1,m+1,e);    
         st[n]=st[2*n]+st[2*n+1];
     }     
}

int query(int n, int b, int e)
{
    if(b>=x && e<=y)return st[n];
    int m=((b+e)>>1);
    if(y<=m)return query(2*n,b,m);
    else if(x>m)return query(2*n+1,m+1,e);
    else
         return query(2*n,b,m)+query(2*n+1,m+1,e);     
}

void print(int n)
{
     for(int i=0;i<n;i++)printf("%d ",st[i]);printf("\n");     
}
int main()
{
    //freopen("Ahoy.txt","r",stdin);
    //freopen("AhoyOut.txt","w",stdout);

    int t,u,n,tt,j,len,q,cases=1;
    char qq;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&u);
        tt=j=0;
        for(int i=0;i<u;++i)
        {
             scanf("%d",&n);
             getchar();
             gets(w);
             len=strlen(w);
             for(int k=0;k<n;k++,j+=len)
                memcpy(a+j,w,sizeof(w));
        }
        a[j]='\0';
        //printf("%s\n",a);
        build(1,0,j-1);
        int cc=1;
        scanf("%d",&q);
        printf("Case %d:\n",cases++);
        while(q--)
        {
            cin>>qq;
            scanf("%d%d",&x,&y);
            switch(qq)
            {
                  case 'F':
                  for(int k=x;k<=y;k++)
                     a[k]='1';
                  update(1,0,j-1);
                  break;
                  
                  case 'I':
                  for(int k=x;k<=y;k++)
                     if(a[k]=='1')a[k]='0';
                     else a[k]='1';
                  update(1,0,j-1);
                  break;
                  
                  case 'E':
                  for(int k=x;k<=y;k++)
                     a[k]='0';
                  update(1,0,j-1);     
                  break;
                  
                  case 'S':
                       printf("Q%d: %d\n",cc++,query(1,0,j-1));
                  break;                  
            }      
            //print(25);
            //printf("%s\n",a);
        }
    }
    //system("pause");

    return 0;
}
