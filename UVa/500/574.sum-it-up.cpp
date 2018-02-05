#include<iostream>
#include<bitset>
#include<set>
#include<string>
#include<sstream>
#include<functional>
using namespace std;
bool sol=false;
int t,n;
int a[12];
bitset<12> b;

set<string> res;
void bt(int k)
{
     if(k==n)
     {
         int s=0;
         for(int i=0;i<n;i++)
            if(b.test(i))s+=a[i];
         if(s==t)
         {
                 sol=true;
                 stringstream ss;      
                 int k=b.count()-1;  
                 for(int i=0;i<n;i++)
                         if(b.test(i))
                         {            
                               ss<<a[i];
                               if(k)ss<<"+";
                               k--;
                         }
                 res.insert(ss.str());
         }             
             
     }
     else
     {
         b.set(k);
         bt(k+1);
         b.set(k,0);
         bt(k+1);   
     }
}

void print()
{
     set<string>::reverse_iterator i;
     for(i=res.rbegin();i!=res.rend();i++)
        cout<<*i<<endl;
}

int main()
{
    while(cin>>t>>n)
    {
         if(t+n==0)break;
         sol=false;
         res.clear();
         for(int i=0;i<n;i++) 
                 cin>>a[i];
         b.reset();
         cout<<"Sums of "<<t<<":"<<endl;
         bt(0);
         if(!sol)cout<<"NONE"<<endl;   
         else print();
    }
}
