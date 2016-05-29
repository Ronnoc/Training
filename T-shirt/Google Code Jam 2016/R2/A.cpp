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
string play(char c,int n){
	string ret;
	if(n==0){
		ret=c;
		return ret;
	}
	string s1,s2;
		if(c=='R'){s1=play('R',n-1),s2=play('S',n-1);}
		if(c=='P'){s1=play('R',n-1),s2=play('P',n-1);}
		if(c=='S'){s1=play('P',n-1),s2=play('S',n-1);}
	return min(s1+s2,s2+s1);
}
bool check(string ss,int r,int p,int s){
	for(auto c:ss){
		if(c=='R')r--;
		if(c=='P')p--;
		if(c=='S')s--;
	}
	return !r&&!p&&!s;
}
void solve(){
	int n,r,p,s;
	scanf("%d%d%d%d",&n,&r,&p,&s);
	string ss;
	ss=play('R',n);
	if(check(ss,r,p,s)){
		cout<<ss<<"\n";
		return;
	}
	ss=play('P',n);
	if(check(ss,r,p,s)){
		cout<<ss<<"\n";
		return;
	}
	ss=play('S',n);
	if(check(ss,r,p,s)){
		cout<<ss<<"\n";
		return;
	}
	cout<<"IMPOSSIBLE\n";
}
int main(){
	int i,j,k,_T;
	scanf("%d",&_T);
	for(int CA=1;CA<=_T;CA++){
		printf("Case #%d: ",CA);
		solve();
	}
	return 0;
}