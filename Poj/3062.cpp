#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;
#define N 2010
#define INF (int)1e9
int record[1000010][2];
int vis[N],n;
int main(){
	srand(6);
	int m,i,j,x,y,p,q;
	while (scanf("%d%d",&n,&m)!=EOF) {
		for(i=1;i<=m;i++) {
			scanf("%d%d%d%d",&p,&q,&x,&y);
			p++;q++;
			record[i][0]=2*p+x;
			record[i][1]=2*q+y;
		}
		for(i=1;i<=n;i++)vis[i]=2*i+rand()%2;
		int flag=0;
		for(int k=0;k<4*n;k++){
			flag=1;
			for(j=1;j<=m;j++){
				int l=record[j][0],r=record[j][1];
				if(vis[l/2]==l&&vis[r/2]==r){
					int tmp=rand()%2;
					x=record[j][tmp]/2;
					vis[x]=2*x+(1-vis[x]%2);
					flag=0;
					break;
				}
			}
			if(flag)break;
		}
		if (flag)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
