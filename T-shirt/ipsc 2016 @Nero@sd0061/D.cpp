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
#define rep(i,a,n) for(int i=(a);i<(int)(n);i++)
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
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const LL MOD = 1000000009;
const double PI = acos(-1.);
const double eps = 1e-9;

LL E=47;
char query[100000+5];
VI h(){
	VI ret;
	rep(i,0,6)ret.PB(i);
	rep(b,1,6){
		E=E*53%MOD;
		swap(ret[E%(b+1)],ret[b]);
	}
	return ret;
}
map<string,string>Color;
int main(){
	Color["#ff0000"]="red";
	Color["#00ff00"]="green";
	Color["#0000ff"]="blue";
	Color["#ffff00"]="yellow";
	Color["#ff8800"]="orange";
	Color["#ff00ff"]="pink";
	
	int i,j,k;
	double t0=1466261845.335-3600;
	t0+=0.001;printf("%d %d %.3f\n",25,25,t0);
	t0+=0.001;printf("next %.3f\n",t0);
	PII last=MP(25,25);
	while(gets(query)){
		vector<PII>b,d;
		for(i=50;i<=150;i+=100)
			for(j=50;j<=250;j+=100)
				b.PB(MP(i,j));
		for(i=250;i<=450;i+=200)
			for(j=50;j<=250;j+=100)
				d.PB(MP(i,j));
		vector<string>e;
		e.PB("#ff0000");
		e.PB("#00ff00");
		e.PB("#0000ff");
		e.PB("#ffff00");
		e.PB("#ff8800");
		e.PB("#ff00ff");
		VI f=h();
		VI g=h();
		map<string,PII>Click;
		Click["background"]=MP(25,25);
		rep(c,0,6)
			Click[Color[e[f[c]]]+" square"]=
				MP(b[c].AA+25,b[c].BB+25);
		rep(c,0,6)
			Click[Color[e[g[c]]]+" wide"]=
				MP(d[c].AA+50,d[c].BB+25);
		string Qy=query;
		string time=" times";
		string sec=" seconds";
		rep(i,0,sz(Qy)){
			for(auto w:Click){
				if(i+sz(w.AA)<=sz(Qy))
					if(Qy.substr(i,sz(w.AA))==w.AA){
						t0+=0.001;
						printf("%d %d %.3f\n",w.BB.AA,w.BB.BB,t0);
						last=w.BB;
					}
			}
			if(i+sz(time)<=sz(Qy))
				if(Qy.substr(i,sz(time))==time){
					j=i-1;
					while(Qy[j]>='0'&&Qy[j]<='9')j--;
					int what=0;
					for(k=j+1;k<i;k++)
						what=what*10+Qy[k]-'0';
					what--;
					while(what--){
						t0+=0.001;
						printf("%d %d %.3f\n",last.AA,last.BB,t0);
					}
				}
			if(i+sz(sec)<=sz(Qy))
				if(Qy.substr(i,sz(sec))==sec){
					j=i-1;
					while(Qy[j]>='0'&&Qy[j]<='9')j--;
					int what=0;
					for(k=j+1;k<i;k++)
						what=what*10+Qy[k]-'0';
					t0+=what+1;
				}
		}
		t0+=0.001;printf("next %.3f\n",t0);
	}
	t0+=0.001;printf("done %.3f\n",t0);
	return 0;
}