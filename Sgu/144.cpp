#include<cstdio>
int main(){
	int x,y;
	double z;
	while(~scanf("%d%d%lf",&x,&y,&z)){
		double l=(y-x)*60;
				//y=x+_ z;
		double ans=1-((l-z)*(l-z))/(l*l);
		printf("%.8lf\n",ans);
	}
	return 0;
}
