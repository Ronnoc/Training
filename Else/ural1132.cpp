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

LL modPow(LL a,LL b,LL mod){
	LL ret=1;
	while(b){if(b&1)ret=ret*a%mod;a=a*a%mod;b>>=1;}
	return ret;
}
/*
	call(b,0,a,(p+1)/2,p) return a sol of {x^2=a (mod p)}
	(there exist a sol)&&(p is odd prime)&&(b^( (p-1)/2 )==-1 mod p)
 */
LL call(LL b,LL c,LL a,LL x,LL p){
	if(x%2==0)return modPow(b,c/2,p)*modPow(a,x/2,p)%p;
	LL tp=modPow(b,c/2,p)*modPow(a,(x-1)/2,p)%p;
	if(tp==1)return call(b,c/2,a,(x+1)/2,p);
	return call(b,(c+p-1)/2,a,(x+1)/2,p);
}
int main() {
	int i,j,k,T;
	scanf("%d",&T);
	while(T--){
		int a,p,b;
		scanf("%d%d",&a,&p);
		a%=p;
		if(p==2){
			if(a==1)printf("%d\n",a%p);
			continue;
		}
		int tmp=modPow(a,(p-1)/2,p);
		if(tmp!=1){printf("No root\n");continue;}
		b=2;
		while(modPow(b,(p-1)/2,p)==1)b++;
		vector<int>Ans;
		Ans.PB(call(b,0,a,(p+1)/2,p));
		Ans.PB(p-Ans[0]);
		sort(Ans.OP,Ans.ED);
		printf("%d %d\n",Ans[0],Ans[1]);
	}
	return 0;
}
