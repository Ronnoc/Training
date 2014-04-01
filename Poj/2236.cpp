#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int ft[1010];
void inift( int n ) {
	for ( int i=1; i<=n; i++ )
		ft[i]=i;
}
int findft( int x ) {
	return ft[x]==x?x:ft[x]=findft( ft[x] );
}
void mergeft( int p,int q ) {
	ft[findft( p )]=findft( q );
}
int x[1010],y[1010];
double pow2( double x ) {return x*x;}
bool dis( int i,int j,int d ) {
	return pow2( x[i]-x[j] )+pow2( y[i]-y[j] )<=d*d;
}
int main() {
	int n,d;
	scanf( "%d %d%*c",&n,&d );
	int i,j;
	inift( n );
	for ( i=1; i<=n; i++ )
		scanf( "%d %d%*c",&x[i],&y[i] );
	vector<int>L;
	char cmd;
	while(scanf("%c",&cmd)!=EOF){
		if(cmd=='O'){
			int z;
			scanf("%d%*c",&z);
			for(i=0;i<L.size();i++)if(dis(L[i],z,d))mergeft(L[i],z);
			L.push_back(z);
		}
		else {
			int p,q;
			scanf("%d %d%*c",&p,&q);
			if(findft(p)==findft(q))printf("SUCCESS\n");
			else printf("FAIL\n");
		}
	}
	return 0;
}
