#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		int L,n;
		scanf("%d%d",&L,&n);
		int x,r1=0,r2=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			r1=max(r1,min(x,L-x));
			r2=max(r2,max(x,L-x));
		}
		printf("%d %d\n",r1,r2);
	}
	return 0;
}
