#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

using namespace std;

const double eps = 1e-8;
const int MOD = 1000000007;
#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(X) sort(X.OP,X.ED)
#define SQ(x) ((x)*(x))
typedef long long LL;
typedef pair<int, int> PII;
LL a,b,w,x,c;
int check(LL P){
	LL A=a,B=b,W=w,X=x,C=c;
	B+=P*(W-X);
	B-=(C-A-1)*X;
	if(B>=X)return 0;
	else return 1;
}
void brute(){
	LL A=a,B=b,W=w,X=x,C=c;
	int t=0;
	while(C>A){
		if(B>=X)C--,B-=X;
		else B+=W-X;
		t++;
	}
	cout<<t<<endl;
}
void solve(){
	int i,j;
	while(cin>>a>>b>>w>>x>>c){
//		brute();
		LL t=0;
		LL l=0,r=5555LL*c,k;
		while(r>=l){
			if(r-l<=1){
				if(check(r))k=r;
				else k=l;
				break;
			}
			LL mid=(l+r)/2;
			if(check(mid))l=mid;
			else r=mid-1;
		}
		b+=k*(w-x);
		t+=k;
		while(c>a){
			if(b>=x)c--,b-=x;
			else b+=w-x;
			t++;
			if(b>=x){
				int add=(b-x-1)/x;
				if(add<0)continue;
				if(c-add<a)add=c-a;
				c-=add;
				t+=add;
				b-=add*x;
			}
		}
		cout<<t<<endl;
	}
}
int main(){
//	while(1)
		solve();
	return 0;
}
//a b w x c
/*
1 998 1000 1 2000
1 2 1000 1 2000
1 998 1000 997 2000
1 2 3 1 2000
4 2 3 1 6
4 2 3 1 7
1 2 3 2 6
1 1 2 1 1
*/
