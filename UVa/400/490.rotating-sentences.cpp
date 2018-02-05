#include<iostream>
#include<string>
using namespace std;
int main()
{
    char c;
    int nl=0;
    int max=0,i=0;
    char a[1000][1000];
    while((c=getchar())!=EOF)
    {
         if(c=='\n')
         {
            if(i<max)
               for(int j=i;j<max;j++)
                   a[nl][j]=' ';        
            if(i>=max)max=i;
            i=0;        
            nl++;
         }
         else {a[nl][i++]=c;}                                                              
    }
    if(i>max)max=i;
    nl--;
       
    for(i=0;i<max;i++)
    {
        for(int j=nl;j>=0;j--)                  
            cout<<a[j][i];           
        cout<<endl;
    }
    //system("pause");
}
