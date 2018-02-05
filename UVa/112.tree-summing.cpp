#include<iostream>
#include<string>
#include<cctype>
using namespace std;
struct Tree{
       int d,p;
       Tree *left;
       Tree *right;
       Tree *parent;
       Tree(int x):d(x),p(0),left(NULL),right(NULL),parent(NULL){};
       };

void inOrder(Tree *root)
{
     if(root!=NULL)
     {
          inOrder(root->left);
          cout<<root->d<<" ";
          inOrder(root->right);              
     }
     
}
       
int hasPathSum(Tree *root, int sum)
{
     if(root==NULL)return (sum==0);
     else
         {
              if(root->left==NULL && root->right!=NULL)
                  return hasPathSum(root->right,sum-root->d);
              else if(root->left!=NULL && root->right==NULL)
                  return hasPathSum(root->left,sum-root->d);
              else 
              return hasPathSum(root->left,sum-root->d) ||
              hasPathSum(root->right,sum-root->d);
         }
    return 0;                                  
}      
       
int main()
{
    int n,aux;
    char c;
    while(cin>>n)
    {
         Tree *root=NULL,*pnode=NULL;
         int p=0,s=0;                                  //top (              
         aux=0;
         
         while(true)         
         {
         
              while(isspace(c=getchar()));
              
              if(c=='-')s=1;
              
              else if(isdigit(c))   
                 aux=aux*10+(c-'0');    
                 
              else if(c=='(')
                   {
                       if(aux!=0)
                       {   
                           aux=s?-aux:aux;
                           if(root==NULL)
                           {
                                root=new Tree(aux);
                                pnode=root;
                           }
                           else
                           {
                                Tree *t=new Tree(aux);
                                if(root->p==0)root->left=t;
                                else root->right=t;
                                t->parent=root;
                                root=t;            
                           } 
                       aux=0;
                       s=0;
                       }                        
                   p++;         
                   }
              else if(c==')')
                   {
                       p--;
                       if(p==0)break;      
                       (root->p)++;
                       if(root->p==2)root=root->parent;
                   }
              /*
              cout<<"p="<<p<<" ";
              if(pnode!=NULL)
                 {
                 cout<<pnode->d<<" ";
                 if(pnode->left!=NULL)cout<<pnode->left->d;
                 cout<<endl;
                 }   
              //cout<<p<<endl;
              */
              if(p==0)break;
         }  
         //cout<<"InOrder ";
         //inOrder(pnode);
         
         if(pnode==NULL)cout<<"no"<<endl;
         else if(hasPathSum(pnode,n))cout<<"yes"<<endl;
         else cout<<"no"<<endl;     
    }       
}
