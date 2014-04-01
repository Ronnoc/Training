#include<stdio.h>
int cho[10];
int num[10];
int flag=0;
int go(int x,int d,int y){
	if(d==1)return x+y;
	if(d==2)return x-y;
	return x*y;
	}
bool check(int t){
	int i;
	for(i=1;i<t;i++)if(cho[i]==cho[t])return 0;
	return 1;
	}
void op(int z){
	int i;
	if(z>5){
		int j,k,l;
		for(i=1;i<4;i++)for(j=1;j<4;j++)for(k=1;k<4;k++)for(l=1;l<4;l++){
			int sum=go(num[cho[1]],i,num[cho[2]]);
			sum=go(sum,j,num[cho[3]]);
			sum=go(sum,k,num[cho[4]]);
			sum=go(sum,l,num[cho[5]]);
			if(sum==23){flag++;}//printf("%d %d %d %d %d %d %d %d %d\n",num[cho[1]],i,num[cho[2]],j,num[cho[3]],k,num[cho[4]],l,num[cho[5]]);}
			}
		}
	else {
		for(i=1;i<=5;i++){
			cho[z]=i;
			if(check(z))op(z+1);
			}
		}
	}
int main(){
	while(scanf("%d%d%d%d%d",&num[1],&num[2],&num[3],&num[4],&num[5])!=EOF){
		flag=0;
		if(num[1]==0&&num[2]==0&&num[3]==0&&num[4]==0&&num[5]==0)break;
		op(1);
		if(flag)printf("Possible\n");
		else printf("Impossible\n");
		}
	return 0;
	}
