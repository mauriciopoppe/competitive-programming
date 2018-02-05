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
#define MX 1000000

int st[4 * MX];          //segment tree
int A[MX];               //array containing the numbers

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


int main()
{
    //get the data
    int interval_length;
    scanf("%d", &interval_length);
    for(int i = 0; i < interval_length; ++i)
        scanf("%d", &A[i]);
        
    //build the segment tree
    build(1, 0, interval_length - 1);
    
    int number_of_queries;
    int index_min;

    //query
    scanf("%d", &number_of_queries);
    for(int i = 0; i < number_of_queries; ++i)
    {
        scanf("%d%d", &LEFT, &RIGHT);
        index_min = query(1, 0, interval_length - 1);
        printf("Min value is at index %d and it's %d\n", index_min, A[index_min]);    
    }
    return 0;
}
