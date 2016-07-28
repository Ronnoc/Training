#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<cstdlib>
#include<cctype>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<fstream>
#include<numeric>
#include<iomanip>
#include<bitset>
#include<list>
#include<stdexcept>
#include<functional>
#include<utility>
#include<ctime>
#include<cassert>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(int)(n);i++)
#define repd(i,a,b,d) for(int i=(a);i!=(b);i+=d)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;
LL modPow(LL a,LL b,LL MOD){
	LL ret=1;for(;b;b>>=1){
		if(b&1)ret=ret*a%MOD;a=a*a%MOD;
	}return ret;
}
const int Maxn = 100005;
//O(nlogn)
//调用da(num, len+1, m);//m为字符个数略大
int len;
int num[Maxn];  //待处理的串
int sa[Maxn], rnk[Maxn], height[Maxn];    //sa[1~n]value(0~n-1); rnk[0..n-1]value(1..n); height[2..n]
int wv[Maxn], wd[Maxn];

int cmp(int *r, int a, int b, int x) {
    return r[a] == r[b] && r[a + x] == r[b + x];
}

void da(int *r, int n, int m) {       //  倍增算法 r为待匹配数组  n为总长度+1 m为字符范围
    int i, j, k, p, *x = rnk, *y = height, *t;
    for(i = 0; i < m; i++) wd[i] = 0;
    for(i = 0; i < n; i++) wd[x[i] = r[i]]++;
    for(i = 1; i < m; i++) wd[i] += wd[i - 1];
    for(i = n - 1; i >= 0; i--) sa[--wd[x[i]]] = i;
    for(j = 1, p = 1; p < n; j <<= 1, m = p) {
        for(p = 0, i = n - j; i < n; i++) y[p++] = i;
        for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
        for(i = 0; i < n; i++) wv[i] = x[y[i]];
        for(i = 0; i < m; i++) wd[i] = 0;
        for(i = 0; i < n; i++) wd[wv[i]]++;
        for(i = 1; i < m; i++) wd[i] += wd[i - 1];
        for(i = n - 1; i >= 0; i--) sa[--wd[wv[i]]] = y[i];
        for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++) {
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
        }
    }

    for(i = 0, k = 0; i < n; i++) rnk[sa[i]] = i;
    for(i = 0; i < n - 1; height[rnk[i++]] = k) {
        for(k ? k-- : 0, j = sa[rnk[i] - 1]; r[i + k] == r[j + k]; k++);
    }
}
char t[5];
char s[Maxn];
int nxt[Maxn];
void solve(){
	scanf("%s%s",t,s);
	int len=strlen(s);
	int last=len;
	repd(i,len,-1,-1){
		if(s[i]==t[0])last=i;
		nxt[i]=last;
	}
	rep(i,0,len)num[i]=s[i]-'a'+1;
	num[len]=0;
	da(num,len+1,27);
	LL ans=0;
	rep(i,1,len+1){
		int lcp=height[i];
		int g=nxt[sa[i]];
		int must=g-sa[i]+1;
		//cout<<i<<" "<<sa[i]<<" "<<lcp<<" "<<g<<" "<<must<<"\n";
		cmax(must,lcp+1);
		ans+=len-sa[i]-must+1;
	}
	cout<<ans<<"\n";
}

int main(){
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		cout<<"Case #"<<CA+1<<": ";
		solve();
	}
	return 0;
}