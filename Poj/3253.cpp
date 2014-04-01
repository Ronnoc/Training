#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> >L;
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		while(!L.empty())L.pop();
		int i,x,y;
		long long res=0;
		for(i=1;i<=n;i++){
			scanf("%d",&x);
			L.push(x);
			}
		while(L.size()>1){
			x=L.top();L.pop();
			y=L.top();L.pop();
			res+=x+y;
			L.push(x+y);
			}
		printf("%I64d\n",res);
		}
	return 0;
	}
