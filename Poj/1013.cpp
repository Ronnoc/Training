#include <cstdio>
#include <cstring>
int w[30]= {0};
int main()
{
	int t;
	for ( scanf( "%d",&t ); t; t-- )
	{
		char l[4][12],r[4][12],csq[4][5];
		for ( int i=1; i<=3; i++ )
			scanf( "%s %s %s",l[i],r[i],csq[i] );
		int ret=0;
		int mi,mj;
		for ( int i=1; !ret&&i<=12; i++ )
			for ( int j=-1; !ret && j<2; j+=2 )
			{
				for ( int k=1; k<=12; k++ )
					w[k]=2;
				w[i]=2+j;
				int flag=1;
				for ( int i=1; i<=3; i++ )
				{
					int L=0,R=0;
					for ( int j=0; j<strlen(l[i]); j++ )
						L+=w[ l[i][j]-'A'+1 ];
					for ( int j=0; j<strlen(r[i]); j++ )
						R+=w[ r[i][j]-'A'+1 ];
					if ( L==R&&strcmp( csq[i],"even" )!=0 )
						flag=0;
					if ( L>R && strcmp( csq[i],"up" )!=0 )
						flag=0;
					if ( L<R && strcmp( csq[i],"down" )!=0 )
						flag=0;
				}
				if ( flag )
				{ret=1; mi=i; mj=j;}
			}
		printf("%c is the counterfeit coin and it is %s. \n",'A'+mi-1,mj>0?"heavy":"light");
	}
	return 0;
}
