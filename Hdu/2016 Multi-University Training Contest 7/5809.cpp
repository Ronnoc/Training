//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<cstdlib>
#include<cctype>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<fstream>
#include<numeric>
#include<iomanip>
#include<bitset>
#include<list>
#include<stdexcept>
#include<functional>
#include<utility>
#include<ctime>
#include<cassert>
using namespace std;
#define RI(X) scanf("%d", &(X))
#define DRI(X) int (X); scanf("%d", &X)
#define rep(i,a,n) for(int i=(a);i<(int)(n);i++)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
#define SQ(x) ((x)*(x))
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;

LL modPow(LL a,LL b,LL MOD){
	LL ret=1;for(;b;b>>=1){
		if(b&1)ret=ret*a%MOD;a=a*a%MOD;
	}return ret;
}

const int MXN = 100005;
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
int xx[MXN],yy[MXN];
int tid[MXN];
int fa[MXN];
int getfa(int u){return fa[u]==u?u:fa[u]=getfa(fa[u]);}
void solve(){
    DRI(N);DRI(Q);
    rep(i,0,N)scanf("%d%d",&xx[i],&yy[i]);
    rep(i,0,N){
        p[i].a[0]=xx[i];
        p[i].a[1]=yy[i];
        p[i].id=i+1;
    }
    initKdTree(N);
    rep(i,0,N){
    	while(!Ans.empty())Ans.pop();
        queryO(root,p[i],2);
    	tid[p[i].id]=Ans.top().BB.id;
    }
    rep(i,1,N+1)fa[i]=i;
    rep(i,1,N+1)fa[getfa(i)]=fa[getfa(tid[i])];
    while(Q--){
    	DRI(l);DRI(r);
    	printf("%s\n",getfa(l)==getfa(r)?"YES":"NO");
    }
}
int main(){
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		printf("Case #%d:\n",CA+1);
		solve();
	}
	return 0;
}