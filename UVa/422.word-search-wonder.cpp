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

char m[102][102];
int x,y,size;

bool ch(string &s,int &i, int &j)
{
     x=i;
     y=j;
     size=s.size();
     for(int k=0;k<size;k++)
        if(m[x][y++]!=s[k])return false;
     x++;
     printf("%d,%d %d,%d\n",i+1,j+1,x,y);
     return true;        
}

bool cv(string &s,int &i, int &j)
{
     x=i;
     y=j;
     size=s.size();
     for(int k=0;k<size;k++)
        if(m[x++][y]!=s[k])return false;
     y++;
     printf("%d,%d %d,%d\n",i+1,j+1,x,y);                
     return true;        
}

bool cd(string &s,int &i, int &j)
{
     x=i;
     y=j;
     size=s.size();
     for(int k=0;k<size;k++)
        if(m[x++][y++]!=s[k])return false;
     printf("%d,%d %d,%d\n",i+1,j+1,x,y);
     return true;        
}

bool cd2(string &s,int &i, int j)
{
     x=i;
     y=j;
     size=s.size();
     for(int k=0;k<size;k++)
        if(m[x++][y--]!=s[k])return false;
     y+=2;
     printf("%d,%d %d,%d\n",i+1,j+1,x,y);
     return true;        
}

bool rch(string &s,int &i, int &j)
{
     x=i;
     y=j;
     size=s.size();
     for(int k=0;k<size;k++)
        if(m[x][y--]!=s[k])return false;
     x++;
     y+=2;
     printf("%d,%d %d,%d\n",i+1,j+1,x,y);
     return true;        
}

bool rcv(string &s,int &i, int &j)
{
     x=i;
     y=j;
     size=s.size();
     for(int k=0;k<size;k++)
        if(m[x--][y]!=s[k])return false;
     y++;
     x+=2;
     printf("%d,%d %d,%d\n",i+1,j+1,x,y);                
     return true;        
}

bool rcd(string &s,int &i, int &j)
{
     x=i;
     y=j;
     size=s.size();
     for(int k=0;k<size;k++)
        if(m[x--][y--]!=s[k])return false;
     x+=2;
     y+=2;
     printf("%d,%d %d,%d\n",i+1,j+1,x,y);
     return true;        
}

bool rcd2(string &s,int &i, int j)
{
     x=i;
     y=j;
     size=s.size();
     for(int k=0;k<size;k++)
        if(m[x--][y++]!=s[k])return false;
     x+=2;
     printf("%d,%d %d,%d\n",i+1,j+1,x,y);
     return true;        
}

int main()
{
    //freopen("wsw.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t=0,i,j;
    string s,rev;
    scanf("%d",&t);
    for(i=0;i<t;i++)
         scanf("%s",m[i]);
     
    while(cin>>s && s[0]!='0')
    {     
         int len=s.size();
         int mx=t-len;
         
         for(i=0;i<t;i++)
            for(j=0;j<t;j++)
            {      
                if(j<=mx && ch(s,i,j))goto l2;
                if(i<=mx && cv(s,i,j))goto l2;
                if(i<=mx && j<=mx && cd(s,i,j))goto l2;
                if(j>=len-1 && i<=mx && cd2(s,i,j))goto l2;           
                                   
                if(j>=len-1 && rch(s,i,j))goto l2;
                if(i>=len-1 && rcv(s,i,j))goto l2;
                if(i>=len-1 && j>=len-1 && rcd(s,i,j))goto l2;
                if(i>=len-1 && j<=mx && rcd2(s,i,j))goto l2;               
            }
         printf("Not found\n");
         continue;                   
         l2: 
             continue;             
    }
    return 0;
}
