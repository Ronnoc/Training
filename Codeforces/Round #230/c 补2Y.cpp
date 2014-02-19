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
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

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
typedef long long LL;
typedef pair<int, int> PII;
int nn=83;
LL mod = 1000000007;
struct matrix{
	LL x[88][88];
	matrix() {memset(x,0,sizeof x);}
};
matrix mul(matrix &a,matrix &b){
	matrix ret;
	int i,j,k;
	for(i=0;i<nn;i++)for(j=0;j<nn;j++)if(a.x[i][j])
		for(k=0;k<nn;k++)ret.x[i][k]=(ret.x[i][k]+a.x[i][j]*b.x[j][k]%mod)%mod;
	return ret;
}
matrix E;
matrix A;
int main(){
	int i,j;
	for(i=0;i<nn;i++)E.x[i][i]=1;
	A.x[0][0]=1;
	for(i=1;i<41;i++){
		A.x[i][0]=1;
		for(j=1;j<i;j++)A.x[i][j]=(A.x[i-1][j]+A.x[i-1][j-1])%mod;
		A.x[i][i]=1;
	}
	A.x[0][41]=1;
	for(i=1;i<41;i++){
		A.x[i][41]=1;
		for(j=41;j<i+41;j++)A.x[i][j]=(A.x[i-1][j]+A.x[i-1][j-1])%mod;
		A.x[i][41+i]=1;
	}
	A.x[41][0]=1;
	for(i=41;i<82;i++){
		A.x[i][0]=1;
		for(j=1;j<i-41;j++)A.x[i][j]=(A.x[i-1][j]+A.x[i-1][j-1])%mod;
		A.x[i][i-41]=1;
	}
	A.x[82][82]=1;
	LL n;
	int k;
	while(cin>>n>>k){
		matrix B,O;
		B=A;
		B.x[82][k]=1;
		O=E;
		n--;
		while(n){
			if(n&1)O=mul(O,B);
			B=mul(B,B);
			n/=2;
		}
		vector<LL>p,q;
		for(i=0;i<nn;i++)p.PB(O.x[82][i]);
		for(i=0;i<=40;i++)q.PB((1LL<<(i+1))%mod);
		for(i=0;i<=40;i++)q.PB((1LL<<(i))%mod);
		q.PB(1);
		LL ans=0;
		for(i=0;i<p.SZ;i++)ans=(ans+p[i]*q[i]%mod)%mod;
		cout<<ans<<endl;
	}
	return 0;
}
