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
const int MXN = 500000+10;
struct BIT {
	LL c[MXN];
	int n;
	void init(int m) {
		n=m+7;
		for(int i=0; i<=n; i++)
			c[i]=0;
	}
	void add(int t,LL k=1) {
		t+=5;
		while(t<=n) {
			c[t]+=k;
			t+=t&-t;
		}
	}
	LL sum(int t) {
		LL ret=0;
		t+=5;
		while(t>0) {
			ret+=c[t];
			t-=t&-t;
		}
		return ret;
	}
};
BIT row[2],col[2];
int n;
int R[MXN],C[MXN];
int main() {
	int i,j,k,_T;
	int n,q;
	while(~scanf("%d%d",&n,&q)) {
		for(i=1; i<=n; i++)R[i]=C[i]=q<<1;
		row[0].init(q);
		col[0].init(q);
		row[1].init(q);
		col[1].init(q);
		row[0].add(q,n);
		col[0].add(q,n);
		for(i=q-1; i>=0; i--) {
			char op[20];
			scanf("%s",op);
			if(op[3]=='Q') {
				int id;
				scanf("%d",&id);
				int f0,f1,mul;
				if(op[0]=='R') {
					f0=col[0].sum(R[id]>>1);
					f1=col[1].sum(R[id]>>1);
					mul=R[id]&1;
				} else {
					f0=row[0].sum(C[id]>>1);
					f1=row[1].sum(C[id]>>1);
					mul=C[id]&1;
				}
				mul=1-mul;
				printf("%d\n",f0+(n-f0-f1)*mul);
			} else {
				int id,w;
				scanf("%d%d",&id,&w);
				if(op[0]=='R') {
					row[R[id]&1].add(R[id]>>1,-1);
					row[w].add(i,1);
					R[id]=i<<1|w;
				} else {
					col[C[id]&1].add(C[id]>>1,-1);
					col[w].add(i,1);
					C[id]=i<<1|w;
				}
			}
		}
	}
	return 0;
}
