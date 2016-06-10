#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;
map<vector<int>,int>F;
int f(vector<int>&L){//L[i]>0
	if(F.find(L)!=F.ED)
		return F[L];
	int ret=0;
	for(auto x:L)ret+=__builtin_popcount(x);
	int mx=*max_element(L.OP,L.ED);
	for(int x=2;x<=mx;x++){
		vector<int>R;
		int tmp=0;
		for(auto y:L){
			tmp+=y%x;
			if(y/x)	R.PB(y/x);
		}
		if(tmp+R.SZ<ret){
			tmp+=f(R);
			cmin(ret,tmp);
		}
	}
	return F[L]=ret;
}
int main(){
	int i,j,k,_T;
	int n;
	while(~scanf("%d",&n)){
		vector<int>L;
		for(i=0;i<n;++i){
			scanf("%d",&j);
			L.PB(j);
		}
		sort(L.OP,L.ED);
		int ans=f(L);
		printf("%d\n",ans);
	}
	return 0;
}
/*
7
500000
499999
499998
499997
499996
499995
499994
*/