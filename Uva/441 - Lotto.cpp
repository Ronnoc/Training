#include<stdio.h>
int a[20];
int cho[20];
int k;
bool check(int t){
	int i;
	for(i=1;i<t;i++)if(cho[i]>=cho[t])return 0;
	return 1;
	}
void op(int t){
	int i;
	if(t>6){
		int fi=1;
		for(i=1;i<=6;i++){
			if(fi)fi=0;
			else printf(" ");
			printf("%d",a[cho[i]]);
			}
		printf("\n");
		}
	else {
		for(i=1;i<=k;i++){
			cho[t]=i;
			if(check(t))op(t+1);
			}
		}
	}
int main(){
	int c=0;
	while(scanf("%d",&k)!=EOF&&k){
		++c;
		if(c!=1)printf("\n");
		int i;
		for(i=1;i<=k;i++)scanf("%d",&a[i]);
		op(1);
		}
	return 0;
	}
