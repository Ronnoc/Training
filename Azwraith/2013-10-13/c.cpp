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

vector<int>ans[111];
int main(){
	int n;
	while(~scanf("%d",&n)){
		int x=0,tot=0,i,j;
		while(tot+x+1<=n)tot+=++x;
		printf("%d\n",x+1);
		int s=0;
		for(i=1;i<=x+1;i++)ans[i].clear();
		for(i=1;i<=x+1;i++){
			for(j=1;j<=x+1-i;j++)ans[i].PB(s+j);
			for(j=1;j<=x+1-i;j++)ans[i+j].PB(s+j);
			s+=x+1-i;
		}
		for(i=1;i<=x+1;i++){
			printf("%d",(int)ans[i].size());
			for(j=0;j<ans[i].size();j++)printf(" %d",ans[i][j]);
			printf("\n");
		}
	}
	return 0;
}
