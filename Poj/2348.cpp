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
#include <cstdlib>
#include <cstring>
#include <fstream>
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

typedef long long LL;
typedef pair<int, int> PII;

int main(){
	int a,b;
	while(cin>>a>>b){
		if(!a&&!b)break;
		int gcd=__gcd(a,b);
		a/=gcd;b/=gcd;
		int res,now=1;
		while(a&&b){
			if(a<b)swap(a,b);
			if(a/b>=2){
				res=now;
				break;
			}
			else {
				now=1-now;
				a-=b;
			}
		}
		if(res)printf("Stan wins\n");
		else printf("Ollie wins\n");
	}
	return 0;
}
