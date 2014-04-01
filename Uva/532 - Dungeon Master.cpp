#include<stdio.h>
#include<string.h>
char map[40][40][40];	//
int ok[40][40][40];		//可走 
int bfs[40][40][40];
bool done[40][40][40];
int k,r,c;
struct point{int x,y,z;}q[65000],s,e;
int qr,ql;		//ql当前队首,qr当前队尾 
bool check_done(point s){
	return done[s.x][s.y][s.z];
	}
point build(int a,int b,int c){
	point s;
	s.x=a,s.y=b,s.z=c;
	return s;
	}
void enq(point s,int t){
//	printf("enq(%d,%d,%d)=%d\n",s.x,s.y,s.z,t);
	done[s.x][s.y][s.z]=1;
	bfs[s.x][s.y][s.z]=t;
	qr++; 
	q[qr]=s;
	}
bool check(int x,int y,int z){
	if(x<0||x>=k)return 0;
	if(y<0||y>=r)return 0;
	if(z<0||z>=c)return 0;
	if(done[x][y][z])return 0;
	if(!ok[x][y][z])return 0;
	return 1;
	}
void BFS(int t){
	if(check_done(e))return;
	int l=ql,r=qr;
	int i;
	for(i=l;i<=r;i++){
		ql++;
		int x=q[i].x,y=q[i].y,z=q[i].z;
		if(check(x+1,y,z))enq(build(x+1,y,z),t);
		if(check(x-1,y,z))enq(build(x-1,y,z),t);
		if(check(x,y+1,z))enq(build(x,y+1,z),t);
		if(check(x,y-1,z))enq(build(x,y-1,z),t);
		if(check(x,y,z+1))enq(build(x,y,z+1),t);
		if(check(x,y,z-1))enq(build(x,y,z-1),t);
		if(ql>qr)return;
		}
	BFS(t+1);
	}
int main(){
	while(scanf("%d%d%d",&k,&r,&c)!=EOF){
		if(k==0&&r==0&&c==0)break;
		int i,j,l;
		for(i=0;i<k;i++)for(j=0;j<r;j++)scanf("%s",map[i][j]);
		for(i=0;i<k;i++)for(j=0;j<r;j++)for(l=0;l<c;l++){
			if(map[i][j][l]=='S'){
				s.x=i,s.y=j,s.z=l;
				}
			if(map[i][j][l]=='E'){
				e.x=i,e.y=j,e.z=l;
				}
			if(map[i][j][l]=='#')ok[i][j][l]=0;
			else ok[i][j][l]=1;
			done[i][j][l]=0;
			bfs[i][j][l]=0;
			}
		ql=1;qr=0;
		bfs[s.x][s.y][s.z]=0;
		enq(s,0);
		BFS(1);
		int res=bfs[e.x][e.y][e.z];
		if(res)printf("Escaped in %d minute(s).\n",res);
		else printf("Trapped!\n");
		}
	return 0;
	}
