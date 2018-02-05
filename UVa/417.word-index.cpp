#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
using namespace std;

int main()
{
    int j=1,a,b,c,d,e;
    map<string,int> m;
    char w[6];
    w[1]='\0';
    
    for(a=0;a<26;a++)
       w[0]=a+'a',m[string(w)]=j++;
    
    w[2]='\0';
    for(a=0;a<26;a++)
       for(b=a+1;b<26;b++)
          w[0]=a+'a',w[1]=b+'a',m[string(w)]=j++;
    
    w[3]='\0';
    for(a=0;a<26;a++)
       for(b=a+1;b<26;b++)
          for(c=b+1;c<26;c++)
             w[0]=a+'a',w[1]=b+'a',w[2]=c+'a',m[string(w)]=j++;
          
    w[4]='\0';
    for(a=0;a<26;a++)
       for(b=a+1;b<26;b++)
          for(c=b+1;c<26;c++)
             for(d=c+1;d<26;d++)
                w[0]=a+'a',w[1]=b+'a',w[2]=c+'a',w[3]=d+'a',m[string(w)]=j++;
    
    w[5]='\0';
    for(a=0;a<26;a++)
       for(b=a+1;b<26;b++)
          for(c=b+1;c<26;c++)
             for(d=c+1;d<26;d++)
                for(e=d+1;e<26;e++)
                   w[0]=a+'a',w[1]=b+'a',w[2]=c+'a',w[3]=d+'a',w[4]=e+'a',m[string(w)]=j++;
    
    string ww;
    while(cin>>ww)
    {
        int f=0,len=ww.size();   
        for(int i=0;i<len-1;i++)
           if(ww[i]>=ww[i+1]){f=1;break;}
        
        if(f)printf("0\n");
        else printf("%d\n",m[ww]);         
    }      
    return 0;
}
