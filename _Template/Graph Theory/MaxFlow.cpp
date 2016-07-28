typedef int ft;
const ft inf = 0x20202020;
const int M = 500000+5,N = 20000+5;
namespace SAP{
	int y[M],nxt[M],gap[N],fst[N],c[N],pre[N],q[N],dis[N];
	ft f[M];
	int S,T,tot,Tn;
	void init(int s,int t,int tn){
		tot=1;
		fill(fst,fst+tn,0);
		fill(dis,dis+tn,0);
		S=s;T=t;Tn=tn;
	}
	void add(int u,int v,ft c1,ft c2=0){
		tot++;y[tot]=v;f[tot]=c1;nxt[tot]=fst[u];fst[u]=tot;
		tot++;y[tot]=u;f[tot]=c2;nxt[tot]=fst[v];fst[v]=tot;
	}
	ft sap(){
		int u=S,t=1;ft flow=0;
		rep(i,0,t){
			int u=q[i];
			for(int j=fst[u];j;j=nxt[j])
				if(dis[y[j]]>dis[u]+1&&f[j^1])
					q[t++]=y[j],dis[y[j]]=dis[u]+1;
		}
		rep(i,0,Tn)gap[dis[i]]++;
		while(dis[S]<=Tn){
			while(c[u]&&(!f[c[u]]||dis[y[c[u]]]+1!=dis[u]))
				c[u]=nxt[c[u]];
			if(c[u]){
				pre[y[c[u]]]=c[u]^1;
				u=y[c[u]];
				if(u==T){
					ft minf=inf;
					for(int p=pre[T];p;p=pre[y[p]])
						cmin(minf,f[p^1]);
					for(int p=pre[T];p;p=pre[y[p]])
						f[p^1]-=minf,f[p]+=minf;
					flow+=minf;u=S;
				}
			}else {
				if(!(--gap[dis[u]]))break;
				int mind=Tn;
				c[u]=fst[u];
				for(int j=fst[u];j;j=nxt[j])
					if(f[j]&&dis[y[j]]<mind)
						mind=dis[y[j]],c[u]=j;
				dis[u]=mind+1;
				gap[dis[u]]++;
				if(u!=S)u=y[pre[u]];
			}
		}
		return flow;
	}
};