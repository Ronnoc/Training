#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
LL read(){
	LL ans=0;
	char last=' ',ch=getchar();
	while(ch<'0' || ch>'9')last=ch,ch=getchar();
	while(ch>='0' && ch<='9')ans=ans*10+ch-'0',ch=getchar();
	if(last=='-')ans=-ans;
	return ans;
}
void out(LL t){
	if(t>9)out(t/10);
	putchar(t%10+'0');
}
LL modPow(LL a,LL b){
	LL ret=1;
	while(b){
		if(b&1)ret=ret*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return ret;
}
const int MXN = 10000000+5;
int mu[MXN], p[666666], pn;
void sieve(int n) {
	pn = 0;
	mu[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!mu[i]) {
			p[pn ++ ] = i;
			mu[i] = i;
		}
		for (int j = 0; j < pn && i * p[j] <= n; j++) {
			mu[i * p[j]] = p[j];
			if (i % p[j] == 0) 
				break;
		}
	}
}
int cl[MXN],cr[MXN];
inline void check(int &a,int mod){
	if(a>=mod)a-=mod;
}
int main(){
	int i,j,k;
	LL x0,m,a,b,c;
	LL x,le,re;
	m=read();x0=read();
	a=read();b=read();c=read();
	int *last=cr;
	for(i=1;i<=c;i++)last[i]=-1;
	x=x0;
	for(i=0;;i++){
		if(last[x]==-1)
			last[x]=i;
		else {
			le=last[x];
			re=i;
			break;
		}
		x=(a*x+b)%c+1;
	}
	for(i=1;i<=c;i++)last[i]=0;
	x=x0;
	for(i=0;i<le&&m>0;i++){
		cl[x]++,cr[x]++,m--;
		x=(a*x+b)%c+1;
	}
	if(m){
		LL turn=m/(re-le);
		LL tl=turn%MOD;
		LL tr=turn%(MOD-1);
		m%=re-le;
		for(i=le;i<re;i++){
			cl[x]+=tl;
			cr[x]+=tr;
			if(m)cl[x]++,cr[x]++,m--;
			x=(a*x+b)%c+1;
		}
	}
	sieve(c);
	LL ans=1;
	for(i=c;i>=2;i--)if(cl[i]+cr[i]){
		int p=mu[i],q=i/p;
		if(p<i){
			cl[p]+=cl[i];
			check(cl[p],MOD);
			cl[q]+=cl[i];
			check(cl[q],MOD);
			cr[p]+=cr[i];
			check(cr[p],MOD-1);
			cr[q]+=cr[i];
			check(cr[q],MOD-1);
		}else {
			ans=modPow(p,cr[p]%(MOD-1))*(cl[p]+1)%MOD*ans%MOD;
		}
	}
	out(ans);
	puts("");
	return 0;
}