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
void solve(){
	int n;
	cin>>n;
	string tp,S="";
	int i;
	for(i=1;i<=n;i++){
		S+="<3";
		cin>>tp;
		S+=tp;
	}S+="<3";
	string Q;
	cin>>Q;
	int id=0;
	for(i=0;i<Q.size();i++){
		if(id<S.size()&&Q[i]==S[id])id++;
	}
	if(id==S.size())cout<<"yes\n";
	else cout<<"no\n";
}
int main(){
//	while(1)
		solve();
	return 0;
}
