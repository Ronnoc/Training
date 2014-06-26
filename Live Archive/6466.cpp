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
int main(){
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j;
	int T,CA;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&CA);
		double D,A,B,F;
		scanf("%lf%lf%lf%lf",&D,&A,&B,&F);
		double d=0,add=INF;
		while(add>1e-4){
			double t=D/(B+F);
			D-=(A+B)*t;
			add=t*F;
			swap(A,B);
			d+=add;
		}
		printf("%d %.2lf\n",CA,d);
	}
	return 0;
}
