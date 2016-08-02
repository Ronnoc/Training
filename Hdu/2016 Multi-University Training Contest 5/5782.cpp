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

const int MXN = 10005;
char s[2][MXN];
bitset<MXN>ocur[2][128];
int last[2][128];
bitset<MXN>d[2];
void solve(){
	while(~scanf("%s%s",s[0],s[1])){
		rep(i,0,2)rep(j,0,128)ocur[i][j].reset();
		int len=strlen(s[0]);
		rep(i,0,2)d[i].reset();
		rep(i,0,2)rep(j,0,128)last[i][j]=-1;
		rep(l,0,len){
			//d[0][k]  s0[k,l]=s1[0,l-k] of [0,l]
			//d'[0][k] s0[k,l-1]=s1[0,l-k-1] of [0,l-1]
			//d[0][k]=d'[0][k] && s0[l]==s1[l-k] := ocur[1][s0[l]][k]
			//d[0]&=ocur[1][s[0][l]]
			//ocur[1][c][i] = I(s1[l-i]==c) of [0,l]
			
			//d[1][k]  s1[l-k+1,l]=s0[0,k-1] of [1,l+1]
			//d'[1][k-1] s1[l-k+1,l-1]=s0[0,k-2] 
			//d[1][k] =d'[1][k-1] && s1[l]==s0[k-1]
			rep(j,0,2){
				int mv=l-last[1][s[j][l]];
				if(mv){
					last[1][s[j][l]]=l;
					ocur[1][s[j][l]]<<=mv;
				}
			}
			ocur[1][s[1][l]].set(0);
			ocur[0][s[0][l]].set(l+1);
			d[0].set(l);
			d[0]&=ocur[1][s[0][l]];
			d[1]<<=1;
			d[1].set(1);
			d[1]&=ocur[0][s[1][l]];
			//rep(i,0,l+1)cout<<d[0][i];cout<<"\n";
			//rep(i,0,l+2)cout<<d[1][i];cout<<"\n";
			int ans=(d[0]&d[1]).any()||d[0][0];
			printf("%d",ans);
		}
		printf("\n");
	}
}
int main(){
	int _T=1;
	//scanf("%d",&_T);
	rep(CA,0,_T){
		solve();
	}
	return 0;
}