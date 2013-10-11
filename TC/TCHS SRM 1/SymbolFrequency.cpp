// BEGIN CUT HERE
/*
PROBLEM STATEMENT

In written languages, some symbols may appear more often than others.  
Expected frequency tables have been defined for many languages.  
For each symbol in a language, a frequency table will contain its expected percentage in a typical passage written in that language.  
For example, if the symbol "a" has an expected percentage of 5, then 5% of the letters in a typical passage will be "a". If a passage contains 350 letters, then 'a' has an expected count of 17.5 for that passage (17.5 = 350 * 5%). Please note that the expected count can be a non-integer value.


The deviation of a text with respect to a language frequency table can be computed in the following manner.  
For each letter ('a'-'z') determine the difference between the expected count and the actual count in the text.  
The deviation is the sum of the squares of these differences.  
Blank spaces (' ') and line breaks (each element of text is a line) are ignored when calculating percentages.


Each frequency table will be described as a concatenation of up to 16 strings of the form "ANN", 
where A is a lowercase letter ('a'-'z') and NN its expected frequency as a two-digit percentage between "00" (meaning 0%) and "99" (meaning 99%), inclusive. 
Any letter not appearing in a table is not expected to appear in a typical passage (0%).
You are given a vector <string> frequencies of frequency tables of different languages.  
Return the lowest deviation the given text has with respect to the frequency tables.


DEFINITION
Class:SymbolFrequency
Method:language
Parameters:vector <string>, vector <string>
Returns:double
Method signature:double language(vector <string> frequencies, vector <string> text)


NOTES
-The returned value must be accurate to within a relative or absolute value of 1E-9.


CONSTRAINTS
-frequencies will contain between 1 and 10 elements, inclusive.
-Each element of frequencies will be formatted as described in the statement.
-Each element of frequencies will contain between 6 and 48 characters, inclusive.
-No letter will appear twice in the same element of frequencies.
-The sum of the percentages in each element of frequencies will be equal to 100.
-text will contain between 1 and 10 elements, inclusive.
-Each element of text will contain between 1 and 50 characters, inclusive.
-Each element of text will contain only lowercase letters ('a'-'z') and spaces (' ').
-text will have at least one non-space character.


EXAMPLES

0)
{"a30b30c40","a20b40c40"}
{"aa bbbb cccc"}

Returns: 0.0

The first table indicates that 30% of the letters are expected to be 'a', 30% to be 'b', and 40% to be 'c'.  The second table indicates that 20% are expected to be 'a', 40% to be 'b', and 40% to be 'c'.
We consider the text to have length 10, as blank spaces are ignored.

With respect to the first table, there are 2 'a' where 3 were expected (a difference of 1), one more 'b' than expected (again a difference of 1) and as many 'c' as expected. 
The sum of the squares of those numbers gives a deviation of 2.0.

As for the second table, the text matches expected counts exactly, so its deviation with respect to that language is 0.0. 


1)
{"a30b30c40","a20b40c40"}
{"aaa bbbb ccc"}

Returns: 2.0

Here we use the same tables as in the previous example, but with a different text. 
The counts for 'b' and 'c' each differ by 1 from the expected counts in the first table, and the counts for 'a' and 'c' each differ by 1 from the expected counts in the second table.
The text has a deviation of 2.0 with respect to both tables.


2)
{"a10b10c10d10e10f50"}
{"abcde g"}

Returns: 10.8

Here, each of the letters 'a' through 'e' is expected to make up 10% of the letters (0.6 letters).  Each of those letters actually appears once, so the difference is 0.4, which becomes 0.16 when squared.  50% of the letters (3 letters) are expected to be 'f', but 'f' does not appear at all.  The square of this difference is 9.0.  No 'g's are expected to appear, but there is one in the text.  This adds 1.0 to the deviation.  The final deviation for this table is: 0.16+0.16+0.16+0.16+0.16+9.0+1.0=10.8.

3)
{"a09b01c03d05e20g01h01i08l06n08o06r07s09t08u07x01"
,"a14b02c05d06e15g01h01i07l05n07o10r08s09t05u04x01"}
{"this text is in english" 
,"the letter counts should be close to"
,"that in the table"}

Returns: 130.6578

These two frequency tables correspond (roughly) to the frequencies found in the English and Spanish languages, respectively. The English passage, as expected, has a lower deviation in the first table than in the second one.

4)
{"a09b01c03d05e20g01h01i08l06n08o06r07s09t08u07x01"
,"a14b02c05d06e15g01h01i07l05n07o10r08s09t05u04x01"}
{"en esta es una oracion en castellano"
,"las ocurrencias de cada letra"
,"deberian ser cercanas a las dadas en la tabla"}

Returns: 114.9472

The same tables again, but with Spanish passage. This time the second table, which correspond to frequencies in Spanish, gives the lowest deviation.

5)
{"z99y01", "z99y01", "z99y01", "z99y01", "z99y01", 
 "z99y01", "z99y01", "z99y01", "z99y01", "z99y01"}
{"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"}

Returns: 495050.0

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
#define SQ(x) ((x)*(x))
typedef long long LL;
typedef pair<int, int> PII;

double gao(string s,int *f){
	double tot[33];
	for(int i=0;i<26;i++)tot[i]=0.0;
	int i,len=0;
	for(i=0;i<s.size();i++)if(s[i]!=' ')tot[s[i]-'a']+=100,len++;
	double ans=0;
	for(i=0;i<26;i++)ans+=SQ(tot[i]-len*f[i]);
	return ans/10000;
}
double solve(string f,vector<string>t){
	int ff[33];
	memset(ff,0,sizeof ff);
	int i;
	for(i=0;i<f.size();){
		while(f[i]==' ')i++;
		int c=f[i]-'a';i++;
		while(f[i]==' ')i++;
		int p=f[i]-'0';i++;
		while(f[i]==' ')i++;
		int q=f[i]-'0';i++;
		ff[c]=p*10+q;
	}
	double ret=0;
	for(i=0;i<t.size();i++)ret+=gao(t[i],ff);
	return ret;
}
class SymbolFrequency {
public:
  double language (vector <string> f, vector <string> t) {
  	vector<string>temp;
  	string tp="";
  	for(int i=0;i<t.size();i++)tp+=t[i];
  	temp.PB(tp);
		double MIN=1e100;
		int PMIN;
		int i,j;
		for(i=0;i<f.size();i++){
			double slv=solve(f[i],temp);
			if(slv<MIN)MIN=slv,PMIN=i;
		}
    return solve(f[PMIN],temp);
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
			string frequencies[]      = {"a30b30c40","a20b40c40"};
			string text[]             = {"aa bbbb cccc"};
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = SymbolFrequency().language( vector <string>( frequencies, frequencies + ( sizeof frequencies / sizeof frequencies[0] ) ), vector <string>( text, text + ( sizeof text / sizeof text[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string frequencies[]      = {"a30b30c40","a20b40c40"};
			string text[]             = {"aaa bbbb ccc"};
			double expected__         = 2.0;

			clock_t start__           = clock();
			double received__         = SymbolFrequency().language( vector <string>( frequencies, frequencies + ( sizeof frequencies / sizeof frequencies[0] ) ), vector <string>( text, text + ( sizeof text / sizeof text[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string frequencies[]      = {"a10b10c10d10e10f50"};
			string text[]             = {"abcde g"};
			double expected__         = 10.8;

			clock_t start__           = clock();
			double received__         = SymbolFrequency().language( vector <string>( frequencies, frequencies + ( sizeof frequencies / sizeof frequencies[0] ) ), vector <string>( text, text + ( sizeof text / sizeof text[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string frequencies[]      = {"a09b01c03d05e20g01h01i08l06n08o06r07s09t08u07x01" ,"a14b02c05d06e15g01h01i07l05n07o10r08s09t05u04x01"};
			string text[]             = {"this text is in english"  ,"the letter counts should be close to" ,"that in the table"};
			double expected__         = 130.6578;

			clock_t start__           = clock();
			double received__         = SymbolFrequency().language( vector <string>( frequencies, frequencies + ( sizeof frequencies / sizeof frequencies[0] ) ), vector <string>( text, text + ( sizeof text / sizeof text[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string frequencies[]      = {"a09b01c03d05e20g01h01i08l06n08o06r07s09t08u07x01" ,"a14b02c05d06e15g01h01i07l05n07o10r08s09t05u04x01"};
			string text[]             = {"en esta es una oracion en castellano" ,"las ocurrencias de cada letra" ,"deberian ser cercanas a las dadas en la tabla"};
			double expected__         = 114.9472;

			clock_t start__           = clock();
			double received__         = SymbolFrequency().language( vector <string>( frequencies, frequencies + ( sizeof frequencies / sizeof frequencies[0] ) ), vector <string>( text, text + ( sizeof text / sizeof text[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			string frequencies[]      = {"z99y01", "z99y01", "z99y01", "z99y01", "z99y01",   "z99y01", "z99y01", "z99y01", "z99y01", "z99y01"};
			string text[]             = {"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"};
			double expected__         = 495050.0;

			clock_t start__           = clock();
			double received__         = SymbolFrequency().language( vector <string>( frequencies, frequencies + ( sizeof frequencies / sizeof frequencies[0] ) ), vector <string>( text, text + ( sizeof text / sizeof text[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			string frequencies[]      = ;
			string text[]             = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = SymbolFrequency().language( vector <string>( frequencies, frequencies + ( sizeof frequencies / sizeof frequencies[0] ) ), vector <string>( text, text + ( sizeof text / sizeof text[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			string frequencies[]      = ;
			string text[]             = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = SymbolFrequency().language( vector <string>( frequencies, frequencies + ( sizeof frequencies / sizeof frequencies[0] ) ), vector <string>( text, text + ( sizeof text / sizeof text[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			string frequencies[]      = ;
			string text[]             = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = SymbolFrequency().language( vector <string>( frequencies, frequencies + ( sizeof frequencies / sizeof frequencies[0] ) ), vector <string>( text, text + ( sizeof text / sizeof text[0] ) ) );
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
