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
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int i,j;
	int x[9][9];
	int T;
	scanf("%d",&T);
	for(int CASE=1;CASE<=T;++CASE){
		set<int>L,R;
		L.clear(),R.clear();
		int a;
		scanf("%d",&a);
		for(i=1;i<=4;i++)for(j=1;j<=4;j++)scanf("%d",&x[i][j]);
		for(i=1;i<=4;i++)L.insert(x[a][i]);
		scanf("%d",&a);
		for(i=1;i<=4;i++)for(j=1;j<=4;j++)scanf("%d",&x[i][j]);
		for(i=1;i<=4;i++)if(L.count(x[a][i]))R.insert(x[a][i]);
		printf("Case #%d: ",CASE);
		if(R.SZ>1)printf("Bad magician!\n");
		else if(R.SZ==1)printf("%d\n",*R.OP);
		else printf("Volunteer cheated!\n");
	}
	return 0;
}
