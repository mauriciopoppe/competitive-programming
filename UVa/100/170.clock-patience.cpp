#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
#include<string>
using namespace std;
vector< vector<int> > p;
vector<int> q;
char num[13]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
char color[4]={'H','D','C','S'};
int fu[52]={0};
char ls[52][3];

int findNum(char a)
{
    for(int i=0;i<13;i++)
       if(a==num[i])return i;    
    return -1;
}

int findColor(char a)
{
    for(int i=0;i<4;i++)
       if(a==color[i])return i;    
    return -1;
}

int main()
{
    char s[3];
    int n;   
    while(scanf("%s",s) && strcmp(s,"#")!=0)
    {               
        p.clear();            
        memset(fu,0,sizeof(fu));
        strcpy(ls[0],s);
        for(int i=1;i<52;i++)
        {
                scanf("%s",s);
                strcpy(ls[i],s);
        }                         
                       
        int j=0;
        for(int i=51;i>=0;i--)                     
        {
             n=findColor(ls[i][1])*13+findNum(ls[i][0]);               
             if(i>38)
             {
                    q.clear(); 
                    q.push_back(n); 
                    p.push_back(q);
             }   
             else
             {
                    p[j%13].push_back(n);
                    j++;
             }
        }
        
        int c,pile=12,sum=0;
        c=n;
        fu[c]=1;
        printf("%d\n",c);
        
        p[pile].pop_back();
        pile=c%13;
        
        while(!p[pile].empty())
        {
             sum++;                     
             p[pile].insert(p[pile].begin(),c);
             int aux=p[pile].back();
             if(fu[aux])break;
             c=p[pile].back();
             p[pile].pop_back();
             fu[c]=1;          
             pile=c%13;                                       
        }          
        
        s[0]=num[c%13];
        s[1]=color[(int)(c/13)];
        printf("%02d,%s\n",sum,s);         
    }
}



