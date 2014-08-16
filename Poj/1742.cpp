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
int n,w;
bool dp[100005];
int A[105],C[105];
int dq[100005],op,ed;
int main(){
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	while(~scanf("%d%d",&n,&w)){
		if(!n&&!w)break;
		for(i=1;i<=n;i++)scanf("%d",&A[i]);
		for(i=1;i<=n;i++)scanf("%d",&C[i]);
		for(dp[0]=1,j=1;j<=w;j++)dp[j]=0;
		for(i=1;i<=n;i++){
			int dis=A[i]*C[i];
			for(j=0;j<A[i];j++){
				op=ed=0;
				for(k=j;k<=w;k+=A[i]){
					if(dp[k])dq[ed++]=k;
					if(!dp[k])while(ed>op){
						if(k-dq[op]>dis)op++;
						else {
							dp[k]=1;
							break;
						}
					}
				}
			}
		}
		int cnt=0;
		for(j=1;j<=w;j++)cnt+=dp[j];
		printf("%d\n",cnt);
	}
	return 0;
}
