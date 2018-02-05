#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MX 100050
char str[35];
int st[4 * MX];          //segment tree
int A[MX];               //array containing the numbers
int ind[35];
int LEFT, RIGHT;         //left and rigth indexes of the query

void build(int node, int begin, int end) 
{
    if(begin == end)
        st[node] = begin;
    else
    {
        int mid = (begin + end) >> 1;           //mid point
        int left_child = 2 * node;              //index of the left_child
        int right_child = 2 * node + 1;         //index of the right_child
        build(left_child, begin, mid);          //build left_child
        build(right_child, mid + 1, end);       //build right_child
        
        //after the children hold the correct information
        //update the value of the segment_tree of this node
        if(A[st[left_child]] < A[st[right_child]])
            st[node] = st[left_child];          //store index of left_child
        else
            st[node] = st[right_child];         //store index of rigth_child
    }
}

int query(int node, int begin, int end)
{
    if(LEFT <= begin && end <= RIGHT)
        //this node holds information of
        //some part of the query
        return st[node];
    
    //otherwise the information is in its children
    int mid = (begin + end) >> 1;           //mid point
    int left_child = 2 * node;              //index of the left_child
    int right_child = 2 * node + 1;         //index of the right_child
    
    if(RIGHT <= mid)        //the information is in the left child
        return query(left_child, begin, mid);
    
    if(mid < LEFT)         //the information is in the right child
        return query(right_child, mid + 1, end);
    
    //the information is in both children
    int left_index = query(left_child, begin, mid);
    int right_index = query(right_child, mid + 1, end);
    
    if(A[left_index] < A[right_index])   //check which has the min value
        return left_index;
    else
        return right_index;
}

void update(int node, int begin, int end)
{
      if(LEFT <= begin && end <= RIGHT)
        //this node holds information of
        //some part of the query
        return;
    
    //otherwise the information is in its children
    int mid = (begin + end) >> 1;           //mid point
    int left_child = 2 * node;              //index of the left_child
    int right_child = 2 * node + 1;         //index of the right_child
    
    if(RIGHT <= mid)        //the information is in the left child
        update(left_child, begin, mid);
    
    if(mid < LEFT)         //the information is in the right child
        update(right_child, mid + 1, end);

    if(A[st[left_child]] < A[st[right_child]])   //check which has the min value
        st[node] = st[left_child];
    else
        st[node] = st[right_child];
}

int main()
{
    //get the data
    int n, q, i, j;
    scanf("%d%d", &n, &q);
    for(i = 0; i < n; ++i)
        scanf("%d", &A[i]);
        
    //build the segment tree
    build(1, 0, n - 1);
    getchar();
    for(i = 0; i < q; ++i)
    {
        gets(str);
        
        int type = str[0] == 'q'? 1 : 0;
        
        for(j = 0; str[j]; ++j)
            if(!isdigit(str[j]))
               str[j] = ' ';
        
        int elements = 0;
        char *ptr = strtok(str, " ");
        while(ptr)
        {
             LEFT = atoi(ptr);
             ind[elements++] = LEFT - 1;
             ptr = strtok(NULL, " ");
        }
            
        if(type)     //query
        {
             LEFT = ind[0];
             RIGHT = ind[1];
             printf("%d\n", A[query(1, 0, n - 1)]);
        }
        else         //update
        {
             int temp = A[ind[0]];
             for(j = 0; j < elements - 1; ++j)
             {
                 A[ind[j]] = A[ind[j + 1]];
                 LEFT = RIGHT = ind[j];
                 update(1, 0, n - 1);
             }
             A[ind[elements - 1]] = temp;
             LEFT = RIGHT = ind[elements - 1];
             update(1, 0, n - 1);
        }
    }
    return 0;
}
