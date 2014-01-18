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

const double eps = 1e-8;
const int MOD = 1000000007;
#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(X) sort(X.OP,X.ED)
#define SQ(x) ((x)*(x))
typedef long long LL;
typedef pair<int, int> PII;
void solve(){
	int i,j;
	int n,m;
	while(cin>>n>>m){
		priority_queue<int>Q;
		for(i=1;i<=n;i++){
			cin>>j;
			Q.push(j);
		}
		j=0;
		while(m>0){
			j++;
			m-=Q.top();
			Q.pop();
		}
		cout<<j<<endl;
	}
}
int main(){
//	while(1)
		solve();
	return 0;
}
