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
int solve(){
	int n;
	cin>>n;
	int i,j;
	for(i=1;i<=n;i++)cin>>a[i];
	vector<PII>L;
	for(i=2;i<=n;i++)L.PB(MP(min(a[i-1],a[i]),max(a[i-1],a[i])));
	for(i=0;i<L.size();i++){
		for(j=i+1;j<L.size();j++){
//			if(L[i].AA<L[j].BB&&L[i].AA>L[j].AA&&L[i].BB>L[j].BB)
//				cout<<L[i].AA<<" "<<L[i].BB<<" "<<L[j].AA<<" "<<L[j].BB<<endl;
			if(L[i].AA<L[j].BB&&L[i].AA>L[j].AA&&L[i].BB>L[j].BB)return 1;
//			if(L[j].AA<L[i].BB&&L[j].AA>L[i].AA)cout<<L[i].AA<<" "<<L[i].BB<<" "<<L[j].AA<<" "<<L[j].BB<<endl;
			if(L[j].AA<L[i].BB&&L[j].AA>L[i].AA&&L[j].BB>L[i].BB)return 1;
		}
	}
	return 0;
}
int main(){
//	while(1)
		if(solve())cout<<"yes\n";
		else cout<<"no\n";
	return 0;
}
