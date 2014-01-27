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
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

using namespace std;

const double eps = 1e-8;
const int MOD = 1000000007;
#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(X) sort(X.OP,X.ED)
#define SQ(x) ((x)*(x))
typedef long long LL;
typedef pair<int, int> PII;
int dcmp(double x) {return x < -eps ? -1 : x > eps;}
struct point {
		double x, y;
		point() {}
		point(double _x, double _y) : x(_x), y(_y) {}
		point operator - (point p) {return point(x - p.x, y - p.y);}
		point operator + (point p) {return point(x + p.x, y + p.y);}
		point operator / (double d){return point(x / d, y / d);}
		point operator * (double d){return point(x * d, y * d);}
		double operator ^ (point p) {return x * p.y - y * p.x;} //叉积
		double operator * (point p) {return x * p.x + y * p.y;} //点积
		double len(){return hypot(x, y);}
		double arc(){return atan2(y, x);}
		bool operator < (const point &p)const {
				return dcmp(x - p.x) == 0 ? dcmp(y - p.y) <= 0 : dcmp(x - p.x) <= 0;
		}
		point normal() {return (*this) / this->len();}	 //规范化
		point rotate(){return point(-y, x);}		 //关于原点对称
		point rotate(double arc){				//绕原点旋转arc角度
				return point(x * cos(arc) - y * sin(arc), x * sin(arc) + y * cos(arc));
		}
		double dis(point p){return (*this - p).len();}
		double dis2(point p){p = p - (*this); return p*p;}
		void out(){printf("%lf %lf",x,y);}
};
point l[111],r[111];
bool play(point la,point lb,point sa,point sb){
	double ka=(lb-la)^(sa-la);
	double kb=(lb-la)^(sb-la);
	if(dcmp(ka)==0)return 1;
	if(dcmp(kb)==0)return 1;
	return (dcmp(ka)*dcmp(kb))<0;
}
void solve(){
	int i,j,k;
	int T;
	scanf("%d",&T);
	while(T--){
		vector<point>L;
		int n;
		scanf("%d",&n);
		for(i=1;i<=n;i++)scanf("%lf%lf%lf%lf",&l[i].x,&l[i].y,&r[i].x,&r[i].y);
		for(i=1;i<=n;i++)L.PB(l[i]);
		for(i=1;i<=n;i++)L.PB(r[i]);
		int yes=0;
		for(i=0;!yes&&i<L.SZ;i++)for(j=i+1;!yes&&j<L.SZ;j++){
			if(dcmp(L[i].x-L[j].x)==0&&dcmp(L[i].y-L[j].y)==0)continue;
			int all=1;
			for(k=1;k<=n;k++)if(!play(L[i],L[j],l[k],r[k])){all=0;break;}
			if(all)yes=1;
		}
		if(yes)printf("Yes!\n");
		else printf("No!\n");
	}
}
int main(){
//	while(1)
		solve();
	return 0;
}
