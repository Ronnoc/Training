**1 kdTree**
>验题: hdu4347

	const int N = 100000+10;
	int K,iCmp,nTid;
	typedef vector<int> Obj;
	void show( Obj &o ) {
		printf( "(%d",o[0] );
		for ( int i=1; i<K; i++ )printf( ",%d",o[i] );
		printf( ")\n" );
	}
	struct Filter {
		Obj L,R;
		bool ok( const Obj &o )const {
			for ( int i=0; i<K; i++ )if ( o[i]<L[i]||o[i]>R[i] )return 0;
			return 1;
		}
	};
	struct Node {
		Obj u;
		int c;
		Node *ls,*rs;
		void update() {
		}
	};
	Node kd[N<<2],*root;
	bool cmp( const Obj &a,const Obj &b ) {
		return a[iCmp]<b[iCmp];
	}
	Node *newNode( const Obj &u,int c ) {
		Node &G=kd[nTid++];
		G.u=u;
		G.c=c;
		G.ls=G.rs=0;
		return &G;
	}
	Node *build( vector<Obj> &a,int l,int r,int c ) {
		if ( l>=r )return NULL;
		int mid=( l+r )/2;
		iCmp=c;
		nth_element( a.OP+l,a.OP+mid,a.OP+r,cmp );
		Node *G=newNode( a[mid],c );
		G->ls=build( a,l,mid,( c+1 )%K );
		G->rs=build( a,mid+1,r,( c+1 )%K );
		G->update();
		return G;
	}
	void queryF( Node *p,const Filter &f ) {   //可以传总filter然后边传变算极限边界
		if ( !p )return;                       //空树
		int x=p->u[p->c];
		if ( f.ok( p->u ) ){}                  //结点
		if ( x>=f.L[p->c] )queryF( p->ls,f );  //左子树
		if ( x<=f.R[p->c] )queryF( p->rs,f );  //右子树
	}
	priority_queue<pair<double,Obj>  >Ans;
	void queryO( Node *p,Obj &o,int m ) {
		if ( !p )return;
		pair<double,Obj> now( 0,p->u );
		for ( int i=0; i<K; i++ )now.AA+=1.0*SQ( p->u[i]-o[i] );
		int c=p->c,flag=0;
		Node *x=p->ls,*y=p->rs;
		if ( o[c]>= p->u[c] )swap( x,y );
		queryO( x,o,m );
		if ( Ans.SZ<m )Ans.push( now ),flag=1;
		else {
			if ( now.AA<Ans.top().AA )Ans.pop(),Ans.push( now );
			if ( 1.0*SQ( o[c]-p->u[c] )<Ans.top().AA )flag=1;
		}
		if ( flag )queryO( y,o,m );
	}
	vector<Obj>p;
	void initKdTree() {
		//set K
		nTid=0;
		root=build( p,0,p.SZ,0 );
	}

**2 BIT**

	inline int LB(int x){return x&(-x);}
	struct BIT{
		LL _[MXN];
		int n;
		void init(int m){
			n=m+5;
			for(int i=0;i<=n;i++)_[i]=0;
		}
		LL query(int w){
			LL ret=0;
			for(w+=3;w>0;w-=LB(w))ret+=_[w];
			return ret;
		}
		void update(int w,LL d){
			for(w+=3;w<n;w+=LB(w))_[w]+=d;
		}
	};


**3 SGT**

	const int MXN = 100000 + 10;
	struct SEG {
		int l,r,m,lazy;
		SEG( int _l=0,int _r=0 ) {l=_l,r=_r;}
	} SGT[MXN<<2];
	void create( SEG &T,int t ) {
		T.m=0;
		T.lazy=0;
	}
	void fresh( SEG &T,SEG &L,SEG &R ) {
	}
	void build( int id,int l,int r ) {
		SGT[id]=SEG( l,r );
		int mid=( l+r )/2;
		if ( l!=r ) {
			build( id*2,l,mid );
			build( id*2+1,mid+1,r );
			fresh( SGT[id],SGT[id<<1],SGT[id<<1|1] );
		} else create( SGT[id],l );
	}
	void update( int id,int l,int r,int w ) {
		SEG &T=SGT[id];
		int mid=( T.l+T.r )/2;
		if ( T.l==l&&T.r==r ) {
			T.m=w;
			return;
		}
		if ( T.lazy ) {
			update( id<<1,T.l,mid,T.lazy );
			update( id<<1|1,mid+1,T.r,T.lazy );
			T.lazy=0;
		}
		if ( r<=mid )update( id<<1,l,r,w );
		else if ( l>mid )update( id<<1|1,l,r,w );
		else {
			update( id<<1,l,mid,w );
			update( id<<1|1,mid+1,r,w );
		}
		fresh( T,SGT[id<<1],SGT[id<<1|1] );
	}
	void query( int id,SEG &A ) {
		SEG &T=SGT[id];
		if ( T.lazy ) {
			int mid=(T.l+T.r)/2;
			update( id<<1,T.l,mid,T.lazy );
			update( id<<1|1,mid+1,T.r,T.lazy );
			T.lazy=0;
		}
		if(T.l==A.l&&T.r==A.r){A=T;return;}
		int mid=( T.l+T.r )/2;
		if ( A.r<=mid )query( id<<1,A );
		else if ( A.l>mid )query( id<<1|1,A );
		else {
			SEG L( A.l,mid ),R( mid+1,A.r );
			query( id<<1,L );
			query( id<<1|1,R );
			fresh( A,L,R );
		}
	}

