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
#define UNIQUE(x) x.erase(unique(x.OP,X.ED),x.ED)
typedef long long LL;
typedef pair<int, int> PII;
set<int>S;
set<int>::iterator iter;
int n,m;
void solve(){
	while(~scanf("%d%d",&n,&m)){
		int i,x;
		S.clear();
		for(i=1;i<=m;i++){
			scanf("%d",&x);
			S.insert(x);
		}
		if(S.find(n)!=S.ED){printf("NO\n");continue;}
		if(S.find(1)!=S.ED){printf("NO\n");continue;}
		vector<int>L;
		L.clear();
		for(iter=S.OP;iter!=S.ED;iter++)L.PB(*iter);
		int fall=0;
		for(i=0;i+2<L.SZ;i++){
			if(L[i+1]==L[i]+1&&L[i+2]==L[i]+2)fall=1;
		}
		if(fall)printf("NO\n");
		else printf("YES\n");
	}
}
int main(){
//	while(1)
		solve();
	return 0;
}
