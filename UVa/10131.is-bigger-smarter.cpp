#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct elephant{
       int w,iq,pos;
       bool operator<(const elephant &a)const{if(a.w!=w)return a.w>w;else return a.iq>iq;}
       elephant(int a, int b, int c):w(a),iq(b),pos(c){}
};

int main()
{
       vector<elephant> v;
       vector<int> place;
       int a,b,c=1;
       while(cin>>a>>b)
           {
           elephant *e=new elephant(a,b,c);
           v.push_back(*e); 
           c++;
           }
       sort(v.begin(),v.end());

       int size=v.size(),max=0,pos=0;
       int lis[size],next[size];
       
       fill(lis,lis+size,1);
       fill(next,next+size,-1);
       
       for(int i=0;i<size-1;i++)
          for(int j=i+1;j<size;j++)
              if(v[j].w>v[i].w && v[i].iq>v[j].iq && lis[i]+1>lis[j])
              {
                   lis[j]=lis[i]+1;
                   next[j]=i;
                   if(lis[j]>max){max=lis[j];pos=j;}           
              }
              
       while(next[pos]!=-1)
       {
            place.push_back(v[pos].pos);                    
            pos=next[pos];               
       }
       place.push_back(v[pos].pos);
       
       printf("%d\n",place.size());
       for(int i=place.size()-1;i>=0;i--)
          printf("%d\n",place[i]);
       system("pause");
}
