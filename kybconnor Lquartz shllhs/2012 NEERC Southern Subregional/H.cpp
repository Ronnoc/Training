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

typedef long long LL;
typedef pair<int, int> PII;
vector<int>L;
vector<int>G[4444];
int m[4444];
int c[4444];
void solve(){
	int n,k;
	while(~scanf("%d%d",&n,&k)){
		int i,j;
		L.clear();
		for(i=1;i<=4000;i++)G[i].clear();
		int mm,cc;
		for(i=1;i<=n;i++){
			scanf("%d%d",&m[i],&c[i]);
			G[m[i]].PB(-c[i]);
		}
		for(i=1;i<=4000;i++)SORT(G[i]);
		for(i=1;i<=4000;i++)L.PB(-G[i].SZ);
		SORT(L);
		int ans1=-L[k-1];
		L.clear();
		int ans2=0;
		for(i=1;i<=4000;i++)if(G[i].SZ>=ans1){
			int now=0;
			for(j=0;j<ans1;j++)now+=-G[i][j];
			L.PB(-now);
			//cout<<now<<" ";
		}//cout<<endl;
		SORT(L);
		for(i=0;i<k;i++)ans2+=-L[i];
		printf("%d %d\n",ans1,ans2);
	}
}
int main(){
//	while(1)
		solve();
	return 0;
}
