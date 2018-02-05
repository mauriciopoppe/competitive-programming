#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;


int main()
{
	int t;
	scanf( "%d", &t );
	while ( t-- )
	{
		int n, m, x;
		scanf("%d %d", &n, &m );
		queue< int > add, get;
		for ( int i = 0; i < n; ++i ) {
			scanf( "%d", &x );
			add.push( x );
		}
		for ( int i = 0; i < m; ++i ) {
			scanf( "%d", &x );
			get.push( x );
		}
		int cnt = 0;
		priority_queue< int, vector< int >, greater< int > > MinHeap;
		priority_queue< int, vector< int >, less< int > > MaxHeap;

		while ( !add.empty() ) {

			if ( !MinHeap.empty() && add.front() > MaxHeap.top() )
				MinHeap.push( add.front() );
			else
				MaxHeap.push( add.front() );
			add.pop();

			while ( !get.empty() && MaxHeap.size() + MinHeap.size() == get.front() ) {
				while ( MaxHeap.size() != cnt ) {
					if ( MaxHeap.size() < cnt ) {
						MaxHeap.push( MinHeap.top() );
						MinHeap.pop();
					}
					else if ( MaxHeap.size() > cnt ) {
						MinHeap.push( MaxHeap.top() );
						MaxHeap.pop();
					}
				}

				printf( "%d\n", MinHeap.top() );
				++cnt, get.pop();
			}
		}
		if ( t )
			puts( "" );
	}
	return 0;
}
