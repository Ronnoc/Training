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

const int BIT_SIZE = 100010;
int BIT[111111];
vector<int>Z;
vector<int>::iterator iter;
vector<PII >L;
int LB(int x){return x&(-x);}
void add(int w,int h){
	for(int i=w;i<=BIT_SIZE;i+=LB(i))
		BIT[i]+=h;
}
int sum(int w){
	int ret=0;
	for(int i=w;i>=1;i-=LB(i))
		ret+=BIT[i];
	return ret;
}
int main(){
	int n;
	while(~scanf("%d",&n)){
		int x,y,i;
		L.clear(),Z.clear();
		memset(BIT,0,sizeof BIT);
		for(i=1;i<=n;i++){
			scanf("%d%d",&x,&y);
			L.PB(MP(x,y));
			Z.PB(y);
		}
		sort(L.begin(),L.end());
		sort(Z.begin(),Z.end());
		Z.erase(unique(Z.begin(),Z.end()),Z.end());
		long long tot=0;
		for(int i=L.size()-1;i>=0;i--){
			y=L[i].BB;
			iter=lower_bound(Z.begin(),Z.end(),y);
			x=iter-Z.begin()+5;
			tot+=sum(x-1);
			add(x,1);
		}
		printf("%I64d\n",tot);
	}
	return 0;
}
