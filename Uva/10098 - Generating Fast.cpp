#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#define INF (int)1e9
char s[110];
bool Next_per(){
	int len=strlen(s);
	int aim=INF;
	int i;
	for(i=len-1;i>0;i--){
		if(s[i]>s[i-1]){
			aim=i-1;
			break;
			}
		}
	if(aim==INF)return 0; 
	for(i=len-1;i>aim;i--){
		if(s[i]>s[aim])break;
		}
	char t;
	t=s[i];s[i]=s[aim];s[aim]=t;
	int l=aim+1,r=len-1;
	while(l<r){
		t=s[l];
		s[l]=s[r];
		s[r]=t;
		l++;
		r--;
		}
	return 1;
	}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){ 
		scanf("%s",s);
		int len=strlen(s);
		std::sort(s,s+len);	
		do{
			printf("%s\n",s);
			}while(Next_per());
		printf("\n");
		}
	return 0;
	}
