const int MXN = 3000000+5;
int mu[MXN], p[MXN], pn;
bool flag[MXN];	//true为合数
//for(inv[1]=1,i=2;i<10000;i++)inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;//MOD is prime
void sieve(int n) {
	pn = 0;
	mu[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!flag[i]) {
			p[pn ++ ] = i;
			mu[i] = -1;						//phi[i]=i-1;
		}
		for (int j = 0; j < pn && i * p[j] <= n; j++) {
			flag[i * p [j]] = true;
			if (i % p[j] == 0) {
				mu[i * p[j]] = 0;			//phi[i * p[j]] = p[j] * phi[i];
				break;
			} else  mu[i * p[j]] = -mu[i];	//phi[i * p[j]] = (p[j] - 1) * phi[i];
		}
	}
	// flag[1]=0;
	// rep(i,2,n+1)flag[i]=flag[i-1]+(!flag[i]);
}
// gao = Calculate how many primes between [1...n]!
LL f[10005][627];//memset(f,-1,sizeof f);
LL play(LL m,LL n){
	if(n==0)return m;
	if(m<=10000){
		if(f[m][n]!=-1)return f[m][n];
		return f[m][n]=play(m,n-1)-play(m/p[n-1],n-1);
	}
	//if(m>4000)cout<<m<<","<<n<<"\n";
	return play(m,n-1)-play(m/p[n-1],n-1);
}
LL gao(LL m){
	if(m<=MXN-5)
		return flag[m];
	LL _3=pow(1.*m,1./3)-1;
	_3=max(_3,0LL);
	while(_3*_3*_3<=m)_3++;_3--;
	LL _2=sqrt(1.*m)-1;
	_2=max(_2,0LL);
	while(_2*_2<=m)_2++;_2--;
	LL n=flag[_3],u=flag[_2]-n;
	LL ans=play(m,n)+n*(u+1)+u*(u-1)/2-1;
	rep(k,1,u+1)
		ans-=gao(m/p[n+k-1]);
	return ans;
}