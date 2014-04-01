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

bool ocur[2222];
int dp[2222];
int main(){
	memset(dp,-1,sizeof dp);
	dp[0]=0;dp[1]=1;dp[2]=1;
	int i,j;
	for(i=3;i<=2000;i++){
		memset(ocur,0,sizeof ocur);
		for(j=1;j+j<=i+1;j++){
			if(j==1)ocur[dp[i-3]]=1;
			if(j==2&&i>=4)ocur[dp[i-4]]=1;
			if(j>=3)ocur[(dp[j-3] xor dp[i-j-2])]=1;
		}
		for(j=0;;j++)if(!ocur[j]){dp[i]=j;break;}
	}
	int n;
	while(~scanf("%d",&n))if(dp[n])printf("1\n");else printf("2\n");
	return 0;
}
