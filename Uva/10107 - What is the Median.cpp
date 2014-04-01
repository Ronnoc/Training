#include<vector>
#include<algorithm>
#include<stdio.h>
std::vector<int> q;
int main(){
	q.clear();
	int x;
	while(scanf("%d",&x)!=EOF){
		q.push_back(x);
		sort(q.begin(),q.end());
		int len=q.size();
		if(len%2==1)printf("%d\n",q[len/2]);
		else printf("%d\n",(q[len/2]+q[len/2-1])/2); 
		}
	return 0;
	}
