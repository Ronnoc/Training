#include<stdio.h>
#include<string.h>
char map[160][160];
int n,m;
int gl_x,gl_y,f_x,f_y;
bool f(int p,int q){
	if(p<0||q<0)return 1;
	if(p>=n||q>=m)return 1;
	return 0;
	}
int line(char *s,int p,int q,int x,int y){
	int len=strlen(s);
	int k;
	for(k=1;k<len;k++){
		p+=x;q+=y;
		if(f(p,q)||map[p][q]!=s[k])return 0;
		}
	return 1;
	}
bool Here(char *s,int p,int q){
	if(map[p][q]!=s[0])return 0;
	int i,j;
	int len=strlen(s);
	for(i=-1;i<=1;i++)for(j=-1;j<=1;j++){
		if(i==0&&j==0)continue;
	//	printf("%s~(%d,%d)+(%d,%d)=%d\n",s,p,q,i,j,line(s,p,q,i,j));
		if(line(s,p,q,i,j)){f_x=p+(len-1)*i;f_y=q+(len-1)*j;return 1;}
		}
	return 0;
	}
void search(char *s){
	int p,q;
	for(p=0;p<n;p++)for(q=0;q<m;q++){
		if(Here(s,p,q)){
			gl_x=p+1;
			gl_y=q+1;
			return;
			}
		}
	}
int main(){
	while(scanf("%d",&n)!=EOF&&n){
		m=n;
		int i,j;
		for(i=0;i<n;i++)scanf("%s",map[i]);
		for(i=0;i<n;i++)for(j=0;j<m;j++){
			char c=map[i][j];
			if(c>='A'&&c<='Z'){
				map[i][j]=c-'A'+'a';
				}
			}
		//	printf("!\n");
		char aim[160];
		int px,py;
		while(scanf("%s",aim)!=EOF){
			if(aim[0]=='0')break;
			gl_x=-1;
			for(i=0;i<strlen(aim);i++){
				char c=aim[i];
				if(c>='A'&&c<='Z'){
					aim[i]=c-'A'+'a';
					}
				}
			search(aim);
			if(gl_x!=-1)printf("%d,%d %d,%d\n",gl_x,gl_y,f_x+1,f_y+1);
			else printf("Not found\n");
			}
		}
	return 0;
	}
