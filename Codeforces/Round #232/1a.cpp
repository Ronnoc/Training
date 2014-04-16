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
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;

const int mod = 1000000007 ;
LL comb[15111][511];
LL play(int tot,int n){
	LL ret=comb[tot+n-1][n-1];
	return ret;
}
int main(){
	int i,j;
	map<int,int>S;
	comb[0][0]=1;
	for(i=1;i<=15100;i++){
		comb[i][0]=1;
		for(j=1;j<i&&j<=500;j++)comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%mod;
		if(i<=500)comb[i][i]=1;
	}
	int n;
	while(~scanf("%d",&n)){
		S.clear();
		for(i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			for(j=2;j*j<=x;j++)if(x%j==0){
				while(x%j==0)S[j]++,x/=j;
			}
			if(x>1)S[x]++;
		}
		map<int,int>::iterator it;
		LL ret=1;
		for(it=S.OP;it!=S.ED;++it)
			ret=ret*play((*it).BB,n)%mod;
		cout<<ret<<endl;
	}
	return 0;
}
