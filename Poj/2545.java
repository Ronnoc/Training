import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	
	public void Solve() throws IOException {
		BigInteger[] P = new BigInteger[3];
		for (int i = 0; i < 3; i++)
			P[i] = nextBigInteger();
		int id = nextInt();
		BigInteger[] A = new BigInteger[1 << 18];
		int NA = 0;
		BigInteger Q = BigInteger.ONE;
		BigInteger E = BigInteger.valueOf(10).pow(18);
		for (int i = 0; i <= 64; i++) {
			BigInteger W = Q;
			for (int j = 0; j <= 64; j++) {
				BigInteger S = W;
				for (int k = 0; k <= 64; k++) {
					A[NA++] = S;
					S = S.multiply(P[2]);
					if (S.compareTo(E) > 0) break;
				}
				W = W.multiply(P[1]);
				if (W.compareTo(E) > 0) break;
			}
			Q = Q.multiply(P[0]);
			if (Q.compareTo(E) > 0) break;
		}
		Arrays.sort(A, 0, NA);
		writer.println(A[id]);
		flh();
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
			while (hasNext())
				Solve();
			reader.close();
			writer.flush();
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
	
	boolean hasNext() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			String nextLine = reader.readLine();
			if (nextLine == null) return false;
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
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}
	
	BigInteger nextBigInteger() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return new BigInteger(tokenizer.nextToken());
	}
}
