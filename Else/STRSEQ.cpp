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
#define NAME ""
typedef long long LL;
typedef pair<int, int> PII;
const double eps=1e-8;
const double PI=acos(-1.);
const LL MOD = 1000000007;

char s[100005];
int len;
int next[100005][10];
int dp[100005];
int re[100005];
int main() {
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
	int i,j,k,_T;
	while(~scanf("%s",s)) {
		len=strlen(s);
		for(i=len;i>0;i--)
			s[i]=s[i-1];
		for(j=0;j<10;j++)next[len+1][j]=len+1;
		for(i=len;i>=1;i--){
			for(j=0;j<10;j++)next[i][j]=next[i+1][j];
			next[i][s[i]-'0']=i;
		}
		for(i=j=0;j<10;j++)next[i][j]=next[i+1][j];
		for(i=len;i>=0;i--){
			dp[i]=MOD,re[i]=-1;
			for(j=0;j<10;j++){
				int id=next[i+1][j];
				if(id<=len){
					if(dp[id]<dp[i])
						dp[i]=dp[id],re[i]=j;
				}else {
					dp[i]=-1;
					re[i]=j;
					break;
				}
			}
			dp[i]++;
		}
		if(next[0][0]>len)printf("0\n");
		else {
			int Min=MOD,Re=-1;
			for(j=1;j<10;j++){
				int id=next[1][j];
				if(id<=len){
					if(dp[id]<Min)
						Min=dp[id],Re=j;
				}else {
					Min=-1,Re=j;
					break;
				}
			}
			int now=0;
			while(now<=len){
				printf("%d",Re);
				now=next[now+1][Re];
				Re=re[now];
			}
			printf("\n");
		}
	}
	return 0;
}
