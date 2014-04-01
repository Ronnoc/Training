#include <cstdio>
#include <set>
using namespace std;
set<int>G[10010];
set<int>::iterator iter;
int main(){
	int n,a,b,x,y;
	while(scanf("%d%d%d",&n,&a,&b)!=EOF){
		int i;
		for(i=0;i<=n;i++)G[i].clear();
		x=0,y=0;
		a%=n;b%=n;
		while(1){
			if(G[x].find(y)==G[x].end())G[x].insert(y);
			else break;
			x+=a;y+=b;
			x%=n;y%=n;
		}
		long long tot=0;
		for(i=0;i<n;i++)tot+=G[i].size();
		printf("%I64d\n",tot);
		for(i=0;i<n;i++){
			iter=G[i].begin();
			while(iter!=G[i].end()){
				printf("%d %d\n",i,*iter);
				iter++;
			}
		}
	}
	return 0;
}
