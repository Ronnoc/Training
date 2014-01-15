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
LL llpow(LL a,LL p,LL mod){
	a%=mod;
	LL ret=1;
	while(p){
		if(p&1)ret=ret*a%mod;
		a=a*a%mod;
		p/=2;
	}
	return ret;
}
bool isprime(LL x){
	if(x==1)return 0;
	LL i;
	for(i=2;i*i<=x;i++)if(x%i);else return 0;
	return 1;
}
void solve(){
	int i,j;
	LL p,a;
	while(cin>>p>>a&&(p&&a)){
		LL tp=llpow(a,p,p);
		if(tp==a&&!isprime(p))cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
}
int main(){
//	while(1)
		solve();
	return 0;
}
