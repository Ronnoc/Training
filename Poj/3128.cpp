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
const double PI=acos ( -1. );
const LL MOD = 1000000007;
#define MAXN 1005
int cnt[MAXN];
int polya ( int* perm, int n) {
	int i, j, p, v[MAXN] = {0}, ret = 1,num=0;
	memset(cnt,0,sizeof cnt);
	for ( num = i = 0; i < n; i++ )
		if ( !v[i] ) {
			for ( num++, j = 0, p = i; !v[p = perm[p]]; j++ )
				v[p] = 1;
			ret *= j / __gcd ( ret, j ),cnt[j]++;
		}
	return ret;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,u,v,w,p,q,r,n,m;
	int T;
	scanf("%d",&T);
	while(T--){
		char s[33];
		scanf("%s",s);
		int a[33];
		for(i=0;s[i];i++)
			a[i]=s[i]-'A';
		polya(a,26);
		int flag=1;
		for(i=2;i<=26;i+=2)if(cnt[i]&1)flag=0;
		if(flag)puts("Yes");
		else puts("No");
	}
	return 0;
}
