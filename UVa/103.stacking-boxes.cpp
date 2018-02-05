#include<iostream>
#include<algorithm>
#include<bitset>
#include<vector>
#include<functional>
#include<numeric>
#define C 35

using namespace std;

struct box{
       vector<int> b;
       int pos;
       box(int a):pos(a){}
       bool operator<=(const box& other) const {
		return (lexicographical_compare(b.begin(), b.end(),
			other.b.begin(), other.b.end()));
	}
       };

vector<box> num;
int lis[C],next[C],nb,m;

bool cmp(box a, box b)
{
    for(int i=0;i<m;i++)
       if(a.b[i]>=b.b[i])return 0;      
    return 1;
}

bool sum(box a, box b)
{
    for(int i=0;i<m;i++)
       {
            if(a.b[i]>b.b[i])return 0;      
            else if(a.b[i]<b.b[i])return 1;
        }
    return 1;
}

int main()
{
    int aux;
    vector<int> final;
    while(cin>>nb>>m)
    {
         final.clear();
         num.clear();
         for(int i=0;i<nb;i++)
         {
             box *newBox=new box(i+1);                
             for(int j=0;j<m;j++)
             {
                     cin>>aux;
                     newBox->b.push_back(aux);                        
             }
             sort((newBox->b).begin(), (newBox->b).end(), greater<int>());
             num.push_back(*newBox);
         }
         
         /*
         printf("==========\n");
         for(int i=0;i<nb;i++)
         {
             for(int j=0;j<m;j++)
                printf("%d ",num[i].b[j]);
             printf("\n");
         }
         */
         
         //printf("==========  %d\n",num.size());
         sort(num.begin(),num.end(),less_equal<box>());         
         
         /*
         printf("==========\n");
         for(int i=0;i<nb;i++)
         {
             for(int j=0;j<m;j++)
                printf("%d ",num[i].b[j]);
             printf("\n");
         }    
         printf("==========\n");
         */
         fill(lis,lis+nb,1);
         fill(next,next+nb,-1);
         
         
         int max=0,pmax=0;
         //lis
         for(int i=0;i<nb-1;i++)
            for(int j=i+1;j<nb;j++)
               if(cmp(num[i],num[j]) && lis[i]+1>lis[j])         
               {
                      lis[j]=lis[i]+1;
                      next[j]=i;
                      if(lis[j]>max)
                      {
                          max=lis[j];
                          pmax=j;          
                      }                                      
               }
         
         //printf("%d\n",max);
         //system("pause");      
         while(next[pmax]!=-1)
         {
              final.push_back(num[pmax].pos);
              pmax=next[pmax];                     
         }      
         
         final.push_back(num[pmax].pos);
         printf("%d\n",final.size());
         //system("pause");  
         for(int i=final.size()-1;i>=0;i--)
            {
                 if(i!=final.size()-1)printf(" ");
                 printf("%d",final[i]);
            }
       printf("\n");
    }    
}
