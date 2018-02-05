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
using namespace std;

struct bud{
       string w;
       int c;
       bud(string a, int b){w=a;c=b;}
       bool operator<(const bud& x)
       const{
         if(x.c!=c)return x.c>c;    
         return !lexicographical_compare(x.w.begin(),x.w.end(),w.begin(),w.end());    
       }
       };

int main()
{
    int n,aux,w;
    string name,ing,a;
    vector<bud> v;
    cin>>n;
    for(int q=0;q<n;q++)
    {
        v.clear();
        getchar();    
        getline(cin,name);
        for(int i=0;i<name.size();i++)
            name[i]=toupper(name[i]);
        cout<<name<<endl;
        int n,m,b;
        map<string,int> ing;
        scanf("%d%d%d",&n,&m,&b);
        for(int i=0;i<n;i++)
        {
             cin>>a>>aux;
             ing[a]=aux;                        
        }
        
        for(int i=0;i<m;i++)
        {
             getchar();   
             int t=0;   
             //printf("a\n");
             getline(cin,name);
             //printf("here");
             cin>>w;
             for(int j=0;j<w;j++)
             {
                 cin>>a>>aux;
                 t+=ing[a]*aux;
             }      
             //printf("COOOOOOOOOOOOOOOST %d\n",t);
             if(t<=b)v.push_back(bud(name,t));
        }
        if(v.size()==0)printf("Too expensive!\n");
        else
        {
            //cout<<v[0].c<<endl;
            sort(v.begin(),v.end());
            //cout<<v[0].c<<endl;            
            for(int i=0;i<v.size();i++)
              cout<<v[i].w<<endl;    
        }  
        printf("\n");
    }
    //system("pause");

    return 0;
}
