#数论#
**1 扩展欧几里得**
>ax+by==gcd(a,b)的解
>验题: poj 1061

	typedef long long LL;
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

**3 素数筛**
>验题: poj 1811

	bool isp[MXN];
	memset (isp, 0, sizeof isp);
	LL i, j, sn = sqrt ( (double) MXN);
	for (i = 3, isp[2] = 1; i < MXN; i+=2)isp[i]=1;
	for (i = 3; i <= sn + 1; i+=2)
		if (isp[i])for (j = i * i; j <= MXN; j += 2 * i)
				isp[j] = 0;
	
	LL prime[PRIME_NUM],mp;	//PRIME_NUM ~= MXN/ln[MXN]
	for (i = 2, mp = 0; i < MXN; i++) if (isp[i]) prime[++mp] = i;
	
**5 因数分解&&质因数分解**
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


**6 Millar素数测试 && rho大整数因数分解**
>验题: poj 2429

	//	Miller_Rabin 算法进行素数测试，速度快，而且可以判断 <2^63的数
	const int S=20;//随机算法判定次数，S越大，判错概率越小
	//以a为基,n-1=x*2^t      a^(n-1)=1(mod n)  验证n是不是合数
	bool check (LL a,LL n,LL x,LL t) {
		LL ret=power (a,x,n);								//power,llpro
		LL last=ret;
		for (int i=1; i<=t; i++) {
			ret=llpro (ret,ret,n);
			if (ret==1&&last!=1&&last!=n-1) return true; //合数
			last=ret;
		}
		if (ret!=1) return true;
		return false;
	}
	bool Miller_Rabin (LL n) {
		if (n<2) return false;
		if (n==2) return true;
		if ( (n&1) ==0) return false; //偶数
		LL x=n-1, t=0;
		while ( (x&1) ==0) {x>>=1; t++;}
		for (int i=0; i<S; i++) {
			LL a=rand() % (n-1) +1;		//rand()需要stdlib.h头文件	(rand64())
			if (check (a,n,x,t))return false;	//合数
		}
		return true;
	}
	long long factor[300];//质因数分解结果（刚返回时是无序的）
	int tol;//质因数的个数。数组小标从0开始
	long long Pollard_rho (long long x,long long c) {
		long long i=1,k=2;
		long long x0=rand() %x;
		long long y=x0;
		while (1) {
			i++;
			x0= (mult_mod (x0,x0,x) +c) %x;
			long long d=__gcd (y-x0,x);
			if (d!=1&&d!=x) return d;
			if (y==x0) return x;
			if (i==k) {y=x0; k+=k;}
		}
	}
	//对n进行素因子分解，调用前tol=0，n==1需要特判
	void findfac (long long n) {
		if (Miller_Rabin (n)) { //素数
			factor[tol++]=n;
			return;
		}
		long long p=n;
		while (p>=n) p=Pollard_rho (p,rand() % (n-1) +1);
		findfac (p);
		findfac (n/p);
	}

**8 阶乘||组合数 取模**
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

**9 欧拉函数**
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

**10 模同余方程组**
>验题:4767?未验

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

**13 阶乘最后非零位**
>验题: 未验

	//求阶乘最后非零位,复杂度O(nlogn)
	//返回该位,n以字符串方式传入
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

**14 离散对数**
>验题: hdu2815

	//a^x = b mod c;
	#define MAXN 65536
	#define LL long long
	struct LINK {
		LL data;
		LL j;
		LL next;
	} HASH_LINK[1000000];
	LL ad, head[MAXN];
	LL bady_step_giant_step (LL a, LL b, LL c) {
		LL i, buf, m, temp, g, D, x, y, n = 0;
		for (i = 0, buf = 1; i < 100; i ++, buf = buf * a % c)
			if (buf == b) return i;
		D = 1;
		while ( (g = __gcd (a, c)) != 1) {
			if (b % g) return -1;
			b /= g,c /= g;
			D = D * a / g % c;
			++ n;
		}
		memset (head, -1, sizeof (head));
		ad = 0;
		m = ceil (sqrt ( (long double) c));
		for (i = 0, buf = 1; i <= m; buf = buf * a % c, i ++) {
			LL hs = buf % MAXN, tail;
			int jump = 0;
			for (tail = head[hs]; ~tail; tail = HASH_LINK[tail]. next)
				if (buf == HASH_LINK[tail]. data) {
					jump = 1;
					break;
				}
			if (jump) continue;
			HASH_LINK[ad]. data = buf;
			HASH_LINK[ad]. j    = i;
			HASH_LINK[ad]. next = head[hs];
			head[hs] = ad ++;
		}
		for (i = 0, temp = power (a, m, c), buf = D; i <= m; i ++, buf = temp * buf % c) {//power
			extGcd (buf, c, x, y);											              //extGcd
			x = ( (x * b) % c + c) % c;
			for (LL tail = head[int (x % MAXN)]; ~tail; tail = HASH_LINK[tail].next)
				if (HASH_LINK[tail]. data == x) return HASH_LINK[tail].j + n + i * m;
		}
		return -1;
	}

**15 等比数列取模**

	#define LL long long
	LL dengbi (LL q,LL n,LL m) {	//sigma(i,0,n)q^i mod m
		if (n==0) return 1;
		if (n==1) return (q+1) %m;
		LL nn=n&1?n/2:n/2-1;
		LL tp=dengbi (q,nn,m);
		LL ret= (n&1) ? (tp+llpow (q,nn+1,m) *tp%m) %m: (1+q*tp%m+llpow (q,nn+2,m) *tp%m) %m;
		return ret;
	}

**16 莫比乌斯**

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