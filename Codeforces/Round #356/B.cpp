#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;
vector<pair<LL,int> >LMin;
pair<LL,int> playMin(LL m){
	int id=lower_bound(LMin.OP,LMin.ED,MP(m+1,-1))-1-LMin.OP;
	//cout<<LMin[id].AA<<"~"<<m<<"\n";
	return LMin[id];
}
map<LL,pair<LL,int> >FMax;
pair<LL,int>playMax(LL m){
	if(FMax.find(m)!=FMax.ED)
		return FMax[m];
	double t=pow(m,1./3);
	pair<LL,int>aim=playMin(m);
	LL now=aim.AA;
	for(LL i=t+2;i>=1;i--)if(m>=i*i*i){
		LL mul=i*i*i;
		for(LL k=m/mul;k>=0;k--){
			LL next=min(m-k*mul,mul-1);
			pair<LL,int>least=playMin(next);
			//cout<<m<<"@"<<i<<"^3="<<k<<"+"<<least.BB<<" "<<aim.BB<<" ?"<<next<<"\n";
			if(least.BB+k==aim.BB){
				pair<LL,int>tmp=playMax(next);
				if(tmp.AA+k*mul>now)
					now=tmp.AA+k*mul;
			}
		}
		return FMax[m]=MP(now,aim.BB);
	}
	return aim;
}
int main(){
	int i,j,k,_T;	
	/*
	int g=10;
	int f=g*g*g;
	int ans=0,last=0;
	for(i=1;i<=f;i++){
		int now=0,w=i;
		for(j=g;j>=1;j--){
			int add=w/(j*j*j);
			now+=add;
			w-=add*(j*j*j);
		}
		if(now>=ans){
			cout<<"+"<<i-last<<" ";
			last=i;
			ans=now;
			cout<<last<<" "<<ans<<"\n";
		}
	}*/
	LL m=2000000000000000LL;
	LL now=0;
	int cnt=0;
	LMin.PB(MP(now,cnt));
	for(LL i=1;now+i*i*i<=m;i++){
		LL j=i+1;
		LL k=j*j*j;
		j=i*i*i;
		while(now+j<=m&&now+j<k){
			now+=j,cnt++;
			LMin.PB(MP(now,cnt));
		}
	}
	while(cin>>m){
		pair<LL,int>ans=playMax(m);
		cout<<ans.BB<<" "<<ans.AA<<"\n";
	}
	return 0;
}