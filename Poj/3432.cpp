#include<vector>
#include<algorithm>
#include<stdio.h>
struct point{
	int x,y;
	bool operator <(const point &tp)const{
		if(x!=tp.x)return x<tp.x;
		return y<tp.y;
		}
	bool operator ==(const point &tp)const{
		return tp.x==x&&tp.y==y;
		}
	}tp;
std::vector<point>L;
int bfind(point t){
	int l=0,r=L.size()-1;
	while(r>l){
		if(r-l==1){
			if(t==L[r]||t==L[l])return 1;
			return 0;
			}
		int mid=(l+r)/2;
		if(L[mid]==t)return 1;
		else if(L[mid]<t)l=mid;
		else r=mid;
		}
	}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		int i,j;L.clear();
		for(i=0;i<n;i++){
			scanf("%d%d",&tp.x,&tp.y);
			tp.x*=2;tp.y*=2;
			L.push_back(tp);
			}
		std::sort(L.begin(),L.end());
		int res=0;
		for(i=0;i<L.size();i++)for(j=i+1;j<L.size();j++){
			int x1=L[i].x,x2=L[j].x,y1=L[i].y,y2=L[j].y;
			tp.x=(x1+x2+y1-y2)/2;
			tp.y=(y1+y2+x2-x1)/2;
			if(bfind(tp)){
				tp.x=(x1+x2-y1+y2)/2;
				tp.y=(y1+y2-x2+x1)/2;
				if(bfind(tp)){
				//	printf("%d %d\n",tp.x,tp.y);
					res++;
					}
				}
			}
		res/=2;
		printf("%d\n",res);
		}
	return 0;
	}
