#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cctype>
#include<sstream>
using namespace std;
set<string> v;
int main()
{
    char a[10000];
    int f;
    string w="",t="";
    while(getline(cin,w))
    {
         f=0;                
         if(w[w.size()-1]=='-'){w[w.size()-1]='0';f=1;}
         int j=0;
         for(int i=0;i<w.size();i++)
         {
             w[i]=tolower(w[i]);
             if(isalpha(w[i]) || w[i]=='-' || w[i]==' ')a[j++]=w[i];
             else if(w[i]!='0')a[j++]=' ';
         }
         a[j]='\0';
         t+=string(a);
         if(!f)t+=" ";
         //cout<<t<<endl;
    }
    stringstream ss(t);
    string buf;
    while(ss>>buf)
        v.insert(buf);
    
    for(set<string>::iterator it=v.begin();it!=v.end();it++)
       cout<<*it<<endl;
    //system("pause");

    return 0;
}
