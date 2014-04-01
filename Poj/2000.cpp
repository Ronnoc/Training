#include<cstdio>
int p1[10010],p2[10010];
int main(){
	int i,j;
	p1[0]=0;p2[0]=0;
	int at=0,now=0;
	while(1){
		++now;
		for(i=1;i<=now;i++){
			p1[++at]=now;
			p2[at]=p2[at-1]+now;
			if(at>10000)break;
		}
		if(at>10000)break;
	}
	while(scanf("%d",&i)!=EOF&&i)printf("%d %d\n",i,p2[i]);
	return 0;
}
