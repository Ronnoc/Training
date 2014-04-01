#include<stdio.h>
#include<math.h>
int f(int x){return x*(x+1)/2;}
int main(){
	long long n;
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		if(n<0)n=-n;
		int min;	
		min=(int)( (sqrt(1.0+8*n)) / 2 );
		while(f(min)<n)min++;
		while(n%2!=f(min)%2)min++;
		if(n==0||n==2)min=3;
		printf("%d\n",min);
		if(t)printf("\n");
		}
	return 0;
	}
