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
    string x;
    string word="roygb";
    while(1)
    {        
         vector<string> w;                 
         while(1)
         {
              getline(cin,x);
              if(x=="#")goto ex;
              if(x[0]=='e')break;
              w.push_back(x);
         }                     
         
         int t=999999999,index=-1;
         
         for(int i=0;i<w.size();i++)
         {
             int sum=0;
             map<char,char> wa;
             for(int j=0;j<w[i].size();j+=4)
                 wa[w[i][j]]=w[i][j+2];
              
             for(int j=0;j<w.size();j++)    
             {
                 if(i!=j)
                 {
                     map<char,char> wb;
                     for(int k=0;k<w[j].size();k++)
                        wb[w[j][k]]=w[j][k+2];
                     
                     for(int k=0;k<word.size();k++)
                        if(wa[word[k]]!=wb[word[k]])sum++;
                 }
             }    
             if(sum<t){t=sum;index=i;}
         }
         printf("%d\n",index+1);
    }
    ex:
    return 0;
}
