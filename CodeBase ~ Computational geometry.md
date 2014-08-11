**1 point及二维操作**

	int sign( double x ) {return x<-eps?-1:x>eps;}
	struct point {
		double x, y;
		point() {}
		point( double _x, double _y ) : x( _x ), y( _y ) {}
		point operator - ( const point p ) const {return point( x - p.x, y - p.y );}//{-,*,/}
		point operator + ( const point p ) const {return point( x+p.x,y+p.y );}
		point operator * ( const double d )const {return point( x*d,y*d );}
		point operator / ( const double d )const {return point( x/d,y/d );}
		bool operator < ( const point &p ) const {
			return sign( x - p.x ) == 0 ? sign( y - p.y ) <= 0 : sign( x - p.x ) <= 0;
		}
		double operator ^( const point &p )const {return x*p.y-y*p.x;} //叉积
		double operator *( const point &p )const {return x*p.x+y*p.y;} //点积
		double len() {return sqrt( x*x+y*y );}
		double arc() {return atan2( y, x );}
		point normal() {return ( *this ) / this->len();}
		point rotate() {return point( -y, x );}
		point rotate( double arc )
		{return point( x*cos( arc ) - y*sin( arc ),x*sin( arc ) + y*cos( arc ) );}
		double dis( point p ) {return ( *this - p ).len();}
		double dis2( point p ) {p = p - ( *this ); return p*p;}//平方
		void in() {scanf( "%lf%lf", &x, &y );}
		void out( char *s="" ) {printf( "(%f,%f)%s",x,y,s );}
	} ORI( 0,0 );
	bool isLL( point p1, point p2, point q1, point q2 ,point &is ) {
		double m=( q2-q1 )^( p1-q1 ),n=( q2-q1 )^( p2-q1 );
		if ( sign( n-m )==0 )return 0;
		is= ( p1*n-p2*m )/( n-m );
		return 1;
	}

**2 凸包及其直径**
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

**3 凸多边形**
>半平面交验题:poj2451

	struct line {
		point s,e;
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

**4 三维凸包**
>验题:poj3528

	struct spt {
		double x,y,z;
		spt() {}
		spt( double _x,double _y,double _z ):x( _x ),y( _y ),z(_z) {}
		spt operator +( const spt &s )const {return spt( x+s.x,y+s.y,z+s.z );} //{-,*,/}
		double len()const {return sqrt( SQ( x )+SQ( y )+SQ(z) );}
		double operator *( const spt &s )const {return x*s.x+y*s.y+z*s.z;} //点积
		spt operator ^( const spt &s )const {	//叉积
			spt ret;
			ret.x=y*s.z-z*s.y;
			ret.y=z*s.x-x*s.z;
			ret.z=x*s.y-y*s.x;
			return ret;
		}
		void output() {printf( "%.6f %.6f %.6f\n",x,y,z );}
	} ORI( 0,0,0 );
	struct sfl{
		spt u,v,w;
		sfl() {}
		sfl(spt _u,spt _v,spt _w):u(_u),v(_v),w(_w) {}
	};
	int SpaceConvexHull(spt *s,int n,sfl *p){
		int vs[MXN][MXN];
		vector<vector<int> >crt;
		vector<vector<int> >::iterator it;
		vector<int>L;
		L.clear();L.PB(0);L.PB(1);L.PB(2);crt.PB(L);
		L.clear();L.PB(2);L.PB(1);L.PB(0);crt.PB(L);
		for(int i=3;i<n;i++){
			vector<vector<int> >next;
			for(it=crt.OP;it!=crt.ED;++it){
				vector<int>t=*it;
				int v=((s[t[1]]-s[t[0]])^(s[t[2]]-s[t[0]]))*(s[i]-s[t[0]])<0?-1:1;
				if(v<0)next.PB(t);
				for(int j=0;j<3;j++){
					int x=t[j],y=t[(j+1)%3];
					if(vs[y][x]==0)vs[x][y]=v;
					else {
						if(vs[y][x]!=v){
							if(v>0){L.clear();L.PB(x);L.PB(y);L.PB(i);next.PB(L);}
							else {L.clear();L.PB(y);L.PB(x);L.PB(i);next.PB(L);}
						}
						vs[y][x]=0;
					}
				}
			}
			crt=next;
		}
		int m=0;
		for(int i=0;i<crt.SZ;i++)
			p[m++]=sfl(s[crt[i][0]],s[crt[i][1]],s[crt[i][2]]);
		return m;
	}

**4 多边形与一个圆面积交**
>验题:poj3675

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
			S=.5*a*r*sin( theta )+( C-theta )/2*r*r;
		} else S=.5*sin( C )*a*b;
		return S;
	}
	double area() {
		double S=0;
		for ( int i=0; i<n; i++ )
			S+=area2( info[i],info[i+1] )*sign( info[i]^info[i+1] );
		return fabs( S );
	}

**5 最小圆覆盖**
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
	
**6 三维操作**

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

**7 平面最近点对**
> 验题:zoj 2107

	const int MAXN = int ( 1e5 + 10 );
	double closed;
	struct Point {
		double x, y;
		int id;
	};
	Point pts[MAXN],lP[MAXN],rP[MAXN];
	struct cmpY {
		bool operator()( const Point &lhs, const Point &rhs ) {
			return lhs.y < rhs.y;
		}
	};
	struct cmpX {
		bool operator()( const Point &lhs, const Point &rhs ) {
			return lhs.x < rhs.x;
		}
	};
	double dist( const Point &pt1, const Point &pt2 ) {
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