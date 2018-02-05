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
set<char> st;
int main()
{
    string a,b,buf;
    int t;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        getline(cin,a);
        cin>>b;
        int size=b.size();
        st.clear();
        getchar();
        stringstream ss(a);
        while(ss>>buf)
        {
             if(buf.size()==size)
             {
                 int key=0;
                 if(buf[0]<b[0])key=b[0]-buf[0];
                 else key=26+b[0]-buf[0];
                 
                 //printf("%d\n",key);                                    
                 int i=1;
                 for(;i<size;i++)
                 {
                     //printf("[%c][%c]\n",buf[i],b[i]);            
                     if(buf[i]+key>'z')
                     {
                        //printf("yes\n");      
                        //printf("[%c][%c]\n",buf[i]+key-26,b[i]);         
                        if(buf[i]+key-26!=b[i]) break;
                     }
                     else if(buf[i]+key!=b[i])break;    
                 }                
                 if(i==size)
                    st.insert(char('z'+1-key));
                 
             }                       
        }      
        string ans="";
        for(set<char>::iterator it=st.begin();it!=st.end();it++)
           ans+=*it;
        printf("%s\n",ans.c_str());      
    }
    return 0;
}
