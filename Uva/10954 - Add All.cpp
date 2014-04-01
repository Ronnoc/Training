#include<stdio.h>
#include<queue>
struct num{
    int x;
    bool operator < (const num &a) const {
        return x>a.x;//最小值优先
    }
};
std::priority_queue<num>L;
int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		while(!L.empty())L.pop();
		int i,res=0,t;
		num x,y;
		for(i=1;i<=n;i++){
			scanf("%d",&t);
			L.push( (num){t} );
			}
		while(L.size()>1){
			x=L.top();L.pop();
			y=L.top();L.pop();
			res+=x.x+y.x;
			if(L.empty())break;
			L.push( (num){x.x+y.x} );
			}
		printf("%d\n",res);
		}
	return 0;
	}
