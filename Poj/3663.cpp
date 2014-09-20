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
int L[20005],nl;
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	while(~scanf("%d%d",&nl,&T)){
		for(i=0;i<nl;i++)scanf("%d",&L[i]);
		sort(L,L+nl);
		LL ans=0;
		for(i=0;i<nl;i++){
			int id=upper_bound(L,L+nl,T-L[i])-L;
//			cout<<id<<"~";
			if(id>0)ans+=id;
			if(L[i]*2<=T)ans--;
		}
		cout<<ans/2<<endl;
	}
	return 0;
}
