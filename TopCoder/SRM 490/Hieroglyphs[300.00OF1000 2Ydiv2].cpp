// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Hieroglyphs were widely used for writing in ancient times and they are used in some languages even now. In this problem, we will consider a simplified model of hieroglyphs.
Let's call a hieroglyph a two-dimensional figure that consists of several segments, each of which has a positive length and is either horizontal or vertical. The segments in the same hieroglyph can touch or intersect each other, but no two segments may overlap. That is, there are no two segments such that the length of their intersection is positive. The segments are considered to be infinitely thin.
You will be given two hieroglyphs in vector <string> hier1 and hier2. Both of them are drawn on the same plane with a Cartesian coordinate system. Each element of hier1 will be a comma-separated list of segments. Each segment is formatted "x1 y1 x2 y2" (quotes for clarity), where (x1, y1) and (x2, y2) are the coordinates of its two endpoints (x1 ¡Ü x2, y1 ¡Ü y2). The set of all segments of the first hieroglyph is the union of all segments presented in elements of hier1. The set of all segments of the second hieroglyph is given in the same format in elements of hier2. It is guaranteed that both hier1 and hier2 describe valid hieroglyphs as defined in the previous paragraph.
You are allowed to move each of the hieroglyphs to an arbitrary place on the plane via translation (See notes). No other operations like applying rotation or symmetry are allowed.
Once the positions for each hieroglyph are chosen, their union is defined as a set of points on the plane that belong to at least one of them. It's easy to see that union of two hieroglyphs can be represented as a set of non-overlapping segments. You are to minimize the total length of these segments.
Return this minimum possible total length.

DEFINITION
Class:Hieroglyphs
Method:minimumVisible
Parameters:vector <string>, vector <string>
Returns:int
Method signature:int minimumVisible(vector <string> hier1, vector <string> hier2)


NOTES
-Translation is an operation that moves every point a constant distance in a specified direction. More exactly, an arbitrary vector (dx, dy) is first chosen, and then translation works as moving each point (x, y) to (x + dx, y + dy).


CONSTRAINTS
-hier1 and hier2 will each contain between 1 and 50 elements, inclusive.
-Each element of hier1 and hier2 will contain between 1 and 50 characters, inclusive.
-Each element of hier1 and hier2 will be a single comma separated list of between 1 and 4 segment descriptions, inclusive, without leading and trailing commas.
-Each segment description will be formatted "x1 y1 x2 y2" (quotes for clarity), where x1, y1, x2 and y2 are integers between 0 and 80, inclusive, with no extra leading zeros.
-In each segment description, x1 will be less than or equal to x2 and y1 will be less than or equal to y2.
-Each segment will be either horizontal or vertical and will have a positive length.
-No two segments of the same hieroglyph will overlap (as defined in the statement).


EXAMPLES

0)
{"0 0 10 0,10 0 10 3"}
{"0 1 10 1","5 1 5 4"}

Returns: 16




Here it's better to combine the horizontal line segments than the vertical ones.

1)
{"1 1 1 5"}
{"3 2 5 2"}

Returns: 6



There is no way to combine the hieroglyphs in such a way that segments overlap.

2)
{"0 2 6 2"}
{"5 1 6 1,8 1 9 1"}

Returns: 6




3)
{"10 20 10 30,15 20 15 30","10 20 15 20,0 30 30 30"}
{"0 5 0 15,5 5 5 25","0 5 5 5,0 15 5 15"}


Returns: 65



4)
{"10 10 10 20,10 30 10 40","10 10 20 10"}
{"10 0 10 20,10 27 10 35","10 0 20 0"}

Returns: 45



*/
// END CUT HERE
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
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(p) sort(p.OP,p.ED)
typedef long long LL;
typedef pair<int, int> PII;

