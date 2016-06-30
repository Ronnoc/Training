// Paste me into the FileEdit configuration dialog
#include<bits/stdc++.h>
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
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;
LL modPow(LL a,LL b,LL MOD){
	LL ret=1;for(;b;b>>=1){
		if(b&1)ret=ret*a%MOD;a=a*a%MOD;
	}return ret;
}
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
class BiconnectedDiv1 {
public:
	int minimize( vector <int> w1, vector <int> w2 ) {
		int i,j;
		int n=sz(w2)+2;
		MinCostFlow<int>mcf(n);
		rep(i,0,n-1)
			mcf.add_edge(i,i+1,1,w1[i]);
		rep(i,0,n-2)
			mcf.add_edge(i,i+2,1,w2[i]);
		return (mcf.mincostflow(0,n-1)).BB;
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
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
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
			int w1[]                  = {1,2};
			int w2[]                  = {3};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = BiconnectedDiv1().minimize( vector <int>( w1, w1 + ( sizeof w1 / sizeof w1[0] ) ), vector <int>( w2, w2 + ( sizeof w2 / sizeof w2[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int w1[]                  = {3,0,4};
			int w2[]                  = {1,2};
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = BiconnectedDiv1().minimize( vector <int>( w1, w1 + ( sizeof w1 / sizeof w1[0] ) ), vector <int>( w2, w2 + ( sizeof w2 / sizeof w2[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int w1[]                  = {3,3,3,3};
			int w2[]                  = {3,6,3};
			int expected__            = 18;

			clock_t start__           = clock();
			int received__            = BiconnectedDiv1().minimize( vector <int>( w1, w1 + ( sizeof w1 / sizeof w1[0] ) ), vector <int>( w2, w2 + ( sizeof w2 / sizeof w2[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int w1[]                  = {7243,7525,8467,6351,9453,8456,8175,5874,6869,7400,6438,8926,6876};
			int w2[]                  = {2642,1743,3546,4100,2788,3019,2678,1935,1790,2674,3775,1920};
			int expected__            = 46729;

			clock_t start__           = clock();
			int received__            = BiconnectedDiv1().minimize( vector <int>( w1, w1 + ( sizeof w1 / sizeof w1[0] ) ), vector <int>( w2, w2 + ( sizeof w2 / sizeof w2[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 4: {
			int w1[]                  = ;
			int w2[]                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BiconnectedDiv1().minimize( vector <int>( w1, w1 + ( sizeof w1 / sizeof w1[0] ) ), vector <int>( w2, w2 + ( sizeof w2 / sizeof w2[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			int w1[]                  = ;
			int w2[]                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BiconnectedDiv1().minimize( vector <int>( w1, w1 + ( sizeof w1 / sizeof w1[0] ) ), vector <int>( w2, w2 + ( sizeof w2 / sizeof w2[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int w1[]                  = ;
			int w2[]                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BiconnectedDiv1().minimize( vector <int>( w1, w1 + ( sizeof w1 / sizeof w1[0] ) ), vector <int>( w2, w2 + ( sizeof w2 / sizeof w2[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
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
