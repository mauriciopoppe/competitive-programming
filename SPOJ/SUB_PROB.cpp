/*
 * 6898 Substring Problem.cpp
 *
 *  Created on: Mar 10, 2012
 *      Author: mauricio
 */

#include<stdio.h>
#include<stdlib.h>
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

#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;

#define SIZE 130
#define PATTERN_LENGTH 1000
#define TEXT_LENGTH 100001

char str[PATTERN_LENGTH][PATTERN_LENGTH];            //patterns
char big_word[TEXT_LENGTH];                            //big word

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

//build a pattern matching automaton
//from a set of strings
node *build_trie(char str[][PATTERN_LENGTH], int number_of_strings)
{
    int i,j;              //loop
    int character;        //temp character
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

void match(node *root, char big_word[TEXT_LENGTH], vector<int> &res)
{
    int size_big_word;      //size of the text
    int i,j;                //loop
    int character;          //character
    node *it;               //iterator to traverse over the trie

    it = root;
    size_big_word = strlen(big_word);

    for(i = 0; i < size_big_word; ++i)
    {
        //get next character from the text
        character = big_word[i];

        //while there's no path from the actual node < it > labeled with < character >
        //backtrack until we find a node which pointer is not null
        while(it->next[character] == NULL)
           it = it->next[0];

        //advance to this node
        it = it->next[character];

        //in case that the failure link of the node points to a full word
        //add this pattern id to the solution array
        node *it2 = it;
        while(it2->next[0] != NULL)
        {
            it2 = it2->next[0];
            int k = it2->size;
            for(j = 0; j < k; ++j)
               res[it2->accept[j]]++;
        }

        //in case that this node is a complete word add to the solution array
        for(j = 0; j < it->size; ++j)
           res[it->accept[j]]++;
    }
}

int main()
{
	int cas;
	scanf("%d", &cas);
    while(cas--)
    {
        int n_patterns;

        //get the big word
		scanf("%s",big_word);

		//get patterns
        scanf("%d",&n_patterns);
        for (int i = 0; i < n_patterns; ++i)
          scanf("%s",str[i]);

        //build the trie with the patterns
        node *root = build_trie(str, n_patterns);

        vector<int> result(n_patterns);

        //match phase
        match(root,big_word,result);

        //if pattern[i] is part of the <big_word>
        //the result[i] will be nonzero
        for(int i = 0; i < n_patterns; ++i)
            puts(result[i]?"y":"n");
    }
    return 0;
}
