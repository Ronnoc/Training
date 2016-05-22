//kybconnor
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
#define UNIQUE(x) x.erase(unique(x.OP,x.ED),x.ED)
typedef long long LL;
typedef pair<int, int> PII;
LL r,g,b;
int dp[5][5][5];
int main() {
	dp[0][0][0]=0;
	dp[0][0][1]=0;
	dp[0][0][2]=1;
	dp[0][1][0]=0;
	dp[0][1][1]=1;
	dp[0][1][2]=3;
	dp[0][2][0]=1;
	dp[0][2][1]=3;
	dp[0][2][2]=6;
	dp[1][0][0]=0;
	dp[1][0][1]=1;
	dp[1][0][2]=3;
	dp[1][1][0]=1;
	dp[1][1][1]=3;
	dp[1][1][2]=6;
	dp[1][2][0]=3;
	dp[1][2][1]=6;
	dp[1][2][2]=10;
	dp[2][0][0]=1;
	dp[2][0][1]=3;
	dp[2][0][2]=6;
	dp[2][1][0]=3;
	dp[2][1][1]=6;
	dp[2][1][2]=10;
	dp[2][2][0]=6;
	dp[2][2][1]=10;
	dp[2][2][2]=15;
	while (~scanf ("%I64d%I64d%I64d",&r,&g,&b)) {
		if (r<=2&&g<=2&&b<=2) {printf ("%d\n",dp[r][g][b]); continue;}
		if (r>=2&&g>=2&&b>=2) {
			LL tp=r-2+g-2+b-2;
			printf ("%I64d\n",tp*6LL+15LL);
			continue;
		}//r>=g>=b
		if (r<g) swap (r,g);
		if (r<b) swap (r,b);
		if (g<b) swap (b,g);
		if (b==0) {
			if (g==0) {
				LL res=0;
				if (r) r--,res+=0;
				if (r) r--,res+=1;
				res+=r*2;
				printf ("%I64d\n",res);
				continue;
			} else if (g==1) {
				LL res=0;
				if (r) r--,res+=1;
				if (r) r--,res+=2;
				res+=r*3;
				printf ("%I64d\n",res);
				continue;
			} else {
				LL res=dp[0][2][2];
				LL tp=r-2+g-2;
				printf ("%I64d\n",res+tp*4LL);
				continue;
			}
		} else if (b==1) {
			if (g==1) {
				LL res=1;
				if (r) r--,res+=2;
				if (r) r--,res+=3;
				res+=4LL*r;
				printf ("%I64d\n",res);
				continue;
			} else {
				LL res=dp[1][2][2];
				LL tp=g-2+r-2;
				printf ("%I64d\n",res+tp*5LL);
				continue;
			}
		}
	}
	return 0;
}
