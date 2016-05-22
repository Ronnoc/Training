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
const double INF=1e20;
const double PI=acos( -1. );
const int MXN = 50;
const LL MOD = 1000000007;
LL D[111];
int main(){
	int i,j;
	int n;
	int T;
	D[1]=0;D[2]=1;
	for(i=3;i<=100;i++)D[i]=(i-1)*(D[i-1]+D[i-2])%MOD;
	scanf("%d",&T);
	for(int CASE=1;CASE<=T;++CASE){
		int n;
		int a[111];
		scanf("%d",&n);
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		LL ans=1;
		for(i=1;i<=n;i++)ans=ans*a[i]%MOD;
		ans=ans*D[n]%MOD;
		printf("Case %d: ",CASE);
		printf("%d\n",(int)(ans%MOD));
	}
	return 0;
}
