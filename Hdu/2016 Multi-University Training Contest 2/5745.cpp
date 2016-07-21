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

char s[100005];
int w[200005];
char p[5005];
bool f[5005][5005];
int fail[5005];
void solve(){
	int n,m;
	rep(i,0,n+m+1)w[i]=0;
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	scanf("%s",p);
	rep(i,0,n){
		w[i]=0;
		while(w[i]<m){
			if(i+w[i]<n&&w[i]<m&&s[i+w[i]]==p[w[i]])w[i]+=1;
			else if(i+w[i]+1<n&&w[i]+1<m&&s[i+w[i]]==p[w[i]+1]&&s[i+w[i]+1]==p[w[i]])w[i]+=2;
			else break;
		}
		printf("%d",w[i]==m);
	}
	printf("\n");
}

int main(){
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		solve();
	}
	return 0;
}