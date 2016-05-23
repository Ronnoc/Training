**1 二维操作**

	int sign( double x ) {return x<-eps?-1:x>eps;}
	struct point {
		double x, y;
		point( double _x=0, double _y=0 ) : x( _x ), y( _y ) {}
		point operator - ( point p ) {return point( x-p.x,y-p.y );}
		point operator + ( point p ) {return point( x+p.x,y+p.y );}
		point operator * ( double d ) {return point( x*d,y*d );}
		point operator / ( double d ) {return point( x/d,y/d );}
		bool operator < ( const point &p ) const {
			return sign( x - p.x ) == 0 ? sign( y - p.y ) <= 0 : sign( x - p.x ) <= 0;
		}
		double operator *( point p ) {return x*p.x+y*p.y;}//dot
		double operator ^( point p ) {return x*p.y-y*p.x;}//det
		double len() {return sqrt( x*x+y*y );}
		double arc() {return atan2( y, x );}
		point normal() {return ( *this ) / this->len();}
		point rotate() {return point( -y, x );}
		point rotate( double arc )
		{return point( x*cos( arc ) - y*sin( arc ),x*sin( arc ) + y*cos( arc ) );}
		double dis( point p ) {return ( *this - p ).len();}
		double dis2( point p ) {p = p - ( *this ); return p*p;}
		void read() {scanf( "%lf%lf", &x, &y );}
		void write( char *s="" ) {printf( "(%f,%f)%s",x,y,s );}
	} Orz( 0,0 );
	bool isLL( point p1, point p2, point q1, point q2 ,point &is ) {
		double m=( q2-q1 )^( p1-q1 ),n=( q2-q1 )^( p2-q1 );
		if ( sign( n-m )==0 )return 0;
		is= ( p1*n-p2*m )/( n-m );
		return 1;
	}

**2 三维操作**

	struct spt {
		double x,y,z;
		spt( double _x=0,double _y=0,double _z=0 ):x( _x ),y( _y ),z(_z) {}
		spt operator +( spt &s ) {return spt( x+s.x,y+s.y,z+s.z );}
		spt operator -( spt &s ) {return spt( x-s.x,y-s.y,z-s.z );}
		spt operator *(double d) {return spt(x*d,y*d,z*d);}
		spt operator /(double d) {return spt(x/d,y/d,z/d);}
		double len() {return sqrt( SQ(x)+SQ(y)+SQ(z) );}
		spt normal() {double d=(*this).len();return (*this)/d;}
		double operator *( spt s ) {return x*s.x+y*s.y+z*s.z;} //dot
		spt operator ^( spt s ) {	//det
			spt ret;
			ret.x=y*s.z-z*s.y;
			ret.y=z*s.x-x*s.z;
			ret.z=x*s.y-y*s.x;
			return ret;
		}
		bool operator < (const spt &s)const {
			if(sign(s.x-x)!=0)return sign(x-s.x)<0;
			if(sign(s.y-y)!=0)return sign(y-s.y)<0;
			return sign(z-s.z)<0;
		}
		bool operator ==(const spt &s)const {
			return sign(s.x-x)==0&&sign(s.y-y)==0&&sign(s.z-z)==0;
		}
		void read() {scanf("%lf%lf%lf",&x,&y,&z);}
		void write(char *s="") {printf( "(%.6f %.6f %.6f)%s",x,y,z,s );}
	} Orz( 0,0,0 );
	struct sfl {
		spt p,o;
		sfl() {}
		sfl( spt _p,spt _o ):p( _p ),o( _o ) {}
		sfl( spt u,spt v,spt w ) {p=u,o=( ( v-u )^( w-u ) ).normal();}
	};
	double disLP( spt p1,spt p2,spt q ) {
		return fabs( ( ( p2-p1 )^( q-p1 ) ).len()/( ( p2-p1 ).len() ) );
	}
	double disLL( spt p1,spt p2,spt q1,spt q2 ) {
		spt p=q1-p1,u=p2-p1,v=q2-q1;
		double d=( u*u )*( v*v )-SQ( u*v );
		if ( sign( d )==0 )return disLP( q1,q2,p1 );
		double s=( ( p*u )*( v*v )-( p*v )*( u*v ) )/d;
		return disLP( q1,q2,p1+u*s );
	}
	bool isFL( sfl f,spt q1,spt q2,spt &is ) {
		double a=f.o*( q2-f.p ),b=f.o*( q1-f.p );
		double d=a-b;
		if ( sign( d )==0 )return 0;
		is=( q1*a-q2*b )/d;
		return 1;
	}
	bool isFF( sfl a,sfl b,spt &is1,spt &is2 ) {
		spt e=a.o^b.o;
		spt v=a.o^e;
		double d=b.o*v;
		if ( sign( d )==0 )return 0;
		is1=a.p+v*( b.o*( b.p-a.p ) )/d;
		is2=is1+e;
		return 1;
	}

