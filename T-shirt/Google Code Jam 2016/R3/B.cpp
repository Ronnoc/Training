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
int fa[105];
int ff[105][105];
vector<int>G[105];
vector<int>Son[105];
char s[105];
void buildSon(int u,int f){
	for(auto v:G[u])if(v!=f){
		buildSon(v,u);
		Son[u].PB(v),ff[u][v]=v;
		for(auto w:Son[v])
			Son[u].PB(w),ff[u][w]=v;
	}
}
int ID[105];
string SU[105];
string get_random(int u,int f){
	random_shuffle(Son[u].OP,Son[u].ED);
	string ret(s,s+Son[u].SZ);
	for(auto v:G[u])if(v!=f)
		SU[v]=get_random(v,u),ID[v]=0;
	for(int i=0;i<Son[u].SZ;i++){
		int sv=ff[u][Son[u][i]];
		ret[i]=SU[sv][ID[sv]++];
	}
	return s[u]+ret;
}
int main(){
	srand(time(NULL));
	int i,j,k,_T;
	scanf("%d",&_T);
	for(int CA=1;CA<=_T;CA++){
		printf("Case #%d:",CA);
		int n,m;
		string q[5];
		int p[5];
		
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&fa[i]);
		scanf("%s",s+1);
		scanf("%d",&m);
		for(i=0;i<m;i++)
			cin>>q[i];
		
		memset(p,0,sizeof p);
		memset(ff,0,sizeof ff);
		for(i=0;i<=n;i++)
			G[i].clear(),Son[i].clear();
		
		for(i=1;i<=n;i++)G[fa[i]].PB(i);
		buildSon(0,-1);
		int tot=10000;
		while(tot--){
			string z=get_random(0,-1);
			for(i=0;i<m;i++)
				if(z.find(q[i])!=string::npos)
					p[i]++;
		}
		for(i=0;i<m;i++)
			printf(" %.4f",p[i]/10000.);
		printf("\n");
		cerr<<"done@"<<CA<<"\n";
	}
	cerr<<(double)clock() / CLOCKS_PER_SEC<<"seconds\n";//148s
	return 0;
}