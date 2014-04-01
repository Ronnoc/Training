#include <iostream>
#include <cstdio>
#define REP(i,n) for(i=0;i<=n;i++)
using namespace std;
int main(){
	int q,w,e,r,t,y;
	int Q,W,E,R,T,Y;
	int TT=0;
	while(cin>>q>>w>>e>>r>>t>>y){
		if(!q&&!w&&!e&&!r&&!t&&!y)break;
		q%=8;w%=8;e%=8;r%=8;t%=8;y%=8;
		int tot=1*q+2*w+3*e+4*r+5*t+6*y;
		int flag=0;
		REP(Q,q)REP(W,w)REP(E,e)REP(R,r)REP(T,t)REP(Y,y){
			int TOT=1*Q+2*W+3*E+4*R+5*T+6*Y;
			if(TOT*2==tot)flag=1;
		}
		printf("Collection #%d:\n",++TT);
		if(flag)printf("Can be divided.\n\n");
		else printf("Can't be divided.\n\n");
	}
	return 0;
}
