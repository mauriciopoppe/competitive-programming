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
#define M 100005
#define SIZE 130
//trie
struct node{
       node *next[SIZE];
       vector<int> accept;
       node()
       {
           memset(next,0,sizeof next);
       }
};

//build a pattern matching automaton 
//from a set of strings
node *build(char str[1001][1001], int number_of_strings)
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
        for(j = 0; str[i][j] != '\0'; ++j)
        {
            character = str[i][j];
            if(it->next[character] == NULL)
             it->next[character] = new node;
            it = it->next[character];   
        }
        it->accept.push_back(i);
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

void match(node *root,char big_word[M], vector<int> &res)
{
    int size_big_word;
    int count;
    int i,j;
    char character; 
    node *it = root;
    size_big_word = strlen(big_word);
    count = 0;
    
    for(i = 0; i < size_big_word; ++i)
    {
        character = big_word[i];
        while(it->next[character] == NULL)
           it = it->next[0];
        it = it->next[character];
        
        if(it->next[0] != NULL && it->next[0]->accept.size())
        for(j = 0; j < it->next[0]->accept.size(); ++j)
           res[it->next[0]->accept[j]]++;
           
        for(j = 0; j < it->accept.size(); ++j)
           res[it->accept[j]]++;
    }
}



char str[1001][1001];
char big_word[M];
int result[M];


int main()
{
    int cas;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%s",big_word);
        int n;
        scanf("%d",&n);
        F(i,n)
          scanf("%s",str[i]);
        node *root = build(str, n);
        
        vector<int> res(n);
		match(root,big_word,res);
		for(int i = 0; i < n; ++i)
			puts(res[i]?"y":"n");
        //SP;
    }
    return 0;
}
