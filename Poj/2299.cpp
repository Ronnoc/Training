#include<iostream>
#include<vector>
#include<algorithm>
#define LL long long
#define N 500010 
using namespace std;
vector<LL>L,map;
vector<LL>::iterator iter;
int tree[N<<1];
int LB(int x){	return x&(-x);	}
void add(int w,int d){
	for(;w<=N+3;w+=LB(w))tree[w]+=d;
	}
int get_sum(int w){
	int res=0;
	for(;w>0;w-=LB(w))res+=tree[w];
	return res;
	} 
int Bfind(int x){
	iter=lower_bound(map.begin(),map.end(),x);
	return iter+2-map.begin();
	}
int main(){
	LL n;
	while(cin>>n){
		if(!n)break;
		L.clear();		
		map.clear();
		LL x;	
		int i;
		for(i=1;i<=n;i++){
			cin>>x;
			L.push_back(x);
			map.push_back(x);
			}
		sort(map.begin(),map.end());
		iter=unique(map.begin(),map.end());
		map.erase(iter,map.end());
		for(i=1;i<=N+3;i++)tree[i]=0;
		LL res=(n-1)*n/2;
		for(i=0;i<n;i++){
			int w=Bfind(L[i]);
			res-=get_sum(w);
			add(w,1); 
			}
		cout<<res<<"\n";
		}
	return 0;
	}
