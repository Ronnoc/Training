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
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>

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
const double eps=1e-8;
const double PI=acos( -1. );
const LL MOD = 1000000007;

int f[2222];
int tot[2222];
int pre[2222];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	int N,K;
	while(cin>>N>>K){
		for(i=0;i<N;i++)scanf("%d",&f[i]);
		for(i=0;i<=2001;i++)tot[i]=0;
		for(i=0;i<N;i++)tot[f[i]]++;
		for(i=2000;i>=1;i--)pre[i]=pre[i+1]+tot[i];
		LL ans=0;
		for(i=2;i<=2000;i++){
			LL gao=pre[i];
			ans+=gao/K;
			if(gao%K)ans++;
		}
		cout<<ans*2<<endl;
	}
	return 0;
}

