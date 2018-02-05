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

char dic[50000][200],a[200],b[200];

struct node{
       int c;
       node* L[26];
       node(){c=0;memset(L,0,sizeof(L));}
       } *root;
       
void insert(char *w)
{
     node *r=root;
     char t;
     for(;*w;w++)
     {
          t=*w-'a';       
          if(r->L[t]==NULL)
             r->L[t]=new node();
          r=r->L[t];                     
     }
     r->c=1;
}

bool find(char *w)
{
     node *r=root;
     char t;
     for(;*w;w++)
     {
         t=*w-'a';             
         if(r->L[t]==NULL)return false;
         r=r->L[t];                    
     }     
     if(r->c)return true;
     return false;
}

int main()
{
    root=new node();
    int n=0;
    while(scanf("%s",dic[n])!=EOF)
        insert(dic[n++]);                     
    
    for(int i=0;i<n;i++)
    {
        int len=strlen(dic[i]);
        int k,x;
        
        //split the word [i,j-1] [j,len]
        for(int j=1;j<len;j++)
        {
             for(k=0;k<j;k++)
                a[k]=dic[i][k];                   
             a[k]='\0';
             
             for(x=0,k=j;k<len;k++,x++)
                b[x]=dic[i][k];
             b[x]='\0';
             if(find(a) && find(b))
             {
                printf("%s\n",dic[i]);
                break;
             }
        }                
    }
    system("pause");

    return 0;
}
