#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
struct line{
	int l,r;
	int x;
	}L[1<<16];
void use(int w){
	printf("i=%d::l=%d,r=%d,x=%d\n",w,L[w].l,L[w].r,L[w].x);
	}
void build(int s,int t,int wl){
//	printf("build (%d,%d) on %d\n",s,t,wl);
//	use(wl);
	L[wl].l=s;L[wl].r=t;
	L[wl].x=0;
	if(s==t)return;
	int mid=(s+t)/2;
	build(s,mid,wl*2);
	build(mid+1,t,wl*2+1);
	}
void insert(int s,int t,int wl,int x){
//	printf("(%d %d)add %d\n",s,t,wl,x);
//	use(wl);
	if(s>t)return;
	if(s==L[wl].l&&t==L[wl].r){L[wl].x=x;return;}
	if(L[wl].l==L[wl].r)return;
	int mid=(L[wl].l+L[wl].r)/2;
		int tp=L[wl].x;L[wl].x=0;
		if(tp)insert(t+1,L[wl].r,wl,tp);
		if(tp)insert(L[wl].l,s-1,wl,tp);
	if(mid>=t)insert(s,t,wl*2,x);
	else if(mid<s)insert(s,t,wl*2+1,x);
	else {
		insert(s,mid,wl*2,x);
		insert(mid+1,t,wl*2+1,x);
		}
	}
int ok[10010];
int l[10010],r[10010];

void visit(int wl){
//	printf("visit(%d)\n",wl);
//	use(wl);
	if(L[wl].x)ok[ L[wl].x ]++;
	else if(L[wl].l==L[wl].r)return;
	else {
		visit(wl*2);
		visit(wl*2+1);
		}
	}
vector<int>Z;
int find(int x){
	int i;
	int l=0,r=Z.size()-1;
	while(1){
		if(r-l==1){
			if(Z[r]==x)return r;
			else return l;
			}
		int mid=(l+r)/2;
		if(Z[mid]==x)return mid;
		else if(Z[mid]>x)r=mid;
		else l=mid;
		}
	}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		Z.clear(); 
		int i;
		for(i=1;i<=n;i++){
			scanf("%d%d",&l[i],&r[i]);
			Z.push_back(l[i]);
			Z.push_back(r[i]);
			}
		build(0,2*n,1);
		sort(Z.begin(),Z.end());
		for(i=1;i<=n;i++){
			insert(find(l[i]),find(r[i]),1,i);
			}
		for(i=1;i<=n;i++)ok[i]=0;
		visit(1);
		int res=0;
		for(i=1;i<=n;i++)if(ok[i])res++;
		printf("%d\n",res);
		}
	return 0;
	}
