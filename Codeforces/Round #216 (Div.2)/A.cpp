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
int a[1111];
void solve(){
	int n,m,k;
	while(cin>>n>>m>>k){
		int i;
		for(i=1;i<=n;i++)cin>>a[i];
		int ans=0;
		for(i=1;i<=n;i++){
			if(a[i]==1){
				if(m==0)ans++;
				else m--;
			}else {
				if(m==0&&k==0)ans++;
				else if(m==0)k--;
				else if(k==0)m--;
				else {
					if(k>0)k--;
					else m--;
				}
			}
		}
		cout<<ans<<endl;
	}
}
int main(){
//	while(1)
		solve();
	return 0;
}
