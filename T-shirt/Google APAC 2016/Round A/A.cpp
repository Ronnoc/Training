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

char s[105];
void solve(){
	int n;
	scanf("%d%*c",&n);
	vector<string>L;
	VI R;
	while(n--){
		gets(s);
		string ss=s;
		L.PB(ss);
		set<char>S;
		for(char c:ss)if(isalpha(c)){
			S.insert(c);
		}
		R.PB(S.SZ);
	}
	string ANS=L[0];
	int w=R[0];
	rep(i,1,sz(L)){
		if(R[i]>w){
			ANS=L[i],w=R[i];
		}else if(R[i]==w&&L[i]<ANS)
			ANS=L[i],w=R[i];
	}
	cout<<ANS<<"\n";
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