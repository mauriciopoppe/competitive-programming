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
#include<sstream>
using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

    int cc[35],g;
    char w[100];
    string t;   
    while(1)
    {
         memset(cc,0,sizeof(cc));
         if(w[0]!='#')
         while(gets(w) && w[0]!='#')
         {
              if(strcmp(w,"#")==0)break;
              t+=string(w);
              int size=t.size();    
              //printf("[%c]",t[size-1]);
              while(t[size-1]==' ')t.erase(size-1,1),size--;               
              if(t[size-1]!='\'' && t[size-1]!='-')t+=" ";              
         }   
         int size=t.size();        
         //cout<<t<<endl;
         for(int i=0;i<size;i++)
         {
             if(t[i]=='\'' || t[i]=='-')
             {
                  t.erase(i,1);
                  size--;                     
             }        
             else if(!isalnum(t[i]))t[i]=' ';                      
         }
         //cout<<t<<endl;
         stringstream ss(t);
         string buf;
         while(ss>>buf)
              cc[buf.size()]++;                       
         
         for(int i=0;i<35;i++)
            if(cc[i])printf("%d %d\n",i,cc[i]);
         
         printf("\n");
         t="";
         if(scanf("%s",w)==EOF)break;
         t+=string(w);           
    }
    return 0;
}