**3 凸包及其直径**
>验题:poj2187

	vector<point> ConvexHull( vector<point> p ) {
		int n = p.size(), m = 0;
		vector<point> q;
		q.resize( n * 2 );
		sort( p.begin(), p.end() );
		for ( int i = 0; i < n; i ++ ) {
			while ( m > 1 && sign( ( q[m - 1] - q[m - 2] ) ^ ( p[i] - q[m - 2] ) )<= 0 )
				m -- ;
			q[m ++ ] = p[i];
		}
		int k = m;
		for ( int i = n - 2; i >= 0; i -- ) {
			while ( m > k && sign( ( q[m - 1] - q[m - 2] ) ^ ( p[i] - q[m - 2] ) )<= 0 )
				m -- ;
			q[m ++ ] = p[i];
		}
		if ( n > 1 ) m -- ;
		q.resize( m );
		return q;
	}
	double ConvecDiameter( vector<point> p ) {
		int n = p.size(), j = 1;
		double maxd = 0;
		p.push_back( p[0] );
		for ( int i = 0; i < n; i ++ ) {
			while ( ( ( p[i + 1] - p[i] ) ^ ( p[j + 1] - p[i] ) )> ( ( p[i + 1] - p[i] ) ^ ( p[j] - p[i] ) ) )
				j = ( j + 1 ) % n;
			cmax( maxd, max( p[i].dis( p[j] ), p[i + 1].dis( p[j + 1] ) ) );
		}
		return maxd;
	}

**4 凸多边形**
>半平面交验题:poj2451

	struct line {
		point s,e; //s->e left
		double k;
		line() {}
		line( point _s,point _e ):s( _s ),e( _e )
		{k = atan2( e.y - s.y,e.x - s.x );}
		bool operator <( const line &L )const {
			if ( sign( k-L.k ) )return k<L.k;
			return ( ( s-L.s )^( L.e-L.s ) )<0;
		}
		point operator &( const line &b )const {
			point res = s;
			double t = ( ( s - b.s )^( b.s - b.e ) )/( ( s - e )^( b.s - b.e ) );
			res.x += ( e.x - s.x )*t;
			res.y += ( e.y - s.y )*t;
			return res;
		}
	};
	int HPI( line *L, int n, point *R ) {
		sort( L,L+n );
		int tot = 1;
		for ( int i = 1; i < n; i++ )
			if ( sign( L[i].k - L[i-1].k )!=0 )
				L[tot++] = L[i];
		line Q[n];
		int fi = 0, la = 1;
		Q[0] = L[0],Q[1] = L[1];
		for ( int i = 2; i < tot; i++ ) {
			if ( sign( ( Q[la].e-Q[la].s )^( Q[la-1].e-Q[la-1].s ) ) ==0 ||
					 sign( ( Q[fi].e-Q[fi].s )^( Q[fi+1].e-Q[fi+1].s ) ) ==0 )
				return 0;
			point s=L[i].s,e=L[i].e;
			while ( fi<la && sign( ( ( Q[la]&Q[la-1] )-s )^( e-s ) )>0 )
				la--;
			while ( fi<la && sign( ( ( Q[fi]&Q[fi+1] )-s )^( e-s ) )>0 )
				fi++;
			Q[++la] = L[i];
		}
		while ( fi<la && sign( ( ( Q[la]&Q[la-1] )-Q[fi].s )^( Q[fi].e-Q[fi].s ) )>0 )
			la--;
		if ( la <= fi + 1 )return 0;
		int ret = 0;
		for ( int i = fi; i < la; i++ )R[ret++] = Q[i]&Q[i+1];
		if ( fi < la - 1 )R[ret++] = Q[fi]&Q[la];
		return ret;
	}

