**1 扩展欧几里得**
>ax+by==gcd(a,b)的解
>验题: poj 1061

	LL extGcd (LL a, LL b, LL &x, LL &y) {
		LL ret = a;
		if (b) {
			ret = extGcd (b, a % b, y, x);
			y -= (a / b) * x;
		} else
			x = 1, y = 0;
		return ret;
	}

**2 逆元**
>验题:未验

	//用于m不是质数 gcd(a,m)==1时有逆元
	LL modInv (LL a, LL m) {
		LL x, y;
		extGcd(a,m,x,y);
		return (m+x%m)%m;
	}
	//if m为质数 [费马小定理]a^(m-1)=1 mod m ==>a^(m-2)是a关于m的逆元
	
**3 因数分解&&质因数分解**
>验题: 未验

	//prime_factor()传入n, 返回不同质因数的个数
	//f存放质因数，nf存放对应质因数的个数
	#define MAXN 2001000
	#define PSIZE 100000
	int plist[PSIZE], pcount = 0; //质数表
	int prime_factor (int n, int* f, int *nf) {
		int cnt = 0;
		int n2 = sqrt ( (double) n);
		for (int i = 0; n > 1 && plist[i] <= n2; ++i)
			if (n % plist[i] == 0) {
				for (nf[cnt] = 0; n % plist[i] == 0; ++nf[cnt], n /= plist[i]);
				f[cnt++] = plist[i];
			}
		if (n > 1) nf[cnt] = 1, f[cnt++] = n;
		return cnt;
	}


**4 Millar素数测试 && rho大整数因数分解**
>验题: poj 2447

	const int S=20;
	inline LL mutiMod( LL a,LL b,LL c ) { //返回(a*b) mod c,a,b,c<2^63
		a%=c,b%=c;
		LL ret=0;
		while ( b ) {
			if ( b&1 ) {
				ret+=a;
				if ( ret>=c ) ret-=c;
			}
			a<<=1,b>>=1;
			if ( a>=c ) a-=c;
		}
		return ret;
	}
	inline LL powMod( LL x,LL n,LL mod ) { //返回x^n mod c ,非递归版
		LL ret=1;
		while ( n ) {
			if ( n&1 )ret=mutiMod( ret,x,mod );
			x=mutiMod( x,x,mod );
			n>>=1;
		}
		return ret;
	}
	bool check( LL a,LL n,LL x,LL t ) { //以a为基，n-1=x*2^t，检验n是不是合数
		LL ret=powMod( a,x,n ),last=ret;
		for ( int i=1; i<=t; i++ ) {
			ret=mutiMod( ret,ret,n );
			if ( ret==1&& last!=1&& last!=n-1 ) return 1;
			last=ret;
		}
		if ( ret!=1 ) return 1;
		return 0;
	}
	bool Miller_Rabin( LL n ) {
		LL x=n-1,t=0;
		while ( ( x&1 )==0 ) x>>=1,t++;
		bool flag=1;
		if ( t>=1&& ( x&1 )==1 ) {
			for ( int k=0; k<S; k++ ) {
				LL a=rand()%( n-1 )+1;
				if ( check( a,n,x,t ) ) {flag=1; break;}
				flag=0;
			}
		}
		if ( !flag || n==2 ) return 0;
		return 1;
	}
	vector<LL>factor;			  	//需要clear
	LL Pollard_rho( LL x,LL c ) {
		LL i=1,x0=rand()%x,y=x0,k=2;
		while ( i++ ) {
			x0=( mutiMod( x0,x0,x )+c )%x;
			LL d=__gcd( y>x0?y-x0:x0-y,x );
			if ( d!=1&& d!=x ) return d;
			if ( y==x0 ) return x;
			if ( i==k ) y=x0,k<<=1;
		}
	}
	void findfac( LL n ) {        	//递归进行质因数分解N
		if ( !Miller_Rabin( n ) ) {
			factor.PB( n );
			return;
		}
		LL p=n;
		while ( p>=n ) p=Pollard_rho( p,rand() % ( n-1 ) +1 );
		findfac( p );
		findfac( n/p );
	}


**5 阶乘||组合数 取模**
>验题:未验

	int fact[MAX_P];	//预处理n! mod p 的表 O(n)
	// n!=a*p^e return a%p
	int modFact (int n, int p, int &e) {
		e = 0;
		if (!n) return 1;
		int res = modFact (n / p, p, e);
		e += n / p;
		if (n / p % 2)
			return res * (p - fact[n % p]) % p;
		return res * fact[n % p] % p;
	}
	//C _(n) ^(k) %p
	int modComb (int n, int k, int p) {
		if (n < 0 || k < 0 || n < k) return 0;
		int e1, e2, e3;
		int a1 = modFact (n, p, e1);
		int a2 = modFact (k, p, e2);
		int a3 = modFact (n - k, p, e3);
		if (e1 > e2 + e3) return 0;
		return a1 * modInv (a2 * a3 % p, p) % p;
	}

