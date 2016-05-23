const int MXN = 10000000+5;
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
}