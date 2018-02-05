#include<iostream>
#include<algorithm>
#include<complex>
#include<vector>
#include<set>
#include<cmath>
#include<sstream>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
#define double long double
const double eps = 0;
typedef complex<double> P;

class DisjointSet{
public:
  vector<int> rank,p;
  DisjointSet(){};
  DisjointSet(int size){
    p.resize(size,0);
    rank.resize(size,0);
  }
  void make_set(int x){
    p[x]=x;
    rank[x]=0;
  }
  void merge(int x,int y){
    link(find_set(x),find_set(y));
  }
  void link(int x,int y){
    if (rank[x]>rank[y]){
      p[y]=x;
    }else {
      p[x]=y;
      if ( rank[x]==rank[y])rank[y]+=1;
    }
  }
  int find_set(int x){
    if ( x != p[x])p[x]=find_set(p[x]);
    return p[x];
  }
};


double cross(P a,P b){
  return a.real()*b.imag()-a.imag()*b.real();
}

double is_point_online(P a,P b,P c){
  return (abs(a-c)+abs(b-c) <=abs(a-b)+eps);
}

bool is_intersected_ls(P a1,P a2,P b1,P b2){
  /*
  if (is_point_online(a1,a2,b1)||
      is_point_online(a1,a2,b2)||
      is_point_online(b1,b2,a1)||
      is_point_online(b1,b2,a2))return true;
  */
  if (  cross(a2-a1,b1-a1)*cross(a2-a1,b2-a1) <eps &&
        cross(b2-b1,a1-b1)*cross(b2-b1,a2-b1) <eps)return true;
  return false;
}



class Polygon{
public:
  vector<P> data;
};


bool is_in(Polygon & in,P &a){
  int cnt=0;
  rep(i,in.data.size()){
    P cur = in.data[i]-a,next=in.data[(i+1)%in.data.size()]-a;
    if ( cur.imag()>next.imag())swap(cur,next);//define cur.imag< next.imag
    if ( cur.imag()<0 && 0<=next.imag() && cross(next,cur) >=0)cnt++;
    if ( is_point_online(in.data[i],in.data[(i+1)%in.data.size()],a))return true;
  }

  if ( cnt%2 == 1)return true;
  else return false;
}


bool P_P_intersected(Polygon & a,Polygon & b){
  rep(i,a.data.size()){
    if ( is_in(b,a.data[i]) )return true;
    rep(j,b.data.size()){
      if ( is_intersected_ls(a.data[i],a.data[(i+1)%a.data.size()],b.data[j],b.data[(j+1)%b.data.size()]))return true;
    }
    
  }
  rep(i,b.data.size()){
    if ( is_in(a,b.data[i]))return true;
  }
  return false;
}




int solve(Polygon *in,int n){
  DisjointSet dj(n);
  rep(i,n)dj.make_set(i);
  rep(i,n){
    rep(j,n){
      if ( dj.find_set(i) == dj.find_set(j) )continue;
      if ( P_P_intersected(in[i],in[j]))dj.merge(i,j);
    }
  }




  set<int> S;
  rep(i,n)S.insert(dj.find_set(i));
  return S.size();
}


main(){
  int n;
  string a;
  while(cin>>n && n){
    getline(cin,a);
    Polygon in[n];
    rep(i,n){
      getline(cin,a);stringstream sin(a);
      P tmp;
      while(sin>>tmp.real() >> tmp.imag())in[i].data.push_back(tmp);
    }
    cout << solve(in,n) << endl;
  }
}
