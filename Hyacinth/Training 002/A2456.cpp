#include <algorithm>
#include <cstdio>
using namespace std;
int a[111000],n,m;
bool can(int d){
	int last=-1000000000,tot=0,i;
	for(i=0;i<n;i++)
		if(a[i]-last>=d)last=a[i],tot++;
	return tot>=m;
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		int i;
		for(i=0;i<n;i++)scanf("%d",&a[i]);
		sort(a,a+n);
		int l=0,r=1000000000,ans=-1;
		while(r>=l){
			if(r-l<=1){
				if(can(r))ans=r;
				else if(can(l))ans=l;
				break;
			}
			int mid=(l+r)/2;
			if(can(mid))l=mid;
			else r=mid;
		}
		printf("%d\n",ans);
	}
	return 0;
}
