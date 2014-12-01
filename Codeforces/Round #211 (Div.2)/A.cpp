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
#define UNIQUE(x) x.erase(unique(x.OP,X.ED),x.ED)
typedef long long LL;
typedef pair<int, int> PII;
string s[11];
void solve(){
	int n;
	s[0]="O-|-OOOO";
	s[1]="O-|O-OOO";
	s[2]="O-|OO-OO";
	s[3]="O-|OOO-O";
	s[4]="O-|OOOO-";
	s[5]="-O|-OOOO";
	s[6]="-O|O-OOO";
	s[7]="-O|OO-OO";
	s[8]="-O|OOO-O";
	s[9]="-O|OOOO-";
	while(~scanf("%d",&n)){
		if(n==0){
			cout<<s[0]<<endl;
			continue;
		}
		vector<string >L;
		while(n){
			L.PB(s[n%10]);
			n/=10;
		}
		for(int i=0;i<L.size();i++)cout<<L[i]<<endl;
	}
	
}
int main(){
//	while(1)
		solve();
	return 0;
}
