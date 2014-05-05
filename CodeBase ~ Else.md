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