#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>L;
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int i,x;
		L.clear();
		for(i=0;i<n;i++){
			scanf("%d",&x);
			L.push_back(x);
			}
		sort(L.begin(),L.end());
		printf("%d\n",L[(n-1)/2]);
		}
	return 0;
	}
