//kybconnor
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
using namespace std;

typedef long long LL;
LL mod = 1000003;
LL comb[1111][1111];
int one[66],zero[66];
int main() {
	LL i,j;
	memset (comb,0,sizeof comb);
	comb[0][0]=1LL;
	for (i=1; i<=1000; i++) {
		comb[i][0]=1LL;
		for (j=1; j<=i; j++) comb[i][j]= (comb[i-1][j]+comb[i-1][j-1]) %mod;
	}
	int n;
	while (scanf ("%d",&n) !=EOF) {
		memset (one,0,sizeof one);
		memset (zero,0,sizeof zero);
		for (i=1; i<=n; i++) {
			LL x;
			scanf ("%I64d",&x);
			for (j=0LL; j<64LL; j++)
				if (x>>j&1LL) one[j]++;
				else zero[j]++;
		}
		int k;
		vector<LL>ans;
		for (k=1; k<=n; k++) {
			LL res=0LL;
			for (j=0LL; j<64LL; j++) {
				LL now=0LL;
				for (i=0LL; i<=k; i++) {
					if (zero[j]+i<k) continue;
					if (i>one[j]) break;
					if (i&1LL) {
						now+=comb[one[j]][i]*comb[zero[j]][k-i]%mod;
						now%=mod;
					}
				}
				res+= (1LL<<j) %mod*now%mod;
			}
			res%=mod;
			ans.push_back (res);
		}
		printf ("%I64d",ans[0]);
		for (i=1LL; i<ans.size(); i++) printf (" %I64d",ans[i]);
		printf ("\n");
	}
	return 0;
}
