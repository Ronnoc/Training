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
	string s;
	int T=0;
	while(cin>>s){
		vector<string>L;
		L.PB(s);
		while(cin>>s){
			if(s=="9")break;
			L.PB(s);
		}
		++T;
		SORT(L);
		int flag=1;
		for(i=1;i<L.SZ;i++){
			if(L[i].SZ<L[i-1].SZ)continue;
			int same=1;
			for(j=0;j<L[i-1].SZ;j++)if(L[i][j]!=L[i-1][j]){same=0;break;}
			if(same)flag=0;
		}
		if(flag)cout<<"Set "<<T<<" is immediately decodable\n";
		else cout<<"Set "<<T<<" is not immediately decodable\n";
	}
}
int main(){
//	while(1)
		solve();
	return 0;
}
