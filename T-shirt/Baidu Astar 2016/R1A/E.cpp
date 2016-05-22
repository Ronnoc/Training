#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<iostream>
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

LL f(int id,LL x){
	//cout<<"?"<<id<<" "<<x<<"\n";
	if(id==1){
		return x==1;
	}
	if(x==(1LL<<id)-1){
		return (1LL<<(id-1));
	}
	int t=id-1;
	LL ct=(1LL<<t)-1;
	LL ret;
	if(x>ct){
		//ct 1 ct
		if(x==ct+1)ret=f(t,x-1)+1;
		else {
			LL y=f(t,ct-(x-ct-1));
			ret=f(t,ct)+1+(ct/2)-(ct-(x-ct-1)-y);
		}
	}else ret=f(t,x);
	//cout<<id<<" "<<x<<" "<<ret<<"\n";
	return ret;
}
int main(){
	int i,j,k,_T;
	scanf("%d",&_T);
	for(int CA=1;CA<=_T;CA++){
		LL le,re;
		cin>>le>>re;
		int id=1;
		while((1LL<<id)-1<=re)
			id++;
		cout<<f(id,re)-f(id,le-1)<<"\n";
	}
	return 0;
}