PII pu[222],pv[222];
PII qu[222],qv[222];
vector<PII>X[88],Y[88];
int FLAG;
int play (vector<PII> &X) {
	if (X.empty()) return 0;
	SORT (X);
	int l=X[0].AA,r=X[0].BB;
	int ret=0;
	for (int i=1; i<X.SZ; i++) {
		int ll=X[i].AA,rr=X[i].BB;
		if (ll<r) r=max (r,rr);
		else {
			ret+=r-l;
			l=ll;
			r=rr;
		}
	}
	ret+=r-l;
	return ret;
}
class Hieroglyphs {
public:
	int minimumVisible (vector <string> hp, vector <string> hq) {
		int ret=1e9+7;
		int i,j;
		int np=0,nq=0;
		string sp="",sq="";
		for (i=0; i<hp.SZ; i++) {
			sp+=",";
			sp+=hp[i];
		}
		for (i=0; i<hq.SZ; i++) {
			sq+=",";
			sq+=hq[i];
		}
		istringstream pin (sp);
		istringstream qin (sq);
		char c;
		while (pin>>c) {
			i=np;
			pin>>pu[i].AA>>pu[i].BB>>pv[i].AA>>pv[i].BB;
			np++;
		}
		while (qin>>c) {
			i=nq;
			qin>>qu[i].AA>>qu[i].BB>>qv[i].AA>>qv[i].BB;
			nq++;
		}
//		cout<<sp<<endl<<sq<<endl;
		int x,y;
		int mnx=80,mxx=0,mny=80,mxy=0;
		for (i=0; i<np; i++) {
			mnx=min (mnx,min (pu[i].AA,pv[i].AA));
			mxx=max (mxx,max (pu[i].AA,pv[i].AA));
			mny=min (mny,min (pu[i].BB,pv[i].BB));
			mxy=max (mxy,max (pu[i].BB,pv[i].BB));
		}
		for (x=-mxx; x<=80-mnx; x++) for (y=-mxy; y<=80-mny; y++) {
				int now=0;
				for (i=0; i<=80; i++) X[i].clear();
				for (i=0; i<=80; i++) Y[i].clear();
				for (i=0; i<nq; i++) {
					if (qu[i].AA==qv[i].AA) X[qu[i].AA].PB (MP (qu[i].BB,qv[i].BB));
					else Y[qu[i].BB].PB (MP (qu[i].AA,qv[i].AA));
				}
				for (i=0; i<np; i++) {
					PII u=MP (pu[i].AA+x,pu[i].BB+y);
					PII v=MP (pv[i].AA+x,pv[i].BB+y);
					if (u.AA==v.AA) {
						if (u.AA<0||u.AA>80) now+=v.BB-u.BB;
						else X[u.AA].PB (MP (u.BB,v.BB));
					} else {
						if (u.BB<0||u.BB>80) now+=v.AA-u.AA;
						else Y[u.BB].PB (MP (u.AA,v.AA));
					}
				}
				for (i=0; i<=80; i++) now+=play (X[i]);
				for (i=0; i<=80; i++) now+=play (Y[i]);
				ret=min (ret,now);
			}
		return ret;
	}
};

