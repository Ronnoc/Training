#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps=1e-8;
const double PI=acos(-1.);
const LL MOD = 1000000007;

vector<PII>gao(int *x,int n,int *X,int *use,int &U,int &len) {
	int i,j,k;
	for(i=0; i<n; i++)X[i]=x[i];
	int mx=*max_element(X,X+n);
	len=0;
	while((1LL<<len)<=mx)len++;
	vector<PII>ret;
	for(j=k=0; k<len; k++) {
		int tmp=-1;
		for(i=j; i<n; i++)if(X[i]>>k&1) {tmp=i; break;}
		use[k]=-1;
		if(tmp==-1)continue;
//		for(i=0;i<n;i++)cout<<X[i]<<" ";cout<<endl;
		if(tmp!=j) {
			ret.PB(MP(j,tmp)); X[j]^=X[tmp];
			ret.PB(MP(tmp,j)); X[tmp]^=X[j];
			ret.PB(MP(j,tmp)); X[j]^=X[tmp];
		}
//		for(i=0;i<n;i++)cout<<X[i]<<" ";cout<<endl;
		for(i=0; i<n; i++)if(i!=j)
				if(X[i]>>k&1) {
					ret.PB(MP(i,j));
					X[i]^=X[j];
				}
//		for(i=0;i<n;i++)cout<<X[i]<<" ";cout<<endl;
//		cout<<endl;
		use[k]=j++;
	}
	U=j;
	return ret;
}
int x[10005],X[10005];
int y[10005],Y[10005];
int useX[66],useY[66];
int UX,UY,lenX,lenY;
int main() {
//	freopen("F.in","r",stdin);
//	freopen("","w",stdout);
	int i,j,k,T;
	int n,U,len;
	while(~scanf("%d",&n)) {
		for(i=0; i<n; i++)scanf("%d",&x[i]);
		for(i=0; i<n; i++)scanf("%d",&y[i]);
		memset(useX,-1,sizeof useX);
		memset(useY,-1,sizeof useY);
		vector<PII>px=gao(x,n,X,useX,UX,lenX);
		vector<PII>py=gao(y,n,Y,useY,UY,lenY);
		map<int,int>mx,my;
		for(i=0;i<lenY;i++)if(~useY[i])my[useY[i]]=i;
		for(i=0;i<lenX;i++)if(~useX[i])mx[useX[i]]=i;
//		for(cout<<"uy:",i=0;i<lenY;i++)if(~useY[i])cout<<i<<endl;
//		for(cout<<"ux:",i=0;i<lenX;i++)if(~useX[i])cout<<i<<endl;
		int fail=0;
		for(i=0;i<lenY;i++)if(~useY[i])
			if(useX[i]==-1)fail=1;
		for(i=0;i<lenX;i++)if(~useX[i]){
			if(useY[i]==-1){
				int id=useX[i];
				for(j=0;j<UY;j++)if(Y[j]>>i&1){
					int t=my[j];
					int s=useX[t];
					px.PB(MP(s,id));
					X[s]^=X[id];
				}
				px.PB(MP(id,id));
				X[id]^=X[id];
				useX[i]=-1;
			}
		}
//		for(i=0;i<n;i++)cout<<X[i]<<" ";cout<<endl;
//		for(i=0;i<n;i++)cout<<Y[i]<<" ";cout<<endl;
		vector<int>tx,ty;
		for(i=0;i<UX;i++)if(X[i])tx.PB(X[i]);
		for(i=0;i<UY;i++)if(Y[i])ty.PB(Y[i]);
		SORT(tx);
		SORT(ty);
		if(tx.SZ!=ty.SZ)fail=1;
		else {
			for(i=0;i<tx.SZ;i++)if(tx[i]!=ty[i])fail=1;
		}
		for(i=0;i<UY;i++){
			for(j=i;j<UX;j++)if(X[j]==Y[i])break;
			if(i!=j){
				px.PB(MP(i,j));X[i]^=X[j];
				px.PB(MP(j,i));X[j]^=X[i];
				px.PB(MP(i,j));X[i]^=X[j];
			}
		}
		for(i=py.SZ-1;i>=0;i--){
			int u=py[i].AA;
			int v=py[i].BB;
			px.PB(MP(u,v));
			X[u]^=X[v];
		}
//		for(i=0;i<n;i++)cout<<X[i]<<" ";cout<<endl;
//		for(i=0;i<n;i++)cout<<y[i]<<" ";cout<<endl;
		for(i=0;i<n;i++)if(X[i]!=y[i])fail=1;
		if(fail)printf("-1\n");
		else {
			printf("%d\n",px.SZ);
			for(i=0; i<px.SZ; i++)printf("%d %d\n",px[i].AA+1,px[i].BB+1);
		}
	}
	return 0;
}
/*
19
299680915 393032551 493663697 236674617 241039110 148124291 285038573 118601390 178201606 158160059 424891269 133264977 49764237 367021593 354153886 218980937 329836106 111979647 479144750
239468561 496077836 332893213 169604566 394951130 432830923 394951130 394951130 239468561 394951130 0 0 394951130 332893213 332893213 169604566 0 0 73266631
*/
