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
bool notp[555];
int p[555],pn;
void shai( int n ) {
	pn=0,notp[0]=1;
	for ( int i=2; i<n; i++ ) {
		if ( !notp[i] )p[pn++]=i;
		for ( int j=0; j<pn&&i*p[j]<n; j++ ) {
			notp[i*p[j]]=1;
			if ( i%p[j]==0 )break;
		}
	}
}
int got(int n,int p){
	if(n<p)return 0;
	return n/p+got(n/p,p);
}
int cnt[555];
int main(){
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	shai(432);
	int N,K;
	while(~scanf("%d%d",&N,&K)){
		for(i=0;i<pn;i++)cnt[i]=got(N,p[i])-got(K,p[i])-got(N-K,p[i]);
		LL ans=1;
		for(i=0;i<pn;i++)ans*=cnt[i]+1;
		cout<<ans<<endl;
	}
	return 0;
}
