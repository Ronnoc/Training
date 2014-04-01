#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
#define LEN 1001
char fs[1000010],I[2010],cmd[2010];
int Q[2010];
struct node
{
	int pre,nxt;
	char c;
	node() {pre=-1,nxt=-1,c='\0';};
	void output()
	{
		printf( "%c",c );
	}
} s[1002010];
int pt[1111],ed,sl,mx;
void PB( char c )
{
	++sl;
	if ( ed>=0 )
		s[ed].nxt=sl;
	s[sl].pre=ed;
	s[sl].nxt=-1;
	s[sl].c=c;
	ed=sl;
}
void insrt( char c,int at )
{
	int pre=s[at].pre;
	++sl;
	if ( pre>=0 )
		s[pre].nxt=sl;
	s[at].pre=sl;
	s[sl].pre=pre;
	s[sl].nxt=at;
	s[sl].c=c;
}
int get( int Q )
{
	int k=Q/LEN,b=Q%LEN;
	if ( k==mx&&( sl%LEN-b )<=b )
	{
		int at=ed;
		int tot=sl%LEN-b;
		while ( tot-- )
			at=s[at].pre;
		return at;
	}
	else
		if ( b<=LEN-b )
		{
			int at=pt[k];
			int tot=b;
			while ( tot-- )
				at=s[at].nxt;
			return at;
		}
		else
		{
			int at=pt[k+1];
			int tot=LEN-b;
			while ( tot-- )
				at=s[at].pre;
			return at;
		}
}
void ini()
{
	scanf( "%s",fs );
	sl=-1;
	ed=-1;
	int len=strlen( fs );
	for ( int i=0; i<len; i++ )
	{
		PB( fs[i] );
		if ( i%LEN==0 )
			pt[i/LEN]=sl;
	}
	mx=( len-1 )/LEN;
}
int main()
{
	int n,i,j;
	ini();
	scanf( "%d%*c",&n );
	for ( i=1; i<=n; i++ )
	{
		cmd[i]=getchar();
		if ( cmd[i]=='Q' )
		{
			scanf( " %d%*c",&Q[i] );
			Q[i]--;
			int at=get( Q[i] );
			printf( "%c\n",s[at].c );
			continue;
		}
		scanf( " %c %d%*c",&I[i],&Q[i] );
		Q[i]--;
		if ( Q[i]>sl )
		{
			PB( I[i] );
			if ( sl/LEN>mx )
				pt[++mx]=sl;
//			for ( j=pt[0]; j!=-1; j=s[j].nxt )
//				s[j].output();
//			printf( "\n" );
			continue;
		}
		int at=get( Q[i] );
		int k=Q[i]/LEN,b=Q[i]%LEN;
		insrt( I[i],at );
		for ( j=( b==0 )?k:k+1; j<=mx; j++ )
			pt[j]=s[pt[j]].pre;
		if ( sl/LEN>mx )
			pt[++mx]=ed;
//		for ( j=pt[0]; j!=-1; j=s[j].nxt )
//			s[j].output();
//		printf( "\n" );
	}
	return 0;
}
