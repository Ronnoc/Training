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
int w[300005];
LL S[300005];
int main(){
	int i,j,k,_T;
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		memset(w,0,sizeof w);
		vector<int>A;
		for(i=0;i<n;i++){
			scanf("%d",&j);
			A.PB(j);
			if(j<=300000)w[j]=1;
		}
		sort(A.OP,A.ED);
		S[0]=0;
		vector<int>L;
		for(i=1;i<=300000;i++){
			S[i]=S[i-1]+(w[i]?0:i);
			if(S[i]>m)break;
			if(!w[i])L.PB(i);
		}
		cout<<L.SZ<<"\n";
		for(i=0;i<L.SZ;i++)
			cout<<L[i]<<" ";
		cout<<"\n";
	}
	return 0;
}