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

int v[55];
int z[55];
int x[55];
int y[55];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		memset(v,0,sizeof v);
		for(i=0;i<n;i++)
			scanf("%d%d%d",&z[i],&x[i],&y[i]);
		int fi=0,fy=y[0],fx=x[0];
		for(i=1;i<n;i++)if(y[i]<fy||(y[i]==fy&&x[i]<fx))fy=y[i],fi=i,fx=x[i];
		printf("%d %d",n,z[fi]);
		v[fi]=1;
		for(i=1;i<n;i++){
			for(j=0;j<n;j++)if(!v[j])break;
			int ti=j,tx=x[j],ty=y[j];
//			cout<<i<<"'"<<z[ti]<<endl;
			for(j++;j<n;j++)if(!v[j]){
				int dx=x[j]-fx;
				int dy=y[j]-fy;
				int dtx=tx-fx;
				int dty=ty-fy;
//				cout<<z[ti]<<"vs"<<z[j]<<":"<<1.*dx/dy<<"vs"<<1.*dtx/dty<<endl;
				if(1LL*dx*dty>1LL*dtx*dy||(1LL*dx*dty==1LL*dtx*dy&&abs(x[j]-fx)<abs(tx-fx)))
					ti=j,tx=x[j],ty=y[j];
			}
			printf(" %d",z[ti]);
			v[ti]=1;
			fx=tx,fy=ty;
		}
		puts("");
	}
	return 0;
}
/*
1
6
1 4 2
2 10 3
3 14 6
4 12 9
5 5 8
6 8 7
*/
