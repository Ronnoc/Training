#include<stdio.h>
int a[1010],s[99];
int ok[11];
int in(){
	int i;
	for(i=1;i<=9;i++)ok[i]=0;
	}
int main(){
	int i,j,k;
	int n;
	int z=0;
	while(scanf("%d",&n)!=EOF&&n){
		for(i=1;i<=n;i++)scanf("%d%d%d%d",&a[i],&a[100+i],&a[200+i],&s[i]);
		int res=-1;
		for(i=1;i<=n;i++)for(j=i+1;j<=n;j++){
				if(a[j]==a[i])continue;
			for(k=j+1;k<=n;k++){
				if(a[k]==a[j])continue;
			int t;
			int flag=0;
			in();
			for(t=0;t<3;t++)if(!ok[ a[i+t*100] ])ok[ a[i+t*100] ]=1;else flag=1;
			for(t=0;t<3;t++)if(!ok[ a[j+t*100] ])ok[ a[j+t*100] ]=1;else flag=1;
			for(t=0;t<3;t++)if(!ok[ a[k+t*100] ])ok[ a[k+t*100] ]=1;else flag=1;
			if(flag)continue;
			int sum=s[i]+s[j]+s[k];
			if(res<sum)res=sum;
		//	if(res==sum)printf("%d,%d,%d::%d\n",i,j,k,res);
			}
		}
		printf("Case %d: ",++z);
		printf("%d\n",res);
			}
	return 0;
	}
