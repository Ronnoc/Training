//kybconnor
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

typedef long long LL;
typedef pair<int, int> PII;
LL w[222222];
LL c[222222];
int n,m,k;
LL sumW[222222];
LL sumC[222222];
void solve(){
	while(~scanf("%d%d%d",&n,&m,&k)){
		int i,j;
		for(i=1;i<=n;i++)scanf("%I64d%I64d",&w[i],&c[i]);
		for(i=1;i<=n;i++)w[i]=k*w[i];
		sumW[0]=0;
		sumC[0]=0;
		for(i=1;i<=n;i++)sumW[i]=sumW[i-1]+w[i];
		for(i=1;i<=n;i++)sumC[i]=sumC[i-1]+c[i];
		LL ans=0,Pans=0,Qans=n;
		for(i=n;i>=m+1;i--){
			LL wh=sumW[i]-sumW[i-m];
			LL wt=sumW[i-m];
			if(wh>k*wt)break;
			LL now=sumC[n]-sumC[i];
			int l=0,r=i-m-1;
			LL mx=sumW[i-m]-wh/k;
			int t;
			while(l<=r){
				if(r-l<=1){
					if(sumW[r]<=mx)t=r;
					else t=l;
					break;
				}
				int mid=(l+r)/2;
				if(sumW[mid]<=mx)l=mid;
				else r=mid;
			}
			now+=sumC[t];
			if(now>ans){
				ans=now;
				Pans=t;
				Qans=i;
			}
		}
		printf("%I64d %I64d\n",Pans+n-Qans,ans);
		for(i=Qans;i<n;i++)putchar('H');
		for(i=1;i<=Pans;i++)putchar('T');
		printf("\n");
	}
}
int main(){
//	while(1)
		solve();
	return 0;
}
