#include <cstdio>
int main() {
int OFFL=0;
#ifndef ONLINE_JUDGE
OFFL=1;
#endif
	int y,m,d,p,q,r;
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%4d/%2d/%2d-%2d:%2d:%2d",&y,&m,&d,&p,&q,&r);
		char c='a';
		if(p>12)c='p',p-=12;
		if(p==12)c='p';
		if(p==0)p+=12;
		printf("%02d/%02d/%04d-%02d:%02d:%02d%cm\n",m,d,y,p,q,r,c);
	}
return 0;}
