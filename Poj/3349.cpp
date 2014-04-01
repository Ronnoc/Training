#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define PIIIIII pair< pair< pair<int,int>,pair<int,int> >,pair<int,int> >
#define MB(a,b) make_pair(a,b)
#define MIIIIII(q,w,e,r,t,y) MB( MB(MB(q,w),MB(e,r)),MB(t,y) )
vector<PIIIIII >L;
int main() {
int OFFL=0;
#ifndef ONLINE_JUDGE
OFFL=1;
#endif
	int n;
	scanf("%d",&n);
	int i,j,x[10];
	for(i=1;i<=n;i++){
		for(j=1;j<=6;j++)scanf("%d",x+j);
		sort(x+1,x+7);
		L.push_back(MIIIIII(x[1],x[2],x[3],x[4],x[5],x[6]));
	}
	sort(L.begin(),L.end());
	int flag=0;
	for(i=1;i<L.size();i++)if(L[i-1]==L[i])flag=1;
	if(flag)printf("Twin snowflakes found.\n");
	else printf("No two snowflakes are alike.\n");
return 0;}
