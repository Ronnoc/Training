#include<stdio.h>
#include<stdlib.h>
int count(int y){
	int res=0,tp=y;
	while(y){
		res+=y%10;y/=10;
		}
	return res;
	}
bool Smith(int x){
	int left=count(x);
	int i,right=0;
	int tp=x;
	for(i=2;i*i<=tp;i++){
		while(x%i==0){
			right+=count(i);
			x/=i;
			}
		}
	if(!right)return 0;
	if(x-1)right+=count(x);
	return left==right;
	}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		while(n++){
			if(Smith(n)){
				printf("%d\n",n);
				break;
				}
			}
		}
	return 0;
	}
