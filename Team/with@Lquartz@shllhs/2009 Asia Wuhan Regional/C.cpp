//kybconnor
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define PB push_back
int p[55],L[55],v[55];
bool isr[1111];
int main() {
	int n,D;
	int CASE=0;
	while (~scanf ("%d%d",&n,&D)) {
		if (n==0&&D==0) break;
		int i,j;
		for (i=1; i<=n; i++) scanf ("%d%d%d",&p[i],&L[i],&v[i]);
		for (i=0; i<D; i++) isr[i]=0;
		for (i=1; i<=n; i++) for (j=0; j<L[i]; j++) isr[p[i]+j]=1;
		int tot=0;
		for (i=0; i<D; i++) if (!isr[i]) tot++;
		double res=tot;
		for (i=1; i<=n; i++) res+=2.0*L[i]/v[i];
		++CASE;
		printf ("Case %d: %.3lf\n\n",CASE,res);
	}
	return 0;
}
