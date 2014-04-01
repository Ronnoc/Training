#include<stdio.h>
#include<vector>
#define SMAX 1000010
#include<algorithm>
int n,a[SMAX];
int dp[SMAX];
int ok[SMAX];
std::vector<int>f;
std::vector<int>::iterator pf;
int max(int a,int b){
	if(a>b)return a;return b;
	}
int main(){
	n=0;f.clear();
	int i,j;
	while(scanf("%d",&a[++n])!=EOF);
	n--;
	dp[1]=1;
	f.push_back(a[1]);
	for(i=2;i<=n;i++){
		pf = lower_bound( f.begin(), f.end(), a[i] );
		int k=pf-f.begin();
	//	printf("%d\n",k);
		if(pf==f.end()){
			f.push_back(a[i]);
			dp[i]=f.size();
			}
		else {
			*pf=a[i];
		//	at[k]=i;
			dp[i]=k+1;
			}
	//	f.push_back(a[i]);
	//	sort(f.begin(),f.end());
	//	for(j=0;j<f.size();j++)printf("%d ",f[j]);printf("\n");
		}
	int res=1;
	for(i=1;i<=n;i++)res=max(dp[i],res);
	int pes=1;
	for(i=1;i<=n;i++)if(dp[i]==res)pes=i;
	printf("%d\n-\n",res);
	for(i=1;i<=n;i++)ok[i]=0;
	ok[pes]=1;
	for(i=pes-1;i>=1;i--){
		if(dp[i]==res-1&&a[i]<a[pes]){
			pes=i;
			ok[pes]=1;
			res--;
			}
		}
	for(i=1;i<=n;i++)if(ok[i])printf("%d\n",a[i]);
//	return main();
	return 0;
	}
