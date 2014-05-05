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
const double INF=1e20;
const double PI=acos( -1. );
const int MXN = 50;
const LL MOD = 1000000007;
map<pair<pair<LL,LL>,LL>,LL >M;
LL solve(LL A,LL B,LL K){
	LL &tp=M[MP(MP(A,B),K)];
	if(tp!=0)return tp;
//	cout<<"Solve "<<A<<" "<<B<<" "<<K<<endl;
	LL ret=0;
	if(A<=1&&B<=1){
		LL i,j;
		for(i=0;i<=A;i++)for(j=0;j<=B;j++)if((i&j)<=K)ret++;
		return tp=ret;
	}
	LL Z=max(A,B);
	LL del=1;
	while(del*2<=Z)del*=2;
	LL pa=min(del-1,A);
	LL pb=min(del-1,B);
	ret+=solve(pa,pb,K);
	if(B>=del)ret+=solve(pa,B-del,K);
	if(A>=del)ret+=solve(A-del,pb,K);
	if(A>=del&&B>=del&&K>=del)
		ret+=solve(A-del,B-del,min(K-del,del-1));
	return tp=ret;
}
int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt2.out","w",stdout);
	int i,j;
	int T;
	scanf("%d",&T);
	for(int CASE=1;CASE<=T;++CASE){
		int A,B,K;
		scanf("%d%d%d",&A,&B,&K);
		printf("Case #%d: ",CASE);
		printf("%lld\n",solve(A-1,B-1,K-1));
	}
	return 0;
}
