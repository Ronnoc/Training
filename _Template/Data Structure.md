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
**2 SAM**

	const int MXN = 100000 + 10;///TODO
	const int goSZ = 26;		///TODO
	inline int mhash(char c) {	///TODO
		return c-'a';
	}
	struct SAM {
		struct State {
			State *suf,*go[goSZ],*nxt;//Parent=suf
			int val,cnt,le;//le~val |Right|=cnt
			int ans;
			void clear() {
				val=cnt=le=0,suf=nxt=0;
				ans=0;
				memset(go,0,sizeof go);
			}
		}*root,*last;
		State pool[MXN<<1|1],*cur;
		State *head[MXN|1];
		int L;
		void init() {
			L=0,cur=pool;
			cur->clear();
			root=last=cur++;
		}
		void extend(int w) {
			L++;
			State *p=last,*np=cur++;
			cur->clear();
			np->val=p->val+1,np->cnt=1;
			while(p&&!p->go[w])p->go[w]=np,p=p->suf;
			if(!p)np->suf=root;
			else {
				State *q=p->go[w];
				if(p->val+1==q->val)np->suf=q;
				else {
					State *nq=cur++;
					cur->clear();
					memcpy(nq->go,q->go,sizeof q->go);
					nq->val=p->val+1;
					nq->suf=q->suf;
					q->suf=nq;
					np->suf=nq;
					while(p&&p->go[w]==q)
						p->go[w]=nq,p=p->suf;
				}
			}
			last=np;
		}
		void topo() {
			for(int i=0; i<=L; i++)head[i]=0;
			for(State *p=pool; p!=cur; ++p) {
				p->nxt=head[p->val],head[p->val]=p;
				if(p->suf)p->le=p->suf->val+1;
				else p->le=1;
			}
			for(int i=L; i>=0; --i)
				for(State *p=head[i]; p; p=p->nxt)
					if(p->suf)p->suf->cnt+=p->cnt;
		}
		void solve(char *s="") {
			State *now=root;
			int len=0;
			for(int i=0;s[i];i++){
				int w=mhash(s[i]);
				if(now->go[w]){
					len++;
					now=now->go[w];
				}else {
					while(now->suf&&!now->go[w])
						now=now->suf;
					if(now->go[w]){
						len=now->val+1;
						now=now->go[w];
					}else len=0;
				}
				cmax(now->ans,len);
			}
			for(State *p=pool;p!=cur;++p)if(p->suf)
				cmax(p->ans,p->suf->ans);
			int ans=0;
			for(State *p=pool;p!=cur;++p)
				cmax(ans,p->ans);
			printf("%d\n",ans);
		}
	} foo;

**3 BIT**

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
		int find_Kth(int k){		//UESTC_Dagon
			int idx=0;
			for(int i=20;i>=0;i--){
				idx|=1<<i;
				if(idx<=n&&_[idx]<k)k-=_[idx];
				else idx^=1<<i;
			}
			return idx-2;
		}
	}Y;

**4 SGT**

	const int MXN = 100000 + 10;
	struct SEG {
		int l,r,m,lazy;
		SEG( int _l=0,int _r=0 ) {l=_l,r=_r;}
	} SGT[MXN<<2|1];
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

