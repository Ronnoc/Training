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
	int A,B,C,D;
	while(~scanf("%d%d%d%d",&A,&B,&C,&D)&&(A||B||C||D)){
		if(A<=C&&B<=D){printf("100%%\n");continue;}
		if(A<=D&&B<=C){printf("100%%\n");continue;}
		if(A>B)swap(A,B);
		if(C>D)swap(C,D);
		double ans=0;
		if(A>C&&B*C<=A*D)cmax(ans,1.*C/A);
		if(A>D&&B*D<=A*C)cmax(ans,1.*D/A);
		swap(A,B);
		if(A>C&&B*C<=A*D)cmax(ans,1.*C/A);
		if(A>D&&B*D<=A*C)cmax(ans,1.*D/A);
		printf("%d%%\n",(int)(ans*100+eps));
	}
	return 0;
}
