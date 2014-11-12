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

typedef long long LL;
typedef pair<int, int> PII;

LL dp[111111][22];
LL n,l,r,Ql,Qr;
LL w[111111];
int main(){
	while(cin>>n>>l>>r>>Ql>>Qr){
		int i,j;
		for(i=1;i<=n;i++)cin>>w[i];
		dp[0][1]=0;dp[n+1][2]=0;
		for(i=1;i<=n;i++)dp[i][1]=dp[i-1][1]+l*w[i];
		for(j=n;j>=1;j--)dp[j][2]=dp[j+1][2]+r*w[j];
		LL ans=min(dp[n][1]+Ql*(n-1),dp[1][2]+Qr*(n-1));
		for(i=1;i<n;i++){
			LL tot=dp[i][1]+dp[i+1][2];
			int left=i-1,right=n-i-1;
			LL leftFirst,rightFirst;
			if(left<n-i){
				int xx=n-i-(i-1);
				leftFirst=Qr*(xx-1);
			}
			else 
				leftFirst=Ql*(left-(n-i));
			if(right<i){
				int xx=i-(right);
				rightFirst=Ql*(xx-1);
			}
			else 
				rightFirst=Qr*(right-i);
			ans=min(ans,tot+min(leftFirst,rightFirst));
		}
		cout<<ans<<endl;
	}
	return 0;
}
