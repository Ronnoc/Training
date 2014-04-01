#include<stdio.h>
#include<stdio.h>
#define LL long long
LL MOD;
struct mtx{LL m[3][3];}bin[40],res;
mtx mutiply(mtx a,mtx b){
	mtx res;
	int i,j,k;
	for(i=1;i<=2;i++)for(j=1;j<=2;j++){
		res.m[i][j]=0;
		for(k=1;k<=2;k++)res.m[i][j]+=a.m[i][k]*b.m[k][j];
		res.m[i][j]%=MOD;
		}
	return res;
	}
int main(){
	int n,i;
	int a,b,m;
	int k,z;
	scanf("%d",&z);
	for(k=1;k<=z;k++){
		scanf("%d%d%d%d",&a,&b,&n,&m);
		MOD=1;
		for(i=1;i<=m;i++)MOD*=10;
		n-=1;
		bin[1].m[1][1]=bin[1].m[1][2]=bin[1].m[2][1]=1;
		bin[1].m[2][2]=0;
		for(i=2;i<=35;i++){
			bin[i]=mutiply(bin[i-1],bin[i-1]);
			}
		res.m[1][1]=b;
		res.m[1][2]=res.m[2][1]=a;
		res.m[2][2]=1;
		int bn[40],pbn=0;
		while(n!=0){
			bn[++pbn]=n%2;
			n/=2;
			}
	//	for(i=pbn;i>=1;i--)printf("%d",bn[i]);printf("\n");
		for(i=1;i<=pbn;i++){
			if(bn[i])res=mutiply(res,bin[i]);
			}
		printf("%lld\n",res.m[1][1]);	
		}
//	return main();
	return 0;
	}
