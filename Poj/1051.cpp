#include<stdio.h>
#include<string.h>
#include<stack>
#include<iostream>
using namespace std;
char map[][30]=
{	".-","-...","-.-.","-..",".","..-.","--.",
	"....","..",".---","-.-",".-..","--","-.",
	"---",".--.","--.-",".-.","...","-","..-",
	"...-",".--","-..-","-.--","--.."
	};
char ue[]="..--";
char pd[]="---.";
char ca[]=".-.-";
char qk[]="----";
int ps;
char s[1010];
stack<int>Q;
void add(char *l){
	Q.push(strlen(l));
	for(int j=0;j<strlen(l);++j){
		s[ps++]=l[j];
		}	
	}
int main(){
	int i,j,T=50,t;
	char old[1010];
	cin>>T;
	for(t=1;t<=T;t++){
		scanf("%s",old);
		int len_o=strlen(old);
		ps=0;
		for(i=0;i<len_o;i++){
			if(old[i]<='Z'&&old[i]>='A'){
				int t=old[i]-'A';
				add(map[t]);
				}
			else if(old[i]=='_')add(ue);
			else if(old[i]==',')add(ca);
			else if(old[i]=='.')add(pd);
			else if(old[i]=='?')add(qk);
			}
		s[ps]='\0';
		ps=0;
		printf("%d: ",t);
		while(!Q.empty()){
			int k=Q.top();
			Q.pop();
			for(i=0;i<k;i++){
				old[i]=s[ps++];
				}old[i]='\0';
			if(strcmp(old,ue)==0)printf("%c",'_');
			else if(strcmp(old,ca)==0)printf("%c",',');
			else if(strcmp(old,pd)==0)printf("%c",'.');
			else if(strcmp(old,qk)==0)printf("%c",'?');
			else for(i=0;i<26;i++){
				if(strcmp(old,map[i])==0)printf("%c",'A'+i);
				}
			}
		cout<<endl;
		}
	return 0;
	}
