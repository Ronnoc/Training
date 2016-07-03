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

char s[10005];
int x[10005];
void solve(){
	scanf("%s",s);
	int len=strlen(s);
	rep(i,0,len)x[i]=s[i]-'0';
	int sum=accumulate(x,x+len,0);
	if(sum%3){
		printf("-1\n");
		return;
	}
	int s=sum/3;
	vector<int>L[3];
	rep(i,0,3){
		int t=s;
		rep(j,0,len){
			int w=0;
			while(t>0&&x[j]>0)
				w++,x[j]--,t--;
			if(!L[i].empty()||w)L[i].PB(w);
		}
		rep(j,0,sz(L[i])){
			putchar('0'+L[i][j]);
		}
		if(i==2)putchar('\n');
		else putchar(' ');
	}
}

int main(){
	int _T=1;
	rep(CA,0,_T){
		solve();
	}
	return 0;
}