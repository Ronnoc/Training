import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	static StreamTokenizer	cin		= new StreamTokenizer( new BufferedReader( new InputStreamReader( System.in ) ) );
	static PrintWriter			cout	= new PrintWriter( new OutputStreamWriter( System.out ) );
	
	public static BigInteger[][] play( BigInteger[][] A, BigInteger[][] B ) {
		BigInteger[][] C = new BigInteger[2][2];
		int i, j, k;
		for ( i = 0; i < 2; i++ )
			for ( j = 0; j < 2; j++ )
				C[i][j] = BigInteger.ZERO;
		for ( i = 0; i < 2; i++ )
			for ( j = 0; j < 2; j++ )
				for ( k = 0; k < 2; k++ )
					C[i][j] = C[i][j].add( A[i][k].multiply( B[k][j] ) );
		return C;
	}
	
	public static void main( String[] args ) throws IOException {
		Scanner in = new Scanner( System.in );
		while ( in.hasNext() ) {
			BigInteger fa, fb, f0, f1;
			int a, b, n, t;
			a = in.nextInt();
			fa = in.nextBigInteger();
			b = in.nextInt();
			fb = in.nextBigInteger();
			n = in.nextInt();
			if ( a > b ) {
				t = a;
				a = b;
				b = t;
				f0 = fa;
				fa = fb;
				fb = f0;
			}
			f0 = fa;
			b -= a;
			n -= a;
			BigInteger[][] A = new BigInteger[2][2];
			BigInteger[][] O = new BigInteger[2][2];
			A[0][0] = A[0][1] = A[1][0] = BigInteger.ONE;
			A[1][1] = BigInteger.ZERO;
			O[0][0] = O[1][1] = BigInteger.ONE;
			O[0][1] = O[1][0] = BigInteger.ZERO;
			t = b - 1;
			while ( t > 0 ) {
				if ( ( t & 1 ) > 0 ) O = play( A, O );
				A = play( A, A );
				t /= 2;
			}
			f1 = fb.subtract( O[0][1].multiply( f0 ) ).divide( O[0][0] );
			if ( n == 0 ) cout.println( f0 );
			else if ( n > 0 ) {
				BigInteger p, q, r;
				p = f0;
				q = f1;
				int id = 1;
				while ( id < n ) {
					r = p.add( q );
					id++;
					p = q;
					q = r;
				}
				cout.println( q );
			} else {
				BigInteger p, q, r;
				q = f0;
				r = f1;
				int id = 0;
				while ( id > n ) {
					p = r.subtract( q );
					r = q;
					q = p;
					id--;
				}
				cout.println( q );
			}
		}
		in.close();
		cout.flush();
	}
	
	static int nextInt() throws IOException {
		cin.nextToken();
		return ( int ) cin.nval;
	}
}
