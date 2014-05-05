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
int isp[66666];
LL llpow(LL a,LL x,LL mod){
	LL ret=1;
	while(x){
		if(x&1)ret=ret*a%mod;
		a=a*a%mod;
		x/=2;
	}
	return ret;
}
int cam[15]={561,1105,1729,2465,2821,6601,8911,10585,15841,29341,41041,46657,52633,62745,63973};
void solve(){
	LL i,j;
	set<int>S;
	for(i=3;i<=65000;i+=2)isp[i]=1;
	for(isp[2]=1,i=3;i<=65000;i+=2)if(isp[i])
		for(j=i*i;j<=65000;j+=2*i)isp[j]=0;
	for(i=1;i<=65000;i++){
		if(isp[i])continue;
		int flag=1;
		for(j=2;j<i;j++)if(llpow(j,i,i)!=j){flag=0;break;}
		if(flag)S.insert(i);
	}
	int n;
//	for(i=0;i<15;i++)S.insert(cam[i]);
	while(scanf("%d",&n)!=EOF&&n){
		int flag=S.find(n)!=S.end();
////		if(isp[n])flag=0;
////		if(flag)for(j=2;j<n;j++)if(llpow(j,n,n)!=j){flag=0;break;}
		if(flag)printf("The number %d is a Carmichael number.\n",n);
		else printf("%d is normal.\n",n);
	}
}
int main(){
//	freopen("cam.txt","w",stdout);
//	while(1)
		solve();
	return 0;
}
