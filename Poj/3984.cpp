#include<stdio.h>
#include<stack>
using namespace std;
stack<pair<int,int> >L;
int map[10][10];
int back[10][10]; 
int d[10][10];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
bool allow(int x,int y){
	if(x<0||x>4)return 0;
	if(y<0||y>4)return 0;
	if(map[x][y])return 0;
	return 1;
	}
void out(int x,int y){
	if(!x&&!y){
		printf("(0, 0)\n");
		return;
		}
	int t=back[x][y];
	out(x-dx[t],y-dy[t]);
	printf("(%d, %d)\n",x,y);
	}
int main(){
	int i,j;
	for(i=0;i<5;i++)for(j=0;j<5;j++)scanf("%d",&map[i][j]);
	for(i=0;i<5;i++)for(j=0;j<5;j++)back[i][j]=-1;
	for(i=0;i<5;i++)for(j=0;j<5;j++)d[i][j]=(int)1e9;
	d[0][0]=0;
	L.push(make_pair(0,0));
	while(!L.empty()){
		int x=L.top().first;
		int y=L.top().second;
		L.pop();
		for(i=0;i<4;i++)if(allow(x+dx[i],y+dy[i])){
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(d[xx][yy]>d[x][y]+1){
				d[xx][yy]=d[x][y]+1;
				L.push(make_pair(xx,yy));
				back[xx][yy]=i;
				}
			}
		}
	out(4,4);
//	return main();
	return 0;
	}
