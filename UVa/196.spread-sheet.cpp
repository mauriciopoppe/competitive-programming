#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
using namespace std;

typedef long long LL;

LL pw(int w)
{
    LL p=1;
    while(w--)
    {
        p*=26;      
    }      
    return p;
}

int main()
{
    int r,c,q;
    char w[150000];
    while(cin>>r>>c)
    {
         cin>>q;
         getchar();
         
         while(q--)
         {
              gets(w);
              if(isalpha(w[0]))
              {
                  int i=0,len=strlen(w);             
                  while(isalpha(w[i]))i++;                  
                  string aux1=string(w,w+i);
                  
                  string aux2=string(w+i,w+len);
                  int  b=atoi(aux2.c_str());
                  
                  //cout<<aux1<<" "<<aux2<<endl;
                  LL res=0;
                  
                  res+=(b-1)*c;
                  //printf("%lld\n",res);
                  for(int i=aux1.size()-1,j=0;i>=0;i--,j++)
                  {
                     int t=aux1[i]-'A'+1;                             
                     res+=((LL)t*pw(j));
                  }
                  
                  printf("%lld\n",res);     
              }
              else
              {
                  int b=atoi(w);
                  int row=((b-1)/c)+1;
                  int col=((b-1)%c)+1;
                  //cout<<col<<endl;
                  string w="";
                  while(col)
                  {                            
                       w=char((col%26)-1+'A')+w;
                       col/=26;
                  }
                  cout<<w<<row<<endl;
              }
         }           
    }
    return 0;
}
