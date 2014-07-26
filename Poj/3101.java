import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	public Long __gcd( Long a, Long b ) {
		if ( b == 0 ) return a;
		return __gcd( b, a % b );
	}
	
	public void Solve() throws IOException {
		while ( hasNext() ) {
			int i, n = nextInt();
			int[] L = new int[n];
			for ( i = 0; i < n; i++ )
				L[i] = nextInt();
			Arrays.sort( L );
			BigInteger U = BigInteger.ONE;
			BigInteger D = BigInteger.ZERO;
			for ( i = 1; i < n; i++ )
				if ( L[i] != L[i - 1] ) {
					Long _u = 1L * L[i] * L[i - 1];
					Long _d = 2L * ( L[i] - L[i - 1] );
					Long _g = __gcd( _u, _d );
					BigInteger u = BigInteger.valueOf( _u / _g );
					U = U.multiply( u.divide( u.gcd( U ) ) );
					D = D.gcd( BigInteger.valueOf( _d / _g ) );
				}
			BigInteger g = U.gcd( D );
			U = U.divide( g );
			D = D.divide( g );
			writer.println( U + " " + D );
		}
	}
	
	public static void main( String[] args ) throws IOException {
		new Main().run();
	}
	
	BufferedReader	reader;
	StringTokenizer	tokenizer;
	PrintWriter			writer;
	
	public void run() {
		try {
			reader = new BufferedReader( new InputStreamReader( System.in ) );
			tokenizer = null;
			writer = new PrintWriter( System.out );
			Solve();
			reader.close();
			writer.flush();
			writer.close();
		} catch ( Exception e ) {
			e.printStackTrace();
			System.exit( 1 );
		}
	}
	
	boolean hasNext() throws IOException {
		while ( tokenizer == null || !tokenizer.hasMoreTokens() ) {
			String nextLine = reader.readLine();
			if ( nextLine == null ) return false;
			tokenizer = new StringTokenizer( nextLine );
		}
		return true;
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt( nextToken() );
	}
	
	long nextLong() throws IOException {
		return Long.parseLong( nextToken() );
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble( nextToken() );
	}
	
	String nextLine() throws IOException {
		return reader.readLine();
	}
	
	String nextToken() throws IOException {
		while ( tokenizer == null || !tokenizer.hasMoreTokens() ) {
			tokenizer = new StringTokenizer( reader.readLine() );
		}
		return tokenizer.nextToken();
	}
	
	BigInteger nextBigInteger() throws IOException {
		while ( tokenizer == null || !tokenizer.hasMoreTokens() ) {
			tokenizer = new StringTokenizer( reader.readLine() );
		}
		return new BigInteger( tokenizer.nextToken() );
	}
}
