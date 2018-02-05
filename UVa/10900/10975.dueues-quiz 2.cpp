#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<stack>
#include<sstream>
#include<utility>
#include<numeric>
#include<functional>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define MP make_pair
#define NL printf("\n")
#define SP system("pause")
#define IMAX 2147483647
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;

#define SIZE 27
#define PATTERN_LENGTH 15000
#define TEXT_LENGTH 105
const int sub = 'a' - 1;
//trie
struct node{
       int size;
       node *next[SIZE];
       vector<int> accept;
       node()
       {
           size = 0;  
           memset(next,0,sizeof next);
       }
};

int cnt[PATTERN_LENGTH];
vector<string> str(PATTERN_LENGTH);
char text[TEXT_LENGTH][TEXT_LENGTH];
char text_copy[TEXT_LENGTH];

//build a pattern matching automaton 
//from a set of strings
node *build_trie(vector<string> &str, int number_of_strings)
{
    int i,j;              //loop      
    char character;       //temp character         
    node *root;           //root node
    node *it;             //iterator of the trie
 
    //build the trie with the set of strings
    root = new node;      
    for(i = 0; i < number_of_strings; ++i)
    {
        it = root;
        int size = str[i].size();
        for(j = 0; j < size; ++j)
        {
            character = str[i][j] - sub;
            if(it->next[character] == NULL)
             it->next[character] = new node;
            it = it->next[character];   
        }
        it->accept.push_back(i);
        (it->size)++;
    }
 
    //make failure links using BFS
    queue<node*> failure_queue;
 
    //root nodes that are null must point to root (the first failure links)
    //and if they're NOT null create the failure links making all root nodes
    //that are NOT null have the failure links point to root
    for(i = 1; i < SIZE; ++i)
    {
        //there's a path from root with character < i >
        if(root->next[i] != NULL)
        {
            //< next[0] > now points to root             
            root->next[i]->next[0] = root;
 
            //check the nodes of node < next[i] >
            failure_queue.push(root->next[i]);                           
        }
        else
            //first failure link from root's character < i > to root
            root->next[i] = root;
    }
 
    while(!failure_queue.empty())
    {
        //get the next node to check                         
        it = failure_queue.front();
        failure_queue.pop();
 
        for(i = 1; i < SIZE; ++i)
        {
            //there's a path from node < it > with character < i >
            if(it->next[i] != NULL)
            {
                //check the nodes of node < it->next[i] >
                failure_queue.push(it->next[i]);
 
                //get the node which is the failure link of node < it >
                node *temp = it->next[0];
 
                //iterate the trie starting from the node which is the failure link
                //of node < it > until the failure link of some node < temp > is not null
                //of course the failure link of node < it->next[i] > will be closest (in levels)
                //to node < it->next[i] >
                while(temp->next[i] == NULL)
                    temp = temp->next[0];
 
                //create the failure link of node < it->next[i] >
                it->next[i]->next[0] = temp->next[i];
            }
        }                         
    }
    //return root
    return root;
}
 
void match(node *root, char big_word[TEXT_LENGTH])
{
    int size_big_word;      //size of the text
    int i,j;                //loop
    char character;         //character
    node *it;               //iterator to traverse over the trie
 
    it = root;        
    size_big_word = strlen(big_word);
 
    for(i = 0; i < size_big_word; ++i)
    {
        //get next character from the text  
        character = big_word[i] - sub;
 
        //while there's no path from the actual node < it > labeled with < character >
        //backtrack until we find a node which pointer is not null
        while(it->next[character] == NULL)
           it = it->next[0];
 
        //advance to this node
        it = it->next[character];
 
        //in case that the failure link of the node points to a full word
        //add this pattern id to the solution array
        if(it->next[0] != NULL && it->next[0]->size)
            for(j = 0; j < it->next[0]->size; ++j)
            {
               //printf("%d ",it->next[0]->accept[j]); 
               //NL;
               cnt[it->next[0]->accept[j]]++;
            }
 
        //in case that this node is a complete word add to the solution array
        for(j = 0; j < it->size; ++j)
        {
           //printf("%d ",it->accept[j]); 
           //NL;              
           cnt[it->accept[j]]++;
        }
    }
}

int main()
{
    //freopen("in2.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    //printf("%d\n",sizeof(char *));
    int cas;
    int n_patterns;
    int q;
    int row, col;
    scanf("%d",&cas);
    F(z,cas)
    {
         map<string, bool> m;
         scanf("%d",&n_patterns);
         int t = 0;
         F(i,n_patterns)
         {
            cin>>str[t];
            if(!m[str[t]])
               m[str[t]] = 1, t++;
         }
         n_patterns = t;
         sort(str.begin(), str.begin() + n_patterns);
         node *root = build_trie(str, n_patterns);
         printf("Test Case #%d\n",z+1);
         scanf("%d",&q);         
         F(x,q)
         {               
             scanf("%d%d",&row,&col);
             F(i,row)
               scanf("%s",&text[i]);
             memset(cnt,0,4*n_patterns);
             //horizontal
             F(i,row)
             {
                 //printf("H\n");    
                 //forward
                 int k;
                 for(k = 0; k < col; k++)
                     text_copy[k] = text[i][k];
                 text_copy[k] = '\0';
                 match(root, text[i]);
                 
                 //backward
                 reverse(text_copy, text_copy + col);
                 match(root, text_copy);   
             }
             
             //vertical
             F(i,col)
             {
                 //printf("V\n");    
    
                 //forward
                 int k;
                 for(k = 0; k < row; ++k)
                     text_copy[k] = text[k][i];
                     
                 text_copy[k] = '\0';
                 match(root, text_copy);
                 //backward
                 reverse(text_copy, text_copy + row);
                 match(root, text_copy);                      
             }
             /*F(k,n_patterns)
                    printf("%d ",cnt[k]);
                 SP;*/
             //diagonal < \ >
             //printf("D first\n");       
             int i,j,run;
             int ind = 0;
             for(int run = 0; run < 2 * col - 1; ++run)
             {
                 //forward       
                 ind = 0;    
                 for(i = 0, j = 1 - col + run; i < row; i++, j++)
                    if(j >= 0 && j < col)
                       text_copy[ind++] = text[i][j];
                 text_copy[ind] = '\0';
                 match(root, text_copy);
                 
                  //backward
                 reverse(text_copy, text_copy + ind);
                 match(root, text_copy); 
             }            
             
             //diagonal < / >
             //printf("D Second\n");        
             //int i,j,run;
             for(int run = 0; run < 2 * col - 1; ++run)
             {
                 //forward       
                 ind = 0;    
                 for(i = 0, j = run; i < row; i++, j--)
                    if(j >= 0 && j < col)
                       text_copy[ind++] = text[i][j];
                 text_copy[ind] = '\0';
                 match(root, text_copy);
                 
                  //backward
                 reverse(text_copy, text_copy + ind);
                 match(root, text_copy); 
             }            
             
             printf("Query #%d\n",x+1);
             F(i,n_patterns)
                if(cnt[i])
                   printf("%s %d\n",str[i].c_str(),cnt[i]);
         }
         NL;
    }
    return 0;
}
