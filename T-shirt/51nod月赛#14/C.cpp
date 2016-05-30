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
long long read(){
	long long ans=0;
	char last=' ',ch=getchar();
	while(ch<'0' || ch>'9')last=ch,ch=getchar();
	while(ch>='0' && ch<='9')ans=ans*10+ch-'0',ch=getchar();
	if(last=='-')ans=-ans;
	return ans;
}
inline int LB(int x) {return x & (-x);}
struct BIT {
	LL _[100015];
	int n;
	void init(int m) {
		n = m + 5;
		for (int i = 0; i <= n; i++)_[i] = 0;
	}
	LL query(int w) {
		LL ret = 0;
		for (w += 3; w > 0; w -= LB(w))ret += _[w];
		return ret;
	}
	void update(int w, LL d) {
		for (w += 3; w < n; w += LB(w))_[w] += d;
	}
};
LL a[100005];
LL S[100005];
int n;
LL check(LL mid){
	vector<LL>Z;
	for(int i=0;i<=n;++i)
		Z.PB(S[i]-mid*i);
	sort(Z.OP,Z.ED);
	Z.erase(unique(Z.OP,Z.ED),Z.ED);
	BIT Y;
	Y.init(Z.SZ+1);
	LL sum=0;
	for(int i=0;i<=n;i++){
		int id=lower_bound(Z.OP,Z.ED,S[i]-mid*i)-Z.OP;
		sum+=Y.query(id);
		Y.update(id,1);
		//cout<<id<<"?";
	}
	//cout<<sum<<"\n";
	return sum;
}
int main(){
	int i,j,_T;
	n=read();
	LL m=read();
	for(i=1;i<=n;i++)
		a[i]=read()*1000;
	for(S[0]=0,i=1;i<=n;i++)
		S[i]=S[i-1]+a[i];
	LL re=*max_element(a+1,a+n+1);
	LL le=*min_element(a+1,a+n+1);
	while(re>le){
		if(re-le<=1){
			if(check(le)>=m)re=le;
			else le=re;
			break;
		}
		//cout<<le<<"~"<<re<<"\n";
		LL mid=(re+le)/2;
		LL fm=check(mid);
		if(fm>=m)le=mid;
		else re=mid;
	}
	printf("%.4f\n",(le+re)/2000.);
	return 0;
}