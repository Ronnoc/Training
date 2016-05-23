**1 扩展欧几里得**
>ax+by==gcd(a,b)的解
>验题: poj1061

	LL extGcd (LL a, LL b, LL &x, LL &y) {
		LL ret = a;
		if (b) {
			ret = extGcd (b, a % b, y, x);
			y -= (a / b) * x;
		} else x = 1, y = 0;
		return ret;
	}

**2 逆元**
>验题: poj2447

	LL modInv (LL a, LL m) {
		LL x, y;
		extGcd(a,m,x,y);
		return (m+x%m)%m;
	}//if m为质数 [费马小定理]a^(m-1)=1 mod m ==>a^(m-2)是a关于m的逆元

**3 Millar素数测试 && rho大整数因数分解**
>验题: poj 2447,2429,1811

	const int S=7;
	LL cs[]={2,325,9375,28178,450775,9780504,1795265022};
	LL mutiMod( LL a,LL b,LL c ) { //(a*b)mod c in 2^63(a,b>0)
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
	/*LL mulMod( LL A,LL B,LL C ) {
		LL y=( ( long double )A*B )/C;
		LL ret=A*B-C*y;
		if ( ret<0 )ret+=C;
		return ret;
	}*///fzu1752
	LL powMod( LL x,LL n,LL mod ) {
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
				LL a=cs[k];
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


**4 阶乘模分解**
>验题:浙大shi哥译书

	int fact[MAX_P];	//预处理n! mod p 的表 O(min(n,p))
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

**5 欧拉函数**
>验题: poj 1284

	int eulerPhi (int n) {			// test: phi(846720)=193536 
		int res = n;
		for (int i = 2; i * i <= n; i++)		//可用质数加速
			if (n % i == 0) {
				res = res / i * (i - 1);
				for (; n % i == 0; n /= i);
			}
		if (n != 1) res = res / n * (n - 1);
		return res;
	}//筛法见mobius

**7 模同余方程组**
>验题:poj2891

	//a_i*x=b_i {%m_i}  m_i可以不互质
	//pair<b,m>			x=b {%m}
	pair<LL,LL> linearMod( vector<LL>&A,vector<LL>&B,vector<LL>&M ) {
		LL x=0,m=1;
		for ( int i=0; i<A.SZ; i++ ) {
			LL a=A[i]*m,b=B[i]-A[i]*x,d=__gcd( M[i],a );
			if ( b%d )return MP( 0,-1 );
			LL t=b/d*modInv( a/d,M[i]/d )%( M[i]/d );
			x+=m*t;
			m*=M[i]/d;
			x%=m;
		}
		return MP( ( ( x%m )+m )%m,m );
	}

**8 离散对数**
>验题:poj3243,hdu2815,hdu5022

	int extBSGS( int A,int B,int C ) { //A^x==B mod C
		for ( int i=0,tmp=1%C; i<100; i++,tmp=1LL*tmp*A%C )if ( tmp==B )return i;
		int temp,d=0;
		LL D=1%C;
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


**9 莫比乌斯**
>验题:zju_watashi(map) hdu1695

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

	int mu[N], p[N], pn;
	bool flag[N];	//true为合数
	void init(int n) {
		pn = 0;
		mu[1] = 1;
		for(int i = 2; i <= n; i++) {
			if(!flag[i]) {
				p[pn ++ ] = i;
				mu[i] = -1;						//phi[i]=i-1;
			}
			for(int j = 0; j < pn && i * p[j] <= n; j++) {
				flag[i * p [j]] = true;
				if(i % p[j] == 0) {
					mu[i * p[j]] = 0;			//phi[i * p[j]] = p[j] * phi[i];
					break;
				} else  mu[i * p[j]] = -mu[i];	//phi[i * p[j]] = (p[j] - 1) * phi[i];
			}
		}
	}

**10 线性递推取模最小值**
>验题 : hdu5022

	LL getmin(LL start,LL slope,LL cnt,LL mod) {	//min{ (start+k*slope)%mod | 0<=k<=cnt }
		start%=mod;
		if(start+slope*cnt<mod)return start;
		if(start>=slope) {
			int use=(mod-1-start)/slope+1;
			return min(start,getmin(start+use*slope,slope,cnt-use,mod));
		}
		LL res=start;
		LL ns=slope-mod%slope;
		LL ncnt=(start+slope*cnt)/mod;
		return min(res,getmin(start,ns,ncnt,slope));
	}


**11 求解x^2=a mod P**
>验题:ural 1132

	//call(b,0,a,(p+1)/2,p) return a sol of {x^2=a (mod p)}
	//{p is odd prime}&&{a^[(p-1)/2]=1 mod p}&&{b^( (p-1)/2 )==-1 mod p}
	LL call(LL b,LL c,LL a,LL x,LL p){
		if(x%2==0)return modPow(b,c/2,p)*modPow(a,x/2,p)%p;
		LL tp=modPow(b,c/2,p)*modPow(a,(x-1)/2,p)%p;
		if(tp==1)return call(b,c/2,a,(x+1)/2,p);
		return call(b,(c+p-1)/2,a,(x+1)/2,p);
	}

**二次模方程**
>a*x^2+b*x+c==0 (mod P) 求0..P-1的根

	int pDiv2, P, a, b, c, Pb, d; 
	inline int calc(int x, int Time) {
	    if (!Time) return 1;  int tmp = calc(x, Time / 2);
	    tmp = (long long)tmp * tmp % P;
	    if (Time & 1) tmp = (long long)tmp * x % P;    return tmp;
	}
	inline int rev(int x) { if (!x) return 0;   return calc(x, P - 2);}
	inline void Compute() {
	    while (1) { b = rand() % (P - 2) + 2;  if (calc(b, pDiv2) + 1 == P) return; }
	}
	int main() {
	    srand(time(0) ^ 312314);  int T;
	    for (scanf("%d", &T); T; --T) {
	        scanf("%d%d%d%d", &a, &b, &c, &P);
	        if (P == 2)  { /*simple case*/
	        } else  {
	            int delta = (long long)b * rev(a) * rev(2) % P;
	            a = (long long)c * rev(a) % P - sqr( (long long)delta ) % P;
	            a %= P; a += P; a %= P;  a = P - a; a %= P;  pDiv2 = P / 2;
	            if (calc(a, pDiv2) + 1 == P) puts("0");
	            else {
	                int t = 0, h = pDiv2;    while (!(h % 2)) ++t, h /= 2;
	                int root = calc(a, h / 2);
	                if (t > 0) {  Compute();  Pb = calc(b, h); }
	                for (int i = 1; i <= t; ++i) {
	                    d = (long long)root * root * a % P;
	                    for (int j = 1; j <= t - i; ++j)  d = (long long)d * d % P;
	                    if (d + 1 == P)  root = (long long)root * Pb % P;
	                    Pb = (long long)Pb * Pb % P;
	                }
	                root = (long long)a * root % P;
	                int root1 = P - root; root -= delta;
	                root %= P; if (root < 0) root += P;
	                root1 -= delta; root1 %= P;  if (root1 < 0) root1 += P;
	                if (root > root1) { t = root; root = root1; root1 = t;  }
	                if (root == root1) printf("1 %d\n", root);
	                else printf("2 %d %d\n", root, root1);
	            }
	        }
	    } return 0;
	}