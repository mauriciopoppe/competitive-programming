#include <iostream>          //  Accepted
#include <cstdlib>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <ctype.h>
using namespace std;
vector<int> num,lis,last,array2;

int main()
{
    int n;
    char str[11];
    cin>>n;
    getchar();
    cin.getline(str, 11, '\n');
    for(int q=0;q<n;q++)
    {
        if(q!=0)printf("\n");
        num.clear();
        lis.clear();
        last.clear();
        array2.clear();
        while(cin.getline(str, 11, '\n'))
        {
             if(strlen(str)==0)break;
             num.push_back(atoi(str));
             lis.push_back(0);
             last.push_back(-1);
        }
        
        lis[0]=1;
        int max=0,pmax=0;
        
        for(int i=0;i<num.size()-1;i++)
           for(int j=i+1;j<num.size();j++)
               if(num[j]>num[i] && lis[i]+1>lis[j])
                  {
                       lis[j]=lis[i]+1;
                       last[j]=i;
                       if(lis[j]>max){max=lis[j];pmax=j;}              
                  }          

        while(last[pmax] != -1)
        {
            array2.push_back(num[pmax]);
            pmax = last[pmax];
        }
        
        array2.push_back(num[pmax]);
        
        cout << "Max hits: " << array2.size() << endl;
        
        for(int i = array2.size()-1; i >= 0; i--)
            cout << array2[i] << endl;
    }   
    return 0;
}
