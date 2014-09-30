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
const double PI=acos(-1.);
const LL MOD = 1000000007;
void show(int a,int b,bool &fi) {
	if(a==0)return;
	if(b==0) {
		if(!fi) {
			if(a>0)printf("+%d",a);
			else printf("%d",a);
		} else printf("%d",a);
	} else {
		if(!fi&&a>0)printf("+");
		if(a<0)printf("-"),a=-a;
		if(a>1)printf("%d",a);
		printf("x");
		if(b>1)printf("^%d",b);
	}
	fi=0;
}
//void show(int a,int b,bool &fi) {
//	if(a==0)return;
//	if(!fi&&a>0)printf("+");
//	if(a<0)printf("-"),a=-a;
//	if(a>1||b==0)printf("%d",a);
//	if(b>0)printf("x");
//	if(b>1)printf("^%d",b);
//	fi=0;
//}
struct poly {
	vector<int>A,B;
	poly() {A.clear(),B.clear();}
	void write()const  {
		if(A.SZ<2)return;
		printf("(");
		bool fi=1;
		for(int i=A.SZ-1; i>=0; i--)
			show(A[i],B[i],fi);
		if(fi)printf("0");
		printf(")");
	}
	bool operator <(const poly &C)const {
		int ti=B.SZ-1,ci=C.B.SZ-1;
		while(ti&&ci) {
			if(B[ti]!=C.B[ci])return B[ti]<C.B[ci];
			if(abs(A[ti])!=abs(C.A[ci]))return abs(A[ti])<abs(C.A[ci]);
			if(A[ti]!=C.A[ci])return A[ti]<C.A[ci];
			ti--; ci--;
		}
		if(ci)return 1;
		return 0;
	}
	bool operator ==(const poly &C)const {
		return A==C.A&&B==C.B;
	}
};
int d[1305];
int r[1305];
bool FAIL;
poly Divide(poly D,poly E) {
//	D.write(); printf("/"); E.write(); printf("\n");
	poly ret;
	int ld=*max_element(D.B.OP,D.B.ED);
	int le=*max_element(E.B.OP,E.B.ED);
	int i,j;
	for(i=0; i<=ld; i++)d[i]=r[i]=0;
	for(i=0; i<D.B.SZ; i++)d[D.B[i]]=D.A[i];
	for(i=ld; i>=le; i--) {
//		for(int i=0; i<=ld; i++)cout<<d[i]<<" "; cout<<endl;
		r[i-le]=d[i];
		for(j=0; j<E.B.SZ; j++)
			d[i-(le-E.B[j])]-=r[i-le]*E.A[j];
	}
//	for(int i=0; i<=ld; i++)cout<<d[i]<<" "; cout<<endl;
	for(i=0; i<le; i++)if(d[i]) {
			FAIL=1;
//			printf("FAIL\n");
			return ret;
		}
	for(i=0; i<=ld; i++)
		if(r[i])ret.A.PB(r[i]),ret.B.PB(i);
//	ret.write(); printf("got\n");
	return ret;
}
poly P[1105];
int main() {
//	freopen("F.wa","w",stdout);
	int i,j,k,T;
	int n;
	for(i=1; i<=1100; i++) {
		P[i].A.PB(-1),P[i].B.PB(0);
		P[i].A.PB(1),P[i].B.PB(i);
	}
	for(i=1;i<=1100;i++)
		for(j=i+i;j<=1100;j+=i)
			P[j]=Divide(P[j],P[i]);
//	for(n=1;n<=30;n++){
	while(~scanf("%d",&n)&&n){
		if(n==1){puts("x-1");continue;}
		vector<poly>L;
		for(i=1;i<=n;i++)if(n%i==0)
			L.PB(P[i]);
		sort(L.OP,L.ED);
		for(i=0;i<L.SZ;i++)L[i].write();
		printf("\n");
	}
	return 0;
}
