#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<map>
#include<set>
using namespace std;

int main()
{
    int n;
    cin>>n;
    map<char,int> m;
    while(n--)
    {
          m.clear();
          int k,art,v;
          char l;
          scanf("%d",&k);
          for(int i=0;i<k;++i)
          {
              cin>>l>>v;
              m[l]=v;
          }
          
          scanf("%d",&art);
          //printf("art=%d",art);
          string w;
          int total=0;
          for(int i=0;i<=art;i++)
          {
              //printf("i = %d\n",i);    
              getline(cin,w);
              int size=w.size();
              for(int j=0;j<size;++j)    
              {
                 if(m.find(w[j])!=m.end())        
                    {
                        total+=m.find(w[j])->second;
                        //printf("letter %c\n",m.find(w[j])->first);
                        //printf("total = %d\n",total);
                    }
              }
              //printf("total=%d\n",total);
          }              
          
          //printf("%d\n",total);
          
          if(total<100)printf("0.%02d$\n",total);
          else
          {
              
              double t=(double)total/100.0;
              printf("%.02lf$\n",t);
          }
    }
    return 0;
}
