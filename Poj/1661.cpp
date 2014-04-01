#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std; 
struct line{
	int l,r;
	int clr;
	int all;
	}T[1000<<4];	//线段树
void Build_tree(int l,int r,int i){				//Build_tree(min,max,1)调用
//	cout<<"Build_tree:"<<l<<","<<r<<"@"<<i<<endl;
	T[i].l=l;
	T[i].r=r;
	T[i].clr=-1;
	T[i].all=0;
	if(l==r)return;
	int mid=(l+r)/2;
	Build_tree(l,mid,2*i);
	Build_tree(mid+1,r,2*i+1); 
	}
void Colour(int l,int r,int i,int x){			//Colour(l,r,1,x)调用 
//	cout<<"Colour:"<<l<<","<<r<<"@"<<i<<"for NO."<<x<<endl;
	if(T[i].l==l&&T[i].r==r){
		T[i].clr=x;
		T[i].all=1;
		return;
		}
	int mid=(T[i].l+T[i].r)/2;
	if(T[i].all){
		int y=T[i].clr;
		T[i].all=0;
		if(mid<l){
			Colour(T[i].l,mid,2*i,y);
			if(l-1>=mid+1)Colour(mid+1,l-1,2*i+1,y);
			Colour(l,r,2*i+1,x);
			if(r+1<=T[i].r)Colour(r+1,T[i].r,2*i+1,y); 
			}
		else if(mid>=r){
			if(T[i].l<=l-1)Colour(T[i].l,l-1,2*i,y);
			Colour(l,r,2*i,x);
			if(r+1<=mid)Colour(r+1,mid,2*i,y);
			Colour(mid+1,T[i].r,2*i+1,y);
			}
		else {
			if(T[i].l<=l-1)Colour(T[i].l,l-1,2*i,y);
			Colour(l,mid,2*i,x);
			Colour(mid+1,r,2*i+1,x);
			if(T[i].r>=r+1)Colour(r+1,T[i].r,2*i+1,y);
			}	
		}
	else {
		if(mid<l)Colour(l,r,2*i+1,x);
		else if(mid>=r)Colour(l,r,2*i,x);
		else {
			Colour(l,mid,2*i,x);
			Colour(mid+1,r,2*i+1,x);
			}
		}
	}
int Get_colour(int here,int i){					//Get_colour(here,1)调用
	if(T[i].all)return T[i].clr;
	int mid=(T[i].l+T[i].r)/2;
	if(here<=mid)return Get_colour(here,2*i);
	else return Get_colour(here,2*i+1);
	}
vector<int>Z;		//将所有出现过的点push到Z里面,sort下,unique下 
vector<int>::iterator iter;
int Z_find(int x){		//二分找到离散化对应 
	iter=lower_bound(Z.begin(),Z.end(),x);
	return iter-Z.begin()+1;
	}
struct table{
	int l,r,h;
	bool operator<(const table tp)const{
		return h<tp.h;
		}
	}L[1010];
vector<pair<int,int> >G[1010];
int dl[1010],dr[1010];
const int INF=(int)1e9;
struct pak{
	int i,x,t;
	pak(int a,int b,int c){
		i=a,x=b,t=c;
		}
	};
int main(){
	int T=20;
	scanf("%d",&T);
	while(T--){
		int N,X,Y,MAX;
		int i;
		scanf("%d%d%d%d",&N,&X,&Y,&MAX);
		for(i=0;i<=N+1;i++)
			G[i].clear();
		for(i=1;i<=N;i++)
			scanf("%d%d%d",&L[i].l,&L[i].r,&L[i].h);
		sort(L+1,L+N+1);
		L[0].h=0;
		L[N+1].h=Y;
		L[N+1].l=L[N+1].r=X;
		Z.clear();
		Z.push_back(X);
		for(i=1;i<=N;i++){
			Z.push_back(L[i].l);
			Z.push_back(L[i].r);
			}
		sort(Z.begin(),Z.end());
		Z.erase(unique(Z.begin(),Z.end()),Z.end());
		Build_tree(1,Z.size(),1);
		Colour(1,Z.size(),1,0);
	//	for(i=1;i<=N;i++)cout<<L[i].l<<" "<<L[i].r<<" "<<L[i].h<<endl;;
		for(i=1;i<=N+1;i++){
			int ll=Z_find(L[i].l);
			int rr=Z_find(L[i].r);
	//		cout<<i<<"~~ll:"<<ll<<" rr:"<<rr<<endl;
			int l_clr=Get_colour(ll,1);
			int r_clr=Get_colour(rr,1);
			if(L[i].h-L[l_clr].h<=MAX)
				G[i].push_back(make_pair(l_clr,-1));	//!not sure how!
			if(L[i].h-L[r_clr].h<=MAX)
				G[i].push_back(make_pair(r_clr, 1));	//!not sure how!
			Colour(ll,rr,1,i);
			}
	/*	for(i=1;i<=N+1;i++){
			for(j=0;j<G[i].size();++j)cout<<G[i][j]<<" ";
			cout<<endl;
			}	*/
		for(i=1;i<=N+1;i++)dl[i]=INF;
		for(i=1;i<=N+1;i++)dr[i]=INF;
		int res=INF;
		queue<pak>Q;
		Q.push(pak(N+1,X,0));
		while(!Q.empty()){
			int u=Q.front().i;
			int x=Q.front().x;
			int t=Q.front().t;
	//		cout<<"@table:"<<u<<" X:"<<x<<" t:"<<t<<endl;
			Q.pop();
			for(i=0;i<G[u].size();i++){
				int v=G[u][i].first;
				int how=G[u][i].second;
				int to_l=x-L[u].l;
				int to_r=L[u].r-x;
				if(how>0){
					if(v==0){
						res=min(res,t+to_r);
						continue;
						}
					if(dr[u]>t+to_r){
						dr[u]=t+to_r;
						Q.push(pak(v,L[u].r,dr[u]));
						}
					}
				if(how<0){
					if(v==0){
						res=min(res,t+to_l);
						continue;
						}
					if(dl[u]>t+to_l){
						dl[u]=t+to_l;
						Q.push(pak(v,L[u].l,dl[u]));
						}
					}
				}
			}
		cout<<res+Y<<endl;
		}
	return 0;
	}
