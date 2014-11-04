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
const LL MOD = 1000000000;

LL f[52][1<<15];
int c[52];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)scanf("%d",&c[i]);
		int ALL=(1<<m)-1;
		for(j=0;j<1<<m;j++)f[0][j]=j%c[0]?1:0;
		for(i=0;i<n;i++){
			for(j=0;j<1<<m;j++)if(f[i][j]>=MOD)f[i][j]%=MOD;
			for(j=0;j<m;j++){
				int host=ALL^(1<<j);
				int sub=host;
				do{
					f[i][sub^(1<<j)]+=f[i][sub];
					sub=(sub-1)&host;
				}while(sub!=host);
			}
			for(j=0;j<1<<m;j++)if(f[i][j]>=MOD)f[i][j]%=MOD;
			for(j=0;j<1<<m;j++)f[i+1][j]=f[i][ALL^j];
			if(i+1<n)for(j=0;j<1<<m;j+=c[i+1])f[i+1][j]=0;
		}
		cout<<f[n-1][ALL]%MOD<<endl;
	}
	return 0;
}
/*
4
1 15 2
2 15 2 3
3 15 2 3 5
4 15 2 3 5 7

16384
3187188
442930468
711993064
*/
