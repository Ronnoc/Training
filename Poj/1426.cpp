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
int mt[111];
int dp[111][222];
int pr[111][222];
int main(){
	int i,j;
	int n;
	while(~scanf("%d",&n)&&n){
		mt[0]=1;
		for(i=1;i<=100;i++)mt[i]=mt[i-1]*10%n;
		memset(dp,0,sizeof dp);
		memset(pr,0,sizeof pr);
		dp[0][0]=1;dp[0][mt[0]]=1;
		int flag=0;
		for(i=0;!flag&&i<100;i++)for(j=0;!flag&&j<n;j++)if(dp[i][j]){
			if((j+mt[i+1])%n==0&&!flag){
				flag=1;
				int x,y;
				x=i,y=j;
				printf("1");
				while(x){
					printf("%d",pr[x][y]);
					if(pr[x][y])y=(y+n-mt[x])%n;
					x--;
				}
				if(y)printf("1\n");
				else printf("0\n");
			}
			dp[i+1][j]=1;
			pr[i+1][j]=0;
			dp[i+1][(j+mt[i+1])%n]=1;
			pr[i+1][(j+mt[i+1])%n]=1;
		}
	}
	return 0;
}
