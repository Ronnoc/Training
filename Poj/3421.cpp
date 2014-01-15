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
LL comb[111][111];
void solve(){
	int i,j;
	comb[0][0]=1;
	for(i=1;i<=100;i++){
		comb[i][0]=1;
		for(j=1;j<=i;j++)comb[i][j]=comb[i-1][j]+comb[i-1][j-1];
	}
	int X;
	while(cin>>X){
		int i;
		map<int,int>S;
		map<int,int>::iterator iter;
		for(i=2;i*i<=X;i++){
			if(X%i)continue;
			while(X%i==0)X/=i,S[i]++;
		}
		if(X!=1)S[X]++;
		int tot=0;
		for(iter=S.OP;iter!=S.ED;++iter)tot+=(*iter).BB;
		cout<<tot<<" ";
		LL ans=1;
		for(iter=S.OP;iter!=S.ED;++iter){
			ans*=comb[tot][(*iter).BB];
			tot-=(*iter).BB;
		}
		cout<<ans<<endl;
	}
}
int main(){
//	while(1)
		solve();
	return 0;
}
