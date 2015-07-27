1.矩阵乘法
 	`for(i)for(j)if(A[i][j])for(k)C[i][k]+=A[i][j]*B[j][k]`

2.错排

	一重错排: D[0]=1;D[1]=0;D[n]=(n-1)*(D[n-1]+D[n-2])
	二重错排: U[n]=∑(-1)^k*(2n)/(2n-k)*comb(2n-k,k)*(n-k)!
	//未验:n+m个数m错排:dp[0]=n!,dp[1]=n*n!,dp[i]=n*dp[i-1]+(i-1)*(dp[i-1]+dp[i-2]);

3.格点简单多边形面积S,边上格点数B,内部格点数I :: S=B/2+I-1

4.四面体O-ABC体积公式 a=AB, b=BC, c=CA, d=OC, e=OA, f=OB

	(12V)^2 = a^2d^2(b^2 + c^2 + e^2 + f^2 − a^2 − d^2) + b^2e^2(c^2 + a^2 + f^2 + d^2 − b^2 − e^2) + c^2f^2(a^2 + b^2 + d^2 + e^2 −c^2 − f^2) − a^2b^2c^2 − a^2e^2f^2 − d^2b^2f^2 − d^2e^2c^2

5.卡特兰数`Cat(n)=Comb(2n,n)/(n+1)=Comb(2n,n)-Comb(2n,n+1)=Cat(n-1)*(4n-2)/(n+1)`

+ n节点二叉树个数Cat(n)
+ 正n边形划分为n-2个三角形的种数Cat(n-2)
+ n个矩阵连乘括号化种数Cat(n-1)
+ n个元素入栈的出栈顺序种数Cat(n)
+ n对括号的合法括号序列个数Cat(n)

6.Bell数:n元素的集合划分数

+ Bell[n+1]=∑comb(n,k)Bell[k]
+ Bell[p+n]=B[n]+B[n+1] (mod p) {p是质数}
+ Bell[n]=∑Stirling2[n,k]

7.第一类Stirling数:将n个物体排成k个非空循环排列的方法数
	`Str1[n,k]=(n-1)*Str1[n-1,k]+Str1[n-1,k-1]`

8.第二类Stirling数:将n个物体划分成k个非空的不可辨别的集合的方法数
	`Str2[n,k]=k*Str2[n-1,k]+Str2[n-1,k-1]`

9.容斥反演:`g(A)=∑{S⊆A}f(S) <==> f(A)=∑{S⊆A}(-1)^(|A|-|S|)g(S)`

10.莫比乌斯反演

+ `g(n)=∑{d|n}f(d) <==> f(n)=∑{d|n}miu[d]g(n/d)`
+ `g(x)=∑{n=1,n<=x}f(x/n) <==> f(x)=∑{n=1,n<=x}miu[n]g(x/n)`

11.二项式反演

+ `an=∑(-1)^k*C(n,k)bk <==> bn=∑(-1)^k*C(n,k)ak`
+ `an=∑C(n,k)bk <==> bn=∑(-1)^(n-k)*C(n,k)ak`

12.二次剩余: 奇素数p,x^2==a mod p 有解 <==> a^((p-1)/2)==1 mod p

13.阶乘近似 n! 约等于 sqrt(2nPI)*(n/e)^n	//Stirling公式

14.枚举定大小集合

		int sub = (1 << k) - 1;
		while (sub < 1 << n) {	//枚举大小为k的子集
			int x = sub & -sub, y = sub + x;
			sub = (sub & ~y) / x >> 1 | y;
		}

15.f(x)某零点临近点x_0,牛顿迭代`x_m=(x*f'[x]-f[x])/f'[x]`

16.Polya:G是集合X上的置换群,X的每个元素可以染成k种颜色,不等价的着色数P,nc(g)为置换g的循环个数`|G|*P=∑{g∈G}k^nc(g)`

17.Burnside:G是集合X上的置换群,对于所有perm∈G,perm(染色方案)不变的个数和/|G|

18.f(n)=a*f(n-1)+b*f(n-2),求f(n)%p的循环节

	1.对p进行质因数分解，p = p1^a1 * p2^a2 * p3^a3 ... * pn^an
	2.分别求 p1^a1,p2^a2,...,pn^an的循环节，然后取最小公倍数
	2.1 p mod px^ax 的循环节 = G(px) * px^(ax-1) , G(px) 就是 p mod px 的最小循环节
	2.2 对于递推式，我们可以得到特征根方程 x^2=a*x+b ,delta=a*a+4*b
	2.3 对于G(px),如果delta是模px的二次剩余，G(px)是px-1的因子，否则G(px)是(px-1)*(px+1)的因子,矩阵快乘暴力判断

19.`for(inv[1]=1,i=2;i<10000;i++)inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;//MOD is prime`

20.四边形不等式:

	rep(r,1,n)rep(i,1,n-r){
		if(r==1)K[i][i+r]=i,dp;
		else rep(k,K[i][i+r-1],K[i+1][i+r])
			if(better)K[i][i+r]=k,dp;
	}

21.拉格朗日插值`p_i(x)=∏{j!=i}(x-x_i)/(x_j-x_i);f(x)=∑y_i*p_i(x)`

22.Jacobi迭代:A=D-L-U,D(主对角线),L(下三角不含D),U(上三角不含D)`AX=B::X=D^(-1)*((L+U)X+B)`

23.n个节点有标号无根树n^(n-2),有标号有根数n^(n-1)

24.反素数(240@720720<=10^6),(1600@2095133040<2^31),
(6720@963761198400<=10^12),(26880@866421317361600<=10^15)

25.素数333333333333333331LL(17个3),2147483647,
13251349,13251361,13251367,13251373,13251377,13251383,13251391

26.简单多面体顶点数V、面数F及棱数E :: V+F-E=2

27.欧拉数，n全排列中，恰有m个上升位置的排列个数`E[n,k]=(k+1)E[n-1,k]+(n-k)E[n-1,k-1]`

28.威尔逊定理(p-1)!=-1 mod p

29.设正整数n的质因数分解为n = ∏pi^ai,则x^2+y^2=n有整数解的充要条件是n中不存在形如pi≡3(mod 4) &(and) 指数ai为奇数的质因数pi

20.p为奇素数，x^b = a(mod p),x为p的b次剩余的必要充分条件为   若x^（(p-1)/  (p-1 和 b的最大公约数)） mod p=1. 
