#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define OP begin()
#define ED end()
#define BG begin()
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
#define SQ(x) ((x)*(x))
int A[20005];
int B[20005];
int C[20005];
int main() {
//	freopen("J.in","r",stdin);
//	freopen("J.wa","w",stdout);
	int i,j;
	int T,N,K;
	scanf("%d",&T);
	for(int CA=1; CA<=T; CA++) {
		memset(C,0,sizeof C);
		printf("Case #%d:\n",CA);
		scanf("%d%d",&N,&K);
		for(i=0; i<=K; i++)scanf("%d",&A[i]);
		for(i=1; i<=K; i++)B[i]=A[i-1]-A[i];
		for(i=1; i<K; i++)C[i]=B[i]-B[i+1];
		int r=N,p=B[1],q=A[0];
		for(i=1; i<K; i++)if(C[i]>0)r--;
		for(i=1; i<K; i++)p-=C[i];
		for(i=1; i<K; i++)q-=i*C[i];
//		printf("p=%d q=%d r=%d K=%d\n",p,q,r,K);
		int fail=0;
		for(i=1;i<K;i++)if(C[i]<0)fail=1;
		for(i=1;i<=K;i++)if(B[i]<0)fail=1;
		if(r<0||p<r||q<p||fail) {
			printf("No Solution\n");
			continue;
		}
		if(r==0) {
			if(p||q)printf("No Solution\n");
			else {
				printf("Unique Solution\n");
				for(int c=1; c<K; c++)if(C[c])
						printf("%d %d\n",c,C[c]);
			}
			continue;
		}
		if(r==1) {
			int got=0;
			for(i=K; i*p<=q; i++) {
				if(i*p==q) {
					got=1;
					C[i]=p;
					printf("Unique Solution\n");
					for(int c=1; c<=i; c++)if(C[c])
							printf("%d %d\n",c,C[c]);
				}
			}
			if(!got)printf("No Solution\n");
			continue;
		}
		if(r==2) {
			vector<pair<PII,PII> >L;
			int a,b,A,B;
			for(a=K; L.SZ<2&&a<=10000; a++)
				for(A=1; L.SZ<2&&A*a<q; A++) {
					B=p-A;
					if(B<=0)break;
					int qr=q-A*a;
					if(qr%B)continue;
					if(qr/B<=a)continue;
					L.PB(MP(MP(a,A),MP(qr/B,B)));
				}
			if(L.SZ>1)printf("Multiple Solutions\n");
			else if(L.empty())printf("No Solution\n");
			else {
				PII ta=L[0].AA,tb=L[0].BB;
				C[ta.AA]=ta.BB;
				C[tb.AA]=tb.BB;
				printf("Unique Solution\n");
				for(int c=1; c<=tb.AA; c++)if(C[c])
					printf("%d %d\n",c,C[c]);
			}
			continue;
		}
		C[K]=p-(r-1);
		for(i=1;i<r;i++)C[K+i]=1;
		int tq=0;
		for(i=0;i<r;i++)tq+=(K+i)*C[K+i];
		if(tq>q)printf("No Solution\n");
		else if(tq==q){
			printf("Unique Solution\n");
			for(int c=1; c<=K+r; c++)if(C[c])
				printf("%d %d\n",c,C[c]);
		}else if(q-tq>1)printf("Multiple Solutions\n");
		else {
			if(C[K]==1){
				printf("Unique Solution\n");
				C[K+r-1]=0;
				C[K+r]=1;
				for(int c=1; c<=K+r; c++)if(C[c])
					printf("%d %d\n",c,C[c]);
			}else printf("Multiple Solutions\n");
		}
	}
	return 0;
}
/*
2
3 1 21 19
17 36	 290 289 284 278 278 266 263 256 250 237 227 215 213 204 190 187 181 169 164 152 139 133 125 124 120 108 93 88 73 63 55 53 43 30 24 16 7
No
6
2 1 65 28
2 2 99 66 33
7 21 355 330 309 288 267 249 231 214 197 180 165 150 135 120 105 90 75 60 45 30 20 10
5 17 205 189 173 157 141 125 109 96 83 70 57 48 39 30 24 18 12 6
4 19 142 131 120 109 98 87 76 68 60 52 44 36 32 28 24 20 16 12 8 4
3 16 184 172 160 148 136 124 112 100 90 80 70 60 50 40 30 20 10
Multiple Solutions
*/
