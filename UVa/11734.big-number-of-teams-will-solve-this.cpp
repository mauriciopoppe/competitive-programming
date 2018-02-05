#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<map>
#include<set>
#include<sstream>
using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    string a,b,buf,good;
    int t;
    scanf("%d",&t);
    getchar();
    for(int i=0;i<t;i++)
    {
            
         string good="",buf="";
         int hs=0;   
         getline(cin,a);   
         for(int j=0;j<a.size();j++)
             if(a[j]==' ')hs=1;
         getline(cin,b);
         stringstream ss(a);
         while(ss>>buf)good+=buf;
         
         //ofe
         printf("Case %d: ",i+1);
         if(good!=b)printf("Wrong Answer\n");
         else if(hs)printf("Output Format Error\n");
         else printf("Yes\n");                       
    }
    return 0;
}
