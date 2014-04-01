#include<stdio.h>
unsigned long long F[50],S[50];
int main(){
	F[0]=0;F[1]=1;S[0]=0;S[1]=1;
	int i;
	for(i=2;i<41;i++)F[i]=F[i-1]+F[i-2];
	for(i=2;i<41;i++)S[i]=S[i-1]+F[i];
	int n;
	while(scanf("%d",&n)!=EOF)printf("%I64u\n",S[n]);
	return 0;
	}
