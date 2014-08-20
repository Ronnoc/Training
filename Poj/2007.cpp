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
const double PI=acos( -1. );
const LL MOD = 1000000007;

struct dot{
	LL x,y;
	dot(LL _x=0,LL _y=0):x(_x),y(_y) {}
	bool operator < (const dot &d)const {
		if(y*d.x!=x*d.y)return y*d.x<x*d.y;
		return (x+y)<(d.x+d.y);
	}
};
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	LL ox,oy;
	while(cin>>ox>>oy){
		LL x,y;
		cout<<"("<<ox<<","<<oy<<")\n";
		vector<dot>L;
		while(cin>>x>>y)
			L.PB(dot(x-ox,y-oy));
		SORT(L);
		for(i=0;i<L.SZ;i++)
			cout<<"("<<L[i].x+ox<<","<<L[i].y+oy<<")\n";
		break;
	}
	return 0;
}
