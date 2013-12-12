//Lquartz kybconnor
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

typedef long long LL;
typedef pair<int, int> PII;
int mp[222222];
vector<int>d,p;
int L;
void solve(){
	scanf("%d%*c",&L);
	int i,x;
	char c;
	priority_queue<PII>pQ;
	for(i=2;i<L;i++){
		scanf("%c%d%*c",&c,&x);
		if(c=='d')
			pQ.push(MP(-x,i));
		else 
			while(pQ.size()>=x)pQ.pop();
	}
	scanf("%c%d%*c",&c,&x);
	for(i=0;i<d.SZ;i++)pQ.push(MP(d[i],i));
	if(pQ.SZ>=x){
		vector<int>L;
		int ans=0;
		while(!pQ.empty()){
			PII tp=pQ.top();
			pQ.pop();
			ans+=tp.AA;
			L.PB(tp.BB);
		}
		SORT(L);
		printf("%d\n%d\n",-ans,L.SZ);
		for(i=0;i<L.SZ;i++)printf("%d ",L[i]);
		printf("\n");
	}
	else printf("-1\n");
}
int main(){
//	while(1)
		solve();
	return 0;
}
