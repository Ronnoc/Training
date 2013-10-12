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


class Wizarding {
public:
  string counterspell (string s, string r) {
		int LAST=1<<int(s.size());
		int MOD=77077;
		int i,j,k;
		string ret="AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
		int ans=-1;
		for(i=1;i<LAST;i++){
			string x="";
			for(j=0;j<s.size();j++)if(i>>j&1)x+=s[j];
			int last=1<<int(x.size());
			for(j=0;j<last;j++){
				string tp=x;
				for(k=0;k<tp.size();k++)
					if(j>>k&1){
						char c=tp[k];
						if(r[c-'A']!='-')tp[k]=r[c-'A'];
					}
				int now=1;
				for(k=0;k<tp.size();k++)now=(now*(tp[k]-'A'+1))%MOD;
				if(now>ans){ret=tp;ans=now;}
				else if(now==ans){
					if(tp.size()<ret.size())ret=tp;
					else if(tp.size()==ret.size()&&tp<ret)ret=tp;
				}
			}
		}
    return string(ret);
  }
};



// Powered by FileEdit
// Powered by moj 4.12 [modified TZTester]
// Powered by CodeProcessor
