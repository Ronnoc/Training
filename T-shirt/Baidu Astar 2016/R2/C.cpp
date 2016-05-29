#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const LL MOD = 1000000007;
const double eps = 1e-9;
int fl[30005],fr[30005],mxl[30005];
int main(){
	int i,j,k,_T;
	scanf("%d",&_T);
	for (int CA = 1; CA <= _T; ++CA){
		printf("Case #%d:\n",CA);
		vector<PII>L,R;
		int n;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			int x,y,z,d;
			scanf("%d%d%d%d",&x,&y,&z,&d);
			if(y-z>x+z)continue;
			if(d>0)	R.PB(MP(y-z,x+z));
			else 	L.PB(MP(y-z,x+z));
		}
		vector<int>ZL,ZR;
		for(i=0;i<L.SZ;i++)ZL.PB(L[i].AA),ZL.PB(L[i].BB);
		for(i=0;i<R.SZ;i++)ZR.PB(R[i].AA),ZR.PB(R[i].BB);
		sort(ZL.OP,ZL.ED);
		sort(ZR.OP,ZR.ED);
		ZL.erase(unique(ZL.OP,ZL.ED),ZL.ED);
		ZR.erase(unique(ZR.OP,ZR.ED),ZR.ED);
		memset(fl,0,sizeof fl);
		memset(fr,0,sizeof fr);
		for(i=0;i<L.SZ;i++){
			int li=lower_bound(ZL.OP,ZL.ED,L[i].AA)-ZL.OP;
			int ri=lower_bound(ZL.OP,ZL.ED,L[i].BB)-ZL.OP;
			fl[li]++;
			fl[ri+1]--;
		}
		for(i=0;i<R.SZ;i++){
			int li=lower_bound(ZR.OP,ZR.ED,R[i].AA)-ZR.OP;
			int ri=lower_bound(ZR.OP,ZR.ED,R[i].BB)-ZR.OP;
			fr[li]++;
			fr[ri+1]--;
		}
		for(i=1;i<=ZL.SZ;i++)
			fl[i]+=fl[i-1];
		mxl[ZL.SZ]=fl[ZL.SZ];
		for(i=ZL.SZ-1;i>=0;i--)
			mxl[i]=max(fl[i],mxl[i+1]);
		for(i=1;i<=ZR.SZ;i++)
			fr[i]+=fr[i-1];
		int ans=0;
		for(i=0;i<ZR.SZ;i++){
			int il=lower_bound(ZL.OP,ZL.ED,ZR[i])-ZL.OP;
			cmax(ans,fr[i]+mxl[il]);
		}
		printf("%d\n",ans);
	}
	return 0;
}