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
LL c[1000005];
LL f[1000005];
void out(LL t){
	if(t>9)out(t/10);
	putchar(t%10+'0');
}
int main(){
	int i,j,k,_T;
	int n,q;
	n=read();
	q=read();
	for(int i=1;i<=n;i++)
		for(j=i;j<=n;j+=i)f[j]++;
	while(q--){
		int iq,x,y;
		iq=read();
		if(iq==1){
			x=read();
			y=read();
			for(i=x,j=1;i<=n;i+=x,j++)
				c[i]+=f[j]*y;
		}else {
			x=read();
			LL t=c[x];
			out(t);
			puts("");
		}
	}
	return 0;
}