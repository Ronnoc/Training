**1 划分数**
>n划分为K个自然数的和的方案数<br>
>验题:hdu4651

	LL dp[100010];
	void partition( int n ) {
		int i,j,r;
		for ( dp[0]=1,i=1; i<=n; i++ ) {
			dp[i]=0;
			for ( j=1,r=1; i>=( 3*j*j-j )/2; j++,r*=-1 ) {
				dp[i]+=dp[i-( 3*j*j-j )/2]*r;
				if ( i>=( 3*j*j+j )/2 )
					dp[i]+=dp[i-( 3*j*j+j )/2]*r;
				dp[i]=dp[i]%MOD+MOD;
			}
		}
	}

>验题:hdu4658

	int get( int n,int k ) {	//all parts are repeated less than k times.
		LL ret=dp[n];			//<==>all parts are less than k
		for ( int j=1,r=-1; n>=k*( 3*j*j-j )/2; j++,r*=-1 ) {
			ret+=dp[n-k*( 3*j*j-j )/2]*r;
			if ( n>=k*( 3*j*j+j )/2 )
				ret+=dp[n-k*( 3*j*j+j )/2]*r;
			ret=ret%MOD+MOD;
		}
		return ret%MOD;
	}

**2 Polya 原理**
>验题:未验

	//perm[0..n-1]为0..n-1的一个置换(排列)
	//返回置换最小周期,num返回循环节个数
	int polya (int* perm, int n, int& num) {
		int i, j, p, v[MXN] = {0}, ret = 1;
		for (num = i = 0; i < n; i++)if (!v[i]) {
				for (num++, j = 0, p = i; !v[p = perm[p]]; j++)
					v[p] = 1;
				ret *= j / __gcd (ret, j);
			}
		return ret;
	}

**3 高斯消元**
>验题:hdu4870

	//全主元gauss消去解a[][]x[]=b[],返回是否有唯一解,若有解在b[]中
	#define MXN 300
	#define fabs(x) ((x)>0?(x):-(x))
	double a[MXN][MXN],b[MXN];
	int index[MXN];
	int gauss_tpivot(int m,int n) {
		int i, j, k, row, col;
		double maxp, t;
		for(i = 0; i < m; i++)index[i] = i;
		for(k = 0; k < n; k++) {
			for(maxp = 0, i = k; i < m; i++)
				for(j = k; j < n; j++)
					if(fabs(a[i][j]) > fabs(maxp))
						maxp = a[row = i][col = j];
			if(fabs(maxp) < eps)
				return 0;
			if(col != k) {
				for(i = 0; i < m; i++)
					swap(a[i][col],a[i][k]);
				swap(index[col],index[k]);
			}
			if(row != k) {
				for(j = k; j < n; j++)
					swap(a[k][j],a[row][j]);
				swap(b[k],b[row]);
			}
			for(j = k + 1; j < n; j++) {
				a[k][j] /= maxp;
				for(i = k + 1; i < m; i++)
					a[i][j] -= a[i][k] * a[k][j];
			}
			b[k] /= maxp;
			for(i = k + 1; i < m; i++)
				b[i] -= b[k] * a[i][k];
		}
		for(i = n - 1; i >= 0; i--)
			for(j = i + 1; j < n; j++)
				b[i] -= a[i][j] * b[j];
		for(k = 0; k < n; k++)
			a[0][index[k]] = b[k];
		for(k = 0; k < n; k++)
			b[k] = a[0][k];
		return 1;
	}
>验题: poj2345

	#define MXN 300
	int idx[MXN];
	LL a[MXN][MXN],b[MXN];
	int gaussTpivotMod(int m,int n,int mod=2) {//mod 下高斯消
		int i,j,k,row,col;
		LL maxp,t;
		int ret=1;
		for(i=0; i<m; i++)idx[i]=i;
		for(k=0; k<n; k++) {
			for(maxp=0,i=k; i<m; i++)
				for(j=k; j<n; j++)
					if(a[i][j]>maxp)
						maxp=a[row=i][col=j];
			if(maxp==0) {
				bool fail=0;
				for(i=k;i<m;i++)if(b[i])fail=1;
				if(fail)return 0;
				ret=k-n;
				break;
			}
			if(col!=k)for(swap(idx[col],idx[k]),i=0; i<m; i++)
					swap(a[i][col],a[i][k]);
			if(row!=k)for(swap(b[k],b[row]),j=k; j<n; j++)
					swap(a[k][j],a[row][j]);
			LL inv=modInv(maxp,mod);
			for(i=k+1; i<m; i++) {
				LL mul=inv*a[i][k];
				for(j=k; j<n; j++)
					a[i][j]-=a[k][j]*mul;
				b[i]-=mul*b[k];
			}
			for(i=k; i<m; i++)
				for(j=k; j<n; j++) {
					LL &tmp=a[i][j];
					if(tmp>=mod)tmp%=mod;
					if(tmp<0)tmp=tmp%mod+mod;
				}
		}
		for(i=n-1;i>=0;i--)
			for(j=i+1;j<n;j++)
				b[i]-=a[i][j]*b[j];
		for(k=0;k<n;k++)
			a[0][idx[k]]=b[k];
		for(k=0;k<n;k++)
			b[k]=(a[0][k]%mod+mod)%mod;
		return ret;
	}

