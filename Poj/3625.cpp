#include<stdio.h>
#include<algorithm> 
#include<vector> 
#include<iostream>
#include<cmath>
using namespace std;
#define LD long double
#define N 1010
struct edge{
	int u,v;
	LD w;
	edge(int p,int q,LD r){
		u=p;v=q;w=r;
		}
	bool operator <(const edge &tp)const {
		return w<tp.w;
		}
	};
vector<edge>L;
int ft[N];
void ini_ft(int n){for(int i=1;i<=n;i++)ft[i]=i;}
int find(int x){return ft[x]==x?x:ft[x]=find(ft[x]);}
void merge(int a,int b){
	int x=find(a),y=find(b);
	ft[x]=y;
	}
LD x[N],y[N];
LD dis(int a,int b){
	LD xx=x[a]-x[b];
	LD yy=y[a]-y[b];
	return sqrt(xx*xx+yy*yy);
	} 
int main(){
	int n,i,j,w,m,a,b;
	while(cin>>n>>m){
		L.clear();
		for(i=1;i<=n;i++)cin>>x[i]>>y[i];
		for(i=1;i<=n;i++)for(j=i+1;j<=n;j++)
			L.push_back( edge(i,j,dis(i,j)) );
		sort(L.begin(),L.end());
		ini_ft(n);
		for(i=1;i<=m;i++){
			cin>>a>>b;
			merge(a,b);
			}
		LD res=0;
		for(i=0;i<L.size();i++){
			a=find(L[i].u);
			b=find(L[i].v);
			if(a!=b){
				res+=L[i].w;
				merge(a,b);
				}
			}
		printf("%.2f\n",(double)res);
		}
	return 0;
	}
