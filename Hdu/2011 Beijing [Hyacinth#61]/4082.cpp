#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <bitset>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define OP begin()
#define ED end()
#define BG begin()
#define SQ(x) ((x)*(x))
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)

LL play(PII A,PII B) {
	LL x=A.AA-B.AA;
	LL y=A.BB-B.BB;
	return x*x+y*y;
}
struct tri {
	LL a,b,c;
	tri() {}
	void read(PII A,PII B,PII C) {
		a=play(B,C);
		b=play(A,C);
		c=play(A,B);
		int g=__gcd(a,__gcd(b,c));
		if(g)a/=g,b/=g,c/=g;
		if(b<a)swap(a,b);
		if(c<a)swap(a,c);
		if(c<b)swap(b,c);
	}
	bool operator ==(const tri &t)const{
		return a==t.a&&b==t.b&&c==t.c;
	}
}foo;
PII z[33];
pair<LL,LL>FFF(PII p,PII q) {
	LL dx=q.AA-p.AA;
	LL dy=q.BB-p.BB;
	LL dg=__gcd(dx,dy);
	if(dg<0)dg=-dg;
	if(dg)dx/=dg,dy/=dg;
	if(dx<0)dx=-dx,dy=-dy;
	if(dx==0)if(dy<0)dy=-dy;
	return MP(dx,dy);
}
vector<tri>L;
int main() {
	int i,j,k;
	int n;
	while(~scanf("%d",&n)&&n) {
		for(i=0; i<n; i++)scanf("%d%d",&z[i].AA,&z[i].BB);
		sort(z,z+n);
		n=unique(z,z+n)-z;
		L.clear();
		int ans=0;
		for(i=0; i<n; i++)
			for(j=i+1; j<n; j++)if(z[i]!=z[j]){
				pair<LL,LL>x=FFF(z[i],z[j]);
				for(k=j+1; k<n; k++)if(z[k]!=z[i]&&z[k]!=z[j]){
					pair<LL,LL>y=FFF(z[i],z[k]);
					if(y!=x){
						foo.read(z[i],z[j],z[k]);
						L.PB(foo);
					}
				}
			}
		for(i=0;i<L.SZ;i++){
			int now=0;
			for(j=0;j<L.SZ;j++)
				if(L[j]==L[i])now++;
			cmax(ans,now);
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
18
0 0
1 1
2 4
3 9
4 16
5 25
6 36
7 49
8 64
9 81
10 100
11 121
12 144
13 169
14 196
15 225
16 256
17 341
*/
