#include <cstdio>
int main(){
	double e=2.5;
	printf("n e\n");
	printf("- -----------\n");
	printf("0 1\n");
	printf("1 2\n");
	printf("2 2.5\n");
	double t=2;
	for(int i=3;i<10;i++){
		t*=i;
		e+=1/t;
		printf("%d %.9lf\n",i,e);
	}
	return 0;
}
