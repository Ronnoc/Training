#include <cstdio>
const int N = 500005;
int mu[N],p[N],pn;
bool flag[N];
unsigned int S[N],T[N],D[N],A[N];
unsigned int gao(long long a){return a*(a+1)/2;}
void init ( int n ) {
	pn=0,mu[1]=1;
	int i,j;
	for ( i=2; i<=n; i++ ) {
		if ( !flag[i] ) p[pn++]=i,mu[i]=-1;
		for ( j=0; j<pn&&i*p[j]<=n; j++ ) {
			flag[i*p[j]]=1;
			if ( i%p[j] ) mu[i*p[j]]=-mu[i];
			else {
				mu[i*p[j]]=0;
				break;
			}
		}
	}
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j+=i)
			S[j]+=j*i;
	for(i=1;i<=n;i++)if(mu[i])
		for(j=i;j<=n;j+=i)
			T[j]+=gao(j/i)*j*i*mu[i];
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j+=i)
			D[j]+=S[i]*T[j/i];
	for(i=1;i<=n;i++)
		A[i]=A[i-1]+D[i];
}
int main() {
	init(500000);
	int T,n;
	scanf ( "%d",&T );
	for ( int CA=1; CA<=T; CA++ ) {
		scanf ( "%d",&n );
		printf ( "Case #%d: %u\n",CA,A[n] );
	}
	return 0;
}
