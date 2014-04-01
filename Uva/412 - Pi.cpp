#include<stdio.h>
#include<cmath>
int gcd(int x,int y){
	if(x<y)return gcd(y,x);
	if(y==0)return x;
	return gcd(y,x%y);
	} 
int a[60];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		int i,j,res=0;
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		for(i=1;i<=n;i++)for(j=i+1;j<=n;j++)if(gcd(a[i],a[j])==1)res++;
		int m=(n-1)*n/2;
		double x=res/(double)m;
		if(res)printf("%.6lf\n",sqrt(6/x));
		else printf("No estimate for this data set.\n");
		}
	return 0;
	}
