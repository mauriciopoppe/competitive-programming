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

bitset<12> f;

int main()
{
    string w;
    
    vector<string> v2;
    v2.push_back("C");
    v2.push_back("C#");
    v2.push_back("D");
    v2.push_back("D#");
    v2.push_back("E");
    v2.push_back("F");
    v2.push_back("F#");
    v2.push_back("G");
    v2.push_back("G#");
    v2.push_back("A");
    v2.push_back("A#");
    v2.push_back("B");
    
    while(getline(cin,w,'\n'))
    {
         if(w=="END")break;         
         f.reset();           
         stringstream ss(w);
         string buf;
         while(ss>>buf)
         {
              //cout<<buf<<endl;         
              
              //find index
              int i=0;
              for(i=0;i<12;i++)
                 if(v2[i]==buf)break;
              
              //set to true the ones that doesnt have the note 
              f.set((i+2)%12);
              f.set((i+4)%12);
              f.set((i+6)%12);
              f.set((i+9)%12);
              f.set((i+11)%12);
              
         }
         string res="";                    
         for(int i=0;i<12;i++)
             if(!f.test(i))
               {
                   if(res=="")res+=v2[i];
                   else res+=(" "+v2[i]);
               }
         cout<<res<<endl;          
    }
    return 0;
}
