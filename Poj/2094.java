import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {

	public void Solve() throws IOException {
		int n = nextInt();
		BigInteger L = nextBigInteger();
		int K = nextInt();
		int m = nextInt();
		BigInteger[] A = new BigInteger[15];
		for(int i = n; i >= 0; i--)
			A[i] = nextBigInteger();
		BigInteger mod = BigInteger.ONE;
		for(; m > 0; m--)
			mod = mod.multiply(BigInteger.valueOf(10));
		for(int i = n; i >= 0; i--)
			A[i] = A[i].mod(mod);
		L = L.mod(mod);
		BigInteger[][] P = new BigInteger[15][1005];
		for(int i = 0; i <= n; i++) {
			BigInteger X = L.add(BigInteger.valueOf(i)).mod(mod);
			P[0][i] = A[n];
			for(int j = n - 1; j >= 0; j--)
				P[0][i] = P[0][i].multiply(X).mod(mod).add(A[j]);
			P[0][i] = P[0][i].mod(mod);
		}
		for(int k = 1; k <= n; k++)
			for(int i = k; i <= n; i++) {
				P[k][i] = P[k - 1][i].subtract(P[k - 1][i - 1]);
				if(P[k][i].compareTo(BigInteger.ZERO) < 0) P[k][i] = P[k][i].add(mod);
			}
		for(int k = n + 1; k < K; k++) {
			P[n][k] = P[n][k - 1];
			for(int i = n - 1; i >= 0; i--) {
				P[i][k] = P[i][k - 1].add(P[i + 1][k]);
				if(P[i][k].compareTo(mod) >= 0) P[i][k] = P[i][k].subtract(mod);
			}
		}
		for(int k = 0; k < K; k++) {
			Long ans = 0L;
			String S = P[0][k].toString();
			for(int i = 0; i < S.length(); i++)
				ans += (S.charAt(i) - '0') * (S.charAt(i) - '0');
			writer.println(ans);
		}
	}

	public static void main(String[] args) throws IOException {
		new Main().run();
	}

	BufferedReader	reader;
	StringTokenizer	tokenizer;
	PrintWriter			writer;

	public void flh() {
		writer.flush();
	}

	public void run() {
		try {
			reader = new BufferedReader(new InputStreamReader(System.in));
			writer = new PrintWriter(System.out);
			tokenizer = null;
			// while (hasNext())
			Solve();
			reader.close();
			writer.flush();
			writer.close();
		} catch(Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	boolean hasNext() throws IOException {
		while(tokenizer == null || !tokenizer.hasMoreTokens()) {
			String nextLine = reader.readLine();
			if(nextLine == null) return false;
			tokenizer = new StringTokenizer(nextLine);
		}
		return true;
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	String nextLine() throws IOException {
		return reader.readLine();
	}

	String nextToken() throws IOException {
		while(tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	BigInteger nextBigInteger() throws IOException {
		while(tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return new BigInteger(tokenizer.nextToken());
	}
}
