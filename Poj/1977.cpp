#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
struct mtx {
	int n,x[110][110];
	mtx() {
		n=0;
		memset( x,0,sizeof( x ) );
		};
	mtx operator * ( const mtx &t ) const {
		mtx ret;
		ret.n=n;
		int i,j,k;
		for ( i=1; i<=n; i++ )
			for ( j=1; j<=n; j++ ) {
				ret.x[i][j]=0;
				for ( k=1; k<=n; k++ )
					ret.x[i][j]+=x[i][k]*t.x[k][j];
				ret.x[i][j]%=2;
				}
		return ret;
		}
	};
int main() {
	int X;
	cin>>X;
	while ( X-- ) {
		int n,t,i,j,k;
		cin>>n>>t;t--;
		string name[110],tp;
		vector<string> to[110];
		int tot[110],now[110];
		for ( i=1; i<=n; i++ ) {
			cin>>name[i]>>now[i]>>tot[i];
			now[i]%=2;
			for ( j=1; j<=tot[i]; j++ ) {
				cin>>tp;
				to[i].push_back( tp );
				}
			}
		mtx E,tsf,pp,qq;
		E.n=n;
		for ( i=1; i<=n; i++ )
			for ( j=1; j<=n; j++ )
				E.x[i][j]=( i==j )?1:0;
		tsf=E;
		for ( i=1; i<=n; i++ )
			for ( j=0; j<to[i].size(); j++ )
				for ( k=1; k<=n; k++ )
					if ( name[k]==to[i][j] ) {
						tsf.x[i][k]+=1;
						break;
						}
		while ( t ) {
			if ( t&1 ) {
				pp=E,qq=tsf;
				E=pp*qq;
				}
			pp=tsf,qq=tsf;
			tsf=pp*qq;
			t/=2;
			}
		int res[110];
		for ( i=1; i<=n; i++ )
			res[i]=0;
		for ( i=1; i<=n; i++ ) {
			for ( j=1; j<=n; j++ )
				res[i]+=now[j]*E.x[j][i];
			res[i]%=2;
			}
		int ans=0;
		for ( i=1; i<=n; i++ )
			ans+=res[i];
		cout<<ans<<endl;
		}
	return 0;
	}
