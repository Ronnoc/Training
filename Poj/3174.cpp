#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps=1e-8;
const double PI=acos(-1.);
const LL MOD = 1000000007;

int x[777],y[777],n;
inline int mabs(int x) {return x>0?x:-x;}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	while(~scanf("%d",&n)) {
		for(i=1; i<=n; i++)scanf("%d%d",&x[i],&y[i]);
		vector<pair<PII,int> >S;
		for(i=1; i<=n; i++) {
			vector<pair<PII,int> >L;
			for(j=i+1; j<=n; j++) {
				int dx=x[j]-x[i];
				int dy=y[j]-y[i];
				int g=__gcd(mabs(dx),mabs(dy));
				dx/=g; dy/=g;
				if(dx<0)dx=-dx,dy=-dy;
				if(dx==0&&dy<0)dy=-dy;
				L.PB(MP(MP(dx,dy),j));
			}
			sort(L.OP,L.ED);
			int le=0,re=0;
			while(le<L.SZ) {
				re=le;
				while(re<L.SZ&&L[le].AA==L[re].AA)re++;
				for(j=le; j<re; j++)
					for(k=j+1; k<re; k++)
						S.PB(MP(MP(i,L[j].BB),L[k].BB));
				le=re;
			}
		}
		printf("%d\n",S.SZ);
		sort(S.OP,S.ED);
		for(i=0; i<S.SZ; i++)
			printf("%d %d %d\n",S[i].AA.AA,S[i].AA.BB,S[i].BB);
	}
	return 0;
}
