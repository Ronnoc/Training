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

int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	LL x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%I64d%I64d",&x,&y);
		y-=x;
		LL t=sqrt(y);
		while(1LL*t*t>y)t--;
		while(1LL*(t+1)*(t+1)<=y)t++;
//		cout<<y<<" "<<t<<endl;
		if(y==0)printf("0\n");
		else if(y==t*t)printf("%I64d\n",2*t-1);
		else {
			LL cnt=2*t-1;
			y-=t*t;
			while(y>=t)y-=t,cnt++;
			if(y)cnt++;
			printf("%I64d\n",cnt);
		}
	}
	return 0;
}
