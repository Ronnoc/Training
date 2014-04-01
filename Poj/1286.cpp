//poj 2409
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
#define _LL long long
#define MN 100
int ak[MN];
int f1[MN],f2[MN];
int p[MN][MN], now[MN], temp[MN];
//求置换的循环节,polya原理
//perm[0..n-1]为0..n-1的一个置换(排列)
//返回置换最小周期,num返回循环节个数

int gcd( int a,int b ) {
	return b?gcd( b,a%b ):a;
}

int polya( int* perm,int n,int& num ) {
	int i,j,p,v[MN]= {0},ret=1;
	for ( num=i=0; i<n; i++ )
		if ( !v[i] ) {
			for ( num++,j=0,p=i; !v[p=perm[p]]; j++ )
				v[p]=1;
			ret*=j/gcd( ret,j );
		}
	return ret;
}

void again( int *now,int *f,int n ) {
	int i;
	for ( i=0; i<n; i++ )
		now[i]=f[now[i]];
}

long long exponent( long long x,int m ) {
	long long res=1;
	while ( m ) {
		if ( m&1 )
			res*=x;
		x*=x;
		m/=2;
	}
	return res;
}

int main() {
	int n=3,m,i,j;
	while ( ~scanf( "%d",&m ) ) {
		if ( m==-1 )
			break;
		for ( i=0; i<m; i++ )
			ak[i]=i;
		for ( i=0; i<m; i++ )
			f1[i]=( i+1 )%m;
		for ( i=0; i<m; i++ )
			f2[i]=m-1-i;
		memcpy( now,ak,sizeof( ak ) );
		for ( i=1; i<=m; i++ ) {
			memcpy( p[i],now,sizeof( now ) );
			memcpy( temp,now,sizeof( now ) );
			again( temp,f2,m );
			memcpy( p[i+m],temp,sizeof( now ) );
			again( now,f1,m );
		}
		int period[MN],cnt[MN];
		for ( i=1; i<=2*m; i++ )
			period[i]=polya( p[i],m,cnt[i] );
		long long res=0;
		for ( i=1; i<=2*m; i++ )
			res+=exponent( n,cnt[i] );
		if(m)res/=( 2*m );
		printf( "%I64d\n",res );
	}
	return 0;
}
