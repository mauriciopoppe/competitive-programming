#include <iostream>          //  Accepted
#include <cstdlib>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <ctype.h>

using namespace std;

int main()
{
    int n = 0;
    vector<int> array, array2;
    char str[11];
    
    cin >> n;
    getchar();
    cin.getline(str, 11, '\n');
    
    for(n--; n >= 0; n--)
    {
        array.clear();
        array2.clear();
        
        while(cin.getline(str, 11, '\n'))
        {
            if(strlen(str) == 0)
                break;
            
            array.push_back(atoi(str));
        }
        
        int len[array.size()], last[array.size()];
        int max_len = 0, pos = 0;
        
        fill(len, len+array.size(), 0);
        fill(last, last+array.size(), -1);
        
        len[0] = 1;
        
        for(int i = 1; i < array.size(); i++)
        {
            for(int j = i-1; j >= 0; j--)
            {
                if((array[i] > array[j])&&(len[i] < len[j]+1))
                {
                    len[i] = len[j] + 1;
                    last[i] = j;
                    
                    if(len[i] > max_len)
                    {
                        max_len = len[i];
                        pos = i;
                    }
                }
            }
        }
        
        while(last[pos] != -1)
        {
            array2.push_back(array[pos]);
            pos = last[pos];
        }
        
        array2.push_back(array[pos]);
        
        cout << "Max hits: " << array2.size() << endl;
        
        for(int i = array2.size()-1; i >= 0; i--)
            cout << array2[i] << endl;
        
        if(n != 0)
            cout << endl;
    }
    
    return 0;
}
