//shllhs
#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int a[100005];
int sum[100005];
vector<int>t;
int main() {
	int n,m,k,i,j;
	while (scanf ("%d%d%d",&n,&m,&k) !=EOF) {
		t.clear();
		sum[0] = 0;
		for (i = 1; i<=n; i++) {
			scanf ("%d",&a[i]);
			sum[i] = sum[i-1]+a[i];
		}
		for (j = 1; j<=m; j++) {
			int x;
			scanf ("%d",&x);
			t.push_back (x);
		}
		int now = 0,pos = 0,st = 0;
		long long ans = 0;
		while (now!=t.size()) {
			if (n-pos<t[now]-st) break;
			ans+=t[now]-st;
			pos+=t[now]-st;
			st = t[now];
			if (sum[pos]-sum[1]<=k) pos = 0;
			else {
				int l = 0,r = pos+1;
				while (l<r-1) {
					int mid = (l+r) >>1;
					if (sum[pos-1]-sum[mid-1]<=k) r = mid;
					else l = mid;
				}
				pos = max (r-2,0);
			}
			now++;
		}
		if (pos!=n) ans+=n-pos;
		printf ("%I64d\n",ans);
	}
	return 0;
	
