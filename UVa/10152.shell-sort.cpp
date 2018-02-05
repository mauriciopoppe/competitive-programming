#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>
using namespace std;

int pos(vector<string> *v,string s)
{
   for (int i=0;i<v->size();i++)
        if(s.compare(v->at(i))==0)return i;    
   return 0;
}

bool not_good(bool v[],int j,int n)
{
     for(int i=j;i<n;i++)
             if(!v[i])return true;
     return false;
}

void op(vector<int> &a,vector<string> &v1)
{
     //vector<int>::const_iterator i,j;
     bool v[a.size()];

     for(int i=0;i<a.size();i++)
     {v[i]=false;}
     
     int t=-1;
     for(int i=a.size()-1;i>=0;i--)
     {
         v[a[i]]=true;
         if(not_good(v,a[i],a.size()))                              
            {
            if(a[i]>t)t=a[i];
            }
     }
     
     if(t>=0)
     for(int i=t;i>=0;i--)
     {cout<<v1.at(i)<<endl;}
}



int main()
{
    int n,m;
    string s;
    cin>>n;
    while(n--)
    {
       cin>>m;
       vector<string> v ;
       vector<string> v1 ;
       vector<int> vi ;
       
       cin.ignore(2048, '\n');
       for(int i=0;i<m;i++)
           {getline(cin,s);v.push_back(s);}
 
       for(int i=0;i<m;i++)
           {getline(cin,s);v1.push_back(s);}    
           
       for(int i=0;i<m;i++)
           vi.push_back(pos(&v1,v.at(i)));
       /*
       for(int i=0;i<vi.size();i++)
              cout<<vi[i]<<"  ";
       */
       op(vi,v1);
       cout<<endl;
    }        
}
