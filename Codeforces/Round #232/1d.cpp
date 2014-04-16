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
const LL mod = 1000000007 ;
int BIT[1111111];
int MXN=1110000;
int LB(int x){return x&(-x);}
void add(int w,int x){
	for(w+=5;w<=MXN;w+=LB(w))BIT[w]+=x;
}
int getsum(int w){
	int ret=0;
	for(w+=5;w>0;w-=LB(w))ret+=BIT[w];
	return ret;
}
LL pre[1111111];
LL jian[1111111];
int a[1111111],n;
LL A[1111111];
LL F[1111111];
int main(){
	int i,j;
	A[0]=1;
	for(i=1;i<=1000000;i++)A[i]=1LL*A[i-1]*i%mod;
	F[1]=0;
	for(i=2;i<=1000000;i++)F[i]=(F[i-1]*i%mod+1LL*i*(i-1)/2%mod*A[i-1]%mod)%mod;
	while(~scanf("%d",&n)){
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		memset(BIT,0,sizeof BIT);
		pre[0]=0,jian[0]=0;
		for(i=1;i<=n;i++){
			LL gs=getsum(a[i]);
			pre[i]=pre[i-1]+i-1-gs;
			jian[i]=jian[i-1]+(a[i]-1-gs)-(i-1-gs);
			add(a[i],1);
		}
		memset(BIT,0,sizeof BIT);
		LL ans=0;
		for(i=1;i<=n;i++){
			int gs=getsum(a[i]);
			int can=a[i]-1-gs;
			LL k=can;
			LL dlt=F[n-i]*can%mod+1LL*k*(k-1)/2%mod*A[n-i]%mod;
			LL per=pre[i-1]+jian[i-1];
			dlt=(dlt+per*k%mod*A[n-i]%mod)%mod;
			ans=(ans+dlt)%mod;
			add(a[i],1);
		}
		cout<<(ans+pre[n])%mod<<endl;
	}
	return 0;
}
/*
5 1 2 4 5 3
4
*/
