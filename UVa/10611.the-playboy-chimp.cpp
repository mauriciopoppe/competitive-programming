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

int a[50001];
int down, up, mid;

int bsearch(int key)
{
    int find=-1;
    while(down<=up)
    {
         mid=(down+up)>>1;
         if(a[mid]==key)return mid;
         if(a[mid]>key)up=mid-1;
         else down=mid+1;     
                    
    }
    return -1;
}

int main()
{
    set<int> s;
    int n,q,c;
    scanf("%d",&n);
    for(q=0;q<n;++q)
    {
        scanf("%d",&c);
        s.insert(c);
    }
    
    n=0;
    for(set<int>::iterator it=s.begin();it!=s.end();it++)
        a[n++]=*it;   
    
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
         down=0;
         up=n-1;
         scanf("%d",&c);
         int res=bsearch(c);
         
         
         if(res!=-1)
         {
               if(up==down && up==0)printf("X X\n");     
               else if(mid!=0 && mid!=n-1)printf("%d %d\n",a[mid-1],a[mid+1]);
               else if(mid==n-1)printf("%d X\n",a[n-2]);
               else if(mid==0)printf("X %d\n",a[mid+1]);                
         } 
         else
         {
               if(up==-1)printf("X %d\n",a[0]);
               else if(down==n)printf("%d X\n",a[n-1]);
               else printf("%d %d\n",a[up],a[down]);
         }                        
    }
    return 0;
}
