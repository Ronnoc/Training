#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<iostream>
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
int n,m;
int dp[333][333];
int ind[333][333];
int W[333],D[333];
map<int,int>De;
int solve(int,int);
bool all(int le,int re){
	int tp=solve(le,re);
	return tp==re-le+1;
}
int solve(int le,int re){//re>=le;
	int &tp=dp[le][re];
	if(~tp)return tp;
	if(le==re)return tp=0;
	if(re<le)return tp=re-le+1;
	tp=max(solve(le,re-1),solve(le+1,re));
	for(int i=le;i<re;i++)
		cmax(tp,solve(le,i)+solve(i+1,re));
	if(~ind[le][re]&&all(le+1,re-1))
		cmax(tp,re-le+1);
	for(int i=le+1;i<re;i++)if(~ind[le][i]&&all(le+1,i-1)){
		if(ind[le][i]==ind[i][re]&&all(i+1,re-1))
			cmax(tp,re-le+1);
		cmax(tp,i-le+1+solve(i+1,re));
	}
	//cout<<le<<" "<<re<<" "<<tp<<"\n";
	return tp;
}
int main(){
	int i,j,k,_T;
	scanf("%d",&_T);
	for(int CA=1;CA<=_T;CA++){
		memset(dp,-1,sizeof dp);
		memset(ind,-1,sizeof ind);
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
			scanf("%d",&W[i]);
		for(i=1;i<=m;i++)
			scanf("%d",&D[i]);
		De.clear();
		for(i=1;i<=m;i++)
			De[D[i]]=i;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++){
				if(De.find(W[j]-W[i])==De.ED)continue;
				ind[i][j]=De[W[j]-W[i]];
			}
		printf("%d\n",solve(1,n));
	}
	return 0;
}