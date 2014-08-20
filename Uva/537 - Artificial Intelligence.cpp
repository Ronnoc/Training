#include<string.h>
#include<stdio.h>
#define eps 1e-8
bool C ( char x ) {
	if ( x=='P'||x=='U'||x=='I' ) return 1;
	return 0;
}
double f ( char dw ) {
	if ( dw=='m' ) return 0.001;
	if ( dw=='k' ) return 1000;
	if ( dw=='M' ) return 1000000;
	return 1;
}
bool is_num ( char c ) {
	if ( c>='0'&&c<='9' ) return 1;
	return 0;
}
double abs ( double x ) {
	if ( x>0 ) return x;
	return -x;
}
double k ( double x ) {
	if ( abs ( x ) <eps ) return 0;
	return x;
}
int main() {
	int z,i;
	scanf ( "%d",&z ); getchar();
	char time=0;
	while ( z-- ) {
		char LL[99999];
		char t[99999];
		gets ( LL );
		double _p=-9999,_u=-9999,_i=-9999;
		int sum=0;
		for ( i=0; i<strlen ( LL )-3; i++ ) {
			if ( C ( LL[i] ) && LL[i+1]=='=' ) { //&& is_num(LL[i+3]) ){
				double x;
				int p,q=0;
				for ( p=i+2; p<=strlen ( LL ); p++ ) {
					t[q++]=LL[p];
				}
				char dw;
				char y=LL[i];
				sscanf ( t,"%lf%c",&x,&dw );
				x*=f ( dw );
				if ( y=='P' ) {_p=x; sum++;}
				if ( y=='U' ) {_u=x; sum++;}
				if ( y=='I' ) {_i=x; sum++;}
				if ( sum==2 ) break;
			}
		}
		printf ( "Problem #%d\n",++time );
		if ( _p==-9999 ) {
			_p=_u*_i;
			_p=k ( _p );
			printf ( "P=%.2fW\n\n",_p );
			continue;
		}
		if ( _u==-9999 ) {
			_u=_p/_i;
			_u=k ( _u );
			printf ( "U=%.2fV\n\n",_u );
			continue;
		}
		if ( _i==-9999 ) {
			_i=_p/_u;
			_i=k ( _i );
			printf ( "I=%.2fA\n\n",_i );
			continue;
		}
	}
	//	printf("!");getchar();
	return 0;
}
