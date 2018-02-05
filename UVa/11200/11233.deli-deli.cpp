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

bool isC(char c)
{
     if(c!='a' && c!='e' && c!='i' && c!='o' && c!='u')return true;     
     return false;
}

bool we(char c)
{
     if(c=='o' || c=='s' || c=='x')return true;
     return false;     
}

bool we2(char a, char b)
{
      if(a=='c' && b=='h')return true;
      if(a=='s' && b=='h')return true;
      return false;     
}

int main()
{
    int pl,lin;
    string a,b;
    map<string,string> m;
    scanf("%d %d",&pl,&lin);
    for(int i=0;i<pl;i++)
    {
        cin>>a>>b;
        m[a]=b;        
    }
    
    for(int i=0;i<lin;i++)
    {
        cin>>a;
        if(m.find(a)!=m.end())
             cout<<m[a]<<endl;
        else if(isC(a[a.size()-2]) && a[a.size()-1]=='y')
        {
             a.erase(a.size()-1,1);
             a+="ies";
             cout<<a<<endl;     
        }
        else if(we(a[a.size()-1]) || we2(a[a.size()-2],a[a.size()-1]))
        {
             a+="es";
             cout<<a<<endl;     
        }
        else{a+="s";cout<<a<<endl;}     
    }
    return 0;
}
