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
const double eps = 1e-8;
const int MOD = 1000000007;
#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(X) sort(X.OP,X.ED)
#define SQ(x) ((x)*(x))
typedef long long LL;
typedef pair<int, int> PII;

void solve(){
	int i,j;
	int n;
	while(cin>>n){
		double xd,yd,xm,ym;
		cin>>xm>>ym>>xd>>yd;
		int i;
		int flag=0;
		for(i=1;i<=n;i++){
			double x,y;
			cin>>x>>y;
			double dd=sqrt(SQ(x-xd)+SQ(y-yd));
			double dm=sqrt(SQ(x-xm)+SQ(y-ym));
			if(dd>dm*2-1e-8&&!flag)flag=1,printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",x,y);
		}
		if(!flag)cout<<"The gopher cannot escape.\n";
	}
}
int main(){
//	freopen("in.txt","r",stdin);
//	while(1)
		solve();
	return 0;
}
