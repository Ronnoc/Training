#include<stdio.h>
#include<math.h>
#define D double
#define eps 1e-9
D S(D x1,D y1,D x2,D y2,D x3,D y3){
	return fabs( (y3-y1)*(x2-x1) - (y2-y1)*(x3-x1) );
	}
int n;
char name[20];
D x[20],y[20];
int main(){
	int n;
	while(scanf("%d%*c",&n)!=EOF&&n){
		int i;
		char s[1010];
		for(i=1;i<=n;i++){
			gets(s);
			sscanf(s,"%c %lf %lf",&name[i],&x[i],&y[i]); 
			}
		int j,k,l;
		int p,q,r;
		D res=-1;
		for(i=1;i<=n;i++)for(j=i+1;j<=n;j++)for(k=j+1;k<=n;k++){
			int flag=1;
			D thiS=S(x[i],y[i],x[j],y[j],x[k],y[k]);
			for(l=1;l<=n;l++){
				if(i==l||j==l||k==l)continue;
				D check=0;
				check+=S(x[l],y[l],x[j],y[j],x[k],y[k]);
				check+=S(x[i],y[i],x[l],y[l],x[k],y[k]);
				check+=S(x[i],y[i],x[j],y[j],x[l],y[l]);
				if(fabs(thiS-check)<eps){
					flag=0;
					break;
					}
				}
			if(flag){
				if(thiS>res){
					res=thiS;
					p=i;q=j;r=k;
					}
				}
			}
		printf("%c%c%c\n",name[p],name[q],name[r]);
		} 
	return 0;
	}
