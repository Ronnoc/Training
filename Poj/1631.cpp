#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
vector<int>L;
vector<int>::iterator it;
int main(){
	int T;
	for(scanf("%d",&T);T;T--){
		L.clear();
		int n;
		scanf("%d",&n);
		int i,x;
		for(i=1;i<=n;i++){
			scanf("%d",&x);
			it=lower_bound(L.begin(),L.end(),x);
			if(it==L.end())L.push_back(x);
			else *it=x;
		}
		printf("%d\n",L.size());
	}
	return 0;
}
