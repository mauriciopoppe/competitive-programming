#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define REP(i,b,n) for(int i=(int)b;i<(int)n;i++)
#define rep(i,n) REP(i,0,n)
#define N 5001

int  dist(int x,int y,int z){
  return (x*x+y*y+z*z);
}

int main(){
  int x[N],y[N],z[N];
  int criteri[10]={1,4,9,16,25,36,49,64,81,100};
  int cnt[10]={0};
  int n=0;
  while(cin>>x[n] >> y[n] >> z[n]){
    if ( x[n] == 0 && y[n]==0&&z[n] ==0)break;
    n++;
  }
  
  for(int i=0;i<n;i++){
    int  val=101;
    for(int j=0;j<n;j++){
      if (i==j)continue;
      val =min(val,dist(x[i]-x[j],y[i]-y[j],z[i]-z[j]));
    }
    if ( val ==101)continue;
    rep(j,10)if (val<criteri[j]){cnt[j]++;break;}
    
  }
  
  
  
  for(int i=0;i<10;i++){
    printf("%4d",cnt[i]);
  }
  putchar('\n');
  return 0;
}
