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

PII z[1005];
PII q[1005];
int main() {
	#define NAME ""
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
	int i,j,k,_T;
	int n,u,q;
	while(~scanf("%d%d%d",&n,&u,&q)){
		for(i=0;i<u;i++)scanf("%d%d",&z[i].AA,&z[i].BB);
		sort(z,z+u);
		for(j=0;j<q;j++){
			int le,re;
			scanf("%d%d",&le,&re);
			LL ans=0;
			for(i=0;i<u;i++){
				if(z[i].BB<le||z[i].AA>re)continue;
				LL p=1,q=z[i].BB-z[i].AA+1;
				if(z[i].AA<le)
					p+=le-z[i].AA;
				if(z[i].BB>re)
					q-=z[i].BB-re;
				ans+=(q-p+1)*(p+q)/2%10000;
			}
			printf("%lld\n",ans%10000);
		}
	}
	return 0;
}
