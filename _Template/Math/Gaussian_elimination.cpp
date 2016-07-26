//高斯消元
//>验题:hdu4870

#define MXN 300
#define fabs(x) ((x)>0?(x):-(x))
double a[MXN][MXN], b[MXN];
int index[MXN];
int gauss_tpivot(int m, int n) {
	int i, j, k, row, col;
	double maxp, t;
	for (i = 0; i < m; i++)index[i] = i;
	for (k = 0; k < n; k++) {
		for (maxp = 0, i = k; i < m; i++)
			for (j = k; j < n; j++)
				if (fabs(a[i][j]) > fabs(maxp))
					maxp = a[row = i][col = j];
		if (fabs(maxp) < eps)
			return 0;
		if (col != k) {
			for (i = 0; i < m; i++)
				swap(a[i][col], a[i][k]);
			swap(index[col], index[k]);
		}
		if (row != k) {
			for (j = k; j < n; j++)
				swap(a[k][j], a[row][j]);
			swap(b[k], b[row]);
		}
		for (j = k + 1; j < n; j++) {
			a[k][j] /= maxp;
			for (i = k + 1; i < m; i++)
				a[i][j] -= a[i][k] * a[k][j];
		}
		b[k] /= maxp;
		for (i = k + 1; i < m; i++)
			b[i] -= b[k] * a[i][k];
	}
	for (i = n - 1; i >= 0; i--)
		for (j = i + 1; j < n; j++)
			b[i] -= a[i][j] * b[j];
	for (k = 0; k < n; k++)
		a[0][index[k]] = b[k];
	for (k = 0; k < n; k++)
		b[k] = a[0][k];
	return 1;
}

#define rep(i,a,n) for(int i=(a);i<(int)(n);i++)
#define MXN 333
int idx[MXN];
LL a[MXN][MXN], b[MXN];
LL extGcd (LL a, LL b, LL &x, LL &y) {
    LL ret = a;
    if (b) {
        ret = extGcd (b, a % b, y, x);
        y -= (a / b) * x;
    } else x = 1, y = 0;
    return ret;
}
LL modInv (LL a, LL m) {
    LL x, y;
    extGcd(a, m, x, y);
    return (m + x % m) % m;
}

void fit(LL &a,LL mod){a=(a%mod+mod)%mod;}
pair<LL,LL>singleMod(LL A,LL B,LL M){
	LL d = __gcd( M, A );
	if ( B % d )return MP( 0, -1 );
	LL m = M / d;
	LL t = B / d * modInv( A / d, m ) % m;
	return MP( ( ( t % m ) + m ) % m, m );
}
int gaussTpivotMod(int m, int n, LL mod) { //mod 下高斯消
    int ret = 0,fail = 0;
    rep(i,0,m){
        idx[i]=i;
        fit(b[i],mod);
        rep(j,0,n)fit(a[i][j],mod);
    }
    rep(k,0,n){
        LL maxp=0;int row,col;
        rep(i,k,m)rep(j,k,n)if(maxp==0)
            maxp=a[row=i][col=j];
        if(maxp==0){
            rep(i,k,m)fail|=b[i]!=0;
            if(fail)return -1;
            ret=n-k;
            break;
        }
        swap(idx[col],idx[k]);
        rep(i,0,m)swap(a[i][col],a[i][k]);
        swap(b[k], b[row]);
        rep(j,k,n)swap(a[k][j], a[row][j]);
        rep(i,k+1,m){
            while(a[i][k]){
                if(a[i][k]<a[k][k]){
                    swap(b[k],b[i]);
                    rep(j,0,n)swap(a[k][j], a[i][j]);
                }
                LL cnt=a[i][k]/a[k][k];
                rep(j,0,n)a[i][j]-=cnt*a[k][j];
                b[i]-=cnt*b[k];
                rep(j,0,n)fit(a[i][j],mod);
                fit(b[i],mod);
            }
        }
    } 
    for (int i = n - 1; i >= 0; i--){
    	rep(j,i+1,n)
        	b[i] -= a[i][j] * b[j];
        if(a[i][i])
        	b[i]=singleMod(a[i][i],b[i],mod).AA;
    }
    rep(k,0,n)a[0][idx[k]] = b[k];
    rep(k,0,n)b[k]=a[0][k];
    rep(k,0,n)fit(b[k],mod);
    return ret;
}