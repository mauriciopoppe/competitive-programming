#include<iostream>
#include<cctype>
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

int main()
{
    map<string,char> m;

    m[".-"]='A';
    m["-..."]='B';
    m["-.-."]='C';
    m["-.."]='D';
    m["."]='E';
    m["..-."]='F';
    m["--."]='G';
    m["...."]='H';
    m[".."]='I';
    m[".---"]='J';
    m["-.-"]='K';
    m[".-.."]='L';
    m["--"]='M';
    m["-."]='N';
    m["---"]='O';
    m[".--."]='P';
    m["--.-"]='Q';
    m[".-."]='R';
    m["..."]='S';
    m["-"]='T';
    m["..-"]='U';
    m["...-"]='V';
    m[".--"]='W';
    m["-..-"]='X';
    m["-.--"]='Y';
    m["--.."]='Z';
    m["-----"]='0';
    m[".----"]='1';
    m["..---"]='2';
    m["...--"]='3';
    m["....-"]='4';
    m["....."]='5';
    m["-...."]='6';
    m["--..."]='7';
    m["---.."]='8';
    m["----."]='9';
    m[".-.-.-"]='.';
    m["--..--"]=',';
    m["..--.."]='?';
    m[".----."]='\'';
    m["-.-.--"]='!';
    m["-..-."]='/';
    m["-.--."]='(';
    m["-.--.-"]=')';
    m[".-..."]='&';
    m["---..."]=':';
    m["-.-.-."]=';';
    m["-...-"]='=';
    m[".-.-."]='+';
    m["-....-"]='-';
    m["..--.-"]='_';
    m[".-..-."]='"';
    m[".--.-."]='@';
    
    int n;
    cin>>n;
    getchar();
    for(int i=1;i<=n;i++)
    {
         string s="";
         string w="";
         int c,spc=0;
         while((c=getchar())!='\n')
         {
              if(c==' ')
              {
                  spc++;
                  if(spc==2)
                  {
                     w+=" ";
                     spc=0;
                  }
                  else if(spc==1 && s!="")
                  {
                     w+=m[s];
                     s="";
                  }
              }              
              else 
              {
                   s+=c;
                   if(spc)spc=0;
              }               
              //cout<<s<<endl;                        
         }
         w+=m[s];
         printf("Message #%d\n",i);
         printf("%s",w.c_str());                
         printf("\n");
         if(i!=n)printf("\n");
    }
    return 0;
}