>凸多边形切割,逆时针 验题:hdu4904

	vector<point> convexCut( const vector<point>&ps, point q1, point q2 ) {
		vector<point> qs;
		int n = ps.size();
		for ( int i = 0; i < n; ++i ) {
			point p1 = ps[i], p2 = ps[( i + 1 ) % n];
			int d1 = sign( ( q2-q1 )^( p1-q1 ) ), d2 = sign( ( q2-q1 )^( p2-q1 ) );
			if ( d1 >= 0 )
				qs.PB( p1 );
			if ( d1 * d2 < 0 ) {
				point is;
				int flag=isLL( p1, p2, q1, q2,is );
				if ( flag )qs.PB( is );
			}
		}
		return qs;
	}

**5 三维凸包**
>验题:poj3528,hdu4449

	const int MXN = 55;
	spt s[MXN];
	int mark[MXN][MXN];
	int cnt,n;
	struct Face {
		int a,b,c;
		Face(int a=0,int b=0,int c=0):a(a),b(b),c(c) {}
		int &operator [](int k) {
			if(!k)return a;
			return k==1?b:c;
		}
	};
	vector<Face>face;
	void insert(int a,int b,int c) {face.PB(Face(a,b,c));}
	double mix(spt a,spt b,spt c) {return a*(b^c);}
	double volume(int a,int b,int c,int d) {return mix(s[b]-s[a],s[c]-s[a],s[d]-s[a]);}
	void add(int v) {
		vector<Face>tmp;
		int a,b,c;
		cnt++;
		for(int i=0; i<face.SZ; i++) {
			a=face[i][0],b=face[i][1],c=face[i][2];
			if(sign(volume(v,a,b,c))<0)
				mark[a][b]=mark[b][a]=mark[b][c]=mark[c][b]=mark[c][a]=mark[a][c]=cnt;
			else tmp.PB(face[i]);
		}
		face=tmp;
		for(int i=0; i<tmp.SZ; i++) {
			a=face[i][0],b=face[i][1],c=face[i][2];
			if(mark[a][b]==cnt)insert(b,a,v);
			if(mark[b][c]==cnt)insert(c,b,v);
			if(mark[c][a]==cnt)insert(a,c,v);
		}
	}
	int Find() {
		for(int i=2; i<n; i++) {
			spt ndir=(s[0]-s[i])^(s[1]-s[i]);
			if(ndir==spt())continue;
			swap(s[i],s[2]);
			for(int j=i+1; j<n; j++)
				if(sign(volume(0,1,2,j))!=0) {
					swap(s[j],s[3]);
					insert(0,1,2);
					insert(0,2,1);
					return 1;
				}
		}
		return 0;
	}
	bool makeFace() {
		sort(s,s+n);
		n=unique(s,s+n)-s;
		random_shuffle(s,s+n);
		face.clear();
		int flag=Find();
		if(!flag);//on same plane
		memset(mark,0,sizeof mark);
		cnt=0;
		for(int i=3; i<n; i++)add(i);
		return 1;
	}

