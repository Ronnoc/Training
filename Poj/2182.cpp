#include<stdio.h>
#include<list>
using namespace std;
int a[9010],n;
list<int>L;
list<int>::iterator iter;
list<int>res;
int main(){
	while(scanf("%d",&n)!=EOF){
		int i;
		for(i=1;i<n;i++)scanf("%d",&a[i]);
		L.clear();res.clear();
		for(i=1;i<=n;i++)L.push_back(i);
		for(i=n-1;i>=1;i--){
			iter=L.begin();
			while(a[i]--)iter++;
			res.push_front(*iter);
			L.erase(iter);
			}
		res.push_front(*L.begin());
		iter=res.begin();
		while(iter!=res.end()){
			printf("%d\n",*iter);
			iter++;
			}
		}
	return 0;
	}
