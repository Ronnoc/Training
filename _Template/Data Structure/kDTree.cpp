//**kdTree**
//>验题: hdu4347

const int N = 100000 + 10;
int K, iCmp, nTid;
typedef vector<int> Obj;
void show( Obj &o ) {
	printf( "(%d", o[0] );
	for ( int i = 1; i < K; i++ )printf( ",%d", o[i] );
	printf( ")\n" );
}
struct Filter {
	Obj L, R;
	bool ok( const Obj &o )const {
		for ( int i = 0; i < K; i++ )if ( o[i] < L[i] || o[i] > R[i] )return 0;
		return 1;
	}
};
struct Node {
	Obj u;
	int c;
	Node *ls, *rs;
	void update() {
	}
};
Node kd[N << 2], *root;
bool cmp( const Obj &a, const Obj &b ) {
	return a[iCmp] < b[iCmp];
}
Node *newNode( const Obj &u, int c ) {
	Node &G = kd[nTid++];
	G.u = u;
	G.c = c;
	G.ls = G.rs = 0;
	return &G;
}
Node *build( vector<Obj> &a, int l, int r, int c ) {
	if ( l >= r )return NULL;
	int mid = ( l + r ) / 2;
	iCmp = c;
	nth_element( a.OP + l, a.OP + mid, a.OP + r, cmp );
	Node *G = newNode( a[mid], c );
	G->ls = build( a, l, mid, ( c + 1 ) % K );
	G->rs = build( a, mid + 1, r, ( c + 1 ) % K );
	G->update();
	return G;
}
void queryF( Node *p, const Filter &f ) {  //可以传总filter然后边传变算极限边界
	if ( !p )return;                       //空树
	int x = p->u[p->c];
	if ( f.ok( p->u ) ) {}                 //结点
	if ( x >= f.L[p->c] )queryF( p->ls, f ); //左子树
	if ( x <= f.R[p->c] )queryF( p->rs, f ); //右子树
}
priority_queue<pair<double, Obj>  >Ans;
void queryO( Node *p, Obj &o, int m ) {
	if ( !p )return;
	pair<double, Obj> now( 0, p->u );
	for ( int i = 0; i < K; i++ )now.AA += 1.0 * SQ( p->u[i] - o[i] );
	int c = p->c, flag = 0;
	Node *x = p->ls, *y = p->rs;
	if ( o[c] >= p->u[c] )swap( x, y );
	queryO( x, o, m );
	if ( Ans.SZ < m )Ans.push( now ), flag = 1;
	else {
		if ( now.AA < Ans.top().AA )Ans.pop(), Ans.push( now );
		if ( 1.0 * SQ( o[c] - p->u[c] ) < Ans.top().AA )flag = 1;
	}
	if ( flag )queryO( y, o, m );
}
vector<Obj>p;
void initKdTree() {
	//set K
	nTid = 0;
	root = build( p, 0, p.SZ, 0 );
}