**6 多边形与一个圆面积交**
>验题:poj3675

	double r;	//O(0,0)
	double area2( point pa,point pb ) {
		if ( pa.len()<pb.len() )swap( pa,pb );
		if ( pb.len()<eps )return 0;
		double a,b,c,B,C,sinB,cosB,sinC,cosC,S,h,theta;
		a=pb.len(),b=pa.len(),c=( pb-pa ).len();
		cosB=pb*( pb-pa )/a/c;
		B=acos( cosB );
		cosC=pa*pb/a/b;
		C=acos( cosC );
		if ( a>r ) {
			S=( C/2 )*r*r;
			h=a*b*sin( C )/c;
			if ( h<r&&B<PI/2 )S-=( acos( h/r )*r*r-h*sqrt( r*r-h*h ) );
		} else if ( b>r ) {
			theta=PI-B-asin( sin( B )/r*a );
			S=.5*a*r*sin( theta )+( C-theta )*.5*r*r;
		} else S=.5*sin( C )*a*b;
		return S;
	}
	double area() {
		double S=0;
		for ( int i=0; i<n; i++ )
			S+=area2( info[i],info[i+1] )*sign( info[i]^info[i+1] );
		return fabs( S );
	}

**7 最小圆覆盖**
>验题:hdu3007

	struct circle {
		point ct;
		double r;
		circle( point a,point b ) {
			ct=( a+b )/2;
			r=( b-a ).len()/2;
		}
		circle( point o,double rr ):ct( o ),r( rr ) {}
		circle( point a,point b,point c ) {
			double A,B,C,D,E,F;
			A=2*a.x-2*b.x;
			B=2*a.y-2*b.y;
			C=SQ( a.len() )-SQ( b.len() );
			D=2*a.x-2*c.x;
			E=2*a.y-2*c.y;
			F=SQ( a.len() )-SQ( c.len() );
			ct.x=( C*E-B*F )/( A*E-B*D );
			ct.y=( A*F-C*D )/( A*E-B*D );
			r=( a-ct ).len();
		}
		bool operator > ( const point a )const {
			return sign( ( a-ct ).len()-r )<=0;
		}
	};
	circle minCircle( vector<point>&L ) {
		circle ans( point( 0,0 ),0 );
		int i,j,k;
		for ( i=2; i<L.SZ; i++ )if ( !( ans>L[i] ) ) {
				ans=circle( L[0],L[i] );
				for ( j=1; j<i; j++ )if ( !( ans>L[j] ) ) {
						ans=circle( L[i],L[j] );
						for ( k=0; k<j; k++ )if ( !( ans>L[k] ) )
								ans=circle( L[i],L[j],L[k] );
					}
			}
		return ans;
	}

**8 平面最近点对**
> 验题:zoj 2107

	const int MAXN = 100000+10;
	double closed;
	struct point {
		double x, y;
		int id;
	};
	point pts[MAXN],lP[MAXN],rP[MAXN];
	struct cmpY {
		bool operator()( const point &lhs, const point &rhs ) {
			return lhs.y < rhs.y;
		}
	};
	struct cmpX {
		bool operator()( const point &lhs, const point &rhs ) {
			return lhs.x < rhs.x;
		}
	};
	double dist( const point &pt1, const point &pt2 ) {
		return sqrt( SQ( pt1.x - pt2.x ) + SQ( pt1.y - pt2.y ) );
	}
	void findNearest( int l, int r ) {
		if ( r<=l ) return;
		int mid = l + r >> 1;
		findNearest( l, mid );
		findNearest( mid + 1, r );
		int lm = mid, rm = mid + 1;
		while ( lm - 1 >= l && pts[mid].x - pts[lm - 1].x < closed ) --lm;
		while ( rm + 1 <= r && pts[rm + 1].x - pts[mid].x < closed ) ++rm;
		int nlP = 0, nrP = 0;
		for ( int i = lm; i <= mid; ++i ) lP[nlP++] = pts[i];
		for ( int i = mid + 1; i <= rm; ++i ) rP[nrP++] = pts[i];
		sort( lP, lP + nlP, cmpY() );
		sort( rP, rP + nrP, cmpY() );
		int j = 0;
		for ( int i = 0; i < nlP; ++i ) {
			while ( j < nrP && rP[j].y < lP[i].y ) ++j;
			for ( int k = j - 2; k <= j + 2; ++k ) {
				if ( k < 0 || k >= nrP ) continue;
				closed=min( dist( lP[i], rP[k] ),closed );
			}
		}
	}

