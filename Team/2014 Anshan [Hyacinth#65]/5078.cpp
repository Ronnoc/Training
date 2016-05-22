#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
using namespace std;
typedef long long LL;
typedef pair<int,int>PII;
#define MP make_pair
#define PB push_back
#define SZ size()
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define BG begin()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
#define SQ(x) ((x)*(x))
LL sq(int x){
	return 1LL*x*x;
}
int t[1005];
int x[1005];
int y[1005];
int main() {
	int i,j;
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(i=0;i<n;i++)scanf("%d%d%d",&t[i],&x[i],&y[i]);
		double ans=0;
		for(i=1;i<n;i++){
			double dis=sqrt(sq(x[i]-x[i-1])+sq(y[i]-y[i-1]))/(t[i]-t[i-1]);
			cmax(ans,dis);
		}
		printf("%.16f\n",ans);
	}
	return 0;
}
/*
2
5
2 1 9
3 7 2
5 9 0
6 6 3
7 6 0
10
11 35 67
23 2 29
29 58 22
30 67 69
36 56 93
62 42 11
67 73 29
68 19 21
72 37 84
82 24 98
*/
