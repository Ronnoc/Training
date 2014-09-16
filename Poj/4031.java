import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main{
	
	public class state {
		
		int						aim;
		BigInteger		X, Y;
		BigInteger[]	FX	= new BigInteger[5];
		BigInteger[]	FY	= new BigInteger[5];
		BigInteger[]	F		= new BigInteger[5];
		
		state () {
			aim = 0;
			X = Y = BigInteger.ZERO;
			for (int i = 0; i < 5; i++)
				FX[i] = FY[i] = F[i] = BigInteger.ZERO;
		}
		
		void show() {
			writer.println(aim + " " + X + "," + Y);
			for (int i = 0; i < 5; i++)
				writer.println(F[i] + "\t" + FX[i] + "," + FY[i]);
			flush();
		}
	}
	
	state merge(state S, state V) {
		state ret = new state();
		int i, j;
		ret.aim = (S.aim + V.aim) % 4;
		BigInteger p = V.X, q = V.Y, t;
		for (j = 0; j < S.aim; j++) {
			t = p;
			p = q;
			q = t.multiply(BigInteger.valueOf(-1));
		}
		ret.X = S.X.add(p);
		ret.Y = S.Y.add(q);
		for (i = 0; i < 5; i++) {
			ret.F[i] = S.F[i];
			ret.FX[i] = S.FX[i];
			ret.FY[i] = S.FY[i];
		}
		for (i = 0; i < 5; i++) {
			p = V.FX[i];
			q = V.FY[i];
			for (j = 0; j < S.aim; j++) {
				t = p;
				p = q;
				q = t.multiply(BigInteger.valueOf(-1));
			}
			p = p.add(S.X);
			q = q.add(S.Y);
			BigInteger F = p.abs().add(q.abs());
			BigInteger[] T = new BigInteger[5];
			T[1] = T[2] = p;
			T[3] = T[4] = p.negate();
			T[1] = T[1].add(q);
			T[4] = T[4].add(q);
			T[2] = T[2].subtract(q);
			T[3] = T[3].subtract(q);
			for (j = 1; j <= 4; j++)
				if (T[j].compareTo(ret.F[j]) > 0) {
					ret.F[j] = T[j];
					ret.FX[j] = p;
					ret.FY[j] = q;
				}
			if (F.compareTo(ret.F[0]) > 0) {
				ret.F[0] = F;
				ret.FX[0] = p;
				ret.FY[0] = q;
			}
		}
		return ret;
	}
	
	public class func {
		
		int				n;
		String[]	L;
		boolean		done, inS;
		state			T;
		
		func () {
			done = inS = false;
			T = new state();
		}
	}
	
	void input(int id) throws IOException {
		A[id] = new func();
		A[id].n = nextInt();
		A[id].L = new String[A[id].n];
		for (int i = 0; i < A[id].n; i++)
			A[id].L[i] = nextToken();
	}
	
	func[]				A;
	static state	LEFT, RIGHT, GO;
	boolean				FAIL, DOGE;
	int[]					Sta	= new int[105];
	int						nS;
	
	void endl() {
		writer.println();
	}
	
	void flush() {
		writer.flush();
	}
	
	void gao(int id) {
		if (A[id].inS) {
			DOGE = true;
			int i, j;
			for (i = 1; i <= nS; i++)
				if (Sta[i] == id) break;
			int z = i;
			state now = new state();
			for (i = 1; i < z; i++)
				now = merge(now, A[Sta[i]].T);
			BigInteger tx = now.X, ty = now.Y;
			for (j = 0; j < 4; j++)
				for (i = z; i <= nS; i++)
					now = merge(now, A[Sta[i]].T);
			if (!tx.equals(now.X) || !ty.equals(now.Y)) FAIL = true;
			A[0].T = now;
			return;
		}
		if (A[id].done) return;
		A[id].inS = true;
		Sta[++nS] = id;
		for (int t = 0; t < A[id].n; t++) {
			String o = A[id].L[t];
			if (o.charAt(0) == 'L') A[id].T = merge(A[id].T, LEFT);
			else if (o.charAt(0) == 'R') A[id].T = merge(A[id].T, RIGHT);
			else if (o.charAt(0) == 'G') A[id].T = merge(A[id].T, GO);
			else {
				o = o.substring(1, o.length());
				int next = Integer.parseInt(o) - 1;
				gao(next);
				if (DOGE) return;
				A[id].T = merge(A[id].T, A[next].T);
			}
		}
		A[id].inS = false;
		nS--;
		A[id].done = true;
	}
	
	public void Solve() throws IOException {
		FAIL = DOGE = false;
		nS = 0;
		LEFT = new state();
		LEFT.aim = 3;
		RIGHT = new state();
		RIGHT.aim = 1;
		GO = new state();
		GO.Y = BigInteger.ONE;
		GO.FY[0] = GO.FY[1] = GO.FY[4] = BigInteger.ONE;
		GO.F[0] = GO.F[1] = GO.F[4] = BigInteger.ONE;
		int n = nextInt();
		A = new func[n];
		for (int i = 0; i < n; i++)
			input(i);
		gao(0);
		if (FAIL) writer.println("Infinity");
		else writer.println(A[0].T.F[0]);
		flush();
	}
	
	public static void main(String[] args) throws IOException {
		new Main().run();
	}
	
	BufferedReader	reader;
	StringTokenizer	tokenizer;
	PrintWriter			writer;
	
	public void run() {
		try {
			 reader = new BufferedReader(new InputStreamReader(System.in));
			 writer = new PrintWriter(System.out);
			//reader = new BufferedReader(new InputStreamReader(new FileInputStream("journey.in")));
			//writer = new PrintWriter(new FileOutputStream("journey.out"));
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
	
	BigInteger nextBigInteger() throws IOException {
		return new BigInteger(nextToken());
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
	
}
