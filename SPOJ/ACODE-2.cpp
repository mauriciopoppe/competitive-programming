using namespace std; 
#include<iostream> 
#include<cstdio> 
#include<cstring> 
#include<algorithm> 
#include<vector> 
#include<limits> 
#include<cmath> 
#include<map> 
#define LLU long long unsigned int 
#define LLD long long double 
#define FOR(i,N) for(int i=0;i<(N);i++) 
int one[5010],two[5010],ways[5010]; 
int main() 
{ 
    int N; 
    string str; 
    while(cin>>str) 
    { 
        if(str[0]=='0') break; 
        N=str.length(); 
        if(N<2) 
        { 
            printf("1\n"); 
            continue; 
        } 
        FOR(i,N) 
        one[i]=str[i]-'0'; 
        for(int i=1;i<N;i++) 
        two[i]=10*one[i-1]+one[i]; 
        ways[0]=1; 
        if(one[1]) ways[1]=1; 
        else ways[1]=0; 
        if(two[1]>9 and two[1]<27) ways[1]++; 
        for(int i=2;i<N;i++) 
        { 
            if(one[i]) ways[i]=ways[i-1]; 
            else ways[i]=0; 
            if(two[i]>9 and two[i]<27) ways[i]+=ways[i-2]; 
        } 
        cout<<ways[N-1]<<endl; 
    } 
}
