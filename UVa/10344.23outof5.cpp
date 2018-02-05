#include<iostream>
#include<algorithm>
using namespace std;
int a[6];
bool t=false;

void backtrack(int i,long s)
{
     //cout<<s<<endl;
     if(t)return;
     if(i>4)
             {
                 if(s==23){t=true;}
                 return;
             }
     backtrack(i+1,s+a[i]);
     backtrack(i+1,s-a[i]);
     backtrack(i+1,s*a[i]);
}

int main()
{
    while(scanf("%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4])==5)
    {
    if(a[0]+a[1]+a[2]+a[3]+a[4]==0)break;
    t=false;
    sort (a,a+5);
    do
      {
      backtrack(1,a[0]);      
      //cout<<"next input -------------"<<endl;
      }while(!t && next_permutation(a,a+5));                                                           
      if(t)cout<<"Possible"<<endl;
      else cout<<"Impossible"<<endl;                                                         
    }
}
