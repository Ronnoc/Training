//kybconnor
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL long long
bool jump[ (1<<25) +2];
const LL mod = 55566677;
int n,m;
int G[33][33];
set<pair<int,int > >DC;
set<pair<int,int > >::iterator iter;
int D[33];
int C[33];
LL JC[55];
map<int,int>ac;
int main() {
	JC[0]=1;
	for (int i=1; i<=50; i++) JC[i]= (JC[i-1]*i) %mod;
	while (~scanf ("%d%d",&n,&m)) {
		ac.clear();
		DC.clear();
		memset (G,0,sizeof G);
		memset (jump,0,sizeof jump);
		int i,j;
		for (i=0; i<m; i++) {
			int p,q;
			scanf ("%d%d",&p,&q);
			DC.insert (make_pair (p,q));
		}
		int tp=0;
		for (iter=DC.begin(); iter!=DC.end(); ++iter) {
			D[tp]= (*iter).first;
			C[tp]= (*iter).second;
			tp++;
		}
		m=tp;
		for (i=0; i<m; i++) for (j=0; j<m; j++) {
				if (D[i]==D[j]) if (C[i]!=C[j]) G[i][j]=1;
				if (C[i]==C[j]) if (D[i]!=D[j]) G[i][j]=1;
			}
		for (i=0; i<m; i++) {
			ac[1<<i]=0;
			for (j=0; j<m; j++) if (G[i][j]) ac[1<<i]=ac[1<<i]| (1<<j);
		}
		LL res=JC[n]%mod;
		for (i=1; i< (1<<m); i++) {
			int last=i& (-i);
			int cnt=__builtin_popcount (i);
			if (jump[i-last]) jump[i]=1;
			else if (i&ac[last]) jump[i]=1;
			else if (cnt&1) res-=JC[n-cnt];
			else res+=JC[n-cnt];
		}
		res= (res%mod+mod) %mod;
		printf ("%lld\n",res);
	}
	return 0;
}
