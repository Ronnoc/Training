#include <cstdio>
#include <iostream>
using namespace std;
#define LL long long
LL n,m;
LL u[2222],d[2222];
int main(){
//	freopen("business.in","r",stdin);
//	freopen("business.out","w",stdout);
	while(cin>>n>>m){
		int i;
		LL ret=-1;
		for(i=1;i<=m;i++){
			cin>>u[i]>>d[i];
			LL tot=n*u[i];
			LL p=tot/(u[i]+d[i]);
			tot-=p*(u[i]+d[i]);
			if(p>0&&tot==0)tot+=u[i]+d[i];
			if(ret==-1&&tot>0)ret=tot;
			else if(tot>0)ret=min(ret,tot);
		}
		cout<<ret<<endl;
	}
	return 0;
}
/*
10 3
15 12
15 4
7 12
*/
