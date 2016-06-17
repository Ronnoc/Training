#define COST_INF 1e9
template <typename T> class MinCostFlow{
	private:
	struct edge{int to;LL cap;T cost;int rev;};
	
	int V;
	vector<vector<edge> >adj;
	vector<T>pot;
	
	pair<LL,T>dijkstra(int s,int t,LL FLOW_BOUND){
		vector<int>used(V,0);
		vector<T>dist(V,COST_INF);
		vector<PII>path(V,MP(-1,-1));
		priority_queue<pair<T,int> >Q;
		dist[s]=0;
		Q.push(MP(0,s));
		while(!Q.empty()){
			int x=Q.top().BB;
			Q.pop();
			if(used[x])continue;
			used[x]=1;
			for(int i=0;i<adj[x].SZ;i++)if(adj[x][i].cap>0){
				edge e=adj[x][i];
				int y=e.to;
				T d=dist[x]+e.cost+pot[x]-pot[y];
				if(d<dist[y]&&!used[y]){
					dist[y]=d;
					path[y]=MP(x,i);
					Q.push(MP(-d,y));
				}
			}
		}
		for(int i=0;i<V;i++)
			pot[i]+=dist[i];
		if(dist[t]==COST_INF)
			return MP(0,0);
		LL f=FLOW_BOUND;
		T sum=0;
		int x=t;
		while(x!=s){
			int y=path[x].AA;
			int id=path[x].BB;
			sum+=adj[y][id].cost;
			cmin(f,adj[y][id].cap);
			x=y;
		}
		x=t;
		while(x!=s){
			int y=path[x].AA;
			int id=path[x].BB;
			adj[y][id].cap-=f;
			int id2=adj[y][id].rev;
			adj[x][id2].cap+=f;
			x=y;
		}
		return MP(f,f*sum);
	}
	public:
	MinCostFlow(int n){//[0,n)
		V=n;
		adj.resize(V,vector<edge>(0));
		pot.resize(V,0);
	}
	void add_edge(int s,int t,LL f,T c){
		edge e1={t,f,c,(int)adj[t].SZ};
		edge e2={s,0LL,-c,(int)adj[s].SZ};
		adj[s].PB(e1);
		adj[t].PB(e2);
	}
	pair<LL,T>mincostflow(int s,int t,LL FLOW_BOUND=(1LL<<48)){
		pair<LL,T>ans=MP(0LL,0);
		while(FLOW_BOUND>0){
			pair<LL,T>tmp=dijkstra(s,t,FLOW_BOUND);
			if(tmp.AA==0)break;
			ans.AA+=tmp.AA;
			ans.BB+=tmp.BB;
			FLOW_BOUND-=tmp.AA;
		}
		return ans;
	}
};