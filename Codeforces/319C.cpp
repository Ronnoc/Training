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
const LL MOD = 1000000007;
int q[100005],op,ed;
int a[100005];
int b[100005];
LL D[100005];
int slope(LL x,LL y,LL p,LL q){
	if(1.0*p*y<1.0*q*x)return -1;
	return 1.0*p*y>1.0*q*x;
}
int main(){
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int n;
	while(~scanf("%d",&n)){
		for(i=1;i<=n;++i)scanf("%d",&a[i]);
		for(i=1;i<=n;++i)scanf("%d",&b[i]);
		op=ed=0;
		D[1]=0;
		q[ed++]=1;
		for(i=2;i<=n;i++){
			while(ed-op>=2){
				int l=q[op],r=q[op+1];
				if(slope(b[r]-b[l],D[r]-D[l],-1,a[i])>0)op++;
				else break;
			}
			D[i]=D[q[op]]+1LL*a[i]*b[q[op]];
			while(ed-op>=2){
				int l=q[ed-2],r=q[ed-1];
				if(slope(b[r]-b[l],D[r]-D[l],b[i]-b[r],D[i]-D[r])<=0)ed--;
				else break;
			}
			q[ed++]=i;
		}
		cout<<D[n]<<endl;
	}
	return 0;
}
