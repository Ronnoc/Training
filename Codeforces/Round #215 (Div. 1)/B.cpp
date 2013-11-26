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
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define UNIQUE(x) x.erase(unique(x.OP,x.ED),x.ED)
typedef long long LL;
typedef pair<int, int> PII;
LL n,m,p;
int a[222222];
int b[222222];
vector<int>ocur,B;
vector<int>::iterator iter;
int tot[222222];
int now[222222];
set<int>BB;
void solve() {
	while (~scanf ("%I64d%I64d%I64d",&n,&m,&p)) {
		memset (tot,0,sizeof tot);
		ocur.clear(),B.clear(),BB.clear();
		int id,i,j;
		for (i=1; i<=n; i++) scanf ("%d",&a[i]);
		for (i=1; i<=m; i++) scanf ("%d",&b[i]);
		if (1+ (m-1) *p>n) {printf ("0\n"); continue;}
		sort (b+1,b+1+m);
		for (i=1; i<=m; i++) ocur.PB (b[i]);
		for (i=1; i<=m; i++) B.PB (b[i]);
		SORT (ocur);
		UNIQUE (ocur);
		for (i=0; i<ocur.SZ; i++)
			tot[i]=upper_bound (B.OP,B.ED,ocur[i])-lower_bound (B.OP,B.ED,ocur[i]);
		set<int>ans;
		set<int>::iterator ster;
		for (id=1; id<=p; id++) {
			for (i=0; i<ocur.SZ; i++) now[i]=0;
			int l=id,r=id-p;
			int same=0;
			while (r<=n) {
				if (r-l== (m-1) *p) {
//					cout<<"!"<<endl;
					if (same==ocur.SZ) ans.insert (l);
					iter=lower_bound (ocur.OP,ocur.ED,a[l]);
					int k=iter-ocur.OP;
					now[k]--;
					same--;
					l+=p;
				} else {
					r+=p;
					if (r>n) break;
					iter=lower_bound (ocur.OP,ocur.ED,a[r]);
					if (iter==ocur.ED||*iter!=a[r]) {
						while (l<=r) {
							iter=lower_bound (ocur.OP,ocur.ED,a[l]);
							int k=iter-ocur.OP;
							now[k]=0;
							l+=p;
						}
						same=0;
					} else {
						int k=iter-ocur.OP;
						now[k]++;
						if (now[k]>tot[k]) {
							while (now[k]>tot[k]) {
								iter=lower_bound (ocur.OP,ocur.ED,a[l]);
								int kk=iter-ocur.OP;
								now[kk]--;
								if (now[kk]+1==tot[kk]) same--;
								l+=p;
							}
						} else if (now[k]==tot[k]) same++;
					}
				}
			}
		}
		printf ("%d\n",ans.SZ);
		for (ster=ans.OP; ster!=ans.ED; ++ster)
			printf ("%d ",*ster);
		printf ("\n");
	}
}
int main() {
//	while(1)
	solve();
	return 0;
}
