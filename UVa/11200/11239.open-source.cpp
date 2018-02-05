#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<map>
#include<set>
#include<cctype>
using namespace std;

struct os{
       string n;
       set<string> names;
       os(string a,set<string> w){n=a;names=w;}
       bool operator<(const os &a)const
            {
            if(names.size()!=a.names.size())return names.size()>a.names.size();
            return n<a.n;
            }                                
       };

int main()
{
    string w="",nm;
    set<string> global;
    while(1)
    {
          vector<os> v;
          global.clear();
          while(1)
          {
              set<string> aux;    
              if(w=="")getline(cin,nm);
              else nm=w;
              if(w=="1" || nm=="1")break;
              while(getline(cin,w) && islower(w[0]) && w!="1")
              {
                   if(global.find(w)==global.end())
                   {
                        global.insert(w);                                                      
                        aux.insert(w);                
                   }   
                   else
                   {
                       for(int i=0;i<v.size();i++)
                       {
                           if(v[i].names.find(w)!=v[i].names.end())
                               v[i].names.erase(v[i].names.find(w));
                       }
                   }
              }     
              v.push_back(os(nm,aux));
              
              //for(int i=0;i<v.size();i++)
              //   printf("%d --\n",v[i].names.size());
              
              if(w=="1")break;
          }
          
          sort(v.begin(),v.end());
          for(int i=0;i<v.size();i++)
              printf("%s %d\n",v[i].n.c_str(),v[i].names.size());        
          getline(cin,w);
          if(w=="0")break;
          v.clear();
    }
    //system("pause");

    return 0;
}
