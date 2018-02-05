#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)

char table[255][255];
char car[255][255];
void A(char *a,char *b){
  char carry='V';
  for(int i=7;i>=0;i--){
    if (carry!='V'){
      char tmp = b[i],tcarry=carry;
      b[i] = table[a[i]][tmp];
      carry= car[a[i]][tmp];
      if (carry == 'U'){//already carried
        b[i]=table[b[i]][tcarry];
      }else {
        carry=car[b[i]][tcarry];
        b[i] =table[b[i]][tcarry];
      }
    }
    else {
      char tmp = b[i];
      b[i] =table[a[i]][tmp];
      carry=car[a[i]][tmp];
    }
  }
}

void R(char *b){
  for(int i=7;i>=1;i--){
    b[i]=b[i-1];
  }
  b[0]='V';
}

void L(char *b){
  for(int i=0;i<7;i++){
    b[i]=b[i+1];
  }
  b[7]='V';
}

bool solve(char *a,char *b){
  rep(i,3){
    char ord;
    cin>>ord;
    if (ord == 'A'){
      A(a,b);
    }else if (ord == 'R'){
      R(b);
    }else if (ord == 'L'){
      L(b);
    }
  }

  char in[8];
  rep(i,8)cin>>in[i];
  rep(i,8)if (b[i] != in[i])return false;
  return true;
}

main(){
  char in[4]={'V','U','C','D'};
  char cpy[4][4]={
    'V','U','C','D',
    'U','C','D','V',
    'C','D','V','U',
    'D','V','U','C'
  };
  char carrycpy[4][4]={
    'V','V','V','V',
    'V','V','V','U',
    'V','V','U','U',
    'V','U','U','U',
  };

  rep(i,4){
    rep(j,4){
      table[in[i]][in[j]]=cpy[i][j];
      car[in[i]][in[j]]  =carrycpy[i][j];
    }
  }

  int te;
  cout << "COWCULATIONS OUTPUT" << endl;
  cin>>te;
  while(te--){
    char a[8];
    char b[8];
    rep(i,8)a[i]='V',b[i]='V';

    REP(i,3,8)cin>>a[i];
    REP(i,3,8)cin>>b[i];

    //    rep(i,8)cout<<a[i];cout << endl;
    //    rep(i,8)cout<<b[i];cout << endl;

    if (solve(a,b))cout << "YES"<<endl;
    else cout <<"NO"<<endl;
  }


  cout << "END OF OUTPUT"<<endl;
}
