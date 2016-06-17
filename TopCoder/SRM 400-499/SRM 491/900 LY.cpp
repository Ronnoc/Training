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

typedef long long LL;
typedef pair<int,int> PII;

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
class FoxCardGame {
public:
	double theMaxProportion( vector <double> A, vector <double> B, int K ) {
		int i,j;
		int n=A.SZ;
		double lim=0;
		for(auto a:A)for(auto b:B){
			double p=a*b,q=a+b;
			if(p<q)swap(p,q);
			cmax(lim,p/q);
		}
		double le=1,re=lim;
		while(re-le>1e-12){
			double me=(le+re)/2;
			MinCostFlow<double> MCF(2*n+2);
			for(i=0;i<n;i++)
				for(j=0;j<n;j++){
					double p=A[i]+B[j],q=A[i]*B[j];
					if(p<q)swap(p,q);//p>=q
					MCF.add_edge(i+1,j+n+1,1,me*q-p+1e5);//
				}
			for(i=0;i<n;i++)
				MCF.add_edge(0,i+1,1,0);
			for(i=0;i<n;i++)
				MCF.add_edge(i+n+1,2*n+1,1,0);
			pair<LL,double>cost=MCF.mincostflow(0,2*n+1,K);
			if(cost.BB<K*1e5)le=me;
			else re=me;
		}
		return (le+re)/2;
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ( double expected, double result ) { if ( isnan( expected ) ) { return isnan( result ); } else if ( isinf( expected ) ) { if ( expected > 0 ) { return result > 0 && isinf( result ); } else { return result < 0 && isinf( result ); } } else if ( isnan( result ) || isinf( result ) ) { return false; } else if ( fabs( result - expected ) < MAX_DOUBLE_ERROR ) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error( double expected, double result ) { if ( isnan( expected ) || isinf( expected ) || isnan( result ) || isinf( result ) || expected == 0 ) return 0; return fabs( result-expected ) / fabs( expected ); }
	
	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if ( topcoder_fequ( expected, received ) ) {
			verdict = "PASSED";
			double rerr = moj_relative_error( expected, received ); 
			if ( rerr > 0 ) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			double pileA[]            = {1, 2, 3};
			double pileB[]            = {4, 5, 6};
			int k                     = 2;
			double expected__         = 1.7692307692307692;

			clock_t start__           = clock();
			double received__         = FoxCardGame().theMaxProportion( vector <double>( pileA, pileA + ( sizeof pileA / sizeof pileA[0] ) ), vector <double>( pileB, pileB + ( sizeof pileB / sizeof pileB[0] ) ), k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			double pileA[]            = {1.234, 5.678, 9.012, 3.456, 7.89};
			double pileB[]            = {2.345, 6.789, 9.876, 5.432, 1.012};
			int k                     = 3;
			double expected__         = 4.159424420079523;

			clock_t start__           = clock();
			double received__         = FoxCardGame().theMaxProportion( vector <double>( pileA, pileA + ( sizeof pileA / sizeof pileA[0] ) ), vector <double>( pileB, pileB + ( sizeof pileB / sizeof pileB[0] ) ), k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			double pileA[]            = {1, 1.1, 1.2, 1.3, 1.4, 1.5};
			double pileB[]            = {5, 10, 15, 20, 25, 30};
			int k                     = 2;
			double expected__         = 1.3972602739726028;

			clock_t start__           = clock();
			double received__         = FoxCardGame().theMaxProportion( vector <double>( pileA, pileA + ( sizeof pileA / sizeof pileA[0] ) ), vector <double>( pileB, pileB + ( sizeof pileB / sizeof pileB[0] ) ), k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			double pileA[]            = {85.302, 92.798, 76.813, 37.994, 36.737, 98.659};
			double pileB[]            = {13.352, 7.3094, 54.761, 8.2706, 63.223, 37.486};
			int k                     = 3;
			double expected__         = 33.58603889836175;

			clock_t start__           = clock();
			double received__         = FoxCardGame().theMaxProportion( vector <double>( pileA, pileA + ( sizeof pileA / sizeof pileA[0] ) ), vector <double>( pileB, pileB + ( sizeof pileB / sizeof pileB[0] ) ), k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 4: {
			double pileA[]            = ;
			double pileB[]            = ;
			int k                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = FoxCardGame().theMaxProportion( vector <double>( pileA, pileA + ( sizeof pileA / sizeof pileA[0] ) ), vector <double>( pileB, pileB + ( sizeof pileB / sizeof pileB[0] ) ), k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			double pileA[]            = ;
			double pileB[]            = ;
			int k                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = FoxCardGame().theMaxProportion( vector <double>( pileA, pileA + ( sizeof pileA / sizeof pileA[0] ) ), vector <double>( pileB, pileB + ( sizeof pileB / sizeof pileB[0] ) ), k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			double pileA[]            = ;
			double pileB[]            = ;
			int k                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = FoxCardGame().theMaxProportion( vector <double>( pileA, pileA + ( sizeof pileA / sizeof pileA[0] ) ), vector <double>( pileB, pileB + ( sizeof pileB / sizeof pileB[0] ) ), k );
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
