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
double a[3005];
double b[3005];
double c[3005];
int main(){
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int n;
	double fl;
	while(~scanf("%d",&n)){
		scanf("%lf%lf",&b[0],&fl);
		for(i=1;i<=n;i++)scanf("%lf",&c[i]);
		a[1]=1;b[1]=0;
		a[0]=0;
		for(i=2;i<=n+1;i++){
			a[i]=2*a[i-1]-a[i-2];
			b[i]=2*b[i-1]-b[i-2]+2*c[i-1];
		}
		fl-=b[n+1];
		fl/=a[n+1];
//		for(i=0;i<=n+1;i++)cout<<a[i]<<"*x+"<<b[i]<<endl;
		printf("%.2f\n",fl);
	}
	return 0;
}
