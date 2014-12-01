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

typedef long long LL;
typedef pair<int, int> PII;
//dp[i][j]表示最小i打k的种数
//dp[1][2]=1;
int dp[3003][3003];
int has100[3003];
int allzero[3003];
int a[3003];
int n,K;
void solve() {
  while (cin>>n>>K) {
    int i,j;
    for (i=1; i<=n; i++) cin>>a[i];
    int *p=a;
    if (n==1) {printf ("1\n"); continue;}
    allzero[n+1]=1;
    for (i=n; i>=1; i--)
      allzero[i]=allzero[i+1]&& (a[i]==0);
    has100[n+1]=0;
    for (i=n; i>=1; i--)
      has100[i]=has100[i+1]|| (a[i]==100);
    memset (dp,0,sizeof dp);
    dp[1][2]=K+1;
    int res=0;
    for (i=1; i<n; i++) {
      for (j=i+1; j<n; j++) {
      	int k=dp[i][j];
        if (!dp[i][j]) continue;
        if (allzero[j]) {		//i bi huo
					if(a[i]==0){dp[i][j]=max(dp[i][j],k-1);}
					else if(a[i]==100){dp[i][j+1]=max(dp[i][j+1],k-1);}
					else {dp[i][j]=max(dp[i][j],k-1);dp[i][j+1]=max(dp[i][j+1],k-1);}
          continue;
        }
        if (has100[j]) {		//i bi si
          if (a[i]==0) {
            dp[j][j+1]=max (dp[j][j+1],k-1);
          } else if (a[i]==100) {
            if (j+2<=n) dp[j+1][j+2]=max (dp[j+1][j+2],k-1);
            else dp[j+1][j+1]=max(dp[j+1][j+1],k-1);
          } else {
            dp[j][j+1]=max (dp[j][j+1],k-1);
            if (j+2<=n) dp[j+1][j+2]=max (dp[j+1][j+2],k-1);
            else dp[j+1][j+1]=max(dp[j+1][j+1],k-1);
          }
          continue;
        }
        if (a[i]==0) {			//j bi huo
//        	dp[i][j]=max(dp[][]);
          dp[j][j+1]=max(dp[j][j+1],k-1);
        } else if (a[i]==100) {//j bi si
          dp[i][j+1]=max(dp[i][j+1],k-1);
          if (j+2<=n) dp[j+1][j+2]=max (dp[j+1][j+2],k-1);
          else dp[j+1][j+1]=max(dp[j+1][j+1],k-1);
        } else {
//					dp[i][j]=1;
          dp[i][j+1]=max(dp[i][j+1],k-1);
          dp[j][j+1]=max (dp[j][j+1],k-1);
          if (j+2<=n) dp[j+1][j+2]=max (dp[j+1][j+2],k-1);
          else dp[j+1][j+1]=max(dp[j+1][j+1],k-1);
        }
      }
      if (dp[i][n]>1){
				if(p[n]==100){
					if(p[i]==100){res=1;}
					else if(p[i]==0){dp[n][n]=1;}
					else {
						dp[n][n]=1;
						res=1;
					}
				}else if(p[n]==0){
					if(p[i]==100){dp[i][i]=1;}
					else if(p[i]==0){dp[i][n]=1;}
					else {dp[i][i]=1;dp[i][n]=1;}
				}else {
					if(p[i]==100){dp[i][i]=1;res=1;}
					else if(p[i]==0){dp[i][n]=1;dp[n][n]=1;}
					else {
						dp[i][n]=1;
						dp[i][i]=1;
						dp[n][n]=1;
						res=1;
					}
				}
      }
    }
    for (i=1; i<=n; i++) for (j=i; j<=n; j++) if (dp[i][j]) res++;//,cout<<i<<" "<<j<<endl;
    printf ("%d\n",res);
  }
}
int main() {
//	while(1)
  solve();
  return 0;
}
