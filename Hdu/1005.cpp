#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "stdlib.h"
#include "time.h"
using namespace std;
#define eps 1e-7
const int N=100005;
double d[3][3]={
    {0.5 ,0.375,0.125},
    {0.25,0.125,0.625},
    {0.25,0.375,0.375}
};
double p[3][4]={
    {0.6 ,0.2 ,0.15,0.05},
    {0.25,0.3,0.2,0.25},
    {0.05,0.10,0.35,0.50}
};
double f[20050][5];
int pre[20050][5];
char s[105];

int check(char *s){
    if(strcmp(s,"Dry")==0)  return 0;
    if(strcmp(s,"Dryish")==0)  return 1;
    if(strcmp(s,"Damp")==0)  return 2;
    if(strcmp(s,"Soggy")==0)  return 3;
    return 0;
}

char ss[3][8]={"Sunny","Cloudy","Rainy"};
void out(int i,int k){
	if(i==0) return;
	out(i-1,pre[i][k]);
    printf("%s\n",ss[k]);
}

int st[12]={0,0,1,1,1,1,1,2,2,2,3,3};
void make_data(){
    char ss[4][10] = {"Dry","Dryish","Damp","Soggy"};

    //freopen("data.in","w",stdout);
    printf("100\n");
    srand( (unsigned)time( NULL ) );
    for(int i=0;i<100;i++){
        int n = rand()%1000+1;
        printf("%d\n",n);
        for(int j=0;j<n;j++){
            int k = rand()%12;
               printf("%s\n",ss[st[k]]);
        }
    }

    fclose(stdout);
}

int main(){
    int T,n,i,j,k,Case= 0;
//    make_data();
//    freopen("data.in","r",stdin);
//    freopen("data.out","w",stdout);

    scanf("%d",&T);
    while(T--){
        printf("Case #%d:\n",++Case);
        f[1][0]=0.63;
        f[1][1]=0.17;
        f[1][2]=0.20;

        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%s",s);
            k = check(s);
            for(j=0;j<3;j++){
                  if(i==1) f[i][j] = log(f[i][j]) + log(p[j][k]);
                  else{
                	  f[i][j]=-100000;
                	  for(int t=0;t<3;t++)
                		  if (f[i][j] < f[i - 1][t] + log(d[t][j])+log(p[j][k]))
                			  f[i][j] = f[i - 1][t] + log(d[t][j])+log(p[j][k]), pre[i][j] = t;
                  }
             }
        }
        k = 0;
        if(f[n][1]>f[n][k]) k=1;
        if(f[n][2]>f[n][k]) k=2;
		out( n,k );
    }

//    fclose(stdin);
//    fclose(stdout);
}

