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
bool v[360365];
int main(){
	freopen("zanzibar.in","r",stdin);
	int i,j,T;
	LL g=360360;
	memset(v,0,sizeof v);
	v[0]=1;
	for(i=2;i<=13;i++)
		for(j=g/i;j<=g;j++)if(!v[j])
			v[j]|=v[j-g/i];
	vector<int>L;
	vector<double>R;
	for(i=0;i<=g;i++)if(v[i])L.PB(i),R.PB(1.*i/g);
	scanf("%d",&T);
	for(int CA=1;CA<=T;CA++){
		LL X,Y;
		scanf("%I64d%I64d",&X,&Y);
		double Z=1.*X/Y;
		int id=lower_bound(R.OP,R.ED,Z)-R.OP;
		double dis=1;
		int t=-1;
		for(i=max(id-2,0);i<=id+2&&i<R.SZ;i++)if(fabs(R[i]-Z)<dis)
			dis=fabs(R[i]-Z),t=L[i];
		LL U=Y*t-X*g;
		LL V=Y*g;
		if(U<0)U=-U;
		LL G=__gcd(U,V);
		U/=G,V/=G;
		printf("Case %d: %I64d/%I64d\n",CA,U,V);
	}
	return 0;
}
