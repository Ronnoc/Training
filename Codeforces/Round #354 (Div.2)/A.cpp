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
	int n;
	while(~scanf("%d",&n)){
		int le=-1,re=-1;
		for(i=1;i<=n;i++){
			scanf("%d",&j);
			if(j==1)le=i;
			if(j==n)re=i;
		}
		int ret=0;
		if(le<n)cmax(ret,n-le);
		if(re<n)cmax(ret,n-re);
		if(le>1)cmax(ret,le-1);
		if(re>1)cmax(ret,re-1);
		cout<<ret<<"\n";
	}
	return 0;
}