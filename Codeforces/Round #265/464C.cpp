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

LL powMod(LL a,LL b,LL m) {
	LL ret=1;
	while(b) {
		if(b&1)ret=ret*a%m;
		a=a*a%m;
		b>>=1;
	}
	return ret;
}
LL len[22],tran[22];
char s[111111];
char t[111111];
vector<string>L;
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	while(~scanf("%s",s)){
		for(i=0;i<=9;i++)len[i]=1,tran[i]=i;
		int n;
		scanf("%d",&n);
		L.clear();
		string ssss="1->"+string(s);
		L.PB(ssss);
		for(i=1;i<=n;i++){
			scanf("%s",t);
			L.PB(string(t));
		}
		reverse(L.OP,L.ED);
		for(i=0;i<L.SZ;i++){
			string ss=L[i].substr(3,L[i].SZ-3);
			int t=L[i][0]-'0';
			LL _l=0,_t=0;
			reverse(ss.OP,ss.ED);
			for(j=0;j<ss.SZ;j++){
				int w=ss[j]-'0';
				_t=(_t+tran[w]*powMod(10,_l,MOD))%MOD;
				_l=(_l+len[w])%(MOD-1);
			}
			tran[t]=_t,len[t]=_l;
		}
		cout<<tran[1]<<endl;
	}
	return 0;
}