// BEGIN CUT HERE
namespace moj_harness {
int run_test_case (int);
void run_test (int casenum = -1, bool quiet = false) {
	if (casenum != -1) {
		if (run_test_case (casenum) == -1 && !quiet)
			cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
		return;
	}
	
	int correct = 0, total = 0;
	for (int i=0;; ++i) {
		int x = run_test_case (i);
		if (x == -1) {
			if (i >= 100) break;
			continue;
		}
		correct += x;
		++total;
	}
	
	if (total == 0) {
		cerr << "No test cases run." << endl;
	} else if (correct < total) {
		cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
	} else {
		cerr << "All " << total << " tests passed!" << endl;
	}
}

int verify_case (int casenum, const int &expected, const int &received, clock_t elapsed) {
	cerr << "Example " << casenum << "... ";
	
	string verdict;
	vector<string> info;
	char buf[100];
	
	if (elapsed > CLOCKS_PER_SEC / 200) {
		sprintf (buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
		info.push_back (buf);
	}
	
	if (expected == received) {
		verdict = "PASSED";
	} else {
		verdict = "FAILED";
	}
	
	cerr << verdict;
	if (!info.empty()) {
		cerr << " (";
		for (int i=0; i< (int) info.size(); ++i) {
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
/*
*/
int run_test_case (int casenum) {
	switch (casenum) {
		case 0: {
				string hier1[]            = {"0 0 10 0,10 0 10 3"};
				string hier2[]            = {"0 1 10 1","5 1 5 4"};
				int expected__            = 16;
				
				clock_t start__           = clock();
				int received__            = Hieroglyphs().minimumVisible (vector <string> (hier1, hier1 + (sizeof hier1 / sizeof hier1[0])), vector <string> (hier2, hier2 + (sizeof hier2 / sizeof hier2[0])));
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 1: {
				string hier1[]            = {"1 1 1 5"};
				string hier2[]            = {"3 2 5 2"};
				int expected__            = 6;
				
				clock_t start__           = clock();
				int received__            = Hieroglyphs().minimumVisible (vector <string> (hier1, hier1 + (sizeof hier1 / sizeof hier1[0])), vector <string> (hier2, hier2 + (sizeof hier2 / sizeof hier2[0])));
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 2: {
				string hier1[]            = {"0 2 6 2"};
				string hier2[]            = {"5 1 6 1,8 1 9 1"};
				int expected__            = 6;
				
				clock_t start__           = clock();
				int received__            = Hieroglyphs().minimumVisible (vector <string> (hier1, hier1 + (sizeof hier1 / sizeof hier1[0])), vector <string> (hier2, hier2 + (sizeof hier2 / sizeof hier2[0])));
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 3: {
				string hier1[]            = {"10 20 10 30,15 20 15 30","10 20 15 20,0 30 30 30"};
				string hier2[]            = {"0 5 0 15,5 5 5 25","0 5 5 5,0 15 5 15"} ;
				int expected__            = 65;
				
				clock_t start__           = clock();
				int received__            = Hieroglyphs().minimumVisible (vector <string> (hier1, hier1 + (sizeof hier1 / sizeof hier1[0])), vector <string> (hier2, hier2 + (sizeof hier2 / sizeof hier2[0])));
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 4: {
				string hier1[]            = {"10 10 10 20,10 30 10 40","10 10 20 10"};
				string hier2[]            = {"10 0 10 20,10 27 10 35","10 0 20 0"};
				int expected__            = 45;
				
				clock_t start__           = clock();
				int received__            = Hieroglyphs().minimumVisible (vector <string> (hier1, hier1 + (sizeof hier1 / sizeof hier1[0])), vector <string> (hier2, hier2 + (sizeof hier2 / sizeof hier2[0])));
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
			
		// custom cases
		
		case 5: {
				string hier1[]            = {"40 37 40 74,11 1 71 1,24 43 70 43,53 11 75 11", "2 61 68 61,39 9 50 9,23 65 52 65,75 61 75 71", "57 11 57 76,75 23 75 61,50 0 69 0,71 1 80 1", "28 67 56 67,77 60 77 71,43 18 75 18,31 41 31 74", "10 39 65 39,35 41 35 64,46 21 53 21,64 8 64 19", "49 66 63 66,69 48 69 51,56 60 67 60,27 31 27 32", "43 9 43 53,19 27 53 27,6 69 48 69,54 4 54 46", "24 70 24 74,44 38 46 38,51 3 51 28,31 74 68 74", "27 9 27 31,4 37 30 37,35 6 35 41,22 80 32 80", "42 2 80 2,22 31 39 31,22 59 22 67,31 11 50 11", "26 40 49 40,50 53 50 58,25 10 25 31,39 47 67 47", "19 54 65 54,9 3 72 3,10 13 47 13,11 21 11 58", "53 22 53 67,55 37 55 40,65 39 80 39,52 4 52 16", "9 31 9 39,15 62 53 62,61 55 61 67,63 64 68 64", "68 32 77 32,7 48 7 67,28 3 28 26,1 74 31 74", "40 1 40 16,37 30 49 30,23 17 54 17,28 60 28 75", "66 9 66 63,11 65 11 77,35 14 60 14,52 53 52 59", "13 8 25 8,3 65 23 65,6 68 20 68,29 18 43 18", "53 62 57 62,39 36 66 36,18 42 69 42,9 17 9 31", "74 44 74 45,23 33 38 33,17 18 17 52,31 22 31 31", "45 29 50 29,23 40 26 40,12 7 12 59,10 67 28 67", "64 78 75 78,58 8 60 8,36 41 43 41,48 5 48 26", "27 25 44 25,34 70 66 70,5 52 5 60,19 56 72 56", "69 0 79 0,40 0 50 0,47 25 60 25,29 60 29 75", "45 3 45 29,13 33 17 33,18 23 70 23,29 44 55 44", "38 22 38 24,49 19 49 79,0 25 0 40,3 4 3 26", "0 3 0 25,0 41 27 41,15 50 15 52,51 28 51 39", "16 18 16 35,22 12 22 48,20 14 35 14,1 7 1 14", "48 66 49 66,64 25 64 49,21 32 21 60,7 33 7 34", "2 3 2 25,2 2 2 3,54 21 65 21,13 37 13 49", "9 35 58 35,4 61 4 72,39 75 56 75,34 25 34 36", "38 71 45 71,9 50 80 50,41 31 41 80,7 55 35 55", "49 19 57 19,49 16 49 19,23 29 31 29,16 19 18 19", "38 59 41 59,20 10 20 47,2 39 2 56,19 57 34 57", "18 66 18 67,0 28 69 28,72 61 72 74,52 65 72 65", "11 51 13 51,4 1 4 39,61 15 69 15,2 75 39 75", "7 14 20 14,70 7 70 9,71 19 71 42,28 43 28 48", "64 20 64 25,7 29 7 33,68 28 68 52,22 48 22 58", "45 68 51 68,10 19 16 19,46 76 69 76,35 6 50 6", "26 36 39 36,8 51 11 51,29 63 39 63,70 43 75 43", "12 40 22 40,50 64 50 66,56 13 63 13,54 2 54 4", "0 40 0 41,54 46 54 79,58 78 64 78,24 49 50 49", "14 4 22 4,7 41 7 48,20 46 54 46,32 80 65 80", "62 55 62 75,32 20 32 55,20 47 20 57,30 13 30 23", "13 32 17 32,11 18 29 18,30 40 30 47,6 2 6 11", "7 8 13 8,49 6 49 16,35 53 80 53,26 59 38 59", "34 77 61 77,13 23 18 23,10 59 20 59,45 34 68 34", "5 5 5 7,25 31 25 36,18 45 18 66,43 41 55 41", "69 33 69 48,9 72 64 72,11 22 65 22,13 2 40 2", "36 18 36 19,3 23 8 23,35 76 35 77,2 33 2 39"};
				string hier2[]            = {"17 8 17 26,41 25 41 41,29 33 29 54,30 63 33 63", "58 9 70 9,33 45 33 73,75 15 75 49,4 62 6 62", "47 13 47 65,44 3 44 65,78 12 78 60,31 31 31 74", "3 46 34 46,51 73 74 73,17 33 17 41,18 64 18 76", "31 56 49 56,6 4 74 4,42 13 50 13,73 52 73 62", "45 43 45 46,13 14 51 14,67 7 67 26,67 35 78 35", "59 43 59 77,45 80 68 80,5 46 5 62,23 13 23 65", "39 43 75 43,11 7 11 21,51 49 64 49,1 44 3 44", "34 16 34 59,17 48 66 48,17 26 17 29,38 59 57 59", "46 27 46 80,49 51 75 51,42 50 80 50,51 57 57 57", "18 34 18 64,42 78 52 78,66 7 66 8,6 40 64 40", "6 70 8 70,7 33 49 33,63 57 63 64,5 62 5 63", "51 14 72 14,23 7 23 13,51 64 51 79,11 56 12 56", "64 45 80 45,42 8 42 21,44 57 51 57,63 32 63 45", "56 49 56 80,63 45 63 57,0 4 0 73,57 2 57 80", "3 16 3 74,25 26 79 26,65 38 78 38,49 4 49 15", "49 56 59 56,12 49 40 49,18 44 58 44,60 21 60 38", "63 20 63 32,1 41 34 41,14 6 34 6,16 21 65 21", "70 16 70 53,13 58 78 58,42 21 42 77,27 13 42 13", "34 46 54 46,53 32 53 49,21 16 21 49,41 50 41 80", "28 31 28 57,38 17 38 39,26 16 26 31,78 68 78 69", "7 32 18 32,40 61 54 61,13 26 24 26,72 62 80 62", "11 10 17 10,5 23 23 23,18 16 18 34,52 17 79 17", "40 28 80 28,34 47 58 47,13 52 63 52,54 30 79 30", "2 9 58 9,14 55 14 60,27 64 38 64,29 9 29 26", "62 58 62 60,1 0 1 69,29 34 51 34,14 66 35 66", "77 29 77 53,20 0 22 0,54 28 54 43,69 16 80 16", "19 43 19 73,45 31 46 31,17 39 18 39,55 29 55 74", "19 22 47 22,61 12 63 12,4 36 4 40,77 53 77 56", "3 8 62 8,19 43 39 43,6 15 39 15,24 73 38 73", "6 55 34 55,36 18 56 18,55 6 55 29,12 74 74 74", "71 13 71 76,56 18 73 18,15 14 15 78,27 54 27 62", "27 62 27 70,29 16 67 16,9 60 21 60,27 13 27 53", "22 42 65 42,61 18 61 70,40 8 40 55,41 22 41 25", "68 15 68 67,0 72 70 72,35 6 35 9,64 70 77 70", "29 53 66 53,32 25 77 25,18 65 69 65,8 24 24 24", "8 14 13 14,5 29 61 29,54 11 54 28,24 31 27 31", "16 11 16 37,73 26 73 38,53 64 69 64,70 1 70 16", "0 41 1 41,47 10 48 10,75 51 79 51,16 37 16 76", "8 17 8 50,30 37 30 54,52 46 52 71,74 74 78 74", "17 29 17 33,44 65 44 78,33 17 33 45,11 25 11 69", "1 46 3 46,76 67 76 70,40 55 40 65,28 38 48 38", "54 5 57 5,12 69 62 69,59 56 73 56,27 11 27 13", "2 69 2 72,39 15 64 15,43 12 59 12,75 49 75 79", "49 19 54 19,70 54 70 63,14 51 14 52,14 38 14 51", "48 0 48 20,31 25 31 31,3 13 20 13,18 76 56 76", "24 5 24 52,48 39 59 39,14 50 42 50,62 7 62 23", "34 55 61 55,6 39 7 39,6 28 40 28,43 68 72 68", "61 3 61 18,74 5 74 67,20 37 20 38,30 29 30 37", "31 18 31 25,2 66 6 66,70 46 77 46,16 71 63 71"};
				int expected__            = 6784;
				
				clock_t start__           = clock();
				int received__            = Hieroglyphs().minimumVisible (vector <string> (hier1, hier1 + (sizeof hier1 / sizeof hier1[0])), vector <string> (hier2, hier2 + (sizeof hier2 / sizeof hier2[0])));
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		/*      case 6: {
					string hier1[]            = ;
					string hier2[]            = ;
					int expected__            = ;
		
					clock_t start__           = clock();
					int received__            = Hieroglyphs().minimumVisible( vector <string>( hier1, hier1 + ( sizeof hier1 / sizeof hier1[0] ) ), vector <string>( hier2, hier2 + ( sizeof hier2 / sizeof hier2[0] ) ) );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 7: {
					string hier1[]            = ;
					string hier2[]            = ;
					int expected__            = ;
		
					clock_t start__           = clock();
					int received__            = Hieroglyphs().minimumVisible( vector <string>( hier1, hier1 + ( sizeof hier1 / sizeof hier1[0] ) ), vector <string>( hier2, hier2 + ( sizeof hier2 / sizeof hier2[0] ) ) );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		default:
			return -1;
	}
}
}


int main (int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test (atoi (argv[i]));
	}
}
// END CUT HERE
