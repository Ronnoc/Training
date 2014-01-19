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
typedef long long LL;
typedef pair<int, int> PII;
map<pair<LL,LL>,LL>S;
LL cb[22][22];
LL comb(LL n,LL m){
	if(m==0LL)return 1LL;
	if(m==1LL)return n;
	if(n<=20LL)return cb[n][m];
	if(m+m>n)return comb(n,n-m);
	LL &tp=S[MP(n,m)];
	if(tp!=0)return tp;
	return tp=comb(n-1,m-1)+comb(n-1,m);
}
void solve(){
	int i,j;
	cb[0][0]=1;
	for(i=1;i<=20;i++){
		cb[i][0]=1;
		for(j=1;j<=i;j++)cb[i][j]=cb[i-1][j-1]+cb[i-1][j];
	}
	LL n,m;
	while(cin>>n>>m){
		if(!m&&!n)break;
		cout<<comb(n+m,n)<<endl;
	}
}
int main(){
//	while(1)
		solve();
	return 0;
}
