const int MXN = 100000 + 10;
struct SEG {
	int l, r, m, lazy;
	SEG( int _l = 0, int _r = 0 ) {l = _l, r = _r;}
} SGT[MXN << 2 | 1];
void create( SEG &T, int t ) {
	T.m = 0;
	T.lazy = 0;
}
void fresh( SEG &T, SEG &L, SEG &R ) {
}
void build( int id, int l, int r ) {
	SGT[id] = SEG( l, r );
	int mid = ( l + r ) / 2;
	if ( l != r ) {
		build( id * 2, l, mid );
		build( id * 2 + 1, mid + 1, r );
		fresh( SGT[id], SGT[id << 1], SGT[id << 1 | 1] );
	} else create( SGT[id], l );
}
void update( int id, int l, int r, int w ) {
	SEG &T = SGT[id];
	int mid = ( T.l + T.r ) / 2;
	if ( T.l == l && T.r == r ) {
		T.m = w;
		return;
	}
	if ( T.lazy ) {
		update( id << 1, T.l, mid, T.lazy );
		update( id << 1 | 1, mid + 1, T.r, T.lazy );
		T.lazy = 0;
	}
	if ( r <= mid )update( id << 1, l, r, w );
	else if ( l > mid )update( id << 1 | 1, l, r, w );
	else {
		update( id << 1, l, mid, w );
		update( id << 1 | 1, mid + 1, r, w );
	}
	fresh( T, SGT[id << 1], SGT[id << 1 | 1] );
}
void query( int id, SEG &A ) {
	SEG &T = SGT[id];
	if ( T.lazy ) {
		int mid = (T.l + T.r) / 2;
		update( id << 1, T.l, mid, T.lazy );
		update( id << 1 | 1, mid + 1, T.r, T.lazy );
		T.lazy = 0;
	}
	if (T.l == A.l && T.r == A.r) {A = T; return;}
	int mid = ( T.l + T.r ) / 2;
	if ( A.r <= mid )query( id << 1, A );
	else if ( A.l > mid )query( id << 1 | 1, A );
	else {
		SEG L( A.l, mid ), R( mid + 1, A.r );
		query( id << 1, L );
		query( id << 1 | 1, R );
		fresh( A, L, R );
	}
}