**6 欧拉函数**
>验题: poj 1284

	int eulerPhi (int n) {
		int res = n;
		for (int i = 2; i * i <= n; i++)		//可用质数加速
			if (n % i == 0) {
				res = res / i * (i - 1);
				for (; n % i == 0; n /= i);
			}
		if (n != 1) res = res / n * (n - 1);
		return res;
	}

	int euler[MAX_N];
	void tableEuler (int n) {
		for (int i = 0; i < n; i++)
			euler[i] = i;
		for (int i = 2; i < n; i++)
			if (euler[i] == i)
				for (int j = i; j < n; j += i) euler[j] = euler[j] / i * (i - 1);
	}

**7 模同余方程组**
>验题:未验

	//a_i*x=b_i {%m_i}  m_i可以不互质
	//pair<b,m>			x=b {%m}
	pair<int, int> linearMod (const vector<int>&A, const vector<int>&B, const vector<int>&M) {
		int x = 0, m = 1;
		for (int i = 0; i < A.size(); i++) {
			int a = A[i] * m, b = B[i] - A[i] * x, d = __gcd (M[i], a);
			if (b % d) return MP (0, -1);
			int t = b / d * modInv (a / d, M[i] / d) % (M[i] / d);
			x = x + m * t;
			m *= M[i] / d;
		}
		return MP (x % m, m);
	}

**8 阶乘最后非零位**
>验题: 未验

	//求阶乘最后非零位,复杂度O(nlogn),返回该位,n以字符串方式传入
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

**9 离散对数**
>验题:poj3243,hdu2815

	int extBSGS( int A,int B,int C ) { //A^x==B mod C
		for ( int i=0,tmp=1%C; i<100; i++,tmp=1LL*tmp*A%C )if ( tmp==B )return i;
		int temp;
		LL D=1%C;
		int d=0;
		while ( ( temp=__gcd( A,C ) )!=1 ) {
			if ( B%temp )return -1;
			C/=temp,B/=temp;
			d++;
			D=1LL*A/temp*D%C;
		}
		int s=( int )ceil( sqrt( C+eps ) )+1;
		vector<PII>L;
		LL G=1%C;
		for ( int i=0; i<s; i++ ) {
			L.PB( MP( G,i ) );
			G=G*A%C;
		}
		SORT( L );
		for ( int i=0; i<=s; i++ ) {
			int tmp=modInv( D,C )*B%C;
			int id=lower_bound( L.OP,L.ED,MP( tmp,-1 ) )-L.OP;
			if ( id<L.SZ&&id>=0&&L[id].AA==tmp )
				return i*s+L[id].BB+d;
			D=D*G%C;
		}
		return -1;
	}



**10 莫比乌斯**
>验题:未验

	map<int,int> moebius (LL n) {
		map<int,int> res;
		vector<int>prime;
		int i,j;
		for (i=2; i*i<=n; i++)
			if (n%i==0) {
				prime.push_back (i);
				while (n%i==0) n/=i;
			}
		if (n!=1) prime.push_back (n);
		
		int m=prime.size();
		for (int i=0; i< (1<<m); i++) {
			int mu=1,d=1;
			for (j=0; j<m; j++) {
				if (i>>j&1) {
					mu*=-1;
					d*=prime[j];
				}
				res[d]=mu;
			}
		}
		return res;
	}

	memset(mul,0,sizeof mul);
	for(i=1;i<=N;i++){
		if(i==1)mul[i]=1;
		else mul[i]*=-1;
		for(j=i*2;j<=N;j+=i)
			mul[j]+=mul[i];
	}
	
	int mu[N], p[N], pn;
	bool flag[N];
	void init() {
			pn = 0;
			mu[1] = 1;
			for(int i = 2; i < N; i++) {
					if(!flag[i]) {
							p[pn ++ ] = i;
							mu[i] = -1;
					}
					for(int j = 0; j < pn && i * p[j] < N; j++) {
							flag[i * p [j]] = true;
							if(i % p[j] == 0) {
									mu[i * p[j]] = 0;
									break;
							} else {
									mu[i * p[j]] = -mu[i];
							}
					}
			}
	}