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
#define UNIQUE(x) x.erase(unique(x.OP,x.ED),x.ED)
typedef long long LL;
typedef pair<int, int> PII;
int isp[10010];
int p[10010],P;
void solve() {
	LL n;
	LL i,j,ii;
	for (i=2; i<=10000; i++) isp[i]=i%2;
	for (isp[2]=1,i=3; i<=10000; i+=2)
		if (isp[i])
			for (j=i*i; j<=10000; j+=2*i) isp[j]=0;
	P=0;
	for (i=2; i<=10000; i++) if (isp[i]) p[++P]=i;
	while (cin>>n) {
		vector<LL>L[1300];
		set<LL>res,temp;
		set<LL>::iterator iter;
		for (i=1; i<=P; i++) {
			LL tp=1;
			while (tp<2LL*n*n) {L[i].PB (tp); tp*=p[i];}
		}
		for (i=0; i<L[1].SZ&&res.SZ<n; i++) res.insert (L[1][i]);
//		cout<<res.SZ<<endl;
		for (i=2; i<=P&&res.SZ<n; i++) {
			temp=res;
			int add=0;
			for (iter=temp.OP; iter!=temp.ED&&add<n/2&&res.SZ<n; iter++)
				for (j=1; j<L[i].SZ&&add<n/2&&res.SZ<n; j++) {
					LL tt=L[i][j]* (*iter);
					if (tt>0&&tt<2LL*n*n&&res.find (tt) ==res.ED) add++,res.insert (tt);
				}
			set<LL>ADD;
			for (iter=res.OP; iter!=res.ED; iter++) for (ii=1; ii<=i; ii++) for (j=1; j<L[ii].SZ; j++) {
						LL tt=L[ii][j]* (*iter);
						if (tt>0&&tt<2LL*n*n&&res.find (tt) ==res.ED) ADD.insert (tt);
					}
			if (ADD.SZ+res.SZ>=n) {
				for (iter=ADD.OP; iter!=ADD.ED&&res.SZ<n; iter++) res.insert (*iter);
			}
		}
		for (i=1; i<=P; i++) {
			int add=0;
			for (iter=res.OP; iter!=res.ED; iter++) if ( (*iter) %p[i]==0) add++;
			while (add>0&&add<=n/2) {
				for (iter=res.OP; iter!=res.ED&&add<=n/2; iter++) {
					if ( (*iter) %p[i]==0) continue;
					for (j=1; j<L[i].SZ&&add<=n/2; j++) {
						LL nw=*iter;
						LL tt= L[i][j]*nw;
						if (tt>0&&tt<2LL*n*n&&res.find (tt) ==res.ED) {
							iter++;
							res.erase (res.find (nw));
							res.insert (tt);
							iter--;
							add++;
							break;
						}
					}
				}
			}
//			if(add)cout<<p[i]<<" "<<add<<endl;
		}
		if(res.SZ!=n)while(1);
		for (iter=res.OP; iter!=res.ED; iter++) cout<< (* iter) <<" ";
		cout<<endl;
	}
}
int main() {
//	while(1)
	solve();
	return 0;
}
