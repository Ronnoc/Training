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

int play(int w){
	if(w<7)return 1;
	return play(w/7)+1;
}
int a[9];
int main(){
	int i,j,k,_T;
	int n,m;
	while(cin>>n>>m){
		int le=play(n-1),re=play(m-1);
		if(le+re>7){
			cout<<0<<"\n";
			continue;
		}
		int ans=0;
		rep(i,0,7)a[i]=i;
		do{
			int u=0,v=0;
			rep(i,0,le)u=u*7+a[i];
			rep(i,0,re)v=v*7+a[le+i];
			if(u<n&&v<m)
				ans++;
		}while(next_permutation(a,a+7));
		rep(i,1,8-le-re)ans/=i;
		cout<<ans<<"\n";
	}
	return 0;
}