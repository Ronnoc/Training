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
const double PI = acos(-1.);
int main(){
	freopen("zeriba.in","r",stdin);
	int i,j,T,n;
	scanf("%d",&T);
	for(int CA=1;CA<=T;CA++){
		scanf("%d",&n);
		int x[1005];
		for(i=1;i<=n;i++)scanf("%d",&x[i]);
		int mx=-1;
		for(i=1;i<=n;i++)if(x[i]>mx)mx=x[i];
		int sum=0;
		for(i=1;i<=n;i++)sum+=x[i];
		sum-=mx;
		if(sum<=mx){
			printf("Case %d: can't form a convex polygon\n",CA);
			continue;
		}
		double le=0,re=10000000;
		for(i=1;i<=n;i++)if(x[i]>le)le=x[i]*0.5;
		for(int t=0;t<=100&&(re-le)>1e-8;t++){
			double mid=(le+re)/2;
			double sum=0;
			for(i=1;i<=n;i++){
				double t=x[i]*0.5;
				double d=sqrt(mid*mid-t*t);
				double A=atan2(t,d);
				sum+=A;
			}
			if(sum<=PI)re=mid;
			else le=mid;
		}
		printf("Case %d: %.4f\n",CA,(le+re)*0.5);
	}
	return 0;
}
