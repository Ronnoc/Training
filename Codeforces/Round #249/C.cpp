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
int w[1010];
char s[1010][1010];
int main(){
	int i,j;
	int n;
	while(~scanf("%d",&n)){
		for(i=1;i<=n;i++)scanf("%d",&w[i]);
		int now=0,sml=0,big=0;
		int all=0;
		for(i=1;i<=n;i++){
			if(i&1)now+=w[i];
			else now-=w[i];
			cmax(big,now);
			cmin(sml,now);
			all+=w[i];
		}
		int d=big-sml;
		int st=-sml;
		memset(s,0,sizeof s);
		for(i=0;i<d;i++)for(j=0;j<all;j++)s[i][j]=' ';
		int x=d-1-st;
		int y=0;
//		cout<<x<<" "<<y<<endl;
		for(i=1;i<=n;i++){
			if(i&1){
				while(w[i]--){
					s[x][y]='/';
					x--;y++;
				}
				x++;
			}else {
				while(w[i]--){
					s[x][y]='\\';
					x++;y++;
				}
				x--;
			}
		}
		for(i=0;i<d;i++)printf("%s\n",s[i]);
	}
	return 0;
}
