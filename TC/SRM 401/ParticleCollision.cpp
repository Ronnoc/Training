// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Particles (which can be considered points in 3D-space for the purposes of the problem) can move in an electro-magnetic field. If a particle is charged, its trajectory can be described as spiral, and if it is uncharged, it is just a straight line. Given two particles (one charged and one uncharged) it should be determined whether they can possibly collide or not. Two particles can possibly collide if and only if their trajectories intersect.
Some steps have already been made by the physicist to simplify the problem, so the coordinates of the charged particle are represented as follows:
x1 = cos(PI * t)
y1 = sin(PI * t)
z1 = t
and for the uncharged particle:
x2 = vx * t + x0
y2 = vy * t + y0
z2 = vz * t + z0
Here t is a parameter which can be chosen arbitrarily and independently for both trajectories.
Your method will be given 6 integers - vx, vy, vz, x0, y0 and z0, describing the trajectory of the uncharged particle. It should determine whether the two given trajectories intersect or not. If they do, it should return a vector <double> containing exactly 3 elements x, y and z - the coordinates of the point where a collision can happen.  If there is more than one such point, it should return a vector <double> containing exactly three zeroes. If collision of the two particles is impossible it should return an empty vector <double>.




DEFINITION
Class:ParticleCollision
Method:collision
Parameters:int, int, int, int, int, int
Returns:vector <double>
Method signature:vector <double> collision(int vx, int vy, int vz, int x0, int y0, int z0)


NOTES
-PI can be considered equal to 3.14159265358979323846.
-All return values with either an absolute or relative error of less than 1.0E-9 are considered correct.


CONSTRAINTS
-vx, vy and vz will each be between -10 and 10, inclusive.
-x0, y0 and z0 will each be between -10 and 10, inclusive.


EXAMPLES

0)
0
0
0
0
0
0

Returns: { }

The second trajectory is a single point (0, 0, 0), which doesn't lie on the first trajectory.

1)
2
4
1
-1
-1
0

Returns: {0.0, 1.0, 0.5 }

There is a single intersection point with coordinates (0, 1, 0.5).

2)
4
4
2
5
4
0

Returns: {0.0, 0.0, 0.0 }

There are two intersection points.

3)
0
0
1
1
0
0

Returns: {0.0, 0.0, 0.0 }

There are infinitely many intersection points.

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

typedef long long LL;
typedef pair<int, int> PII;

const long double PI = 3.14159265358979323846;
bool dbeq (double a, double b) {
	if (fabs (a - b) < 1e-10) return 1;
	return 0;
}
int vx,vy,vz,x0,y0,z0;
double getTime(double x,double y){
	
}
class ParticleCollision {
public:
	vector <double> collision (int vx, int vy, int vz, int x0, int y0, int z0) {
		::vx=vx,::vy=vy,::vz=vz;
		::x0=x0,::y0=y0,::z0=z0;
		vector<double>ret;
		double A = vy, B = -vx, C = vx * y0 - vy * x0;
		double dis=fabs (C / (hypot (A, B)));
		if (!dbeq (hypot (A, B), 0) && dis > 1 + 1e10) return ret;
		if (dbeq (hypot (A, B), 0)) {
			if (!dbeq (hypot (x0, y0), 1)) return ret;
			double t = atan2 (y0, x0) / PI;
			if(vz==0){
				double Z0=z0;
				while(Z0>PI)Z0-=2*PI;
				while(Z0<-PI)Z0+=2*PI;
				if(dbeq(Z0,t)){
					ret.PB(x0);ret.PB(y0);ret.PB(z0);
					return ret;
				}else return ret;
			}
			ret.PB(0.0);
			ret.PB(0.0);
			ret.PB(0.0);
			return ret;
		}
		double beta=atan2(B,A);
		double theta=acos(dis);
		if(dbeq(dis,1)){
			double xx=cos(beta),yy=sin(beta);
			double t=getTime(xx,yy);
			
		}
		double ap1=beta+theta;
		double ap2=beta-theta;
		double xx1=cos(ap1),yy1=sin(ap1);
		double xx2=cos(ap2),yy2=sin(ap2);
		double t1,t2;
		t1=getTime(xx1,yy1);
		t2=getTime(xx2,yy2);
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
	for (int i = 0;; ++i) {
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

static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ (double expected, double result) {
	if (isnan (expected)) {
		return isnan (result);
	} else if (isinf (expected)) {
		if (expected > 0) {
			return result > 0 && isinf (result);
		} else {
			return result < 0 && isinf (result);
		}
	} else if (isnan (result) || isinf (result)) {
		return false;
	} else if (fabs (result - expected) < MAX_DOUBLE_ERROR) {
		return true;
	} else {
		double mmin = min (expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR));
		double mmax = max (expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR));
		return result > mmin && result < mmax;
	}
}
double moj_relative_error (double expected, double result) {
	if (isnan (expected) || isinf (expected) || isnan (result) || isinf (result) || expected == 0) return 0;
	return fabs (result - expected) / fabs (expected);
}
static bool topcoder_fequ (const vector<double> &a, const vector<double> &b) {
	if (a.size() != b.size()) return false;
	for (size_t i = 0; i < a.size(); ++i) if (!topcoder_fequ (a[i], b[i])) return false;
	return true;
}
double moj_relative_error (const vector<double> &expected, const vector<double> &result) {
	double ret = 0.0;
	for (size_t i = 0; i < expected.size(); ++i) {
		ret = max (ret, moj_relative_error (expected[i], result[i]));
	} return ret;
}

template<typename T> ostream& operator<< (ostream &os, const vector<T> &v) {
	os << "{";
	for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) {
		if (vi != v.begin()) os << ",";
		os << " " << *vi;
	} os << " }";
	return os;
}

