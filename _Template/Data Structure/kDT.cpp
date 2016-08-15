//**kdTree**
//>验题: hdu5809
int K,iCmp,nTid;
struct Obj{
	LL a[2];
	int id;
	LL operator [](int id)const{return a[id];}
	bool operator < (const Obj &c)const{
		if(a[iCmp]!=c[iCmp])return a[iCmp]<c[iCmp];
		rep(i,1,K)if(a[i]!=c[i])return a[i]<c[i];
		return id<c.id;
	}
};
struct Filter{
	Obj L,R;
	bool ok(Obj &o){
		rep(i,0,K)if(o[i]<L[i]||o[i]>R[i])return 0;
		return 1;
	}
};
LL dis(Obj &a,Obj &b){
	LL ret=0;
	rep(i,0,K)ret+=SQ(a[i]-b[i]);
	return ret;
}
struct Node{
	Obj u;
	char c;
	Node *ls,*rs;
};
Node kd[MXN<<2],*root;
Node *newNode(const Obj &u,int c){
	Node &G=kd[nTid++];
	G.u=u,G.c=c,G.ls=G.rs=NULL;
	return &G;
}
Node *build(Obj a[],int l,int r,int c){
	if(l>=r)return NULL;
	int mid=(l+r)>>1;
	iCmp=c;
	nth_element(a+l,a+mid,a+r);
	Node *G=newNode(a[mid],c);
	G->ls=build(a,l,mid,(c+1)%K);
	G->rs=build(a,mid+1,r,(c+1)%K);
	return G;
}
void queryF(Node *p,Filter &f){
	if(!p)return;
	int x=p->u[p->c];
	if(f.ok(p->u)){};
	if(x>=f.L[p->c])queryF(p->ls,f);
	if(x<=f.R[p->c])queryF(p->rs,f);
}
priority_queue<pair<LL,Obj> >Ans;
void queryO(Node *p,Obj &o,int m){
	if(!p)return;
	pair<LL,Obj>now(dis(o,p->u),p->u);
	int c=p->c,flag=0;
	Node *x=p->ls,*y=p->rs;
	if(o[c]>=p->u[c])swap(x,y);
	queryO(x,o,m);
	if(sz(Ans)<m)Ans.push(now),flag=1;
	else {
		if(now<Ans.top())Ans.pop(),Ans.push(now);
		if(SQ(o[c]-p->u[c])<=Ans.top().AA)flag=1;
	}
	if(flag)queryO(y,o,m);
}
Obj p[MXN];
void initKdTree(int n){
	K=2;
	nTid=0;
	root=build(p,0,n,0);
	iCmp=0;
}