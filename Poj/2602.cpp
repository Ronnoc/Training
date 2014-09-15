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
char L[1000005];
int nl;
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	int n;
	while(~scanf("%d",&n)){
		nl=0;
		char s1[3],s2[3];
		for(i=0;i<n;i++){
			scanf("%s%s",s1,s2);
			L[nl++]=s1[0]-'0'+s2[0]-'0';
		}
		for(i=nl-1;i>=1;i--)
			if(L[i]>=10)L[i]-=10,L[i-1]++;
		if(L[0]>=10){
			L[0]-=10;
			putchar('1');
		}
		for(i=0;i<nl;i++)putchar(L[i]+'0');
		putchar('\n');
	}
	return 0;
}
