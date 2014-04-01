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

const double eps = 1e-8;
const int MOD = 1000000007;
#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(X) sort(X.OP,X.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
typedef long long LL;
typedef pair<int, int> PII;
int main(){
	int i,j;
	int n;
	int x[1111],y[1111];
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
		set<PII>S;
		for(i=1;i<=n;++i)S.insert(MP(x[i],y[i]));
		int tot=0;
		for(i=1;i<=n;i++)for(j=i+1;j<=n;j++){
			if(y[i]!=y[j])continue;
			int d=abs(x[i]-x[j]);
			if(S.count(MP(x[i],y[i]+d))&&S.count(MP(x[j],y[j]+d)))
				tot++;
		}
		printf("%d\n",tot);
	}
	return 0;
}
