#include <cstdio>
#include <cmath>
using namespace std;
double pow2(double x){return x*x;}
int main() {
int OFFL=0;
#ifndef ONLINE_JUDGE
OFFL=1;
#endif
	int rgb[22][4];
	int i,j;
	for(i=1;i<=16;i++)for(j=1;j<=3;j++)scanf("%d",&rgb[i][j]);
	int r,g,b;
	while(scanf("%d%d%d",&r,&g,&b)!=EOF){
		if(r==-1&&g==-1&&b==-1)break;
		double dis=99999;
		int to=-1;
		for(i=1;i<=16;i++){
			double s=sqrt(pow2(rgb[i][1]-r)+pow2(rgb[i][2]-g)+pow2(rgb[i][3]-b));
			if(s<dis){dis=s,to=i;}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n",r,g,b,rgb[to][1],rgb[to][2],rgb[to][3]);
	}
return 0;}
