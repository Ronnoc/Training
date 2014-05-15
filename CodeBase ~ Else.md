**1 JAVA I/O**

	public class Main {
		static StreamTokenizer in = new StreamTokenizer(new BufferedReader(
				new InputStreamReader(System.in)));
		static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	
		public static void main(String[] args) throws IOException {
			int T=nextInt();
			out.flush(); // 刷新缓冲区 输出结果
			out.close();
		}
		 static int nextInt() throws IOException {
			in.nextToken();
			return (int) in.nval;
		}
	}

*based on Petr's template*

	public class Main implements Runnable {
		public static void main( String[] args ) {
			new Main().run();
		}
		BufferedReader reader;
		StringTokenizer tokenizer;
		PrintWriter writer;
		public void run() {
			try {
				reader = new BufferedReader( new InputStreamReader( System.in ) );
				tokenizer = null;
				writer = new PrintWriter( System.out );
				int t = 10000;
				for ( int i = 1; i <= t; i ++ ) {
					if ( !this.hasNext() )
						break;
					System.out.print( "Case " + i + ": " );
					solve();
				}
				reader.close();
				writer.close();
			} catch ( Exception e ) {
				e.printStackTrace();
				System.exit( 1 );
			}
		}
		
		boolean hasNext() throws IOException {
			while ( tokenizer == null || !tokenizer.hasMoreTokens() ) {
				String nextLine = reader.readLine();
				if ( nextLine == null )
					return false;
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
