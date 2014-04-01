#include<stdio.h>
int n;
int cho[20];
int x[20],y[20];
int xm,ym;
int res;
int abs(int x){if(x>0)return x;return -x;}
int f(int a,int b,int c,int d){
//	printf("%d\t",abs(a-c)+abs(b-d));
	return abs(a-c)+abs(b-d);
	}
bool check(int t){
	int i;
	for(i=1;i<t;i++){
		if(cho[i]==cho[t])return 0;
		}
	return 1;
	}
void op(int t){
	int i;
	if(t>n){
		int sum=0;
		for(i=1;i<=n+1;i++)sum+=f(x[cho[i-1]],y[cho[i-1]],x[cho[i]],y[cho[i]]);
		if(sum<res)res=sum;
		}
	else {
		for(i=1;i<=n;i++){
			cho[t]=i;
//			printf("!"); 
			if(check(t))op(t+1);
			}
		}
	}
int main(){
	int k,z;
	scanf("%d",&z);
	for(k=1;k<=z;k++){
		scanf("%d%d",&xm,&ym);
		scanf("%d%d",&x[0],&y[0]);
		scanf("%d",&n);
		res=214748364;
		int i;
		for(i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
		x[n+1]=x[0],y[n+1]=y[0];
		cho[0]=0;cho[n+1]=n+1; 
//		for(i=0;i<=n+1;i++)printf("%3d",x[i]);printf("\n"); 
//		for(i=0;i<=n+1;i++)printf("%3d",y[i]);printf("\n"); 
		op(1);
		printf("The shortest path has length %d\n",res); 
		}
	return 0;
	}
