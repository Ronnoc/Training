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

string s[100005][2];
int p[100005];
int ok[100005][2];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	int n;
	ios::sync_with_stdio(false);
	while(cin>>n){
		for(i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
		for(i=1;i<=n;i++)cin>>p[i];
		memset(ok,0,sizeof ok);
		ok[1][0]=ok[1][1]=1;
		for(i=1;i<n;i++)for(j=0;j<2;j++)if(ok[i][j]){
			if(s[p[i+1]][0]>s[p[i]][j])ok[i+1][0]=1;
			if(s[p[i+1]][1]>s[p[i]][j])ok[i+1][1]=1;
		}
		if(ok[n][0]||ok[n][1])printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
