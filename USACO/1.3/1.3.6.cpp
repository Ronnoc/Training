/*
ID: kybconn1
PROG: crypt1
LANG: C++
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n,can[11];
bool legal(int x,int k){
	while(x){
		int t=x%10;x/=10;k--;
		if(!can[t])return 0;
	}
	return k==0;
}
int main() {
	freopen ("crypt1.in", "r", stdin);
	freopen ("crypt1.out", "w", stdout);
	while(~scanf("%d",&n)){
		int i,j,x;
		for(i=0;i<=9;i++)can[i]=0;
		for(i=1;i<=n;i++){
			scanf("%d",&x);
			can[x]=1;
		}
		int tot=0;
		for(i=100;i<=999;i++)for(j=10;j<=99;j++)
			if(legal(i,3)&&legal(j,2)&&legal(i*j,4)&&legal(i*(j%10),3)&&legal(i*(j/10),3))
				tot++;
		printf("%d\n",tot);
	}
	return 0;
}
