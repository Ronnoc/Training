/*
ID: kybconn1
PROG: sprime
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ size()
vector<int>G[11];
bool isprime(int a){
	for(int i=3;i*i<=a;i++)if(a%i==0)return 0;
	return 1;
}
int main() {
	freopen ("sprime.in", "r", stdin);
	freopen ("sprime.out", "w", stdout);
	int i,j,n;
	G[1].PB( 2 );
	G[1].PB( 3 );
	G[1].PB( 5 );
	G[1].PB( 7 );
	for ( i=1; i<=7; i++ )
		for ( j=0; j<G[i].SZ; j++ ) {
			int w=G[i][j];
			if(isprime(w*10+1))G[i+1].PB(w*10+1);
			if(isprime(w*10+3))G[i+1].PB(w*10+3);
			if(isprime(w*10+7))G[i+1].PB(w*10+7);
			if(isprime(w*10+9))G[i+1].PB(w*10+9);
		}
	while(~scanf("%d",&n)){
		for(i=0;i<G[n].SZ;i++)printf("%d\n",G[n][i]);
	}
	return 0;
}
