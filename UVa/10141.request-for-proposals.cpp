#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<map>
#include<set>
#include<limits>
#include<string>

using namespace std;

int main()
{
    int c=0;
    while(1)
    {
            int r,p;
            cin>>r>>p;
            if(r==0 && p==0)break;
            getchar();
            for(int i=0;i<r;i++)
               {
                    string w;
                    getline(cin,w,'\n');
               }
            
            double max2=(double)(INT_MAX),max;
            string name,name2;
            int req,req2=0;
            
            for(int i=0;i<p;i++)
            {
               getline(cin,name,'\n');
               cin>>max>>req;   
               getchar();
               if(req>req2)
                 {
                      name2=name;
                      req2=req;
                      max2=max;                     
                 }
               
               else if(req==req2 && max<max2)
                {
                    req2=req;
                    name2=name;
                    max2=max;  
                }           
                   
               for(int j=0;j<req;j++)
                   {
                       string str;
                       getline(cin,str,'\n');
                       }
            }
            
            if(c != 0)
            cout << endl;
            
            cout<<"RPF #"<<++c<<endl;
            cout<<name2<<endl;
    }
    return 0;
}
