#include<stdio.h>
#include<string.h>

char w[1000003],b[15];
int n,i,j,k,m,max;

struct node{
       int c;
       node *n[26];
       node(){c=0;memset(n,0,sizeof(n));}
       } *root;

void insert()
{
     node *r=root;
     for(k=i;k<j;++k)
     {
          char t=w[k]-'a';   
          if(r->n[t]==NULL)r->n[t]=new node();
          r=r->n[t];
     } 
     (r->c)++;
     if(r->c>max)     
     {
          m=-1;
          max=r->c;
          for(k=i;k<j;b[++m]=w[k],++k);    
     }
}

int main()
{
    int ss;
    while(scanf("%d",&n)!=EOF)
    {
          getchar();
          gets(w);
          ss=strlen(w)-n+1;
          root=new node();
          m=max=i=0;
          j=i+n;
          for(int x=0;x<ss;++x,++i,++j)
             insert();              
          
          b[n]='\0';
          printf("%s\n",b);
    }
    return 0;
}
