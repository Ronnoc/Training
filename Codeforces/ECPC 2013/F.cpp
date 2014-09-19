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
typedef long long LL;
const double PI = acos(-1.);
const double eps = 1e-8;
LL gao(LL id,LL g){
	if(id<=g)return id*(id+1)/2;
	return g*g-gao(2*g-1-id,g);
}
int main(){
	freopen("army.in","r",stdin);
	int i,j,T;
	LL sum=0;
	scanf("%d",&T);
	for(int CA=1;CA<=T;CA++){
		LL n;
		scanf("%I64d",&n);
		LL le=1,re=1442251,ge=-1;
		while(1){
			if(re-le<=1){
				LL fr=re*(re+1)*(2*re+1)/6;
				LL fl=le*(le+1)*(2*le+1)/6;
				if(fr<=n){ge=re;break;}
				if(fl<=n)ge=le;
				break;
			}
			LL mid=(le+re)>>1;
			LL f=mid*(mid+1)*(2*mid+1)/6;
			if(f<=n)le=mid;
			else re=mid;
		}
		LL ans=ge*ge;
		n-=ge*(ge+1)*(2*ge+1)/6;
		ge++;
		LL l=0,r=2*ge-1,g=-1;
		while(1){
			if(r-l<=1){
				LL fl=gao(l,ge);
				LL fr=gao(r,ge);
				if(fl>=n){g=l;break;}
				if(fr>=n)g=r;
				break;
			}
			LL mid=(l+r)>>1;
			LL f=gao(mid,ge);
			if(f>=n)r=mid;
			else l=mid;
		}
		ans+=g;
		printf("Case %d: %I64d\n",CA,ans);
	}
	return 0;
}
