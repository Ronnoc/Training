#include<stdio.h>
long long f(long long x) {
	long long count=1,p=x;
	while(p!=1) {
		if(p%2==1) {p=(3*p+1)/2; count+=2;}
		else {p/=2; count++;}
	}
	return count;
}
long long max(long long a,long long b) {
	if(a>b)return a;
	else return b;
}
int main() {
	long long a,b;
	while(scanf("%lld%lld",&a,&b)!=EOF) {
		long long maax=-1,i;
		for(i=a+b-max(a,b); i<=max(a,b); i++) {
			maax=max(maax,f(i));
		}
		printf("%lld %lld %lld\n",a,b,maax);
	}
	return 0;
}
