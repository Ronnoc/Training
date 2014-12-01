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
int dp[3010][3010][2][2];
int n,a[3333],b[3333],c[3333];
int solve(){
	cin>>n;
	int i,j,l,p,q;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++)cin>>b[i];
	for(i=1;i<=n;i++)cin>>c[i];
	for(i=1;i<=n;i++)dp[i][i][0][0]=a[i];
	for(i=1;i<=n;i++)dp[i][i][1][0]=b[i];
	for(i=1;i<=n;i++)dp[i][i][0][1]=b[i];
	for(i=1;i<=n;i++)dp[i][i][1][1]=c[i];
	for(l=2;l<=n;l++)for(p=0;p<=1;p++)for(q=0;q<=1;q++)for(i=1;i+l-1<=n;i++){
		//i ~ i+l-1
		int le=i,ri=i+l-1;
		int &temp=dp[le][ri][p][q];
		temp=dp[le][ri-1][p][1]+dp[ri][ri][0][q];
		temp=max(temp,dp[le][ri-1][p][0]+dp[ri][ri][1][q]);
	}
	return dp[1][n][0][0];
}
int main(){
//	while(1)
		cout<<solve()<<endl;
	return 0;
}
