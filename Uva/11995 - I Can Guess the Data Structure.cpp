#include<stdio.h>
#include<queue>
#include<stack>
std::queue<int>ty1;
std::priority_queue<int>ty2;
std::stack<int>ty3;
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int i;
		int flag1=1,flag2=1,flag3=1;
		while(!ty1.empty())ty1.pop();
		while(!ty2.empty())ty2.pop();
		while(!ty3.empty())ty3.pop();
		int order,x;
		for(i=1;i<=n;i++){
			scanf("%d%d",&order,&x);
			if(order==1){
				ty3.push(x);
				ty2.push(x);
				ty1.push(x);
				}
			else {
				if(flag3&&!ty3.empty()){
					if(ty3.top()==x)ty3.pop();
					else flag3=0;
					}
				else flag3=0;
				
				if(flag2&&!ty2.empty()){
					if(ty2.top()==x)ty2.pop();
					else flag2=0;
					}
				else flag2=0;
				
				if(flag1&&!ty1.empty()){
					if(ty1.front()==x)ty1.pop();
					else flag1=0;
					}
				else flag1=0;
				}
			}
		int sum=flag1+flag2+flag3;
		if(sum>=2)printf("not sure\n");
		else if(sum==0)printf("impossible\n");
		else if(flag1)printf("queue\n");
		else if(flag2)printf("priority queue\n");
		else printf("stack\n"); 
		}
	return 0;
	}
