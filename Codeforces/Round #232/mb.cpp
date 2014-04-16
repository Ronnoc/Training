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
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
bool isp(int x){
	if(x==1)return 0;
	int i;
	for(i=2;i*i<=x;i++)if(x%i==0)return 0;
	return 1;
}
int main(){
	int i,j;
	LL a=0,b=1;
	freopen("bt.txt","w",stdout);
	for(i=2;i<=97;i++){
		int l=i,r=i+1;
		while(!isp(r))r++;
		while(!isp(l))l--;
		LL p=1,q=l*r;
		//p/q+a/b
		LL aa=p*b+q*a;
		LL bb=b*q;
		LL g=__gcd(aa,bb);
		aa/=g;
		bb/=g;
		a=aa,b=bb;
		cout<<a<<"/"<<b<<endl;
	}
	return 0;
}
