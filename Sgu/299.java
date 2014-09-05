import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {
	
	public void Solve() throws IOException {
		int n = nextInt();
		BigInteger[] A = new BigInteger[n];
		for (int i = 0; i < n; i++)
			A[i] = nextBigInteger();
		Arrays.sort(A);
		BigInteger p, q, r;
		p = BigInteger.ZERO;
		q = BigInteger.ZERO;
		r = BigInteger.ZERO;
		for (int i = 0; i + 2 < n; i++) {
			if (A[i].add(A[i + 1]).compareTo(A[i + 2]) > 0) {
				p = A[i];
				q = A[i + 1];
				r = A[i + 2];
			}
		}
		writer.println(p + " " + q + " " + r);
		writer.flush();
	}
	
	public static void main(String[] args) throws IOException {
		new Solution().run();
	}
	
	BufferedReader	reader;
	StringTokenizer	tokenizer;
	PrintWriter			writer;
	
	public void run() {
		try {
			reader = new BufferedReader(new InputStreamReader(System.in));
			tokenizer = null;
			writer = new PrintWriter(System.out);
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
