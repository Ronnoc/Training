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
#include <cassert>
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
const double PI=acos(-1.);
const LL MOD = 1000000007;

LL modPow(LL a,LL b,LL mod){
	LL ret=1;
	while(b){
		if(b&1)ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
LL modInv(LL t,LL mod){return modPow(t,mod-2,mod);}
#define MXN 300
int idx[MXN];
LL a[MXN][MXN],b[MXN];
int gaussTpivotMod(int m,int n,int mod=2) {
	int i,j,k,row,col;
	LL maxp,t;
	int ret=1;
	for(i=0; i<m; i++)idx[i]=i;
	for(k=0; k<n; k++) {
		for(maxp=0,i=k; i<m; i++)
			for(j=k; j<n; j++)
				if(a[i][j]>maxp)
					maxp=a[row=i][col=j];
		if(maxp==0) {
			bool fail=0;
			for(i=k;i<m;i++)if(b[i])fail=1;
			if(fail)return 0;
			ret=k-n;
			break;
		}
		if(col!=k)for(swap(idx[col],idx[k]),i=0; i<m; i++)
				swap(a[i][col],a[i][k]);
		if(row!=k)for(swap(b[k],b[row]),j=k; j<n; j++)
				swap(a[k][j],a[row][j]);
		LL inv=modInv(maxp,mod);
		for(i=k+1; i<m; i++) {
			LL mul=inv*a[i][k];
			for(j=k; j<n; j++)
				a[i][j]-=a[k][j]*mul;
			b[i]-=mul*b[k];
		}
		for(i=k; i<m; i++)
			for(j=k; j<n; j++) {
				LL &tmp=a[i][j];
				if(tmp>=mod)tmp%=mod;
				if(tmp<0)tmp=tmp%mod+mod;
			}
	}
	for(i=n-1;i>=0;i--)
		for(j=i+1;j<n;j++)
			b[i]-=a[i][j]*b[j];
	for(k=0;k<n;k++)
		a[0][idx[k]]=b[k];
	for(k=0;k<n;k++)
		b[k]=(a[0][k]%mod+mod)%mod;
	return ret;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	int n;
	while(~scanf("%d",&n)){
		for(i=0;i<n;i++)for(j=0;j<n;j++)a[i][j]=0;
		for(i=0;i<n;i++)b[i]=1;
		for(i=0;i<n;i++){
			while(1){
				scanf("%d",&k);
				if(~k)a[k-1][i]=1;
				else break;
			}
		}
		int flag=gaussTpivotMod(n,n);
		if(flag){
			bool first=1;
			for(i=0;i<n;i++)if(b[i]){
				if(first)first=0;
				else printf(" ");
				printf("%d",i+1);
			}
			printf("\n");
		}else printf("No solution\n");
	}
	return 0;
}
