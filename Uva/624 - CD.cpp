#include<stdio.h>
int n;
int a[30];
int cho[30];
int result;
int mem[30];
int m;
bool check(int t){
	int i;
	int sum=0;
	for(i=1;i<=t;i++)if(cho[i])sum+=a[i];
	if(sum>n)return 0;
	return 1;
	}
void op(int t){
	int i;
	if(t>m){
		int sum=0;
		for(i=1;i<=m;i++)if(cho[i])sum+=a[i];
		if(sum>=result&&sum<=n){
			int p,q;
			for(i=1;i<=m;i++){p+=mem[i];q+=cho[i];}
			if(p<q)for(i=1;i<=m;i++)mem[i]=cho[i];
			result=sum;
			}
		}
	else {
		for(i=0;i<=1;i++){
			cho[t]=i;
			if(check(t))op(t+1);
			}
		}
	}
int main(){
	while(scanf("%d",&n)!=EOF){
		int i;
		scanf("%d",&m);
		for(i=1;i<=m;i++)scanf("%d",&a[i]);
		for(i=1;i<=m;i++)mem[i]=0;result=0;
		op(1);
		for(i=1;i<=m;i++)if(mem[i])printf("%d ",a[i]);
		printf("sum:%d\n",result);
		}
	}
