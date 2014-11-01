**1 BigNum**
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

**2 多项式拟合**
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

**3 NTT数论变换**
>EternalReality

    //g是p的原根,p为素数且len|p-1&&ppt(len)=1
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

**4 直线下格点统计**
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

**5 环状最长公共字串**
>shoka

	int n, a[N << 1], b[N << 1];
	bool has(int i, int j) {
		return a[(i - 1) % n] == b[(j - 1) % n];
	}
	const int DELTA[3][2] = {{0, -1}, {-1, -1}, {-1, 0}};
	int from[N][N];
	int solve() {
		memset(from, 0, sizeof(from));
		int ret = 0;
		for(int i = 1; i <= 2 * n; ++ i) {
			from[i][0] = 2;
			int left = 0, up = 0;
			for(int j = 1; j <= n; ++ j) {
				int upleft = up + 1 + !!from[i - 1][j];
				if(!has(i, j))
					upleft = INT_MIN;
				int tmp = std::max(left, std::max(upleft, up));
				if(left == tmp) 
					from[i][j] = 0;
				else if(upleft == tmp)
					from[i][j] = 1;
				else
					from[i][j] = 2;
				left = tmp;
			}
			if(i >= n) {
				int count = 0;
				for(int x = i, y = n; y;) {
					int t = from[x][y];
					count += t == 1;
					x += DELTA[t][0];
					y += DELTA[t][1];
				}
				ret = std::max(ret, count);
				int x = i - n + 1;
				from[x][0] = 0;
				int y = 0;
				while(y <= n && from[x][y] == 0)
					y++;
				for(; x <= i; ++ x) {
					from[x][y] = 0;
					if(x == i)
						break;
					for(; y <= n; ++ y) {
						if(from[x + 1][y] == 2)
							break;
						if(y + 1 <= n && from[x + 1][y + 1] == 1) {
							y ++;
							break;
						}
					}
				}
			}
		}
		return ret;
	}