**4 FFT**
>验题:NEERC 2013 Eastern subregional G

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
>验题: hdu2979

	const int MVar = 444, MEqa = 444;
	long double a[MEqa][MVar];
	int idx[MVar],nv,ne;
	int nxt[MVar];//-a[0][0]=max ∑a[0][i]*x[i]
	void show() {
		int i,j;
		for ( i=0; i<=ne; i++ ) {
			printf( "%d[%d]%3.5lf=\t",i,idx[i],a[i][0] );
			for ( j=1; j<=nv; j++ )if(abs(a[i][j])>eps)printf( "%3.5lf*x[%d] ",a[i][j],j );
			printf( "\n" );
		}
		printf( "\n" );
	}
	void pivot( int e,int v ) {
		int i,j;
		long double temp;
		int tp=MVar-1;
		for ( j=nv; j>=0; j-- )nxt[j]=-1;
		for ( j=nv; j>=0; j-- )if ( abs( a[e][j] )>eps ) {nxt[tp]=j; tp=j;}
		temp=a[e][v];
		for ( tp=nxt[MVar-1]; tp!=-1; tp=nxt[tp] )a[e][tp]/=temp;
		for ( i=0; i<=ne; i++ )if ( abs( a[i][v] )>eps&&i!=e ) {
				temp=a[i][v];
				for ( tp=nxt[MVar-1]; tp!=-1; tp=nxt[tp] )
					a[i][tp]-=temp*a[e][tp];
			}
		idx[e]=v;
	}
	int dualsolve() {
		int i,j;
		long double temp;
		for ( j=1; j<=nv; j++ )if ( a[0][j]<-eps )return 0;
		while ( 1 ) {
			int l=0,r=0;
			temp=-eps;
			for ( i=1; i<=ne; i++ )if ( a[i][0]<temp )temp=a[i][0],r=i;
			if ( !r )return 1;
			temp=1e100;
			for ( j=1; j<=nv; j++ )if ( a[r][j]<-eps&&a[0][j]/a[r][j]<temp )
					temp=a[0][j]/a[r][j],l=j;
			if ( !l )return 0;
			pivot( r,l );
		}
	}
	int solve() {
		int i,j;
		long double temp;
		for ( i=1; i<=ne; i++ )if ( abs( a[0][idx[i]] )>eps ) {
				temp=a[0][idx[i]];
				for ( j=0; j<=nv; j++ )a[0][j]-=temp*a[i][j];
			}
		int dual=0;
		for ( i=1; i<=ne; i++ )if ( a[i][0]<-eps )dual=1;
		if ( dual ) {
			int dual=dualsolve();
			if ( !dual )return 0;	//no solution
		}
		while ( 1 ) {
			int l=0,r=0;
			temp=1e100;
			for ( j=1; j<=nv; j++ )if ( a[0][j]>eps ) {l=j; break;}
			if ( !l )return 1;		//done
			for ( i=1; i<=ne; i++ )if ( a[i][l]>eps&&a[i][0]+eps<a[i][l]*temp )
					temp=a[i][0]/a[i][l],r=i;
			if ( !r )return -1;		//infinite
			pivot( r,l );
		}
	}

			
**6 阶乘最后非零位**
>验题: hdu1066

	//求阶乘最后非零位,复杂度O(nlogn),返回该位,n以字符串方式传入 MAXN cstring
	int lastdigit(char* buf){
		const int mod[20]={1,1,2,6,4,2,2,4,2,8,4,4,8,4,6,8,8,6,8,2};
		int len=strlen(buf),a[MAXN],i,c,ret=1;
		if (len==1)
			return mod[buf[0]-'0'];
		for (i=0;i<len;i++)
			a[i]=buf[len-1-i]-'0';
		for (;len;len-=!a[len-1]){
			ret=ret*mod[a[1]%2*10+a[0]]%5;
			for (c=0,i=len-1;i>=0;i--)
				c=c*10+a[i],a[i]=c/5,c%=5;
		}
		return ret+ret%2*5;
	}