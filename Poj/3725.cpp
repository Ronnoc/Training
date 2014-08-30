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
#include <cassert>
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
const double PI=acos( -1. );
const LL MOD = 1000000007;

LL ten[33];
string gao(LL a){
	string ret="";
	while(a){
		ret+=a%10+'0';
		a/=10;
	}
	reverse(ret.OP,ret.ED);
	return ret;
}
LL meet(LL p,LL q,LL a,LL b){
	p=max(p,a),q=min(q,b);
	if(q>=p)return q-p+1;
	return 0;
}
LL getid(LL m,LL a){//[1,a]<m? a>=m
	LL ret=0;
	int i,j=0,k;
	for(i=1;ten[i]<=m;i++);
	while((--i)>=1)
		ret+=m/ten[i]-(ten[j++]-1);
	LL pe=ten[j],qe=m;
	while(meet(pe,qe-1,1,a)){
		ret+=meet(pe,qe-1,1,a);
		pe*=10,qe*=10;
	}
	return ret;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,n,m,u,v,T;
	for(ten[0]=1,i=1;i<=20;i++)ten[i]=ten[i-1]*10;
	while(~scanf("%d%d",&k,&m)){
		LL l=m,r=1LL<<60,ans=0;
		k--;
		while(r>=l){
			if(r-l<=1){
				if(getid(m,l)==k)ans=l;
				else if(getid(m,r)==k)ans=r;
				break;
			}
			LL mid=(l+r)>>1;
			if(getid(m,mid)>=k)r=mid;
			else l=mid;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
