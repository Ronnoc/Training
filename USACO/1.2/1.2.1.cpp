/*
ID: kybconn1
PROG: milk2
LANG: C++
*/
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct farmer{
	int l,r;
	bool operator<(const farmer &tp)const
		{return l<tp.l;}
	}tp;
vector<farmer>L;
int main(){
	freopen("milk2.in","r",stdin);
	freopen("milk2.out","w",stdout);
	int n;
	while(scanf("%d",&n)!=EOF){
		int i;
		L.clear();
		for(i=1;i<=n;i++){
			scanf("%d%d",&tp.l,&tp.r);
			L.push_back(tp);
			}
		sort(L.begin(),L.end());
		int x=0,y=0;
		int minl=L[0].l,maxr=L[0].r;
		x=maxr-minl;
		for(i=1;i<L.size();i++){
			if(L[i].l>maxr){
				y=max(y,L[i].l-maxr);
				x=max(x,L[i].r-L[i].l);
				maxr=L[i].r;
				minl=L[i].l; 
				}
			else {
				if(L[i].r<=maxr)continue;
				maxr=L[i].r;
				x=max(x,maxr-minl);
				}
			}
		printf("%d %d\n",x,y);
		}
	return 0;
	}
