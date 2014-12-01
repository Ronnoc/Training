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
LL n,m,a[111111], b[111111],fee;
bool check(LL su){
	LL i,j;
	LL owe=0;
	for(i=1;i<=su;i++)
		if(b[i]<a[su+1-i])owe+=a[su+1-i]-b[i];
	if(owe<=fee)return 1;
	return 0;
}
void solve() {
	while (~scanf ("%I64d%I64d%I64d",&n,&m,&fee)) {
		LL i,j;
		for (i=1; i<=n; i++) scanf ("%I64d",&b[i]);
		for (j=1; j<=m; j++) scanf ("%I64d",&a[j]);
		for (i=1; i<=n; i++) b[i]=-b[i];
		sort(a+1,a+1+m);
		sort(b+1,b+1+n);
		for (i=1; i<=n; i++) b[i]=-b[i];
//		for(i=1;i<=n;i++)cout<<b[i]<<" ";cout<<endl;
//		for(i=1;i<=m;i++)cout<<a[i]<<" ";cout<<endl;
		LL l1=0,r1=min(n,m);
		LL res1,res2;
		while(r1>=l1){
			if(r1-l1<=1){
				if(check(r1))res1=r1;
				else res1=l1;break;
			}
			LL mid=(l1+r1)/2;
			if(check(mid))l1=mid;else r1=mid;
		}
		LL my=0,our=0;
		for(i=1;i<=res1;i++){
			if(b[i]<a[res1+1-i])my+=b[i],our+=a[res1+1-i]-b[i];
			else my+=a[res1+1-i];
		}
		LL last=fee-our;
		my-=last;
		if(my<0)my=0; 
		cout<<res1<<" "<<my<<endl;
	}
}
int main() {
//	while(1)
	solve();
	return 0;
}
