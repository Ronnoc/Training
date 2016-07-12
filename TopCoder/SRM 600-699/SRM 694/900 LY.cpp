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
class SRMDiv0Easy {
public:
	int get( int N, vector <int> L, vector <int> R, vector <int> X, vector <int> Y ) {
		int i,j;
		int ret;
		MinCostFlow<LL>mcf(N+4);
		int T=N,S=N+1;
		mcf.add_edge(S,N+2,200000,-1000000);
		mcf.add_edge(N+3,T,200000,-1000000);
		mcf.add_edge(S,0,200000,-1);
		rep(i,0,sz(L)){
			mcf.add_edge(N+2,R[i]+1,X[i],0);
			mcf.add_edge(L[i],N+3,X[i],0);
			mcf.add_edge(L[i],R[i]+1,Y[i]-X[i],0);
		}
		pair<LL,LL>info=mcf.mincostflow(S,T);
		LL sum=2*accumulate(all(X),0);
		LL force=(-info.BB)/1000000;
		if(force!=sum)return -1;
		return -info.BB-force*1000000;
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
			int N                     = 2;
			int L[]                   = {0,1};
			int R[]                   = {0,1};
			int X[]                   = {1,2};
			int Y[]                   = {2,3};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = SRMDiv0Easy().get( N, vector <int>( L, L + ( sizeof L / sizeof L[0] ) ), vector <int>( R, R + ( sizeof R / sizeof R[0] ) ), vector <int>( X, X + ( sizeof X / sizeof X[0] ) ), vector <int>( Y, Y + ( sizeof Y / sizeof Y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int N                     = 2;
			int L[]                   = {0,1};
			int R[]                   = {0,1};
			int X[]                   = {1,3};
			int Y[]                   = {2,4};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = SRMDiv0Easy().get( N, vector <int>( L, L + ( sizeof L / sizeof L[0] ) ), vector <int>( R, R + ( sizeof R / sizeof R[0] ) ), vector <int>( X, X + ( sizeof X / sizeof X[0] ) ), vector <int>( Y, Y + ( sizeof Y / sizeof Y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int N                     = 3;
			int L[]                   = {0,1,0,0,2};
			int R[]                   = {2,2,1,0,2};
			int X[]                   = {1,3,1,4,2};
			int Y[]                   = {11,13,19,15,17};
			int expected__            = 41;

			clock_t start__           = clock();
			int received__            = SRMDiv0Easy().get( N, vector <int>( L, L + ( sizeof L / sizeof L[0] ) ), vector <int>( R, R + ( sizeof R / sizeof R[0] ) ), vector <int>( X, X + ( sizeof X / sizeof X[0] ) ), vector <int>( Y, Y + ( sizeof Y / sizeof Y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int N                     = 12;
			int L[]                   = {0,0,1,4,9,7,0};
			int R[]                   = {6,11,11,4,10,11,0};
			int X[]                   = {1,73,334,1,1,5,362};
			int Y[]                   = {546,342,645,249,999,535,458};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = SRMDiv0Easy().get( N, vector <int>( L, L + ( sizeof L / sizeof L[0] ) ), vector <int>( R, R + ( sizeof R / sizeof R[0] ) ), vector <int>( X, X + ( sizeof X / sizeof X[0] ) ), vector <int>( Y, Y + ( sizeof Y / sizeof Y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int N                     = 200;
			int L[]                   = {0,49,0,97,0,65,0,55,0,24,0,86,0,139,0,34,0,11,0,62,0,172,0,59,0,97,0,47,0,156,0,24,0,103,0,184,0,130,0,154,0,26,0,121,0,72,0,183,0,5};
			int R[]                   = {48,199,96,199,64,199,54,199,23,199,85,199,138,199,33,199,10,199,61,199,171,199,58,199,96,199,46,199,155,199,23,199,102,199,183,199,129,199,153,199,25,199,120,199,71,199,182,199,4,199};
			int X[]                   = {1,1,1,1,2,1,2,2,2,2,1,1,1,1,2,1,1,1,1,1,2,2,2,1,2,1,1,2,2,1,1,1,2,2,1,1,2,1,1,1,1,1,2,2,2,2,2,2,2,1};
			int Y[]                   = {964,962,952,993,983,973,971,954,978,980,958,999,991,978,977,991,971,976,977,998,968,992,951,955,987,981,986,958,968,966,992,957,975,995,958,995,983,985,956,974,966,986,985,999,959,989,980,998,971,973};
			int expected__            = 24202;

			clock_t start__           = clock();
			int received__            = SRMDiv0Easy().get( N, vector <int>( L, L + ( sizeof L / sizeof L[0] ) ), vector <int>( R, R + ( sizeof R / sizeof R[0] ) ), vector <int>( X, X + ( sizeof X / sizeof X[0] ) ), vector <int>( Y, Y + ( sizeof Y / sizeof Y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int N                     = 5;
			int L[]                   = {};
			int R[]                   = {};
			int X[]                   = {};
			int Y[]                   = {};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = SRMDiv0Easy().get( N, vector <int>( L, L + ( sizeof L / sizeof L[0] ) ), vector <int>( R, R + ( sizeof R / sizeof R[0] ) ), vector <int>( X, X + ( sizeof X / sizeof X[0] ) ), vector <int>( Y, Y + ( sizeof Y / sizeof Y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			int N                     = ;
			int L[]                   = ;
			int R[]                   = ;
			int X[]                   = ;
			int Y[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SRMDiv0Easy().get( N, vector <int>( L, L + ( sizeof L / sizeof L[0] ) ), vector <int>( R, R + ( sizeof R / sizeof R[0] ) ), vector <int>( X, X + ( sizeof X / sizeof X[0] ) ), vector <int>( Y, Y + ( sizeof Y / sizeof Y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int N                     = ;
			int L[]                   = ;
			int R[]                   = ;
			int X[]                   = ;
			int Y[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SRMDiv0Easy().get( N, vector <int>( L, L + ( sizeof L / sizeof L[0] ) ), vector <int>( R, R + ( sizeof R / sizeof R[0] ) ), vector <int>( X, X + ( sizeof X / sizeof X[0] ) ), vector <int>( Y, Y + ( sizeof Y / sizeof Y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			int N                     = ;
			int L[]                   = ;
			int R[]                   = ;
			int X[]                   = ;
			int Y[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SRMDiv0Easy().get( N, vector <int>( L, L + ( sizeof L / sizeof L[0] ) ), vector <int>( R, R + ( sizeof R / sizeof R[0] ) ), vector <int>( X, X + ( sizeof X / sizeof X[0] ) ), vector <int>( Y, Y + ( sizeof Y / sizeof Y[0] ) ) );
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
