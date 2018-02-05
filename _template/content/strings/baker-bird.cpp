#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;++i)
#define rep(i,n)   REP(i,0,n)

#define SIZE 130
#define PATTERN_LENGTH 105
#define TEXT_LENGTH 1005

char text[TEXT_LENGTH][TEXT_LENGTH];
char str[PATTERN_LENGTH][PATTERN_LENGTH];

int matched[TEXT_LENGTH][TEXT_LENGTH];
int kmp_table[PATTERN_LENGTH];

//trie
struct node{
       int id;
       node *next[SIZE];
       node()
       {
           id = -1;  
           memset(next,0,sizeof next);
       }
};

node *build_trie(char str[][PATTERN_LENGTH], int &number_of_strings, int *id)
{      
    int i,j;              //loop      
    char character;       //temp character         
    node *root;           //root node
    node *it;             //iterator of the trie
    int cnt;              //index counter
    
    //build the trie with the set of strings
    root = new node;      
    cnt = 0;
    
    for(i = 0; i < number_of_strings; ++i)
    {
        it = root;
        for(j = 0; str[i][j]; ++j)
        {
            character = str[i][j];
            if(it->next[character] == NULL)
                it->next[character] = new node;
            it = it->next[character];   
        }
        if(it->id == -1)
            it->id = cnt++;
        id[i] = it->id;
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

void match(node *it, char *big_word, int &row)
{
    int i,j;                //loop
    char character;         //character   
    
    for(i = 0; big_word[i]; ++i)
    {
        //get next character from the text  
        character = big_word[i];
        
        //while there's no path from the actual node < it > labeled with < character >
        //backtrack until we find a node which pointer is not null
        while(it->next[character] == NULL)
           it = it->next[0];
        
        //advance to this node
        it = it->next[character];
        
        //in case that this node is a complete word add to the solution array
        if(it->id != -1)
           matched[i][row] = it->id;
           
        //in case that the failure link of the node points to a full word
        //add this pattern id to the solution array
        if(it->next[0] != NULL && it->next[0]->id != -1)
           matched[i][row] = it->next[0]->id;
        
    }
}

void kmp_preprocess(int *id, int &size)
{
    int i,j;
    i = 0;
    j = -1;
    kmp_table[i] = j;                        //first value of b is -1 because this substring has no border
    
    while(i < size)
    {
        while(j >= 0 && (id[i] != id[j]))    //while there's a mismatch
            j = kmp_table[j];                //shift string_b forward
        ++j;
        ++i;
        kmp_table[i] = j;                    //places to shift
    }    
}

int kmp_search(int *text, int &size_text, int *id, int &size_id)
{
    int i,j;            //loops
    int n_match;
    
    i = 0;
    j = 0;
    n_match = 0;
 
    while(i < size_text)
    {
        while(j >= 0 && (text[i] != id[j]))        //while there's a mismatch
            j = kmp_table[j];                      //shift string_b forward
        ++j;
        ++i;
        if(j == size_id)                           //we found a match !!
        {
            ++n_match;                             //increase number of matches
            j = kmp_table[j];                      //shift string_b forward
        }
    }
    return n_match;
}

int baker_bird(int &text_row, int &text_col, int &str_row)
{
    static int id[PATTERN_LENGTH];        //id of every pattern
    int ocurrences;                       //ocurrences in the text
    int i,j;                              //loop
    node *root;
    
    ocurrences = 0;
    root = build_trie(str, str_row, id);
    
    //initialize values of the ocurrence matrix
    for (i = 0; i < text_col; ++i)
        for (j = 0; j < text_row; ++j)
            matched[i][j] = -1;
    
    //perform a lineal search of every row on the trie
    //occurrences are saved in the occurrence matrix < matched >
    //(the occurrence matrix is trasposed for easier comparison with KMP)
    for (i = 0; i < text_row; ++i)
        match(root, text[i], i);
    
    //preprocess once the id of the patterns
    kmp_preprocess(id, str_row);
    
    //KMP search over every column (because the occurrence matrix is trasposed)
    for(i = 0; i < text_col; ++i)
        ocurrences += kmp_search(matched[i], text_row, id, str_row);  
    
    return ocurrences;
}

int main(){
  int te;
  scanf("%d",&te);
  while(te--){
    int r,c,pr,pc;
    scanf("%d%d",&r,&c);
    //getchar();
    rep(i,r){
      scanf("%s",text[i]);
      //gets(m[i]);
    }

    scanf("%d%d",&pr,&pc);
    //getchar();
    rep(i,pr){
      scanf("%s",str[i]);
      //gets(in[i]);
    }
    printf("%d\n",baker_bird(r,c,pr));
  }
  return 0;
}
