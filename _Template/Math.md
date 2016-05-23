**1 划分数**
>n划分为K个自然数的和的方案数;验题:hdu4651

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
>验题:poj1286

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

	const int MXN = 1<<20;
	double ax[MXN],ay[MXN];
	double bx[MXN],by[MXN];
	double ansx[MXN],ansy[MXN];
	int revv(int x,int mask) {
		int ret=0;
		for(int i=0; i<mask; i++) {
			ret<<=1;
			ret|=x&1;
			x>>=1;
		}
		return ret;
	}
	void fft(double * rl, double * ig, int n, bool sign) {
		int d=0;
		while((1<<d) <n) ++d;
		for(int i=0; i<n; i++) {
			int j=revv(i,d);
			if(i<j) swap(rl[i],rl[j]),swap(ig[i],ig[j]);
		}
		for(int m=2; m<=n; m<<=1) {
			int mh=m>>1;
			double _wr=cos(2*PI/m),_wi=sin(2*PI/m);
			if(sign) _wi*=-1.0;
			for(int i=0; i<n; i+=m) {
				double wr=1,wi=0;
				for(int j=i; j<mh+i; j++) {
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
		if(sign) for(int i=0; i<n; i++)
				rl[i]/=n,ig[i]/=n;
	}
	int fftmultiply(int *a,int la,int *b,int lb,LL *ans) {
		int lans=max(la,lb),ln=0,i;
		while((1<<ln) <lans) ++ln;
		lans=2<<ln;
		for(i=0; i<lans; i++)
			ax[i]=i<la?a[i]:0,ay[i]=0;
		fft(ax,ay,lans,0);
		for(i=0; i<lans; i++)
			bx[i]=i<lb?b[i]:0,by[i]=0;
		fft(bx,by,lans,0);
		for(i=0; i<lans; i++) {
			ansx[i]=ax[i]*bx[i]-ay[i]*by[i];
			ansy[i]=ax[i]*by[i]+ay[i]*bx[i];
		}
		fft(ansx,ansy,lans,1);
		for(i=0; i<lans; i++)
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
		for ( i=1; i<=ne; i++ )for(k=0;k<=ne;k++)if (k!=i&& abs( a[k][idx[i]] )>eps ) {
				temp=a[k][idx[i]];
				for ( j=0; j<=nv; j++ )a[k][j]-=temp*a[i][j];
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

	
**6 自适应Simpson**
>验题:hdu4978

	long double simpson(long double a,long double b) {
		long double c=a+ (b-a) /2;
		return (f(a)+4*f(c)+f(b)) * (b-a) /6;
	}
	long double asr(long double a,long double b,long double eps,long double A) {
		long double c=a+ (b-a) /2;
		long double L=simpson(a,c),R=simpson(c,b);
		if(fabs(L+R-A) <15*eps) return L+R+ (L+R-A) /15.;
		return asr(a,c,eps/2,L)+asr(c,b,eps/2,R);
	}
	long double asr(long double a,long double b,long double eps) {
		return asr(a,b,eps,simpson(a,b));
	}

**7 无标号树计数**
>来自yh_victor的板子

	int solve(int k,int n,int p) {//无标号树计数
		int a[55],s[55][55],tmp,foo;
		a[1]=1;
		for(int j=1; j<n; j++) {
			a[j+1]=0;
			for(int i=1; i<=j; i++) {
				if(j-i<i) s[j][i]=a[j+1-i];
				else s[j][i]=(s[j-i][i]+a[j+1-i])%p;
				a[j+1]+=s[j][i]*i%p*a[i]%p;
			}
			foo=a[j+1]%p;
			extGcd(j,p,a[j+1],tmp);
			a[j+i]*=foo,tmp*=foo;
			if(a[j+1]>=0) a[j+1]%=p;
			else a[j+1]=p-(-a[j+1])%p;
		}
		if(k==1) {		//if无根树
			for(int i=1; i<=n/2; i++)a[n]=(a[n]+p-a[i]*a[n-i]%p)%p;
			if((n&1)==0) a[n]+=a[n/2]*(a[n/2]+1)/2;
		}
		return a[n]%p;
	}

**8 BigNum**
>EternalReality

	class BigNum {
	public:
			static const int MOD = 100000000;
			static const int BIT = 8, SIZE = 105;
			mutable int n,o;
			long long u[SIZE];
			BigNum(){}
			BigNum(const string& s){
					memset(this,0,sizeof(BigNum));
					int num=0,cnt=1;
					for(int i=s.size()-1;~i;i--){
							if(s[i]=='-') o^=1;
							if(s[i]>='0' && s[i]<='9'){
									num+=(s[i]-'0')*cnt;
									cnt*=10;
									if(cnt==MOD) u[n++]=num,num=0,cnt=1;
							}
					}
					if(!n || cnt>=10) u[n++]=num;
					if(!u[0] && n==1) o=0;
			}
			BigNum(long long x){
					memset(this,0,sizeof(BigNum));
					if(x<0) o=1,x=-x;
					do u[n++]=x%MOD; while(x/=MOD);
			}
			operator string() const {
					static char s[SIZE*BIT+10];
					char* c=s+sprintf(s,"%s%d",o?"-":"",int(u[n-1]));
					for(int i=n-2;~i;i--) c+=sprintf(c,"%0*d",BIT,int(u[i]));
					return s;
			}
			int operator [](int pos) const {
					static int e[BIT]={1};
					for(static int i=1;i<BIT;i++) e[i]=e[i-1]*10;
					return u[pos/BIT]/e[pos%BIT]%10;
			}
			int length() const {
					int ret=(n-1)*BIT+1;
					for(int x=u[n-1]/10;x;x/=10) ret++;
					return ret;
			}
			friend int cmp(const BigNum& l, const BigNum& r){
					if(l.o!=r.o) return (l.o?-1:1);
					if(l.n!=r.n) return (l.o?-1:1)*(l.n-r.n);
					for(int i=l.n-1;~i;i--) if(l.u[i]-r.u[i])
									return (l.o?-1:1)*(l.u[i]-r.u[i]);
					return 0;
			}
			// 运算符
			bool operator < (const BigNum& r) const {return cmp(*this,r)<0;}
			bool operator > (const BigNum& r) const {return cmp(*this,r)>0;}
			bool operator <=(const BigNum& r) const {return cmp(*this,r)<=0;}
			bool operator >=(const BigNum& r) const {return cmp(*this,r)>=0;}
			bool operator ==(const BigNum& r) const {return cmp(*this,r)==0;}
			bool operator !=(const BigNum& r) const {return cmp(*this,r)!=0;}
			BigNum operator +(const BigNum& r) const {return BigNum(*this)+=r;}
			BigNum operator -(const BigNum& r) const {return BigNum(*this)-=r;}
			BigNum operator *(int x) const {return BigNum(*this)*=x;}
			BigNum operator /(int x) const {return BigNum(*this)/=x;}
			BigNum& operator *=(const BigNum& r){return *this=*this*r;}
			BigNum& operator /=(const BigNum& r){return *this=*this/r;}
			BigNum& operator %=(const BigNum& r){return *this=*this%r;}
			BigNum& operator %=(int x){return *this=*this%x;}
			BigNum operator -() const {
					BigNum s=*this;
					if(s.u[0] || s.n>=2) s.o^=1;
					return s;
			}
			BigNum& operator +=(const BigNum& r){
					if(r.n==1 && !r.u[0]) return *this;
					if(r.o^o) return r.o^=1,*this-=r,r.o^=1,*this;
					if(r.n>n) n=r.n;
					for(int i=0;i<r.n;i++) u[i]+=r.u[i];
					for(int i=0;i<n;i++) if(u[i]>=MOD) u[i+1]++,u[i]-=MOD;
					if(u[n]) n++;
					return *this;
			}
			BigNum& operator -=(const BigNum& r){
					if(r.n==1 && !r.u[0]) return *this;
					if(r.o^o) return r.o^=1,*this+=r,r.o^=1,*this;
					if(cmp(*this,r)*(r.o?-1:1)<0){
							o^=1,n=r.n;
							for(int i=0;i<r.n;i++) u[i]=r.u[i]-u[i];
					}else{
							for(int i=0;i<r.n;i++) u[i]=u[i]-r.u[i];
					}
					for(int i=0;i<n;i++) if(u[i]<0) u[i+1]--,u[i]+=MOD;
					while(!u[n-1] && n>=2) --n;
					if(!u[0] && n==1) o=0;
					return *this;
			}
			BigNum operator *(const BigNum& r) const {
					BigNum s=0;
					if(!u[n-1] || !r.u[r.n-1]) return s;
					s.n=r.n+n-1;
					s.o=r.o^o;
					for(int i=0;i<n;i++) for(int j=0;j<r.n;j++)
							s.u[i+j]+=u[i]*r.u[j];
					for(int i=0;i<s.n;i++) if(s.u[i]>=MOD){
							s.u[i+1]+=s.u[i]/MOD;
							s.u[i]%=MOD;
							if(i==s.n-1) s.n++;
					}
					return s;
			}
			BigNum operator /(const BigNum& r) const {
					BigNum e[35],s=0,c=0;
					int m=0,ro=r.o,lo=o;
					r.o^=ro,o^=lo;
					for(e[m]=r;MOD>>++m;e[m]=e[m-1]+e[m-1]);
					for(int i=n-1;~i;i--){
							int tag=0;
							(s*=MOD)+=u[i];
							for(int x=m-1;~x;x--) if(s>=e[x]) s-=e[x],tag|=1<<x;
							(c*=MOD)+=tag;
					}
					r.o^=ro,o^=lo;
					if(c.u[0] || c.n>=2) c.o=r.o^o;
					return c;
			}
			BigNum operator %(const BigNum& r) const {
					BigNum e[35],s=0;
					int m=0,ro=r.o,lo=o;
					r.o^=ro,o^=lo;
					for(e[m]=r;MOD>>++m;e[m]=e[m-1]+e[m-1]);
					for(int i=n-1;~i;i--){
							(s*=MOD)+=u[i];
							for(int x=m-1;~x;x--) if(s>=e[x]) s-=e[x];
					}
					r.o^=ro,o^=lo;
					if(s.u[0] || s.n>=2) s.o=o;
					return s;
			}
			BigNum& operator *=(int x){
					if(!x) return *this=0;
					if(x<0) o^=1,x=-x;
					for(int i=0;i<n;i++) u[i]*=x;
					for(int i=0;i<n;i++) if(u[i]>=MOD){
							u[i+1]+=u[i]/MOD;
							u[i]%=MOD;
							if(i==n-1) n++;
					}
					if(!u[0] && n==1) o=0;
					return *this;
			}
			BigNum& operator /=(int x){
					if(x<0) o^=1,x=-x;
					for(int i=n-1;i;u[i--]/=x) u[i-1]+=u[i]%x*MOD;
					for(u[0]/=x;n>=2;n--) if(u[n-1]) break;
					if(!u[0] && n==1) o=0;
					return *this;
			}
			int operator %(int x) const {
					long long c=0;
					for(int i=n-1;~i;i--) c=(c*MOD+u[i])%x;
					return (1-o-o)*int(c);
			}
	};

**9 多项式拟合**
>EternalReality

    typedef double VAL;
    // 传入y=f(x)上的n个点，拟合出对应的一元n-1次方程，返回各项系数
    // VAL类型需支持加、减、乘、除、取反、加等于这六种操作
    vector<VAL> interpolation(const VAL x[], const VAL y[], int n){
        vector<VAL> u(y,y+n),ret(n),sum(n);
        ret[0]=u[0],sum[0]=1;
        for(int i=1;i<n;i++){
            for(int j=n-1;j>=i;j--) u[j]=(u[j]-u[j-1])/(x[j]-x[j-i]);
            for(int j=i;j;j--){
                sum[j]=-sum[j]*x[i-1]+sum[j-1];
                ret[j]+=sum[j]*u[i];
            }
            sum[0]=-sum[0]*x[i-1];
            ret[0]+=sum[0]*u[i];
        }
        return ret;
    }

**10 NTT数论变换**
>EternalReality

    //g是p的原根,p为素数且len|p-1&&len=2^?
    const int p=786433,g=10;
    LL pm(LL a,int n,int m=p) {
        LL r=1;
        for(;n;n>>=1,a=a*a%p)
        if(n&1) r = r * a %p;
        return r;
    }
    int rb(int x,int m) {
        int r=0;
        for(;m>1;m>>=1,x>>=1)r=r<<1|x&1;
        return r;
    }
    void ntt(int *a,int len){
        for(int i=0,j;i<len;++i)
        if(i<(j=rb(i,len)))swap(a[i],a[j]);
        for(int m=1; m < len ; m<<=1) {
            LL w=1;int w0 = pm(g, (p-1)/m>>1);
            for(int k = 0; k<len; k+=(m<<1), w=1)
            for(int j=0;j<m; ++j , w=w*w0 %p) {
                int t= w*a[k+j+m]%p;
                a[k+j+m] = (a[k+j]+p-t) %p;
                a[k+j] = (a[k+j]+t)%p;
            }
        }
    }
    void conv(int *a, int *b, int *c, int len) {
        static int wa[N], wb[N];
        rep (i, len) wa[i] = a[i], wb[i] = b[i];
        ntt(wa, len);
        ntt(wb, len);
        int inv = pm(len, p - 2);
        rep (i, len) c[i] = wa[i] * (LL)wb[i] % p * inv % p;
        reverse(c + 1, c + len);
        ntt(c, len);
    }

**11 直线下格点统计**
>shoka

	//sigma i in range(0,n) [(a+b*i)/m]
	//n,m>0;a,b>=0;
	LL count(LL n, LL a, LL b, LL m) {
		if(b == 0)
			return n * (a / m);
		if(a >= m)
			return n * (a / m) + count(n, a % m, b, m);
		if(b >= m)
			return (n - 1) * n / 2 * (b / m) + count(n, a, b % m, m);
		return count((a + b * n) / m, (a + b * n) % m, m, b);
	}

**12 FWT**
>Nero

	//copy from Nero
	//C[i^j]+=A[i]*B[j]
	//C=fwt(fwt(A,1)*fwt(B,1),0)
	const int MOD = (int)1e9 + 7;
	const int inv2 = MOD + 1 >> 1;
	int A[1 << 18];

	void fwt(int A[],int n,int inv) {
	    for (int l = 1; l << 1 <= n; l <<= 1) {
	        for (int s = 0; s < n; ++ s) {
	            if (~s & l) {
	                int a = A[s];
	                int b = A[s ^ l];
	                if (inv == 1) {
	                    A[s] = (a - b + MOD) % MOD;
	                    //xor a-b   $ and a+b   $ or a
	                    A[s ^ l] = (a + b) % MOD;
	                    //xor a+b   $ and b     $ or a+b
	                } else {
	                    A[s] = (a + b) * 1ll * inv2 % MOD;
	                    A[s ^ l] = (b - a + MOD) * 1ll * inv2 % MOD;
	                }
	            }
	        }
	    }
	}

**Java 开根**
>ftiasch

	public static BigInteger getsqrt(BigInteger n) {
	    if (n.compareTo(BigInteger.ZERO) <= 0) return n;
	    BigInteger x, xx, txx;        xx = x = BigInteger.ZERO;
	    for (int t = n.bitLength() / 2; t >= 0; t--) {
	        txx = xx.add(x.shiftLeft(t + 1)).add(BigInteger.ONE.shiftLeft(t + t));
	        if (txx.compareTo(n) <= 0) {
	            x = x.add(BigInteger.ONE.shiftLeft(t));   xx = txx;
	        }
	    } 
	    return x;
	}