int verify_case (int casenum, const vector <double> &expected, const vector <double> &received, clock_t elapsed) {
	cerr << "Example " << casenum << "... ";
	
	string verdict;
	vector<string> info;
	char buf[100];
	
	if (elapsed > CLOCKS_PER_SEC / 200) {
		sprintf (buf, "time %.2fs", elapsed * (1.0 / CLOCKS_PER_SEC));
		info.push_back (buf);
	}
	
	if (topcoder_fequ (expected, received)) {
		verdict = "PASSED";
		double rerr = moj_relative_error (expected, received);
		if (rerr > 0) {
			sprintf (buf, "relative error %.3e", rerr);
			info.push_back (buf);
		}
	} else {
		verdict = "FAILED";
	}
	
	cerr << verdict;
	if (!info.empty()) {
		cerr << " (";
		for (int i = 0; i < (int) info.size(); ++i) {
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

int run_test_case (int casenum) {
	switch (casenum) {
		case 0: {
				int vx                    = 0;
				int vy                    = 0;
				int vz                    = 0;
				int x0                    = 0;
				int y0                    = 0;
				int z0                    = 0;
				double expected__[]       = { };
				
				clock_t start__           = clock();
				vector <double> received__ = ParticleCollision().collision (vx, vy, vz, x0, y0, z0);
				return verify_case (casenum, vector <double> (expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock() - start__);
			}
		case 1: {
				int vx                    = 2;
				int vy                    = 4;
				int vz                    = 1;
				int x0                    = -1;
				int y0                    = -1;
				int z0                    = 0;
				double expected__[]       = {0.0, 1.0, 0.5 };
				
				clock_t start__           = clock();
				vector <double> received__ = ParticleCollision().collision (vx, vy, vz, x0, y0, z0);
				return verify_case (casenum, vector <double> (expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock() - start__);
			}
		case 2: {
				int vx                    = 4;
				int vy                    = 4;
				int vz                    = 2;
				int x0                    = 5;
				int y0                    = 4;
				int z0                    = 0;
				double expected__[]       = {0.0, 0.0, 0.0 };
				
				clock_t start__           = clock();
				vector <double> received__ = ParticleCollision().collision (vx, vy, vz, x0, y0, z0);
				return verify_case (casenum, vector <double> (expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock() - start__);
			}
		case 3: {
				int vx                    = 0;
				int vy                    = 0;
				int vz                    = 1;
				int x0                    = 1;
				int y0                    = 0;
				int z0                    = 0;
				double expected__[]       = {0.0, 0.0, 0.0 };
				
				clock_t start__           = clock();
				vector <double> received__ = ParticleCollision().collision (vx, vy, vz, x0, y0, z0);
				return verify_case (casenum, vector <double> (expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock() - start__);
			}
			
			// custom cases
			
			/*      case 4: {
						int vx                    = ;
						int vy                    = ;
						int vz                    = ;
						int x0                    = ;
						int y0                    = ;
						int z0                    = ;
						double expected__[]       = ;
			
						clock_t start__           = clock();
						vector <double> received__ = ParticleCollision().collision( vx, vy, vz, x0, y0, z0 );
						return verify_case( casenum, vector <double>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
					}*/
			/*      case 5: {
						int vx                    = ;
						int vy                    = ;
						int vz                    = ;
						int x0                    = ;
						int y0                    = ;
						int z0                    = ;
						double expected__[]       = ;
			
						clock_t start__           = clock();
						vector <double> received__ = ParticleCollision().collision( vx, vy, vz, x0, y0, z0 );
						return verify_case( casenum, vector <double>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
					}*/
			/*      case 6: {
						int vx                    = ;
						int vy                    = ;
						int vz                    = ;
						int x0                    = ;
						int y0                    = ;
						int z0                    = ;
						double expected__[]       = ;
			
						clock_t start__           = clock();
						vector <double> received__ = ParticleCollision().collision( vx, vy, vz, x0, y0, z0 );
						return verify_case( casenum, vector <double>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
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
		for (int i = 1; i < argc; ++i)
			moj_harness::run_test (atoi (argv[i]));
	}
}
// END CUT HERE
