//kybconnor
#include <cstdio>
#include <cstring>
#define LL long long
struct mtx {
	LL x[4][4];
	mtx() {
		memset (x,0,sizeof x);
	}
};
const LL mod = 1000000007;
LL n,m,k;
mtx multi (mtx A,mtx B) {
	mtx ret;
	int i,j,k;
	for (i=1; i<=2; i++) for (j=1; j<=2; j++)
			for (k=1; k<=2; k++) ret.x[i][j]= (ret.x[i][j]+A.x[i][k]*B.x[k][j]) %mod;
	return ret;
}
int main() {
	mtx E;
	E.x[1][1]=1;
	E.x[2][2]=1;
	while (scanf ("%lld%lld%lld",&n,&m,&k) !=EOF) {
		LL temp=n-1;
		k=m-k;
		mtx X=E;
		mtx Y;
		Y.x[1][1]=m-k-1;
		Y.x[1][2]=m-k;
		Y.x[2][1]=k;
		Y.x[2][2]=k;
		while (temp) {
			if (temp&1) X=multi (X,Y);
			Y=multi (Y,Y);
			temp/=2;
		}
		LL res= (m-k) * (X.x[1][1]+X.x[2][1]) +k* (X.x[1][2]+X.x[2][2]);
		res%=mod;
		printf ("%lld\n",res);
	}
	return 0;
}
