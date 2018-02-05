#include<iostream>
using namespace std;
int n,k,b,s=0;

void bfs(int a[],int k)
{
     if(k==b)s++;     
     else
     {
     k++;
     int c[9],issol;
     //int cand=cc(a,c,k);
        for(int i=1;i<=n;i++)
        {
             issol=true;
             for(int j=1;j<k;j++)
                 if(abs(k-j)==abs(i-a[j])){issol=false;break;}                                
             if(issol)
             {
                 a[k]=k;
                 bfs(a,k);
             }
        }    
     }
}

int main()
{
    while(cin>>n>>b)
    {
         int a[9];
         bfs(a,0);        //normal
         //bfs(a,0);        //reverse
         cout<<s*4<<endl;
         s=0;        
    }        
}
