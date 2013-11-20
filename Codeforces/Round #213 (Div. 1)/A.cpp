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
vector<LL>L;
vector<LL>::iterator iter,jter;
char s[4444];
LL sum[4444];
void solve() {
	int a;
	int i,j;
	while (cin>>a>>s) {
		int len=strlen (s);
		L.clear();
		sum[0]=0;
		for (i=0; i<len; i++) sum[i+1]=sum[i]+s[i]-'0';
		for (i=1; i<=len; i++) for (j=i; j<=len; j++) {
				LL p=sum[j]-sum[i-1];
				L.PB (p);
			}
		SORT (L);
		LL res=0;
		if(a!=0)for (i=0; i<L.SZ; i++) {
			if (L[i]!=0&&a%L[i]==0) {
				iter=lower_bound (L.OP,L.ED,a/L[i]);
				jter=upper_bound (L.OP,L.ED,a/L[i]);
				res+=jter-iter;
			}
		}else for (i=0; i<L.SZ; i++)
			if(L[i]==0)res+=L.SZ;
			else {
				iter=lower_bound (L.OP,L.ED,0);
				jter=upper_bound (L.OP,L.ED,0);
				res+=jter-iter;
			}
		cout<<res<<endl;
	}
}
int main() {
//	while(1)
	solve();
	return 0;
}