**9 三维绕轴旋转**
>hdu 4087

	mat ret;
	double Cos=cos(A),Sin=sin(A);
	S.normal();
	ret[3][3]=1;
	ret[0][0]=x*x+(1-x*x)*Cos;
	ret[0][1]=x*y*(1-Cos)-z*Sin;
	ret[0][2]=x*z*(1-Cos)+y*Sin;
	ret[1][0]=y*x*(1-Cos)+z*Sin;
	ret[1][1]=y*y+(1-y*y)*Cos;
	ret[1][2]=y*z*(1-Cos)-x*Sin;
	ret[2][0]=z*x*(1-Cos)-y*Sin;
	ret[2][1]=z*y*(1-Cos)+x*Sin;
	ret[2][2]=z*z+(1-z*z)*Cos;
	return ret;

**10 多圆面积**
>sjtu

	struct Tevent {
	    point p; double ang; int add;
	    Tevent(point q = point(0, 0), double w = 0, int e = 0) {p = q, ang = w, add = e;}
	    bool operator <(const Tevent &a) const {return ang < a.ang; }
	} eve[maxn * 2];
	int E, cnt;
	struct Tcir {point o; double r;};
	void circleCrossCircle(Tcir &a, Tcir &b) {
	    double l = (a.o - b.o).len2();
	    double s = ((a.r - b.r) * (a.r + b.r) / l + 1) * .5;
	    double t = sqrt(-(l - sqr(a.r - b.r)) * (l - sqr(a.r + b.r)) / (l * l * 4.));
	    point dir = b.o - a.o;  point Ndir = point(-dir.y, dir.x);
	    point aa = a.o + dir * s + Ndir * t, bb = a.o + dir * s - Ndir * t;
	    double A = atan2(aa.y - a.o.y, aa.x - a.o.x), B = atan2(bb.y - a.o.y, bb.x - a.o.x);
	    eve[E++] = Tevent(bb, B, 1); eve[E++] = Tevent(aa, A, -1); if (B > A) cnt++;
	}
	bool g[maxn][maxn], Overlap[maxn][maxn];
	//必须去掉重复的圆 Overlap[i][j]:i包含j g[i][j]:i和j相交
	double Area[maxn]; Tcir c[maxn]; int C;
	int main() {
	    for (int i = 0; i <= C; ++i) Area[i] = 0;
	    for (int i = 0; i < C; ++i) {
	        E = 0, cnt = 1;
	        for (int j = 0; j < C; ++j) if (j != i && Overlap[j][i]) cnt++;
	        for (int j = 0; j < C; ++j) if (i != j && g[i][j])
	                circleCrossCircle(c[i], c[j]);//cnt表示覆盖次数超过cnt
	        if (E == 0) {
	            Area[cnt] += PI * c[i].r * c[i].r;
	        } else {
	            double counts = 0; sort(eve, eve + E); eve[E] = eve[0];
	            for (int j = 0; j < E; ++j) {
	                cnt += eve[j].add;
	                Area[cnt] += (eve[j].p ^ eve[j + 1].p) * .5; //det
	                double theta = eve[j + 1].ang - eve[j].ang;
	                if (theta < 0) theta += PI * 2.;
	                Area[cnt] += (theta - sin(theta)) * c[i].r * c[i].r * .5;
	            }
	        }
	    }
	}
