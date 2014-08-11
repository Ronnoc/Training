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
#define SORT(X) sort(X.OP,X.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps = 1e-8;
const LL MOD = 1000000007;
double E[1005][1005];
int main() {
	int i,j;
	int n,s;
	while(~scanf("%d%d",&n,&s)){
		E[n][s]=0;
		for(i=n;i>=1;i--)for(j=s;j>=1;j--){
			if(i==n&&j==s)continue;
			double p=n*s-i*j;
			p=n*s/p;
			E[i][j]=1;
			if(i<n)E[i][j]+=E[i+1][j]*(n-i)*j/(n*s);
			if(j<s)E[i][j]+=E[i][j+1]*(s-j)*i/(n*s);
			if(i<n&&j<s)E[i][j]+=E[i+1][j+1]*(n-i)*(s-j)/(n*s);
			E[i][j]*=p;
		}
		printf("%.4f\n",E[1][1]+1);
	}
	return 0;
}
