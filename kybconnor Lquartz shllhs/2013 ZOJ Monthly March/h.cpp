//kybconnor shllhs
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char s[11111];
int main() {
	int i,j;
	int n,k;
	double w;
	while (cin>>n>>w>>k) {
		n+=2;
		w*=100;
		int W;
		sprintf (s,"%.0lf", w);
		sscanf (s,"%d",&W); //n W k
		int num = n/k;
		int tot= (n-num) *W;
		int per= (tot+1) /2;
		printf ("%d.%02d\n",per/100,per%100);
	}
	return 0;
}
