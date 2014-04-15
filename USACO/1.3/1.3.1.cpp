/*
ID: kybconn1
PROG: milk
LANG: C++
*/
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct milk{
	int p,n;
	bool operator<(const milk &tp)const{return p<tp.p;}
	}tp;
vector<milk>L;
int main(){
	freopen("milk.in","r",stdin);
	freopen("milk.out","w",stdout);
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		L.clear();
		int i;
		long long res=0;
		for(i=1;i<=m;i++){
			scanf("%d%d",&tp.p,&tp.n);
			L.push_back(tp);
			}
		sort(L.begin(),L.end());
		for(i=0;i<L.size();i++){
			if(n>=L[i].n){
				n-=L[i].n;
				res+=L[i].n*L[i].p;
				}
			else {
				res+=L[i].p*n;
				n=0;
				}
			}
		printf("%lld\n",res);
		}
	return 0;
	}
