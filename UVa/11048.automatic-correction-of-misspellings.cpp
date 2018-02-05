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

int dp[10002];
char dic[100002][30];

struct node{
       int c;
       node *n[26];
       node(){c=0;memset(n,0,sizeof(n));}
       } *root;

void insert(char *w)
{
      node *r=root;
      char t;
      for(;*w;w++)
      {
           t=*w-'a';      
           if(r->n[t]==NULL)
              r->n[t]=new node();
           r=r->n[t];                   
      }                
      r->c=1;
}

bool find(char *w)
{
     node *r=root;
     for(;*w;w++)
     {
          char t=*w-'a';
          if(r->n[t]==NULL)return false;
          r=r->n[t];                   
     }
     if(r->c)return true;
     return false;               
}

bool diff(char w[], char a[],int &s)
{
     int e=1;
     for(int i=0;i<s;i++)
     {
        if(w[i]!=a[i])
        {
             if(!e)return false;
             e--;
        }
     }
     return true;
}

bool diff_l(char w[], char a[], int &s)
{
     int e=1;
     for(int i=0,j=0;i<s;i++)
     {
        if(w[i]!=a[j++])
        {
             if(!e)return false;
             e--;
             i--;
        }
     }
     return true;
}

bool diff_m(char w[], char a[], int &s)
{
     int e=1;
     for(int i=0,j=0;i<s;i++,j++)
     {
        //printf("[%c] [%c]\n",w[i],a[j]);     
        if(w[i]!=a[j])
        {
             if(!e)return false;
             e--;
             j--;
             //printf("%d\n",e);
        }
     }
     return true;
}
int main()
{
    root=new node();
    int n,i,k,j;
    char w[30],w2[30];  
    
    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
        scanf("%s",dic[i]);
        insert(dic[i]);                
        dp[i]=strlen(dic[i]);
    }
    
    int q;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%s",&w);
        if(find(w))
        {      
             printf("%s is correct\n",w);                
             continue;
        }
        
        int len=strlen(w);
        for(int k=0;k<n;k++)
        {
            if(dp[k]==len)
            {
                strcpy(w2,w);
                for(i=0;i<dp[k]-1;i++)
                {
                    swap(w2[i],w2[i+1]);
                    if(strcmp(w2,dic[k])==0)break;
                    swap(w2[i],w2[i+1]);    
                }
                
                if(i!=dp[k]-1 || diff(w,dic[k],dp[k]))
                {       
                    printf("%s is a misspelling of %s\n",w,dic[k]);
                    goto l1;
                }                                    
            }    
            
            else if(len-1==dp[k] && diff_m(w,dic[k],len))
            {
                 //printf("1");
                 printf("%s is a misspelling of %s\n",w,dic[k]);
                 goto l1;                   
            }
            
            else if(len+1==dp[k] && diff_l(w,dic[k],dp[k]))
            {
                 //printf("2");
                 printf("%s is a misspelling of %s\n",w,dic[k]);
                 goto l1;                   
            }    
        //no option    
        }
        printf("%s is unknown\n",w);
        continue;
        l1:;
    }
    
    return 0;
}
