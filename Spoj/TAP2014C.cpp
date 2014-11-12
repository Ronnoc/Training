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

pair<pair<int,int>,LL>z[1000005];
int nz;
PII w[1005];
int main() {
#define NAME ""
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
	int i,j,k,_T;
	int n;
	while(~scanf("%d",&n)) {
		for(i=nz=0; i<n; i++)
			scanf("%d%d",&w[i].AA,&w[i].BB);
		sort(w,w+n);
		for(i=0; i<n; i++)
			for(j=i+1; j<n; j++) {
				int dx=w[j].AA-w[i].AA;
				int dy=w[j].BB-w[i].BB;
				int g=__gcd(dx,dy);
				z[nz++]=MP(MP(dx,dy),-1LL*w[i].AA*(dy/g)+1LL*w[i].BB*(dx/g));
			}
		sort(z,z+nz);
		int le=0,re;
		LL ans=0;
		while(le<nz){
			re=le;
			while(re<nz&&z[re].AA==z[le].AA)
				re++;
			ans+=1LL*(re-le)*(re-le);
			int l=le,r;
			while(l<re){
				r=l;
				while(r<re&&z[r].BB==z[l].BB)
					r++;
				ans-=1LL*(r-l)*(r-l);
				l=r;
			}
			le=re;
		}
		cout<<ans/4<<"\n";
	}
	return 0;
}
