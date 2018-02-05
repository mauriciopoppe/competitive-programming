#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    while(getline(cin,s))
    {
          for(string::const_iterator i=s.begin();i!=s.end();i++)
          cout<<(char)(*i-7);               
          cout<<endl;                   
    }    
}
