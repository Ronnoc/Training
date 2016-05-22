#include<bits/stdc++.h>
using namespace std;
#define OP begin()
#define ED end()
#define SZ size()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)

int a[500005];
int main() {
	int i, j, k, _T;
	scanf("%d", &_T);
	while (_T--) {
		int n;
		scanf("%d", &n);
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		if(a[1]==a[n]){
			printf("%d\n",a[1]);
			continue;
		}
		set<int>Y;
		for(int i=1;i*i<=a[1];i++)if(a[1]%i==0){
			Y.insert(i);
			Y.insert(a[1]/i);
		}
		n=unique(a+1,a+n+1)-a;
		int ans=-1;
		for(set<int>::iterator it=Y.ED;it!=Y.OP;){
			it--;
			int x=*it;
			if(x<=ans)break;
			int le=0,re=a[1];
			for(int i=2;i<n;i++){
				if(a[i]%x)le=__gcd(le,a[i]);
				else re=__gcd(re,a[i]);
			}
			if(le==0)le=__gcd(le,a[n]);
			else if(a[n]%x)le=__gcd(le,a[n]);
			else re=__gcd(re,a[n]);
			cmax(ans,min(le,re));
		}
		printf("%d\n",ans);
	}
	return 0;
}