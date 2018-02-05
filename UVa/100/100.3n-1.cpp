#include<iostream>
using namespace std;

int v[1000000],best=0;
unsigned int cycle(unsigned int val, unsigned int c)
{
    if(val == 1) return c;
    if(val%2 == 0) return cycle(val/2, c+1);
    else return cycle((val*3)+1, c+1);
}

unsigned int maxC(unsigned int a, unsigned int b)
{
    unsigned int cur = 0, temp=0;

    if(a>b) swap(a, b);

    
    for(unsigned int i=a; i<=b;i++)
    {
        if(v[i] == 0){
            temp = cycle(i, 1);
            v[i] = temp;
        }
        else temp = v[i];

        if(temp>cur){cur = temp;best=i;}
    }
    return cur;
}

int main()
{
    unsigned int a;
    unsigned int b;
    memset(v,0,sizeof(v));
    while(cin >> a >> b)
    {
         int w=maxC(a,b);     
         printf("Between %d and %d, %d generates the longest sequence of %d values.\n",a,b,best,w);     
    }
    return 0;
}
