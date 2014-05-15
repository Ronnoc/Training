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
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>

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
const double eps=1e-8;
const double INF=1e20;
const double PI=acos( -1. );
const int MXN = 50;
const LL MOD = 1000000007;
void show(vector<LL>L){
	int i;
	if(L.empty())cout<<"empty";
	else {
		cout<<L[0];
		for(i=1;i<L.SZ;i++)cout<<","<<L[i];
	}
}
int main(){
	int i,j;
	int T;
	cin>>T;
	while(T--){
		LL l,r;
		cin>>l;
		r=0;
		vector<LL>L,R;
		LL next=1;
		while(l){
			if(l%3==1)R.PB(next);
			else if(l%3==2){
				L.PB(next);
				l++;
			}
			l/=3;
			next*=3;
		}
		show(L);
		printf(" ");
		show(R);
		printf("\n");
	}
	return 0;
}
