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
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;
int x[100005];
int y[100005];
int r[100005];
vector<pair<double,double> >TL;
int sign(double x){
	return x<-eps?-1:x>eps;
}
void play(double le,double re){
	//cout<<"p "<<le<<" "<<re<<"\n";
	if(sign(le+PI)<=0&&sign(re+PI)>=0){
		TL.PB(MP(-PI,re));
		TL.PB(MP(le+2*PI,PI));
	}else if(sign(le-PI)<=0&&sign(re-PI)>=0){
		TL.PB(MP(-PI,re-2*PI));
		TL.PB(MP(le,PI));
	}else TL.PB(MP(le,re));
}
int main(){
	int i,j,k,_T;
	int p,q,v,T;
	while(~scanf("%d%d%d%d",&p,&q,&v,&T)){
		int init=0;
		TL.clear();
		int n;
		scanf("%d",&n);
		double d=1.*v*T;
		for(i=1;i<=n;i++){
			scanf("%d%d%d",&x[i],&y[i],&r[i]);
			x[i]-=p,y[i]-=q;
			if(1LL*r[i]*r[i]>=1LL*x[i]*x[i]+1LL*y[i]*y[i])
				init=1;
			else {
				double alpha=atan2(y[i],x[i]);
				double len=sqrt(1LL*x[i]*x[i]+1LL*y[i]*y[i]);
				double s=sqrt(1LL*x[i]*x[i]+1LL*y[i]*y[i]
							 -1LL*r[i]*r[i]);
				double beta=atan2(r[i],s);
				if(sign(d-s)<0){
					if(sign(d+r[i]-len)>0){
						double theta=acos(
							(-1LL*r[i]*r[i]+len*len+d*d)/(2*len*d) );
						play(alpha-theta,alpha+theta);
					}
				}else 
					play(alpha-beta,alpha+beta);
			}
		}
		sort(TL.OP,TL.ED);
		double last=-PI;
		double res=2*PI;
		for(auto z:TL){
			//cout<<z.AA/PI<<"~"<<z.BB/PI<<"\n";
			if(sign(z.AA-last)>=0){
				res-=z.AA-last;
				last=z.BB;
			}else {
				cmax(last,z.BB);
			}
		}
		res-=PI-last;
		if(!init)
			printf("%.16f\n",res/(2*PI));
		else printf("%.16f\n",1.);
	}
	return 0;
}