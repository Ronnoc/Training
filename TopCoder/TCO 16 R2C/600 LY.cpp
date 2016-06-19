// Paste me into the FileEdit configuration dialog

#include <bits/stdc++.h>
using namespace std;
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define MP make_pair
#define PB push_back
#define cmax(x,y) x=max((x),(y))
#define cmin(x,y) x=min((x),(y))
#define rep(i,a,b) for(int i=a;i<b;i++)

typedef long long LL;
typedef pair<int,int> PII;
#define COST_INF 1e9
template <typename T> class MinCostFlow{
public:
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
class BearGridRect {
public:
	vector <int> findPermutation( int N, vector <int> r1, vector <int> r2, vector <int> c1, vector <int> c2, vector <int> cnt ) {
		int i,j,k;
		vector <int> ret;
		MinCostFlow<int>G(N+N+2*cnt.SZ+2);
		int S=N+N+2*cnt.SZ;
		int T=N+N+2*cnt.SZ+1;
		int id[55][55];
		memset(id,-1,sizeof id);
		rep(i,0,cnt.SZ)rep(j,r1[i],r2[i]+1)rep(k,c1[i],c2[i]+1)
			id[j][k]=i;
		rep(i,0,N)G.add_edge(S,i,1,0);
		rep(i,0,N)G.add_edge(i+N,T,1,0);
		rep(i,0,N)rep(j,0,N)
			if(id[i][j]==-1)
				G.add_edge(i,j+N,1,100);
		rep(i,0,cnt.SZ)G.add_edge(2*i+N+N,2*i+N+N+1,cnt[i],0);
		rep(i,0,cnt.SZ)rep(j,r1[i],r2[i]+1)
			G.add_edge(j,2*i+N+N,1,0);
		rep(i,0,cnt.SZ)rep(j,c1[i],c2[i]+1)
			G.add_edge(2*i+N+N+1,j+N,1,0);
		pair<LL,int>Z=G.mincostflow(S,T);
		int sum=0;
		rep(i,0,cnt.SZ)sum+=cnt[i];
		if(N-Z.BB/100!=sum||Z.AA!=N){
			ret.PB(-1);
			return ret;
		}
		ret.resize(N);
		map<int,vector<int> >X;
		rep(i,0,N)for(auto e:G.adj[i])if(e.cap==0){
			if(e.to>=N&&e.to<2*N){
				ret[i]=e.to-N;
			}else {
				int id=(e.to-2*N)/2;
				X[id].PB(i);
			}
		}
		rep(i,0,cnt.SZ){
			vector<int>xx=X[i];
			vector<int>yy;
			for(auto e:G.adj[2*i+N+N+1])if(e.cap==0)
				yy.PB(e.to-N);
			rep(i,0,xx.SZ)
				ret[xx[i]]=yy[i];
		}
		return ret;
	}
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if ( casenum != -1 ) {
			if ( run_test_case( casenum ) == -1 && !quiet )
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			return;
		}
		
		int correct = 0, total = 0;
		for ( int i=0;; ++i ) {
			int x = run_test_case(i);
			if ( x == -1 ) {
				if ( i >= 100 ) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if ( total == 0 ) {
			cerr << "No test cases run." << endl;
		} else if ( correct < total ) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	template<typename T> ostream& operator<<( ostream &os, const vector<T> &v ) { os << "{"; for ( typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) { if ( vi != v.begin() ) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if ( expected == received ) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case( int casenum ) {
		switch( casenum ) {
		case 0: {
			int N                     = 5;
			int r1[]                  = {4, 0};
			int r2[]                  = {4, 1};
			int c1[]                  = {2, 1};
			int c2[]                  = {4, 2};
			int cnt[]                 = {0, 2};
			int expected__[]          = {1, 2, 4, 3, 0 };

			clock_t start__           = clock();
			vector <int> received__   = BearGridRect().findPermutation( N, vector <int>( r1, r1 + ( sizeof r1 / sizeof r1[0] ) ), vector <int>( r2, r2 + ( sizeof r2 / sizeof r2[0] ) ), vector <int>( c1, c1 + ( sizeof c1 / sizeof c1[0] ) ), vector <int>( c2, c2 + ( sizeof c2 / sizeof c2[0] ) ), vector <int>( cnt, cnt + ( sizeof cnt / sizeof cnt[0] ) ) );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 1: {
			int N                     = 5;
			int r1[]                  = {4, 0, 2};
			int r2[]                  = {4, 1, 2};
			int c1[]                  = {2, 1, 2};
			int c2[]                  = {4, 2, 2};
			int cnt[]                 = {0, 2, 1};
			int expected__[]          = {-1 };

			clock_t start__           = clock();
			vector <int> received__   = BearGridRect().findPermutation( N, vector <int>( r1, r1 + ( sizeof r1 / sizeof r1[0] ) ), vector <int>( r2, r2 + ( sizeof r2 / sizeof r2[0] ) ), vector <int>( c1, c1 + ( sizeof c1 / sizeof c1[0] ) ), vector <int>( c2, c2 + ( sizeof c2 / sizeof c2[0] ) ), vector <int>( cnt, cnt + ( sizeof cnt / sizeof cnt[0] ) ) );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 2: {
			int N                     = 3;
			int r1[]                  = {0};
			int r2[]                  = {2};
			int c1[]                  = {0};
			int c2[]                  = {2};
			int cnt[]                 = {0};
			int expected__[]          = {-1 };

			clock_t start__           = clock();
			vector <int> received__   = BearGridRect().findPermutation( N, vector <int>( r1, r1 + ( sizeof r1 / sizeof r1[0] ) ), vector <int>( r2, r2 + ( sizeof r2 / sizeof r2[0] ) ), vector <int>( c1, c1 + ( sizeof c1 / sizeof c1[0] ) ), vector <int>( c2, c2 + ( sizeof c2 / sizeof c2[0] ) ), vector <int>( cnt, cnt + ( sizeof cnt / sizeof cnt[0] ) ) );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 3: {
			int N                     = 4;
			int r1[]                  = {0};
			int r2[]                  = {0};
			int c1[]                  = {0};
			int c2[]                  = {0};
			int cnt[]                 = {0};
			int expected__[]          = {1, 0, 2, 3 };

			clock_t start__           = clock();
			vector <int> received__   = BearGridRect().findPermutation( N, vector <int>( r1, r1 + ( sizeof r1 / sizeof r1[0] ) ), vector <int>( r2, r2 + ( sizeof r2 / sizeof r2[0] ) ), vector <int>( c1, c1 + ( sizeof c1 / sizeof c1[0] ) ), vector <int>( c2, c2 + ( sizeof c2 / sizeof c2[0] ) ), vector <int>( cnt, cnt + ( sizeof cnt / sizeof cnt[0] ) ) );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 4: {
			int N                     = 2;
			int r1[]                  = {0, 0, 1, 1};
			int r2[]                  = {0, 0, 1, 1};
			int c1[]                  = {0, 1, 0, 1};
			int c2[]                  = {0, 1, 0, 1};
			int cnt[]                 = {0, 1, 1, 0};
			int expected__[]          = {1, 0 };

			clock_t start__           = clock();
			vector <int> received__   = BearGridRect().findPermutation( N, vector <int>( r1, r1 + ( sizeof r1 / sizeof r1[0] ) ), vector <int>( r2, r2 + ( sizeof r2 / sizeof r2[0] ) ), vector <int>( c1, c1 + ( sizeof c1 / sizeof c1[0] ) ), vector <int>( c2, c2 + ( sizeof c2 / sizeof c2[0] ) ), vector <int>( cnt, cnt + ( sizeof cnt / sizeof cnt[0] ) ) );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 5: {
			int N                     = 2;
			int r1[]                  = {0, 0, 1, 1};
			int r2[]                  = {0, 0, 1, 1};
			int c1[]                  = {0, 1, 0, 1};
			int c2[]                  = {0, 1, 0, 1};
			int cnt[]                 = {0, 1, 0, 1};
			int expected__[]          = {-1 };

			clock_t start__           = clock();
			vector <int> received__   = BearGridRect().findPermutation( N, vector <int>( r1, r1 + ( sizeof r1 / sizeof r1[0] ) ), vector <int>( r2, r2 + ( sizeof r2 / sizeof r2[0] ) ), vector <int>( c1, c1 + ( sizeof c1 / sizeof c1[0] ) ), vector <int>( c2, c2 + ( sizeof c2 / sizeof c2[0] ) ), vector <int>( cnt, cnt + ( sizeof cnt / sizeof cnt[0] ) ) );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 6: {
			int N                     = 2;
			int r1[]                  = {0, 0, 1, 1};
			int r2[]                  = {0, 0, 1, 1};
			int c1[]                  = {0, 1, 0, 1};
			int c2[]                  = {0, 1, 0, 1};
			int cnt[]                 = {1, 1, 1, 1};
			int expected__[]          = {-1 };

			clock_t start__           = clock();
			vector <int> received__   = BearGridRect().findPermutation( N, vector <int>( r1, r1 + ( sizeof r1 / sizeof r1[0] ) ), vector <int>( r2, r2 + ( sizeof r2 / sizeof r2[0] ) ), vector <int>( c1, c1 + ( sizeof c1 / sizeof c1[0] ) ), vector <int>( c2, c2 + ( sizeof c2 / sizeof c2[0] ) ), vector <int>( cnt, cnt + ( sizeof cnt / sizeof cnt[0] ) ) );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 7: {
			int N                     = 6;
			int r1[]                  = {0, 0, 4};
			int r2[]                  = {2, 3, 5};
			int c1[]                  = {0, 5, 1};
			int c2[]                  = {4, 5, 5};
			int cnt[]                 = {3, 1, 1};
			int expected__[]          = {1, 2, 4, 5, 3, 0 };

			clock_t start__           = clock();
			vector <int> received__   = BearGridRect().findPermutation( N, vector <int>( r1, r1 + ( sizeof r1 / sizeof r1[0] ) ), vector <int>( r2, r2 + ( sizeof r2 / sizeof r2[0] ) ), vector <int>( c1, c1 + ( sizeof c1 / sizeof c1[0] ) ), vector <int>( c2, c2 + ( sizeof c2 / sizeof c2[0] ) ), vector <int>( cnt, cnt + ( sizeof cnt / sizeof cnt[0] ) ) );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 8: {
			int N                     = 3;
			int r1[]                  = {0};
			int r2[]                  = {0};
			int c1[]                  = {0};
			int c2[]                  = {0};
			int cnt[]                 = {2};
			int expected__[]          = {-1 };

			clock_t start__           = clock();
			vector <int> received__   = BearGridRect().findPermutation( N, vector <int>( r1, r1 + ( sizeof r1 / sizeof r1[0] ) ), vector <int>( r2, r2 + ( sizeof r2 / sizeof r2[0] ) ), vector <int>( c1, c1 + ( sizeof c1 / sizeof c1[0] ) ), vector <int>( c2, c2 + ( sizeof c2 / sizeof c2[0] ) ), vector <int>( cnt, cnt + ( sizeof cnt / sizeof cnt[0] ) ) );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}

		// custom cases

/*      case 9: {
			int N                     = ;
			int r1[]                  = ;
			int r2[]                  = ;
			int c1[]                  = ;
			int c2[]                  = ;
			int cnt[]                 = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = BearGridRect().findPermutation( N, vector <int>( r1, r1 + ( sizeof r1 / sizeof r1[0] ) ), vector <int>( r2, r2 + ( sizeof r2 / sizeof r2[0] ) ), vector <int>( c1, c1 + ( sizeof c1 / sizeof c1[0] ) ), vector <int>( c2, c2 + ( sizeof c2 / sizeof c2[0] ) ), vector <int>( cnt, cnt + ( sizeof cnt / sizeof cnt[0] ) ) );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}*/
/*      case 10: {
			int N                     = ;
			int r1[]                  = ;
			int r2[]                  = ;
			int c1[]                  = ;
			int c2[]                  = ;
			int cnt[]                 = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = BearGridRect().findPermutation( N, vector <int>( r1, r1 + ( sizeof r1 / sizeof r1[0] ) ), vector <int>( r2, r2 + ( sizeof r2 / sizeof r2[0] ) ), vector <int>( c1, c1 + ( sizeof c1 / sizeof c1[0] ) ), vector <int>( c2, c2 + ( sizeof c2 / sizeof c2[0] ) ), vector <int>( cnt, cnt + ( sizeof cnt / sizeof cnt[0] ) ) );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}*/
/*      case 11: {
			int N                     = ;
			int r1[]                  = ;
			int r2[]                  = ;
			int c1[]                  = ;
			int c2[]                  = ;
			int cnt[]                 = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = BearGridRect().findPermutation( N, vector <int>( r1, r1 + ( sizeof r1 / sizeof r1[0] ) ), vector <int>( r2, r2 + ( sizeof r2 / sizeof r2[0] ) ), vector <int>( c1, c1 + ( sizeof c1 / sizeof c1[0] ) ), vector <int>( c2, c2 + ( sizeof c2 / sizeof c2[0] ) ), vector <int>( cnt, cnt + ( sizeof cnt / sizeof cnt[0] ) ) );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}*/
		default:
			return -1;
		}
	}
}
 

int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
