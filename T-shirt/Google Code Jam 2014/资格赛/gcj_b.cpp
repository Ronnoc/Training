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
int main() {
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int i,j,k;
	int T;
	scanf("%d",&T);
	for(int CASE=1;CASE<=T;++CASE){
		double C,F,X;
		double per=2;
		double ans=1e20;
		double time=0;
		scanf("%lf%lf%lf",&C,&F,&X);
		printf("Case #%d: ",CASE);
//		cout<<endl;
		while(1){
			double now=time+X/per;
			if(now<ans){
				ans=now;
				time+=C/per;
				per+=F;
			}else break;
		}
		printf("%.7lf\n",ans);
	}
	return 0;
}
