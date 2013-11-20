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
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define UNIQUE(x) x.erase(unique(x.OP,x.ED),x.ED)
typedef long long LL;
typedef pair<int, int> PII;
int dp[20][10];
int  duipai(int n,int m){
	int i;
	int tot=0;
	for(i=n;i<=m;i++){
		char s[11];
		sprintf(s,"%d",i);
		int j;
		int bug=0;
		for(j=0;s[j+1];j++)if(s[j]=='6'&&s[j+1]=='2')bug=1;
		for(j=0;s[j];j++)if(s[j]=='4')bug=1;
		if(!bug)tot++;
	}
//	cout<<n<<"~"<<tot<<endl;
	return tot;
}
int play (int x) {
	int s[11];
	int i,xx=x;
	for(i=1;i<=10;i++){
		s[i]=xx%10;
		xx/=10;
		if(!xx)break;
	}
	int z=i,j;
	int ret=0;
	for(i=z;i>1;i--){
		for(j=0;j<s[i];j++){
			if(j==2&&i+1<=z&&s[i+1]==6)continue;
			if(j==4)continue;
			if(j==6)ret+=dp[i-1][1];
			else ret+=dp[i-1][1]+dp[i-1][2];
		}
		if(i+1<=z&&s[i+1]==6&&s[i]==2)break;
		if(s[i]==4)break;
	}
	for(i=0;i<=s[1];i++){
		ret+=duipai(x-s[1]+i,x-s[1]+i);
	}
	return ret-1;
}
void solve() {
	int n,m;
	int i,j;
	memset(dp,0,sizeof dp);
	dp[1][1]=8;
	dp[1][2]=1;
	for (i=1; i<=10; i++) {
		dp[i+1][1]=8*dp[i][1]+7*dp[i][2];
		dp[i+1][2]=1*dp[i][1]+1*dp[i][2];
	}
//	while(~scanf("%d",&n))cout<<play(n)<<endl;
	while (scanf ("%d%d",&n,&m) !=EOF) {
		if (!n&&!m) break;
		cout<<duipai(n,m)<<endl;
//		cout<<play(m)<<"-"<<play(n-1)<<endl;
		printf ("%d\n",play (m)-play (n-1));
	}
}
int main() {
//	while(1)
	solve();
	return 0;
}
