#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const LL MOD = (1<<28)-1;
const double PI = acos(-1.);
const double eps = 1e-9;
LL modPow(LL a,LL b,LL MOD){
	LL ret=1;for(;b;b>>=1){
		if(b&1)ret=ret*a%MOD;a=a*a%MOD;
	}return ret;
}
int N,X,L,km;
int a[100005];
int S[100005];
int dp[100005];
struct node{
	node * _[2];
	deque<PII>Q;
	node(){init();}
	void init(){_[0]=_[1]=NULL;while(!Q.empty())Q.pop_back();}
};
void update(node *T,int id){
	deque<PII>&Q=T->Q;
	while(!Q.empty()&&Q.back().AA<=dp[id])Q.pop_back();
	Q.PB(MP(dp[id],id));
}
int solve(){
	node *root=new node();
	root->init();
	node *now=root;
	dp[0]=0;
	update(now,0);
	for(int i=0;i<km;i++){
		now->_[0]=new node();
		now->_[0]->init();
		now=now->_[0];
		update(now,0);
	}
	for(int i=1;i<=N;i++){
		dp[i]=0;
		node *now=root;
		int k;
		for(k=km-1;k>=0;k--){
			int me=S[i]>>k&1;
			if(X>>k&1){
				node* free=now->_[me];
				if(free){
					while(!free->Q.empty()&&free->Q.front().BB<i-L)
						free->Q.pop_front();
					if(!free->Q.empty()){
						//cout<<k<<"@"<<T[free].Q.front().AA<<" "<<T[free].Q.front().BB<<"\n";
						cmax(dp[i],free->Q.front().AA+1);
					}
				}
				if(now->_[me^1])
					now=now->_[me^1];
				else break;
			}else {
				if(now->_[me])
					now=now->_[me];
				else break;
			}
		}
		if(k==-1){
			node* free=now;
			while(!free->Q.empty()&&free->Q.front().BB<i-L)
				free->Q.pop_front();
			if(!free->Q.empty()){
				cmax(dp[i],free->Q.front().AA+1);
			}
		}
		if(dp[i]){
			now=root;
			update(now,i);
			for(k=km-1;k>=0;k--){
				int me=S[i]>>k&1;
				if(!now->_[me]){
					now->_[me]=new node();
					now->_[me]->init();
				}
				now=now->_[me];
				update(now,i);
			}
		}
	}
	return dp[N];
}
int main(){
	int i,j,k,_T;
	scanf("%d",&_T);
	for(int CA=1;CA<=_T;CA++){
		scanf("%d%d%d",&N,&X,&L);
		int P,Q;
		scanf("%d%d%d",&a[1],&P,&Q);
		for(i=2;i<=N;i++)a[i]=(1LL*a[i-1]*P+Q)&MOD;
		S[0]=0;
		for(i=1;i<=N;i++)S[i]=S[i-1]^a[i];
		int me=*max_element(a+1,a+N+1);
		km=0;
		while(me>>km)km++;
		printf("%d\n",solve());
	}
	return 0;
}