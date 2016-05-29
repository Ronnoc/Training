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
int fa[333];
int getfa(int u){
	return fa[u]==u?u:fa[u]=getfa(fa[u]);
}
void merfa(int u,int v){
	int fu=getfa(u),fv=getfa(v);
	fa[fu]=fv;
}
int id[105][105][4];
int wt[405];
int pr[405];
int res[105][105];
void solve(){
	int i,j,k;
	int R,C;
	scanf("%d%d",&R,&C);
	for(i=1;i<=2*(R+C);i++)
		scanf("%d",&wt[i]);
	for(i=1;i<=2*(R+C);i+=2)
		pr[wt[i]]=wt[i+1],pr[wt[i+1]]=wt[i];
	if(R*C<=16&&false){
		int m=R*C;
		for(int mask=0;mask<1<<m;mask++){
			int n=4*m+2*R+2*C;
			int nid=2*R+2*C;
			for(i=0;i<R;i++)
				for(j=0;j<C;j++)
					for(k=0;k<4;k++)
						id[i][j][k]=nid++;
			for(i=0;i<nid;i++)
				fa[i]=i;
			for(i=0;i<R;i++){
				int lid=2*C+2*R-i -1;
				int rid=C+i+1 -1;
				merfa(lid,id[i][0][1]);
				merfa(rid,id[i][C-1][3]);
				for(j=1;j<C;j++)
					merfa(id[i][j-1][3],id[i][j][1]);
			}
			for(j=0;j<C;j++){
				int uid=j+1 -1;
				int did=2*C+R-j -1;
				merfa(uid,id[0][j][0]);
				merfa(did,id[R-1][j][2]);
				for(i=1;i<R;i++)
					merfa(id[i-1][j][2],id[i][j][0]);
			}
			k=0;
			for(i=0;i<R;i++)
				for(j=0;j<C;j++){
					res[i][j]=mask>>k&1;
					if(res[i][j]){//"/"
						merfa(id[i][j][0],id[i][j][1]);
						merfa(id[i][j][3],id[i][j][2]);
					}else {//"\"
						merfa(id[i][j][0],id[i][j][3]);
						merfa(id[i][j][1],id[i][j][2]);
					}
					k++;
				}
			int fail=0;
			for(i=1;i<=2*(R+C);i++){
				int fu=getfa(i-1),fv=getfa(pr[i]-1);
				if(fu!=fv)fail=1;
			}
			if(!fail){
				for(i=0;i<R;i++){
					for(j=0;j<C;j++){
						printf("%s",res[i][j]?"/":"\\");
					}
					printf("\n");
				}
				return;
			}
		}
		printf("IMPOSSIBLE\n");
		return;
	}
	if(false){
		set<vector<int> >S[105];
		map<vector<int>,vector<int> >prestat[105];
		map<vector<int>,int>preway[105];
		if(R<=10){
			vector<int>init;
			for(i=2*(C+R);i>=2*C+R+1;i--)
				init.PB(i);
			S[0].insert(init);
			for(k=0;k<C;k++){
				int le=k+1,re=2*C+R-k;
				for(auto L:S[k]){
					for(int msk=0;msk<1<<R;msk++){
						for(i=0;i<4*R+2;i++)
							fa[i]=i;
						for(i=1;i<R;i++)
							merfa(3*R+(i-1),R+i);
						merfa(R,4*R);
						merfa(4*R-1,4*R+1);
						for(i=0;i<R;i++){
							if(msk>>i&1){//"/"
								merfa(0*R+i,1*R+i);
								merfa(2*R+i,3*R+i);
							}else {//"\"
								merfa(0*R+i,3*R+i);
								merfa(2*R+i,1*R+i);
							}
						}
						for(i=0;i<R;i++)
							for(j=i+1;j<R;j++)if(L[i]==L[j])
								merfa(i,j);
						int fail=0;
						map<int,int>G;
						G[getfa(4*R+1)]=re;
						if(G.find(getfa(4*R))!=G.ED){
							int xx=le,yy=G[getfa(4*R)];
							if(pr[xx]!=yy)fail=1;
						}else G[getfa(4*R)]=le;
						for(i=0;i<R;i++){
							int Gi=getfa(i);
							if(G.find(Gi)!=G.ED){
								int xx=L[i],yy=G[Gi];
								if(pr[xx]!=yy)fail=1;
							}else G[Gi]=L[i];
						}
						if(fail){
							continue;
						}
						int fuck=2*(R+C)+1;
						vector<int>next;
						for(i=0;i<R;i++){
							int Gi=getfa(2*R+i);
							if(G.find(Gi)==G.ED)
								G[Gi]=fuck++;
							next.PB(G[Gi]);
						}
						S[k+1].insert(next);
						prestat[k+1][next]=L;
						preway[k+1][next]=msk;
					}
				}
			}
			for(auto L:S[C]){
				int fail=0;
				for(i=0;i<R;i++){
					int xx=L[i],yy=C+1+i;
					if(pr[xx]!=yy)fail=1;
				}
				if(fail)continue;
				vector<int>T=L;
				vector<int>M;
				for(i=C;i>0;i--){
					M.PB(preway[i][T]);
					T=prestat[i][T];
				}
				reverse(M.OP,M.ED);
				for(i=0;i<C;i++)
					for(j=0;j<R;j++)
						res[j][i]=M[i]>>j&1;
				for(i=0;i<R;i++){
					for(j=0;j<C;j++){
						printf("%s",res[i][j]?"/":"\\");
					}
					printf("\n");
				}
				return;
			}
			printf("IMPOSSIBLE\n");
			return;
		}else {//C<=10
			vector<int>init;
			for(i=1;i<=C;i++)
				init.PB(i);
			S[0].insert(init);
			for(k=0;k<R;k++){
				int le=2*R+2*C-k,re=C+1+k;
				for(auto L:S[k]){
					for(int msk=0;msk<1<<C;msk++){
						for(i=0;i<4*C+2;i++)
							fa[i]=i;
						for(i=1;i<C;i++)
							merfa(3*C+(i-1),C+i);
						merfa(C,4*C);
						merfa(4*C-1,4*C+1);
						for(i=0;i<C;i++){
							if(msk>>i&1){//"/"
								merfa(0*C+i,1*C+i);
								merfa(2*C+i,3*C+i);
							}else {//"\"
								merfa(0*C+i,3*C+i);
								merfa(2*C+i,1*C+i);
							}
						}
						for(i=0;i<C;i++)
							for(j=i+1;j<C;j++)if(L[i]==L[j])
								merfa(i,j);
						int fail=0;
						map<int,int>G;
						G[getfa(4*C+1)]=re;
						if(G.find(getfa(4*C))!=G.ED){
							int xx=le,yy=G[getfa(4*C)];
							if(pr[xx]!=yy)fail=1;
						}else G[getfa(4*C)]=le;
						for(i=0;i<C;i++){
							int Gi=getfa(i);
							if(G.find(Gi)!=G.ED){
								int xx=L[i],yy=G[Gi];
								if(pr[xx]!=yy)fail=1;
							}else G[Gi]=L[i];
						}
						if(fail){
							continue;
						}
						int fuck=2*(R+C)+1;
						vector<int>next;
						for(i=0;i<C;i++){
							int Gi=getfa(2*C+i);
							if(G.find(Gi)==G.ED)
								G[Gi]=fuck++;
							next.PB(G[Gi]);
						}
						S[k+1].insert(next);
						prestat[k+1][next]=L;
						preway[k+1][next]=msk;
					}
				}
			}
			for(auto L:S[R]){
				int fail=0;
				for(i=0;i<C;i++){
					int xx=L[i],yy=2*C+R-i;
					if(pr[xx]!=yy)fail=1;
				}
				cout<<"?";
				if(fail)continue;
				vector<int>T=L;
				vector<int>M;
				for(i=R;i>0;i--){
					M.PB(preway[i][T]);
					T=prestat[i][T];
				}
				reverse(M.OP,M.ED);
				for(i=0;i<R;i++)
					for(j=0;j<C;j++)
						res[i][j]=M[i]>>j&1;
				for(i=0;i<R;i++){
					for(j=0;j<C;j++){
						printf("%s",res[i][j]?"/":"\\");
					}
					printf("\n");
				}
				return;
			}
			printf("IMPOSSIBLE\n");
			return;

		}
	}
}
int main(){
	int _T;
	scanf("%d",&_T);
	for(int CA=1;CA<=_T;CA++){
		printf("Case #%d:\n",CA);
		solve();
	}
	return 0;
}