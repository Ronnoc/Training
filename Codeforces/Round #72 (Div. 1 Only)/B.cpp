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
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps=1e-8;
const double INF=1e20;
const double PI=acos( -1. );
const int MXN = 50;
const LL MOD = 1000000007;
LL a[111111];
map<LL,int>S;
map<LL,int>::iterator it;
LL n,k;
LL check(LL t){
	LL all=0;
	for(it=S.OP;it!=S.ED;++it){
		if((*it).AA>=t)all+=t*((*it).BB);
		else all+=((*it).AA)*((*it).BB);
//		cout<<(*it).AA<<" ? "<<(*it).BB<<" "<<all<<endl;
	}
	return all;
}
int main() {
	int i,j;
	while ( cin>>n>>k ) {
		S.clear();
		LL tot=0,mx=-1;
		for ( i=1; i<=n; i++ ) {
			cin>>a[i];
			S[a[i]]++;
			tot+=a[i];
			cmax(mx,a[i]);
		}
		if(tot<k){
			cout<<-1<<endl;
			continue;
		}
		if(tot==k){
			continue;
		}
		LL l=0,r=mx;
		while ( r>=l ) {
			if ( r-l<=1 ) {
				if(check(r)<=k)l=r;
				break;
			}
			LL mid=(l+r)/2;
//			cout<<l<<"~"<<mid<<"~"<<r<<" "<<check(mid)<<endl;
			if(check(mid)<=k)l=mid;
			else r=mid;
		}
//		cout<<l<<endl;
		queue<pair<LL,int> >Q;
		for(i=1;i<=n;i++)
			if(a[i]>l)Q.push(MP(a[i]-l,i));
		k-=check(l);
		while(k--){
			if(Q.empty())while(1);
			pair<LL,int> tp=Q.front();
			Q.pop();
			if(tp.AA>1)Q.push(MP(tp.AA-1,tp.BB));
		}
		while(!Q.empty()){
			pair<LL,int> tp=Q.front();
			Q.pop();
			cout<<tp.BB<<" ";
		}
		cout<<endl;
	}
	return 0;
}
