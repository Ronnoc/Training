#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[1010][1010];
int main(){
	int n=0;
	for(;scanf("%d",&n)!=EOF;){
		if(!n)break;
		int i,j;
		int flag=1;
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)scanf("%d",&a[i][j]);
		for(i=1;i<=n;i++)for(j=i+1;j<=n;j++){
			int l=a[i][j]+a[j][i];
			int r=a[i][i]+a[j][j];
			if(l!=r)flag=0;
		}
		if(flag)printf("homogeneous\n");
		else printf("not homogeneous\n");
	}
	return 0;
}
