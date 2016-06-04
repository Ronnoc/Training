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
LL inv[2000005];
LL A[2000005];
LL iA[2000005];
LL C(int n,int m){
	return A[n]*iA[m]%MOD*iA[n-m]%MOD;
}
int main(){
	int i,j,k,_T;
	for(inv[1]=1,i=2;i<=2000000;i++)
		inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;//MOD is prime
	A[0]=iA[0]=1;
	for(i=1;i<=2000000;i++){
		A[i]=A[i-1]*i%MOD;
		iA[i]=iA[i-1]*inv[i]%MOD;
	}
	int b,g,p;
	scanf("%d%d%d",&b,&g,&p);
	LL ans=0;
	if(b==0)
		ans=A[g];
	else if(g==0)
		ans=A[b];
	else {
		for(i=1;i<=p;i++){
			LL mul=A[p]*iA[p-i]%MOD;
			int ng,nb;
			//bggbbg...
			ng=(i+1)/2,nb=i/2+1;
			ans+=mul*C(g-i+ng-1,ng-1)%MOD*C(b-i+nb-1,nb-1)%MOD*A[b-i]%MOD*A[g-i]%MOD;
			//gbbggb
			nb=(i+1)/2,ng=i/2+1;
			ans+=mul*C(g-i+ng-1,ng-1)%MOD*C(b-i+nb-1,nb-1)%MOD*A[b-i]%MOD*A[g-i]%MOD;
		}
	}
	cout<<ans%MOD<<"\n";
	return 0;
}