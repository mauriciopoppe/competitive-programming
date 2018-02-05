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

int main()
{
    char r[13][3]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int v[13]={1000,900,500,400,100,90,50,40,10,9,5,4,1},val;
    
    map<char,int> m;
    m['M']=1000;
    m['D']=500;
    m['C']=100;
    m['L']=50;
    m['X']=10;
    m['V']=5;
    m['I']=1;
    
    
    string w;
    while(cin>>w)
    {
         if(isdigit(w[0]))
         {
                val=atoi(w.c_str()); 
                int i=0;
                while(val>0)
                {
                     if(val>=v[i])
                        {
                             printf("%s",r[i]);
                             val-=v[i];
                        }
                     else i++;
                }
                printf("\n");
                
         }
         else
         {
             int total=0;
             char t=w[0];
             total+=m[w[0]];
             for(int i=1;i<w.size();i++)
             {
                 if(m[w[i]]>m[t])total=total-2*m[w[i-1]]+m[w[i]];
                 else total+=m[w[i]];
                 t=w[i];
             }    
             printf("%d\n",total);
         }         
    }
    
    return 0;
}
