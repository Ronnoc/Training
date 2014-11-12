#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <bitset>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define OP begin()
#define BG begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
PII z[100005];
LL p[100005];
vector<int>A,B;
void update(PII &A,PII B){
	if(B.AA>A.AA)A=B;
	else if(B.AA==A.AA)
		cmin(A.BB,B.BB);
}
PII query(int len,int sum){
	if(len<=0)return MP(0,0);
	if(p[len]<=sum)return MP(len,p[len]);
	int id=upper_bound(p,p+len+1,sum)-p-1;
	return MP(id,p[id]);
}
int main() {
	int i,j;
	int n,m,CA=0,_T;
	scanf("%d",&_T);
	while(_T--) {
		scanf("%d%d",&n,&m);
		for(i=0; i<n; i++)scanf("%d%d",&z[i].AA,&z[i].BB);
		sort(z,z+n);
		A.clear(),B.clear();
		int tot=0;
		for(i=0; i<n; i++)
			if(z[i].BB)B.PB(z[i].AA),tot+=z[i].BB-1;
			else A.PB(z[i].AA);
		p[0]=0;
		for(i=0;i<A.SZ;i++)
			p[i+1]=p[i]+A[i];
		PII Ans=query(A.SZ,m);
		LL use=0;
		for(i=1;i<=B.SZ;i++){
			use+=B[i-1];
			if(use>m)break;
			//tot+i
			PII tp=query(A.SZ-tot-i,m-use);
			tp.AA+=min((int)A.SZ,tot+i);
			tp.AA+=B.SZ;
			tp.BB+=use;
			update(Ans,tp);
		}
		printf("Case %d: %d %d\n",++CA,Ans.AA,Ans.BB);
	}
	return 0;
}

