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
const int Max = 100005;

int  num[Max];
int sa[Max], rank[Max], height[Max];
int wa[Max], wb[Max], wv[Max], wd[Max];

int cmp( int *r, int a, int b, int l ) {
	return r[a] == r[b] && r[a+l] == r[b+l];
}
void da( int *r, int n, int m ) {       //  倍增算法 r为待匹配数组  n为总长度 m为字符范围
	int i, j, p, *x = wa, *y = wb, *t;
	for ( i = 0; i < m; i ++ ) wd[i] = 0;
	for ( i = 0; i < n; i ++ ) wd[x[i]=r[i]] ++;
	for ( i = 1; i < m; i ++ ) wd[i] += wd[i-1];
	for ( i = n-1; i >= 0; i -- ) sa[-- wd[x[i]]] = i;
	for ( j = 1, p = 1; p < n; j *= 2, m = p ) {
		for ( p = 0, i = n-j; i < n; i ++ ) y[p ++] = i;
		for ( i = 0; i < n; i ++ ) if ( sa[i] >= j ) y[p ++] = sa[i] - j;
		for ( i = 0; i < n; i ++ ) wv[i] = x[y[i]];
		for ( i = 0; i < m; i ++ ) wd[i] = 0;
		for ( i = 0; i < n; i ++ ) wd[wv[i]] ++;
		for ( i = 1; i < m; i ++ ) wd[i] += wd[i-1];
		for ( i = n-1; i >= 0; i -- ) sa[-- wd[wv[i]]] = y[i];
		for ( t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i ++ ) {
			x[sa[i]] = cmp( y, sa[i-1], sa[i], j ) ? p - 1: p ++;
		}
	}
}
void calHeight( int *r, int n ) {        //  求height数组。
	int i, j, k = 0;
	for ( i = 1; i <= n; i ++ ) rank[sa[i]] = i;
	for ( i = 0; i < n; height[rank[i ++]] = k ) {
		for ( k ? k -- : 0, j = sa[rank[i]-1]; r[i+k] == r[j+k]; k ++ );
	}
}
char s[100005];
int tot[100005];
LL p1[100005];
LL p2[100005];
int ans[100005];
int main() {
	int i,j;
	p1[0]=1;
	for ( i=1; i<=100000; i++ )p1[i]=p1[i-1]*31%MOD;
	p2[0]=1;
	for ( i=1; i<=100000; i++ )p2[i]=p2[i-1]*37%MOD;
	while ( ~scanf( "%s",s ) ) {
		int len=strlen(s);
		for(i=0;i<=len;i++)num[i]=s[i];
		num[len]=0;
		da(num,len+1,300);
		calHeight(num,len);
		memset( tot,0,sizeof tot );
		int id=rank[0];
		tot[len]++;
		int now=len;
		for ( i=id; i>=1; i-- ) {
			cmin( now,height[i] );
			tot[now]++;
		}
		now=len;
		for ( i=id+1; i<len; i++ ) {
			cmin( now,height[i] );
			tot[now]++;
		}
		ans[len]=tot[len];
		for ( i=len-1; i>=0; i-- )ans[i]=ans[i+1]+tot[i];
		set<LL>S1,S2;
		LL h1=0,h2=0;
		for ( i=len-1; i>=0; i-- ) {
			h1=( h1+( s[i]-'A'+1 )*p1[len-1-i] )%MOD;
			h2=( h2+( s[i]-'A'+1 )*p2[len-1-i] )%MOD;
			S1.insert( h1 ),S2.insert(h2);
		}
		h1=0,h2=0;
		int cnt=0;
		for ( i=0; i<len; i++ ) {
			h1=( h1*31+s[i]-'A'+1 )%MOD;
			h2=( h2*37+s[i]-'A'+1 )%MOD;
			if ( S1.count( h1 )&&S2.count(h2) )cnt++;
		}
		h1=0,h2=0;
		printf("%d\n",cnt);
		for ( i=0; i<len; i++ ) {
			h1=( h1*31+s[i]-'A'+1 )%MOD;
			h2=( h2*37+s[i]-'A'+1 )%MOD;
			if ( S1.count( h1 )&&S2.count(h2) )printf( "%d %d\n",i+1,ans[i+1] );
		}
	}
	return 0;
}
