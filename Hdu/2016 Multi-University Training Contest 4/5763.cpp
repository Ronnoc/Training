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

const int MXN = 100005;
struct KMP {//调用init(s(待匹配串),t(模式串));适用多次KMP
    char S[MXN], T[MXN];
    int next[MXN], is[MXN];
    int LT, LS;
    void init(char s[], char t[]) {
        int i;
        LT = strlen(t);
        LS = strlen(s);
        for(i = 0; i <= LT; i++) T[i] = t[i];
        for(i = 0; i <= LS; i++) S[i] = s[i];
    }
    void getnext() {
        int i, j;
        next[0]=-1; next[1] = 0;
        for (i = 1, j = 0; i < LT; ) {
            while (j != -1 && T[i] != T[j]) j = next[j];
            i++; j++;
            next[i] = j;
        }
    }
    void kmp() {
        int i, j;
        for(i = 0; i < LS; i++) is[i] = 0;
        for (i = 0, j = 0; i < LS; i++) {
            while (j != -1 && S[i] != T[j]) j = next[j];
            j++;
            if (j == LT) {
                is[i - LT + 1] = 1;
                j = next[j];
            }
        }
    }
}kmp;
char ss[Maxn],tt[Maxn];
LL dp[Maxn];
void solve(){
	scanf("%s%s",ss,tt);
	kmp.init(ss,tt);
	kmp.getnext();
	kmp.kmp();
	int lenss=strlen(ss);
	int lentt=strlen(tt);
	rep(i,0,lenss+1)dp[i]=0;
	dp[0]=1;
	rep(i,0,lenss){
		dp[i]%=MOD;
		dp[i+1]+=dp[i];
		if(kmp.is[i])
			dp[i+lentt]+=dp[i];
	}
	printf("%d\n",int(dp[lenss]%MOD));
}

int main(){
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		printf("Case #%d: ",CA+1);
		solve();
	}
	return 0;
}