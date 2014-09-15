#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;
LL MOD = 1000000007;
struct mat {
	LL _[4][4];
	mat() {memset(_,0,sizeof _);}
	LL *operator [](int a) {return _[a];}
	mat friend operator *(mat &A,mat &B) {
		mat C;
		int i,j,k;
		for(i=0; i<4; i++)for(j=0; j<4; j++)if(A[i][j])
					for(k=0; k<4; k++)C[i][k]+=A[i][j]*B[j][k];
		for(i=0; i<4; i++)for(j=0; j<4; j++)if(C[i][j]>=MOD)C[i][j]%=MOD;
		return C;
	}
	mat operator ^(LL a) {
		mat C,A=*(this);
		for(int i=0; i<4; i++)C[i][i]=1;
		while(a) {
			if(a&1)C=C*A;
			A=A*A;
			a>>=1;
		}
		return C;
	}
	void show() {
		for(int i=0; i<4; i++,cout<<endl)
			for(int j=0; j<4; j++)cout<<_[i][j]<<" ";
	}
};
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	scanf("%d",&T);
	while(T--) {
		LL x,m,n;
		scanf("%I64d%I64d%I64d",&x,&n,&m);
		x%=m;
		MOD=m;
		mat A;
		A[0][0]=4*x%m*x%m;
		A[0][1]=1%m;
		A[0][2]=(m-(4*x)%m)%m;
		A[1][0]=1%m;
		A[2][0]=2*x%m;
		A[2][2]=(m-1)%m;
		A[3][0]=4*x%m*x%m;
		A[3][1]=1%m;
		A[3][2]=(m-(4*x)%m)%m;
		A[3][3]=1%m;
		mat B=A^(n-2);
		LL Y[4],y[4];
		y[0]=x*x%m;
		y[1]=1%m;
		y[2]=x%m;
		y[3]=(1+x*x)%m;
		for(i=0; i<4; i++) {
			Y[i]=0;
			for(j=0; j<4; j++)Y[i]+=B[i][j]*y[j];
			Y[i]%=m;
		}
		printf("%I64d\n",Y[3]);
	}
	return 0;
}
/*
1
4 4 1000000007

60514
*/
