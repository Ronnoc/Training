#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps=1e-8;
const double PI=acos(-1.);
const LL MOD = 1000000007;
struct node {
	int x[6];
	node() {}
	bool operator < (const node &a)const {
		for(int i=0; i<5; i++)if(a.x[i]!=x[i])return a.x[i]<x[i];
		return a.x[5]<x[5];
	}
	bool operator == (const node &a)const {
		for(int i=0; i<6; i++)if(a.x[i]!=x[i])return 0;
		return 1;
	}
};
vector<node>L;
node D[15];
node gao(int *x) {
	int i,j,nd=0;
	int mn=*min_element(x,x+6);
	for(i=0; i<6; i++)if(x[i]==mn){
		node tp;
		for(j=0; j<6; j++)
			tp.x[j]=x[(i+j)%6];
		D[nd++]=tp;
		for(j=0; j<6; j++)
			tp.x[j]=x[(i-j+6)%6];
		D[nd++]=tp;
	}
	int id=0;
	for(i=1;i<nd;i++)if(D[i]<D[id])id=i;
	return D[id];
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,n,m,T;
	while(~scanf("%d",&n)) {
		L.clear();
		for(i=0; i<n; i++) {
			int x[6];
			for(j=0; j<6; j++)scanf("%d",&x[j]);
			L.push_back(gao(x));
		}
		sort(L.begin(),L.end());
		int flag=0;
		for(i=1; i<L.size(); i++)if(L[i-1]==L[i])flag=1;
		if(flag)printf("Twin snowflakes found.\n");
		else printf("No two snowflakes are alike.\n");
	}
	return 0;
}
/*
2
1 2 3 4 5 6
1 2 4 3 5 6
*/
