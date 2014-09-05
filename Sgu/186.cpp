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
const double PI=acos( -1. );
const LL MOD = 1000000007;

int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,n,m,u,v,T;
	while(~scanf("%d",&n)){
		multiset<int>S;
		for(i=0;i<n;i++){
			scanf("%d",&u);
			S.insert(u);
		}
		int cnt=0;
		while(1){
			if(S.empty())break;
			int w=*S.OP;
			S.erase(S.OP);
			if(S.empty())break;
			int p=*(--S.ED);
			S.erase(--S.ED);
			if(S.empty()){
				cnt++;
				break;
			}else {
				int q=*(--S.ED);
				S.erase(--S.ED);
				S.insert(p+q+1);
				cnt++;
				if(w>1)S.insert(w-1);
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
