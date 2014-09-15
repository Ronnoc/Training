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
const double INF=1e20;
const double PI=acos( -1. );
const LL MOD = 1000000007;
const int MVar = 444, MEqa = 444;
long double a[MEqa][MVar];
int idx[MVar],nv,ne;
int nxt[MVar];//-a[0][0]=max ¡Æa[0][i]*x[i]
void show() {
	int i,j;
	for ( i=0; i<=ne; i++ ) {
		printf( "%d[%d]%3.5lf=\t",i,idx[i],a[i][0] );
		for ( j=1; j<=nv; j++ )if(abs(a[i][j])>eps)printf( "%3.5lf*x[%d] ",a[i][j],j );
		printf( "\n" );
	}
	printf( "\n" );
}
void pivot( int e,int v ) {
	int i,j;
	long double temp;
	int tp=MVar-1;
	for ( j=nv; j>=0; j-- )nxt[j]=-1;
	for ( j=nv; j>=0; j-- )if ( abs( a[e][j] )>eps ) {nxt[tp]=j; tp=j;}
	temp=a[e][v];
	for ( tp=nxt[MVar-1]; tp!=-1; tp=nxt[tp] )a[e][tp]/=temp;
	for ( i=0; i<=ne; i++ )if ( abs( a[i][v] )>eps&&i!=e ) {
			temp=a[i][v];
			for ( tp=nxt[MVar-1]; tp!=-1; tp=nxt[tp] )
				a[i][tp]-=temp*a[e][tp];
		}
	idx[e]=v;
}
int dualsolve() {
	int i,j;
	long double temp;
	for ( j=1; j<=nv; j++ )if ( a[0][j]<-eps )return 0;
	while ( 1 ) {
		int l=0,r=0;
		temp=-eps;
		for ( i=1; i<=ne; i++ )if ( a[i][0]<temp )temp=a[i][0],r=i;
		if ( !r )return 1;
		temp=1e100;
		for ( j=1; j<=nv; j++ )if ( a[r][j]<-eps&&a[0][j]/a[r][j]<temp )
				temp=a[0][j]/a[r][j],l=j;
		if ( !l )return 0;
		pivot( r,l );
	}
}
int solve() {
	int i,j;
	long double temp;
	for ( i=1; i<=ne; i++ )if ( abs( a[0][idx[i]] )>eps ) {
			temp=a[0][idx[i]];
			for ( j=0; j<=nv; j++ )a[0][j]-=temp*a[i][j];
		}
	int dual=0;
	for ( i=1; i<=ne; i++ )if ( a[i][0]<-eps )dual=1;
	if ( dual ) {
		int dual=dualsolve();
		if ( !dual )return 0;	//no solution
	}
	while ( 1 ) {
		int l=0,r=0;
		temp=1e100;
		for ( j=1; j<=nv; j++ )if ( a[0][j]>eps ) {l=j; break;}
		if ( !l )return 1;		//done
		for ( i=1; i<=ne; i++ )if ( a[i][l]>eps&&a[i][0]+eps<a[i][l]*temp )
				temp=a[i][0]/a[i][l],r=i;
		if ( !r )return -1;		//infinite
		pivot( r,l );
	}
}
int N,L,R;
int A[105][4],P[105];
int B[4];
int main() {
	int i,j,CA=0;
	while(~scanf("%d",&N)&&N){
		scanf("%d%d",&L,&R);
		for(i=0;i<N;i++){
			for(j=1;j<=3;j++)scanf("%d",&A[i][j]);
			scanf("%d",&P[i]);
		}
		for(j=1;j<=3;j++)scanf("%d",&B[j]);
		ne=0,nv=3;
		memset(a,0,sizeof a);
		for(i=0;i<N;i++){
			int iy=++nv;
			int iz=++nv;
			ne++;
			a[ne][1]=A[i][1]+A[i][2]+A[i][3];
			a[ne][2]=A[i][2]+A[i][3];
			a[ne][3]=A[i][3];
			a[ne][iy]=1;
			a[ne][0]=P[i]-L;
			idx[ne]=iy;
			ne++;
			a[ne][1]=-(A[i][1]+A[i][2]+A[i][3]);
			a[ne][2]=-(A[i][2]+A[i][3]);
			a[ne][3]=-(A[i][3]);
			a[ne][iz]=1;
			a[ne][0]=R-P[i];
			idx[ne]=iz;
		}
		a[0][1]=(B[1]+B[2]+B[3]);
		a[0][2]=(B[2]+B[3]);
		a[0][3]=(B[3]);
		int flag=solve();
		printf("Case %d: ",++CA);
		if(flag==-1)printf("Too expensive!\n");
		else if(flag==0)printf("Inconsistent data\n");
		else printf("%.4f\n",(double)(R-a[0][0]));
	}
	return 0;
}
