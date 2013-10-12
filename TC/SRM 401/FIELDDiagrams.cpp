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
#include <fstream>
#include <cstdlib>
#include <cstring>
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

typedef long long LL;
typedef pair<int, int> PII;

LL dp[33][33];
LL dfs(LL n,LL pre){
	LL &tp=dp[n][pre];
	if(tp!=-1)return tp;
//	cout<<n<<" "<<pre<<endl;
//	system("pause");
	int i;
	LL ret=0;
	for(i=0;i<=min(n-1,pre);i++)ret+=dfs(n-1,i);
	return tp=ret;
}
class FIELDDiagrams {
public:
  long long countDiagrams (int O) {
		int i,j,k;
		memset(dp,-1,sizeof dp);
		dp[1][1]=1;
		dp[1][0]=1;
		LL ret=0;
		for(i=0;i<=O;i++)ret+=dfs(O,i);
    return ret-1;
  }
};



// Powered by FileEdit
// Powered by moj 4.12 [modified TZTester]
// Powered by CodeProcessor
