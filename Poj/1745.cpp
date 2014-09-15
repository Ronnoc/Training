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
int a[10005],n,m;
int ok[2][105];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	while(~scanf("%d%d",&n,&m)){
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		memset(ok,0,sizeof ok);
		ok[0][0]=1;
		int x=0,y=1;
		for(i=1;i<=n;i++){
			for(j=0;j<m;j++)ok[y][j]=0;
			for(j=0;j<m;j++)if(ok[x][j]){
				int p=((j+a[i])%m+m)%m;
				int q=((j-a[i])%m+m)%m;
				ok[y][p]=ok[y][q]=1;
			}
			swap(x,y);
		}
		if(ok[x][0])puts("Divisible");
		else puts("Not divisible");
	}
	return 0;
}
