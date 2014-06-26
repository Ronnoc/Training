import java.io.IOException;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {

	// static StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new
	// InputStreamReader(System.in)));
	// static PrintWriter cout = new PrintWriter(new
	// OutputStreamWriter(System.out));
	
	public static void main( String[] args ) throws IOException {
		Scanner in = new Scanner( System.in );
		int TT = in.nextInt();
		for ( int CA = 1; CA <= TT; CA++ ) {
			if ( CA > 1 ) System.out.println();
			String z = in.next();
			int Z = z.length();
			int K = in.nextInt();
			int[] ed = new int[K + 5];
			for ( int i = 1; i <= K; i++ )
				ed[i] = 0;
			int S = in.nextInt();
			int nt = in.nextInt();
			for ( int i = 1; i <= nt; i++ ) {
				int t = in.nextInt();
				ed[t] = 1;
			}
			int[][] G = new int[K + 5][Z + 5];
			int[][] F = new int[K + 5][Z + 5];
			for ( int i = 1; i <= K; i++ )
				for ( int j = 1; j <= Z; j++ )
					G[i][j] = in.nextInt();
			for ( int i = 1; i <= K; i++ )
				for ( int j = 1; j <= Z; j++ )
					F[i][j] = in.nextInt();
			int N = in.nextInt();
			int[][] T = new int[1010][1010];
			for ( int i = 1; i <= K; i++ )
				for ( int j = 1; j <= K; j++ )
					T[i][j] = 0;
			for ( int j = 1; j <= Z; j++ ) {
				int[] g = new int[K + 5];
				for ( int i = 1; i <= K; i++ )
					g[i] = -1;
				for ( int i = 1; i <= K; i++ )
					if ( F[i][j] == 0 ) g[i] = G[i][j];
				for ( int i = 1; i <= K; i++ )
					if ( g[i] == -1 ) {
						int u = i, v;
						Set<Integer> SS = new HashSet<Integer>();
						int[] L = new int[K + 5];
						int nl = 0;
						boolean cir = false;
						L[nl++] = u;
						while ( true ) {
							v = G[u][j];
							L[nl++] = v;
							if ( g[v] != -1 ) break;
							else if ( F[u][j] > 0 ) {
								if ( SS.contains( u ) ) {
									cir = true;
									break;
								} else {
									SS.add( u );
									u = v;
								}
							} else break;
						}
						if ( cir || g[v] == -1 ) g[v] = 0;
						for ( int k = 0; k < nl; k++ )
							g[L[k]] = g[v];
					}
				for ( int i = 1; i <= K; i++ )
					T[i][g[i]]++;
			}
			BigInteger[][] dp = new BigInteger[N + 5][K + 5];
			for ( int i = 0; i <= N; i++ )
				for ( int j = 1; j <= K; j++ )
					dp[i][j] = BigInteger.valueOf( 0 );
			dp[0][S] = BigInteger.valueOf( 1 );
			for ( int i = 0; i < N; i++ )
				for ( int p = 1; p <= K; p++ )
					if ( dp[i][p].compareTo( BigInteger.ZERO ) > 0 ) 
						for ( int q = 1; q <= K; q++ )
							if ( T[p][q] > 0 ) 
								dp[i + 1][q] = 
									dp[i + 1][q].add( dp[i][p].multiply( BigInteger.valueOf( T[p][q] ) ) );
			BigInteger ans = BigInteger.ZERO;
			for ( int i = 1; i <= K; i++ )
				if ( ed[i] > 0 ) ans = ans.add( dp[N][i] );
			System.out.println( ans );
		}
		in.close();
	}
	// static int nextInt() throws IOException {
	// cin.nextToken();
	// return (int) cin.nval;
	// }
}
