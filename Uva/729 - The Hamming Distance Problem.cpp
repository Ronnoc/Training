#include<stdio.h>
int m,n;
int cho[20];
bool check(int t){
	int i,sum=0;
	for(i=1;i<=t;i++)sum+=cho[i];
	if(sum>m)return 0;
	return 1;
	}
void op(int t){
	int i;
	if(t>n){
		int sum=0;
		for(i=1;i<=n;i++)sum+=cho[i];
		if(sum==m){
			for(i=1;i<=n;i++)printf("%d",cho[i]);
			printf("\n");
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
	int k,z;
	scanf("%d",&z);
	for(k=1;k<=z;k++){
		scanf("%d%d",&n,&m);
		op(1);
		if(k!=z)printf("\n");
		}
//	return main();
	return 0;
	}
