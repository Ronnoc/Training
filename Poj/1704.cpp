class Matrix
{
private:
    int r, c;
    long long ele[MAXS][MAXS];
public:
    Matrix(int _r=0, int _c=0):r(_r),c(_c)
    {
        memset(ele, 0, sizeof(ele));
	Matrix( int _r, int _c, long long v ) { //µ•Œªæÿ’Û
		new( this )Matrix( _r, _c );
		for ( int i=0; i<_r && i<_c; i++ )
			ele[i][i] = v;
		}
	int getSum() {
		long long ret=0;
		for ( int i=0; i<r; i++ )
			for ( int j=0; j<c; j++ )
				ret = ( ret+ele[i][j] )%mod;
		return ( int )ret;
		}
	friend Matrix operator*( Matrix a, Matrix b ) {
		Matrix product( a.r, b.c );
		for ( int i=0; i<a.r; i++ )
			for ( int j=0; j<a.c; j++ )
				for ( int k=0; k<b.c; k++ )
					product.ele[i][j] = ( product.ele[i][j] + ( a.ele[i][k] )*( b.ele[k][j] ) )%mod;
		return product;
		}
	void update( int x, int y, int c ) {
		ele[x][y] = ( c+ele[x][y] )%mod;
		}
	void modify( int x, int y, int c ) {
		ele[x][y] = c%mod;
		}
	Matrix pow( int n ) {
		Matrix ret( r, c, 1 ), base = ( *this );
		for ( int i=n; i; base = base*base,i>>=1 )
			if ( i&1 )
				ret = ret*base;
		return ret;
		}
	};
