#include <iostream>
#include <cstdio>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
#endif
	int n;
	scanf( "%d",&n );
	int res=1;
	res+= ( n&1 )? ( n+1 )/2*n : n/2*( n+1 ) ;
	printf( "%d\n",res );
	return 0;
	}
