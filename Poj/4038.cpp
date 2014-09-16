#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
double f(double p){
	return pow(p,4)+4*pow(p,4)*(1-p)+10*pow(p,4)*pow(1-p,2)+20*pow(p,5)*pow(1-p,3)/(1-2*p*(1-p));
}
bool cangao(int a,int b){
	if(a>=7&&a>=b+2)return 0;
	if(b>=7&&b>=a+2)return 0;
	return 1;
}
double gao(double p){
	double dp[33][33];
	int i,j;
	for(i=0;i<=10;i++)for(j=0;j<=10;j++)dp[i][j]=0;
	dp[0][0]=1;
	for(i=0;i<10;i++)for(j=0;j<10;j++)if(cangao(i,j)){
		dp[i][j+1]+=dp[i][j]*(1-p);
		dp[i+1][j]+=dp[i][j]*p;
	}
	double ret=0;
	for(i=0;i<=5;i++)ret+=dp[7][i];
	ret+=dp[6][6]*p*p/(1-2*p*(1-p));
	return ret;
}
double ff(double g,double p){
	double ret=0;
	ret+=1*pow(1-g,0);
	ret+=6*pow(1-g,1);
	ret+=21*pow(1-g,2);
	ret+=56*pow(1-g,3);
	ret+=126*pow(1-g,4);
	ret*=pow(g,6);
	ret+=252*pow(g,7)*pow(1-g,5);
	ret+=504*pow(g,6)*pow(1-g,6)*gao(p);
	return ret;
}
int main(){
	int n;
	char s[1111];
	while(~scanf("%s",s)){
		if(strcmp(s,"-1")==0)break;
		double p;
		sscanf(s,"%lf",&p);
		double g=f(p);
		double s=ff(g,p);
		double m=s*s+2*s*s*(1-s);
		printf("%.11f %.11f %.11f\n",g,s,m);
	}
	return 0;
}
