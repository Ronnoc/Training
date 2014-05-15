**1 分割数**
>n划分为K个自然数的方案数<br>
>验题:未验

	int dp[MAX_N];
	int partition (int n) {
		dp[0]=1;
		for (int i=1; i<=n; i++) {
			for (int j=1,r=1; i- (3*j*j-j) /2>=0; j++,r*=-1) {
				dp[i]+=dp[i- (3*j*j-j) /2]*r;
				if (i- (3*j*j+j) /2>=0)
					dp[i]+=dp[i- (3*j*j+j) /2]*r;
			}
		}
		return dp[n];
	}


**2 Polya 原理**
>验题:未验

	//perm[0..n-1]为0..n-1的一个置换(排列)
	//返回置换最小周期,num返回循环节个数
	#define MAXN 1000
	//gcd need
	int polya (int* perm, int n, int& num) {
		int i, j, p, v[MAXN] = {0}, ret = 1;
		for (num = i = 0; i < n; i++)
			if (!v[i]) {
				for (num++, j = 0, p = i; !v[p = perm[p]]; j++)
					v[p] = 1;
				ret *= j / gcd (ret, j);
			}
		return ret;
	}
**3 高斯消元**
>验题:未验

	//全主元gauss消去解a[][]x[]=b[]
	//返回是否有唯一解,若有解在b[]中
	#define MAXN 100
	#define fabs(x) ((x)>0?(x):-(x))
	#define eps 1e-10
	int gauss_tpivot (int n, double a[][MAXN], double b[]) {
		int i, j, k, row, col, index[MAXN];
		double maxp, t;
		for (i = 0; i < n; i++)
			index[i] = i;
		for (k = 0; k < n; k++) {
			for (maxp = 0, i = k; i < n; i++)
				for (j = k; j < n; j++)
					if (fabs (a[i][j]) > fabs (maxp))
						maxp = a[row = i][col = j];
			if (fabs (maxp) < eps)
				return 0;
			if (col != k) {
				for (i = 0; i < n; i++)
					t = a[i][col], a[i][col] = a[i][k], a[i][k] = t;
				j = index[col], index[col] = index[k], index[k] = j;
			}
			if (row != k) {
				for (j = k; j < n; j++)
					t = a[k][j], a[k][j] = a[row][j], a[row][j] = t;
				t = b[k], b[k] = b[row], b[row] = t;
			}
			for (j = k + 1; j < n; j++) {
				a[k][j] /= maxp;
				for (i = k + 1; i < n; i++)
					a[i][j] -= a[i][k] * a[k][j];
			}
			b[k] /= maxp;
			for (i = k + 1; i < n; i++)
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

**4 FFT**
>验题:未验

	int revv (int x,int mask) {
		int ret=0;
		for (int i=0; i<mask; i++) {
			ret<<=1;
			ret|=x&1;
			x>>=1;
		}
		return ret;
	}
	void fft (double * rl, double * ig, int n, bool sign) {
		int d=0;
		while ( (1<<d) <n) ++d;
		for (int i=0; i<n; i++) {
			int j=revv (i,d);
			if (i<j) swap (rl[i],rl[j]),swap (ig[i],ig[j]);
		}
		for (int m=2; m<=n; m<<=1) {
			int mh=m>>1;
			double _wr=cos (2*PI/m),_wi=sin (2*PI/m);
			if (sign) _wi*=-1.0;
			for (int i=0; i<n; i+=m) {
				double wr=1,wi=0;
				for (int j=i; j<mh+i; j++) {
					int k=j+mh;
					double er=rl[k]*wr-ig[k]*wi;
					double ei=rl[k]*wi+ig[k]*wr;
					double cr=rl[j],ci=ig[j];
					rl[j]+=er,ig[j]+=ei;
					rl[k]=cr-er,ig[k]=ci-ei;
					double qr=wr*_wr-wi*_wi;
					double qi=wr*_wi+wi*_wr;
					wr=qr,wi=qi;
				}
			}
		}
		if (sign) for (int i=0; i<n; i++)
				rl[i]/=n,ig[i]/=n;
	}
	double ax[222222],ay[222222];
	double bx[222222],by[222222];
	double ansx[222222],ansy[222222];
	int fftmultiply (int *a,int la,int *b,int lb,int *ans) {
		int lans=max (la,lb),ln=0,i;
		while ( (1<<ln) <lans) ++ln;
		lans=2<<ln;
		for (i=0; i<lans; i++)
			ax[i]=i<la?a[i]:0,ay[i]=0;
		fft (ax,ay,lans,0);
		for (i=0; i<lans; i++)
			bx[i]=i<lb?b[i]:0,by[i]=0;
		fft (bx,by,lans,0);
		for (i=0; i<lans; i++) {
			ansx[i]=ax[i]*bx[i]-ay[i]*by[i];
			ansy[i]=ax[i]*by[i]+ay[i]*bx[i];
		}
		fft (ansx,ansy,lans,1);
		for (i=0; i<lans; i++)
			ans[i]=ansx[i]+0.5;
		return lans;
	}

**5 单纯形**
>验题:未验

	#define rep(i,l,n) for(int i = l; i <= n; i++)
	const int MAXR = 300, MAXC = 500, inf = ( ~0U )>>2;
	int n, m, a[MAXR][MAXC], next[MAXC], s, t, c;
	inline void orz( int l, int e ) {
		a[l][e] = -1;
		t = MAXC - 1;
		rep( i,0,m ) if ( a[l][i] ) next[t] = i, t = i;
		next[t] = -1;
		rep( i,0,n ) if ( i != l && ( t = a[i][e] ) ) {
			a[i][e] = 0;
			for ( int j = next[MAXC - 1]; j != -1; j = next[j] ) a[i][j] += a[l][j] * t;
		}
	}
	int solve( void ) {
		for ( ;; ) {
			int min = inf, l = 0, e = 0;
			rep( i,1,m ) if ( a[0][i] > 0 ) {e = i; break;}
			if ( !e ) return a[0][0];
			rep( i,1,n ) if ( a[i][e] < 0 && a[i][0] < min ) min = a[i][0], l = i;
			orz( l,e );
		}
	}
	/*scanf( "%d%d", &m, &n );						//m个方程,n个变量
		rep( j,1,m ) scanf( "%d", &a[0][j] );		//第j个方程左端 隐含标准化变元
		rep( i,1,n ) {
			scanf( "%d%d%d", &s, &t, &c );
			rep( j,s,t ) a[i][j] = -1; 				//a[0][j]+sigma{a[i][j]*x[i]}<=0;
			a[i][0] = c;							//最小化z中的x[i]系数
		}*/
