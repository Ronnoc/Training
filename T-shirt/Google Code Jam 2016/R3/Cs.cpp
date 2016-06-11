#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
#define SQ(x) ((x)*(x))
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;
const int MXN = 1005;
int sign(double t){return t<-eps?-1:t>eps;}
struct spt {
	double x,y,z;
	spt( double _x=0,double _y=0,double _z=0 ):x( _x ),y( _y ),z(_z) {}
	spt operator +( spt s ) {return spt( x+s.x,y+s.y,z+s.z );}
	spt operator -( spt s ) {return spt( x-s.x,y-s.y,z-s.z );}
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
int fa[MXN];
int getfa(int u){
	return fa[u]==u?u:fa[u]=getfa(fa[u]);
}
int n,leap;
int x[MXN],y[MXN],z[MXN];
int dx[MXN],dy[MXN],dz[MXN];
double cal(int p,int q,int t){
	LL fx=x[p]-x[q]+t*(dx[p]-dx[q]);
	LL fy=y[p]-y[q]+t*(dy[p]-dy[q]);
	LL fz=z[p]-z[q]+t*(dz[p]-dz[q]);
	return sqrt(fx*fx+fy*fy+fz*fz);
}
double tl[MXN][MXN],tr[MXN][MXN];
double dp[MXN][MXN];
double calmin(int p,int q){
	spt p1(x[p],y[p],z[p]),p2(x[p]+dx[p],y[p]+dy[p],z[p]+dz[p]);
	spt q1(x[q],y[q],z[q]),q2(x[q]+dx[q],y[q]+dy[q],z[q]+dz[q]);
	return disLL(p1,p2,q1,q2);
}
double calLP(int p,int q){
	spt p1(x[p],y[p],z[p]),p2(x[p]+dx[p],y[p]+dy[p],z[p]+dz[p]);
	spt q1(x[q],y[q],z[q]),q2(x[q]+dx[q],y[q]+dy[q],z[q]+dz[q]);
	return disLP(q1,q2,p1);
}
void solvelarge(){
	int i,j,k;
	scanf("%d%d",&n,&leap);
	for(i=1;i<=n;i++)
		scanf("%d%d%d%d%d%d",&x[i],&y[i],&z[i],&dx[i],&dy[i],&dz[i]);
	vector<pair<double,PII> >L;
	L.clear();
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++){
			double fun=-1;
			int oki=dx[i]||dy[i]||dz[i];
			int okj=dx[j]||dy[j]||dz[j];
			if(oki&&okj)fun=calmin(i,j);
			else if(oki)fun=calLP(j,i);
			else if(okj)fun=calLP(i,j);
			else fun=cal(i,j,0);
			L.PB(MP(fun,MP(i,j)));
			
		}
	sort(L.OP,L.ED);
	for(i=1;i<=n;i++)fa[i]=i;
	double le=-1,re=cal(1,2,0);
	for(i=0;i<L.SZ;i++){
		int u=L[i].BB.AA,v=L[i].BB.BB;
		int fu=getfa(u),fv=getfa(v);
		fa[fu]=fv;
		if(getfa(1)==getfa(2)){
			le=L[i].AA;
			break;
		}
	}
	while(re-le>1e-5){
		double me=(le+re)/2;
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++){
				int oki=dx[i]||dy[i]||dz[i];
				int okj=dx[j]||dy[j]||dz[j];
				if(!oki&&!okj)tl[i][j]=0,tr[i][j]=N*leap;
				else {
					spt A(x[i]-x[j],y[i]-y[j],z[i]-z[j]);
					spt B(x[i]-x[j]+dx[i]-dx[j],
						  y[i]-y[j]+dy[i]-dy[j],
						  z[i]-z[j]+dz[i]-dz[j]);
					double d=disLP(A,B,Orz);
					if(d>me)tl[i][j]=tr[i][j]=0;
					else {
						
					}
				}
			}
	}
	printf("%.7f\n",(le+re)/2);
}
void solvesmall(){
	int i,j,k;
	scanf("%d%d",&n,&leap);
	for(i=1;i<=n;i++)
		scanf("%d%d%d%d%d%d",&x[i],&y[i],&z[i],&dx[i],&dy[i],&dz[i]);
	vector<pair<double,PII> >L;
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			L.PB(MP(cal(i,j,0),MP(i,j)));
	sort(L.OP,L.ED);
	for(i=1;i<=n;i++)fa[i]=i;
	for(i=0;i<L.SZ;i++){
		int u=L[i].BB.AA,v=L[i].BB.BB;
		int fu=getfa(u),fv=getfa(v);
		fa[fu]=fv;
		int f1=getfa(1),f2=getfa(2);
		if(f1==f2){
			printf("%.16f\n",L[i].AA);
			return;
		}
	}
}
int main(){
	int i,j,k,_T;
	scanf("%d",&_T);
	for(int CA=1;CA<=_T;CA++){
		printf("Case #%d: ",CA);
		solvelarge();
	}
	return 0;
}