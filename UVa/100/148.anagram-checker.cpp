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
#define M 26
using namespace std;

vector<vector<string> > v;

char w[2001][22];
int size=0;

bool contains(int word[],int n)
{
     int t[M];
     copy(word,word+M,t);
     
     int len=strlen(w[n]);
     for(int k=0;k<len;k++)    
         if(t[w[n][k]-'A']==0)return false;        
         else t[w[n][k]-'A']--;
     return true;
}

void kill(char buf[], int word[], int ind)
{
     int t[M];
     copy(word,word+M,t);
     
     //kill
     int len=strlen(w[ind]);
     for(int i=0;i<len;i++)
          t[w[ind][i]-'A']--;

     int j=0;
     for(int i=0;i<M;i++)
          if(t[i])
          {
              int temp=t[i];
              while(temp--)
                  buf[j++]=(char)(i+'A');           
          }     
          buf[j]='\0';
}

void bt(char buf[],vector<string> x,int c)
{
     if(strlen(buf)==0)
            v.push_back(x);
     else
     {
            vector<string> temp(x);
            
            int word[M];
            fill(word,word+M,0);
            int len=strlen(buf);
            for(int i=0;i<len;i++)
              word[buf[i]-'A']++;

            for(int a=c;a<size;a++)
            {     
               if(strlen(w[a])<=len && contains(word,a))
               {     
                     //printf("[%s] %d\n",buf,strlen(buf));                           
                     kill(buf,word,a);
                     x.push_back(string(w[a]));
                     //printf("[%s] %d\n",buf,strlen(buf));
                     //system("pause");
                     bt(buf,x,a+1);   
                     x=temp;  
               }                                  
            }                                            
     }     
}

int main()
{
    char buf[22];
    for(;;size++)
    {
        scanf("%s",w[size]);
        if(strcmp(w[size],"#")==0)break;
    }
    
    getchar();
    while(gets(buf) && strcmp(buf,"#")!=0)
    {
          v.clear();          
          int l=strlen(buf);
          string org(buf);
          char nw[26];
          int j=0;
          for(int i=0;i<l;i++)
             if(buf[i]!=' ')nw[j++]=buf[i];
          nw[j]='\0';
          strcpy(buf,nw);
          //printf("MAIN [%s]\n",buf);
          vector<string> x;
          bt(buf,x,0);
          x.clear();
          
          stringstream ss(org);
          string buf;
          while(ss>>buf)
                x.push_back(buf);
          
          sort(x.begin(),x.end());  
          
          string sorted="",test;
          for(int i=0;i<x.size();i++)
          {
              if(i)sorted+=" ";
              sorted+=x[i];
          }
              
          int k=0;
          for(int i=0;i<v.size();i++)
          {
               test="";   
               for(j=0;j<v[i].size();j++)
               {
                     if(j)test+=" ";
                     test+=v[i][j];
               }      
               
               if(test!=sorted)
                    printf("%s = %s\n",org.c_str(),test.c_str());              
          }                    
    }
    
    return 0;
}
