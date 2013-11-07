//kybconnor
#include <map>
#include <set>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define PB push_back
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)

map<string,set<int> >S;
vector<string>L;
string ss;
int n,m;
char s[111];
int main() {
	while (~scanf ("%d",&n)) {
		S.clear();
		int ii,i,j,num;
		for (ii=1; ii<=n; ii++) {
			L.clear();
			scanf ("%d",&num);
			for (j=1; j<=num; j++) {
				scanf ("%s",s);
				ss=s;
				L.PB (ss);
			}
			SORT (L);
			for (i=1; i< (1<<num); i++) {
				string ss="";
				for (j=0; j<num; j++) if (i>>j&1) ss+=L[j]+"$";
				S[ss].insert (ii);
			}
		}
		scanf ("%d",&m);
		while (m--) {
			L.clear();
			scanf ("%d",&num);
			for (j=1; j<=num; j++) {
				scanf ("%s",s);
				ss=s;
				L.PB (ss);
			}
			SORT (L);
			ss="";
			for (i=0; i<L.SZ; i++) ss+=L[i]+"$";
			printf ("%d\n",S[ss].size());
		}
	}
	return 0;
}
