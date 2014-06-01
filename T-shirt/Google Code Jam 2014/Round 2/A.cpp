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
int w[100005];
int main(){
	int i,j;
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int CASE=1;CASE<=T;++CASE){
		int n,x;
		scanf("%d%d",&n,&x);
		for(i=1;i<=n;i++)scanf("%d",&w[i]);
		int cnt[777];
		memset(cnt,0,sizeof cnt);
		int l,r;
		for(i=1;i<=n;i++)cnt[w[i]]++;
		r=x;
		l=1;
		int ans=0;
		while(!cnt[r])r--;
		while(!cnt[l])l++;
		while(1){
			ans++;
			cnt[r]--;
			if(l+r<=x&&cnt[l]>0)cnt[l]--;
			while(!cnt[l]&&l<=x)l++;
			while(!cnt[r]&&r>=1)r--;
			if(r<0||l>x)break;
		}
		printf("Case #%d: %d\n",CASE,ans);
	}
	return 0;
}
