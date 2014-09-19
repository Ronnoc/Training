#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define PB push_back
#define OP begin()
#define ED end()
#define BB second
#define AA first
#define SZ size()
typedef pair<int,int> PII;
int main(){
	freopen("cubes.in","r",stdin);
	int i,j,T;
	scanf("%d",&T);
	for(int CA=1;CA<=T;CA++){
		int vis[105],n,a[105];
		scanf("%d",&n);
		for(i=0;i<n;i++)scanf("%d",&a[i]);
		for(i=1;i<=n;i++)vis[i]=i*(n-i+1);
		vector<PII>L;
		for(i=1;i<=n;i++)L.PB(MP(vis[i],-i));
		sort(L.OP,L.ED);
		reverse(L.OP,L.ED);
		sort(a,a+n);
		for(i=0;i<n;i++)vis[-L[i].BB]=a[i];
		printf("Case %d:\n",CA);
		printf("%d",vis[1]);
		for(i=2;i<=n;i++)printf(" %d",vis[i]);
		printf("\n");
	}
	return 0;
}
