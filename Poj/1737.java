import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {
	
	public void Solve() throws IOException {
		BigInteger[][] Comb = new BigInteger[51][51];
		BigInteger[][] two = new BigInteger[51][51];
		BigInteger[][][] F = new BigInteger[51][51][51];
		BigInteger[][][] dp = new BigInteger[51][51][51];
		BigInteger[][] Ans = new BigInteger[51][51];
		BigInteger[] AAA = new BigInteger[51];
		int i, j, t, n, a, b, R;
		AAA[0] = BigInteger.ONE;
		for (i = 1; i <= 50; i++)
			AAA[i] = AAA[i - 1].multiply(BigInteger.valueOf(i));
		for (i = 0; i <= 50; i++) {
			Comb[i][0] = Comb[i][i] = BigInteger.ONE;
			for (j = 1; j < i; j++)
				Comb[i][j] = Comb[i - 1][j].add(Comb[i - 1][j - 1]);
		}
		for (a = 0; a <= 50; a++) {
			two[a][0] = BigInteger.ONE;
			BigInteger val = BigInteger.ZERO;
			for (i = 1; i <= a; i++)
				val = val.shiftLeft(1).add(BigInteger.ONE);
			for (t = 1; t <= 50; t++)
				two[a][t] = two[a][t - 1].multiply(val);
		}
		for (R = 0; R <= 50; R++) {
			for (a = 1; a <= 50; a++) {
				F[R][0][a] = BigInteger.ONE;
				for (t = 1; a * t <= R; t++) {
					F[R][t][a] = BigInteger.ONE;
					for (j = 1; j <= t; j++)
						F[R][t][a] = F[R][t][a].multiply(Comb[R - (j - 1) * a][a]);
					F[R][t][a] = F[R][t][a].divide(AAA[t]);
				}
			}
		}
		dp[0][0][0] = BigInteger.ONE;
		for (n = 1; n <= 50; n++) {
			dp[n][0][0] = BigInteger.ONE;
			for (b = 1; b < n; b++)
				dp[n][0][b] = BigInteger.ZERO;
			for (a = 1; a < n; a++) {
				for (b = 0; b < n; b++) {
					dp[n][a][b] = BigInteger.ZERO;
					for (t = 0; t * a <= b; t++) {
						BigInteger val = F[n - 1 - b + t * a][t][a];
						val = val.multiply(two[a][t].multiply(Ans[a][t]));
						dp[n][a][b] = dp[n][a][b].add(dp[n][a - 1][b - t * a].multiply(val));
					}
				}
			}
			Ans[n][0] = BigInteger.ONE;
			Ans[n][1] = dp[n][n - 1][n - 1];
			for (t = 2; t * n <= 50; t++)
				Ans[n][t] = Ans[n][t - 1].multiply(Ans[n][1]);
		}
		while (hasNext()) {
			n = nextInt();
			if (n == 0) break;
			writer.println(Ans[n][1]);
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
			//			while (hasNext())
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
