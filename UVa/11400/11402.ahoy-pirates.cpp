#include <iostream>
#include <algorithm>
#define MAX 1024002
using namespace std;

/*
    st -> segment tree
    lazy -> lazy action to propagate to children
    flag -> true in a node which needs to be updated
    a -> the initial string is stored here
*/    

int n,act,st[2*MAX],lazy[2*MAX],L=0,R,N=1;
bool flag[2*MAX];
char w[55],a[MAX+10],qq;

void build( int &n, int &b, int &e) 
{
   if(b==e)
      st[n]=a[b]-'0';
   else
   {
      int m = ((b+e)>>1),le=2*n,ri=2*n+1;
      build(le,b,m);
      ++m;
      build(ri,m,e);
      
      //update value
      st[n]=st[le]+st[ri];
   }
}

int A, B;
int ret;

/*
    next_action works like this:
    if a node needs to be updated and it has a lazy action to do
    but its parent now propagates a new action, then merge the actions
*/
void next_action(int n)
{
     if(act==1 || act==2 || !lazy[n])lazy[n]=act;
     else
     {
         if(lazy[n]==1)lazy[n]=2;
         else if(lazy[n]==2)lazy[n]=1;
         else lazy[n]=0;
     }
}

int update( int &n, int &b, int &e) 
{
   //if it needs to be updated  
   if(flag[n])
   {
       //set a flag on its children
       if(b!=e)
       {
           flag[2*n]=flag[2*n+1]=1;
       
           //propagate its children the lazy action
           lazy[2*n]=lazy[2*n+1]=lazy[n];
       }
       if(lazy[n]==1)          //put to 1's
           st[n]=e-b+1;                
       else if(lazy[n]==2)     //put to 0's
           st[n]=0;
       else if(lazy[n]==3)     //invert
           st[n]=e-b-st[n]+1;
           
       lazy[n]=flag[n]=0;      //it was updated so flag is 0 
                               //also ive propagated its lazy action so its 0 too                
   }
   
   if( A <= b && e <= B )      //if it's inside the range
   {
       int old=st[n];          //create an old value so if this node value changes 
                               //take the difference between them and update its parent
       
       if(act==1)
           st[n]=e-b+1;                
       else if(act==2)
           st[n]=0;
       else if(act==3)
           st[n]=e-b-st[n]+1;
       
       old=st[n] - old;        //update the old value to return to its parent

       //set a flag on their children
       if(b!=e)
       {
          flag[2*n]=flag[2*n+1]=1;
       
          //put the children the action to do
          next_action(2*n);
          next_action(2*n+1);          
          
          //if the new action is double INVERT flag them to 0
          if(lazy[2*n]==0)
             flag[2*n]=flag[2*n+1]=0;
             
       }   
       //new flag on this node is
       flag[n]=0;
       return old;        //return the difference so the parent is updated too
   }
   else
   {
       int m=((b+e)>>1);
       if(B<=m)
       {
            int le=2*n,p1=update(le,b,m);
            st[n]+=p1;
            return p1;
       }
       else if(A>m)
       {
            ++m;
            int ri=2*n+1,p1=update(ri,m,e);
            st[n]+=p1;
            return p1;
       }
       else
       {
            int p1,p2,le=2*n,ri=2*n+1;
            p1=update(le,b,m);
            ++m;
            p2=update(ri,m,e);
            st[n]+=p1+p2;
            return (p1+p2);
       }
   }
}


void query(int &n, int &b, int &e) 
{
   //if it needs to be updated  
   if(flag[n])
   {
       
       if(b!=e)
       {
           //set a flag on its children    
           flag[2*n]=flag[2*n+1]=1;
       
           //propagate its children the lazy action
           lazy[2*n]=lazy[2*n+1]=lazy[n];
       }
       if(lazy[n]==1)
           st[n]=e-b+1;                
       else if(lazy[n]==2)
           st[n]=0;
       else if(lazy[n]==3)
           st[n]=e-b-st[n]+1;
           
       lazy[n]=flag[n]=0;                       
   }

   if( A <= b && e <= B ) 
       ret+=st[n];         //return value                     
   else
   {
       int m=((b+e)>>1);
       if(B<=m)
       {
            int le=2*n;
            query(le,b,m);
       }
       else if(A>m)
       {
            int ri=2*n+1;
            ++m;
            query(ri,m,e);
       }
       else
       {
           int le=2*n,ri=2*n+1;
           query(le,b,m);
           ++m;
           query(ri,m,e);
       }
   }
}



int main() 
{
 
   int n, m, t, i, u, j, k, cases=1, q, x, y, len, cc;
   scanf("%d",&t);
   for(;cases<=t;++cases)
   {
       scanf("%d",&u);
       j=0;
       for(int i=0;i<u;++i)
       {
             scanf("%d",&n);
             getchar();
             gets(w);
             len=strlen(w);
             for(k=0;k<n;++k,j+=len)
                memcpy(a+j,w,sizeof(w));
       }
       a[j]='\0';
       
       memset(flag,0,j*2);
       memset(lazy,0,4*j*2);
       
       //reinit
       R=j-1;
   
       build(N,L,R);
       cc=1;
       scanf("%d",&q);
       printf("Case %d:\n",cases);
       for(int z=0;z<q;z++)
       {
            cin>>qq;
            scanf("%d%d",&A,&B);
            if(qq=='F')
            {
                  act=1;
                  update(N,L,R);
            }
            else if(qq=='E')
            {
                  act=2;
                  update(N,L,R);                
            }    
            else if(qq=='I')
            {
                  act=3;
                  update(N,L,R);                
            }    
            else
            {
                  ret=0;
                  query(N,L,R);
                  printf("Q%d: %d\n",cc++,ret);
            }
        }
        
    }

    return 0;
}
