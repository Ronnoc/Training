//kybconnor
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long LL;
LL s[111111];
LL p[111111];
LL mn[111111];
int main() {
	int T;
	scanf ("%d",&T);
	while (T--) {
		int n,m;
		scanf ("%d%d",&n,&m);
		int i,j;
		for (i=1; i<=n; i++)
			scanf ("%lld%lld",&s[i],&p[i]);
		mn[n]=s[n]*p[n];
		for (i=n-1; i>=1; i--)
			mn[i]=min (mn[i+1],s[i]*p[i]);
		for (int q=1; q<=m; q++) {
			LL x;
			scanf ("%lld",&x);
			if (x>=s[n]) {printf ("%lld\n",x*p[n]); continue;}
			int l=1,r=n,bin;
			while (r>=l) {
				if (r-l<=1) {
					if (s[l]<=x) bin=l;
					else bin=r;
					break;
				}
				int mid= (l+r) /2;
				if (s[mid]<=x) l=mid;
				else r=mid;
			}
			printf ("%lld\n",min (p[bin]*x,mn[bin+1]));
		}
	}
	return 0;
}
