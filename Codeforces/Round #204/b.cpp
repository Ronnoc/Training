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

double e[9000000];
int p[3333];
int main(){
	int n;
	while(~scanf("%d",&n)){
		int i,j;
		for(i=1;i<=n;i++)scanf("%d",&p[i]);
		int tot=0;
		for(i=1;i<=n;i++)for(j=i+1;j<=n;j++)if(p[i]>p[j])tot++;
		cout<<tot<<endl;
//		e[0]=0;e[1]=1;
//		for(i=2;i<=(n)*(n-1)/2;i++)e[i]=e[i-2]+4;
//		printf("%.6lf\n",e[tot]);
	}
	return 0;
}
