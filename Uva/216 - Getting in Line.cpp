#include<stdio.h>
#include<math.h>
int cho[10];
double ans;
int pns[10];
int n;
struct point{double x,y;}p[10];
double odis(int i,int j){
	double a1=p[ i ].x,a2=p[i].y;
	double b1=p[ j ].x,b2=p[j].y;
	double d1=(a1-b1)*(a1-b1);
	double d2=(a2-b2)*(a2-b2);
	double res=sqrt(d1+d2);
	return res;
	}
int place(int x){
	int i;
	for(i=1;i<x;i++)if(cho[i]==cho[x])return 0;
	return 1;
	}
int dfs(int x){
	int i;
	if(x>n){
		double res=0;
		for(i=2;i<=n;i++)res+=odis(cho[i-1],cho[i]);
		if(res<ans){
			ans=res;
			for(i=1;i<=n;i++)pns[i]=cho[i];
			}
		}
	else {
		for(i=1;i<=n;i++){
			cho[x]=i;
			if(place(x))dfs(x+1);
			}
		}
	}
int main(){
	int t=0;
	while(scanf("%d",&n)!=EOF&&n){
		int i;
		for(i=1;i<=n;i++)scanf("%lf%lf",&p[i].x,&p[i].y);
		ans=sqrt(150*150*2.0)*n;
		dfs(1);
		ans+=(n-1)*16.0;
		printf("**********************************************************\n");
		printf("Network #%d\n",++t);
		for(i=2;i<=n;i++){
			printf("Cable requirement to connect (%.0lf,%.0lf)",p[pns[i-1]].x,p[pns[i-1]].y);
			printf(" to (%.0lf,%.0lf) is %.2lf feet.\n",p[pns[i]].x,p[pns[i]].y,odis(pns[i-1],pns[i])+16);
	//		printf("odis(%d,%d)=%lf\n",pns[i-1],pns[i],odis(pns[i-1],pns[i]));
			}
		printf("Number of feet of cable required is %.2lf.\n",ans);
		}
	return 0;
	}
