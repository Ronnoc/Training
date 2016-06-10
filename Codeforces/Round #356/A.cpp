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
int main(){
	int i,j,k,_T;
	set<int>S;
	for(i=2;i<=100;i++)
		S.insert(i);
	int rem=20;
	while(rem--&&S.SZ>1){
		int cnt=0,ask=-1;
		for(int x=2;x<=100;x++){
			int now=0;
			for(auto y:S){
				if(y%x==0)now++;
			}
			if(now*(S.SZ-now)>cnt*(S.SZ-cnt))ask=x,cnt=now;
		}
		if(ask==-1)break;
		cout<<ask<<"\n";
		fflush(stdout);
		char s[15];
		scanf("%s",s);
		set<int>SS;
		if(strlen(s)==3){
			for(auto x:S)
				if(x%ask==0)SS.insert(x);
		}else {
			for(auto x:S)
				if(x%ask!=0)SS.insert(x);
		}
		S=SS;
	}
	int flag=0;
	for(auto x:S){
		for(j=2;j*j<=x;j++)
			if(x%j==0)flag=1;
	}
	if(flag)puts("composite");
	else puts("prime");
	return 0;
}