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
int ishp[1000011];
vector<LL>hp;
int issp[1000011];
int sum[1000011];
void solve(){
	LL i,j;
	for(i=5;i<=1000000;i+=4)ishp[i]=1;
	for(i=5;i<=1000000;i+=4)if(ishp[i]){
		for(j=i*i;j<=1000000;j+=i)if(j%4==1)ishp[j]=0;
	}
	for(i=5;i<=1000000;i+=4)if(ishp[i])hp.PB(i);
	for(i=0;i<hp.SZ;i++)for(j=i;j<hp.SZ;j++){
//		cout<<hp[i]<<" "<<hp[j]<<endl;
//		system("pause");
		if(hp[i]*hp[j]>1000000)break;
		issp[ hp[i]*hp[j] ]=1;
	}
	sum[0]=0;
	for(i=1;i<=1000000;i++)sum[i]=sum[i-1]+issp[i];
	while(cin>>i&&i)cout<<i<<" "<<sum[i]<<endl;
}
int main(){
//	while(1)
		solve();
	return 0;
}
