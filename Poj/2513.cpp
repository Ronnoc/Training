#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#define N 250003 
using namespace std;
struct chop{
	char s[12];
	bool operator < (const chop &tp)const{return strcmp(s,tp.s)<0;}
	bool operator ==(const chop &tp)const{return strcmp(s,tp.s)==0;}
	}tp,rp;
vector<chop>L;
int B_search(chop tp){
	int l=0,r=L.size()-1;
	while(r>l){
		if(L[r]==tp)return r;
		if(L[l]==tp)return l;
		int mid=(l+r)/2;
		if(L[mid]==tp)return mid;
		else if(tp<L[mid])r=mid;
		else l=mid;
		}
	}
char map[N][2][12];
int ft[N<<1];
int sum[N<<1];
void ini(int x){
	int i;
	for(i=0;i<x;i++)ft[i]=i;
	for(i=0;i<x;i++)sum[i]=0;
	}
int find(int x){ return (x==ft[x]) ? x : ft[x]=find(ft[x]); }
void merge(int a,int b){
//	printf("merge(%d,%d)\n",a,b);
	int ra=find(a),rb=find(b);
	ft[ra]=rb;
	sum[a]++;sum[b]++;
	}
int main(){
	L.clear();
	int t=1;
	while(scanf("%s%s",map[t][0],map[t][1])!=EOF){
		strcpy(tp.s,map[t][0]);
		L.push_back(tp);
		strcpy(tp.s,map[t][1]);
		L.push_back(tp);
		t++;
		}
	sort(L.begin(),L.end());
	L.erase(unique(L.begin(),L.end()),L.end());
	int n=L.size(),i;
	ini(n);
	for(i=1;i<t;i++){
		strcpy(tp.s,map[i][0]);
		strcpy(rp.s,map[i][1]);
		merge(B_search(tp),B_search(rp));
		}
	int bug=0;
	for(i=0;i<n;i++)if(sum[i]%2==1)bug++;
//	printf("%d\n",bug);
	int root=find(0);
	int flag=1;
	for(i=1;i<n;i++)if(find(i)!=root)flag=0;
//	for(i=0;i<n;i++)printf("%d ",find(i));
	if(flag&&bug<=2&&bug!=1)printf("Possible\n");
	else printf("Impossible\n");
	return 0;
	}
