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
#define PI acos(-1)
typedef long long LL;
typedef pair<int, int> PII;
	int revv (int x,int mask) {
		int ret=0;
		for (int i=0; i<mask; i++) {
			ret<<=1;
			ret|=x&1;
			x>>=1;
		}
		return ret;
	}
	void fft (double * rl, double * ig, int n, bool sign) {
		int d=0;
		while ( (1<<d) <n) ++d;
		for (int i=0; i<n; i++) {
			int j=revv (i,d);
			if (i<j) swap (rl[i],rl[j]),swap (ig[i],ig[j]);
		}
		for (int m=2; m<=n; m<<=1) {
			int mh=m>>1;
			double _wr=cos (2*PI/m),_wi=sin (2*PI/m);
			if (sign) _wi*=-1.0;
			for (int i=0; i<n; i+=m) {
				double wr=1,wi=0;
				for (int j=i; j<mh+i; j++) {
					int k=j+mh;
					double er=rl[k]*wr-ig[k]*wi;
					double ei=rl[k]*wi+ig[k]*wr;
					double cr=rl[j],ci=ig[j];
					rl[j]+=er,ig[j]+=ei;
					rl[k]=cr-er,ig[k]=ci-ei;
					double qr=wr*_wr-wi*_wi;
					double qi=wr*_wi+wi*_wr;
					wr=qr,wi=qi;
				}
			}
		}
		if (sign) for (int i=0; i<n; i++)
				rl[i]/=n,ig[i]/=n;
	}
	double ax[222222],ay[222222];
	double bx[222222],by[222222];
	double ansx[222222],ansy[222222];
	int fftmultiply (int *a,int la,int *b,int lb,int *ans) {
		int lans=max (la,lb),ln=0,i;
		while ( (1<<ln) <lans) ++ln;
		lans=2<<ln;
		for (i=0; i<lans; i++)
			ax[i]=i<la?a[i]:0,ay[i]=0;
		fft (ax,ay,lans,0);
		for (i=0; i<lans; i++)
			bx[i]=i<lb?b[i]:0,by[i]=0;
		fft (bx,by,lans,0);
		for (i=0; i<lans; i++) {
			ansx[i]=ax[i]*bx[i]-ay[i]*by[i];
			ansy[i]=ax[i]*by[i]+ay[i]*bx[i];
		}
		fft (ansx,ansy,lans,1);
		for (i=0; i<lans; i++)
			ans[i]=ansx[i]+0.5;
		return lans;
	}

char A[222222],B[222222];

int a[222222],b[222222];
int ans[222222];
int la,lb,lans;

void solve() {
  while (~scanf ("%s%s",A,B)) {
    int i;
    la=strlen (A);
    lb=strlen (B);
    for (i=0; i<la; i++)
      a[i]=A[la-i-1]-'0';
    for (i=0; i<lb; i++)
      b[i]=B[lb-i-1]-'0';
    memset (ans,0,sizeof ans);
    lans=fftmultiply (a,la,b,lb,ans);
    for (i=0; i<lans||ans[i]>=10; i++) {
      ans[i+1]+=ans[i]/10;
      ans[i]%=10;
    }
    int id=i;
    while (id&&ans[id]<=0) id--;
    for (i=id; i>=0; i--)
      putchar (ans[i] + '0');
    putchar ('\n');
  }
}
int main() {
//    while(1)
  solve();
  return 0;
}
