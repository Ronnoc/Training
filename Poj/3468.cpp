#include<stdio.h>
#define LL long long
struct line{
	int l,r;
	LL x,s;
	}T[1<<18];
void build(int s,int t,int w){
	T[w].l=s;T[w].r=t;
	T[w].x=0;T[w].s=0;
	if(s==t)return;
	int mid=(s+t)/2;
	build(s,mid,w*2);
	build(mid+1,t,w*2+1);
	}
void insert(int s,int t,int w,LL val){
	if(T[w].l==s&&T[w].r==t){T[w].x+=val;return;}
	T[w].s+=(t+1-s)*val;
	int mid=(T[w].l+T[w].r)/2;
	if(s>mid)insert(s,t,w*2+1,val);
	else if(t<=mid)insert(s,t,w*2,val);
	else {
		insert(s,mid,w*2,val);
		insert(mid+1,t,w*2+1,val);
		}
	}
LL sum(int s,int t,int w){
	LL tp=(t+1-s)*T[w].x; 
	if(T[w].l==s&&T[w].r==t)return tp+T[w].s;
	int mid=(T[w].l+T[w].r)/2;
	if(s>mid)return tp+sum(s,t,w*2+1);
	else if(t<=mid)return tp+sum(s,t,w*2);
	else {
		return tp+sum(s,mid,w*2)+sum(mid+1,t,w*2+1);
		}	
	}
int main(){
	int N,Q;
	while(scanf("%d%d",&N,&Q)!=EOF){
		build(1,N,1);
		int i,j,s,t;
		LL x;
		char c;
		for(i=1;i<=N;i++){
			scanf("%lld%*c",&x);
			insert(i,i,1,x);
			}
		for(i=1;i<=Q;i++){
			scanf("%c",&c);
			if(c=='Q'){
				scanf("%d %d%*c",&s,&t);
				printf("%lld\n",sum(s,t,1)); 
				continue;
				}
			scanf("%d %d %lld%*c",&s,&t,&x);
			insert(s,t,1,x);
			}
		} 
	return 0;
	}
