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
int isp[10000007];
int p[2000007];
bool flag[10000007];
typedef long long LL;
const LL MOD = 1000000007;
int play(int n,int p) {
	if(n<p)return 0;
	return n/p+play(n/p,p);
}
int main() {
	int n;
	int i,j;
	int pn=0;
	for(i=2; i<=5000000; i++) {
		if(!flag[i])p[pn++]=i;
		for(j=0; j<pn&&i*p[j]<=5000000; j++)
			flag[i*p[j]]=1;
	}
	while(~scanf("%d",&n)&&n) {
		LL ans=1;
		for(i=0; i<pn&&2LL*p[i]<=1LL*n; i++) {
			int cnt=play(n,p[i]);
			LL x=p[i];
			cnt-=cnt%2;
			while(cnt) {
				if(cnt&1)ans=ans*x%MOD;
				x=x*x%MOD;
				cnt/=2;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
