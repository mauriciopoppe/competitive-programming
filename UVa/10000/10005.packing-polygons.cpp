#include <cmath>
#include <iostream>

using namespace std;

int N,x[99],y[99];

bool check(double &cx, double &cy, double &R){
    for(int i=0;i<N;++i) if((cx-x[i])*(cx-x[i])+(cy-y[i])*(cy-y[i])>R*R+1e-8) return false;
    return true;
}

int main(){
    double R,cx1,cy1,cx2,cy2,dx1,dy1,L,dx2,dy2;
    bool found;
    
    while(true){
        cin>>N;
        if(N==0) break;
        
        for(int i=0;i<N;++i) cin>>x[i]>>y[i];
        cin>>R;
        
        found = false;
        
        for(int i=0;i<N;++i){
            for(int j=i+1;j<N;++j){
                dx1 = (x[i]-x[j])/2.0;
                dy1 = (y[i]-y[j])/2.0;
                
                L = sqrt(dx1*dx1+dy1*dy1);
                if(L>R) continue;
                
                dx2 = -dy1*sqrt(R*R-L*L)/L;
                dy2 = dx1*sqrt(R*R-L*L)/L;
                
                cx1 = x[j]+dx1+dx2;
                cy1 = y[j]+dy1+dy2;
                
                cx2 = x[j]+dx1-dx2;
                cy2 = y[j]+dy1-dy2;
                
                if(check(cx1,cy1,R)) found = true;
                if(check(cx2,cy2,R)) found = true;
            }
        }
        
        if(found) cout<<"The polygon can be packed in the circle."<<endl;
        else cout<<"There is no way of packing that polygon."<<endl;
    }
    
    return 0;
}
