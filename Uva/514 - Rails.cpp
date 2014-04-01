#include<stdio.h>
#include<vector>
std::vector<int>q;
int a[100010];
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("o.txt","w",stdout);
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		while(scanf("%d",&a[1])!=EOF&&a[1]){
			int flag=1;
			int i;
			for(i=2;i<=n;i++)scanf("%d",&a[i]);
			int pa=1;
			for(i=1;i<=n;i++){
				if(a[pa]==i)pa++;
				else {
					while(q.size()>0){
						if(q[q.size()-1]==a[pa]){
							q.pop_back();
							pa++;
							}
						else break;
						}
					q.push_back(i);
					}
				}
//			for(i=0;i<q.size();i++)printf("%d ",q[i]);printf("\n");
			for(i=0;i<q.size();i++){
				if(q[i]!=a[n-i])flag=0;
				}
			q.clear();
			if(flag)printf("Yes\n");
			else printf("No\n");
			}
		printf("\n");
		}
	return 0;
	}
