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
const double PI=acos( -1. );
LL n,m;
struct mat{
	LL A[2][2];
	mat(){memset(A,0,sizeof A);}
	LL* operator [](int a){return A[a];}
	mat friend operator * (mat p,mat q){
		int i,j,k;
		mat ret;
		for(i=0;i<2;i++)
			for(j=0;j<2;j++)
				for(k=0;k<2;k++)ret[i][k]+=p[i][j]*q[j][k];
		for(i=0;i<2;i++)for(j=0;j<2;j++)ret[i][j]%=m;
		return ret;
	}
	mat operator ^(LL a){
		mat ret,p=*this;
		ret[0][0]=ret[1][1]=1;
		while(a){
			if(a&1)ret=ret*p;
			p=p*p;
			a>>=1;
		}
		return ret;
	}
};
LL gao(LL n){
	n>>=1;
	mat P;
	P[0][0]=4;
	P[0][1]=2;
	P[1][1]=1;
	P=P^n;
	return P[0][1];
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	while(cin>>n>>m){
		LL ans=gao(n-n%2);
		if(n&1)ans=(ans*2+1)%m;
		cout<<ans<<endl;
	}
	return 0;
}
