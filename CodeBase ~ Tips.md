 1. 矩阵乘法通用优越姿势
 	`for(i)for(j)if(a.x[i][j])for(k)ret.x[i][k]+=a.x[i][j]*b.x[j][k]`
 2. 错排

		一重错排: D[0]=1;D[1]=0;D[n]=(n-1)*(D[n-1]+D[n-2])
		二重错排: U[n] = ∑(-1)^k * (2n)/(2n-k) * comb(2n-k,k)*(n-k)!
 3. 格点简单多边形面积S,边上格点数B,内部格点数I满足S=B/2+I-1
 4. 四面体O-ABC体积公式a = AB, b = BC, c = CA, d = OC, e = OA, f = OB<br>
	(12V)^2 = a^2d^2(b^2 + c^2 + e^2 + f^2 − a^2 − d^2) + b^2e^2(c^2 + a^2 + f^2 + d^2 − b^2 − e^2) + c^2f^2(a^2 + b^2 + d^2 + e^2 −c^2 − f^2) − a^2b^2c^2 − a^2e^2f^2 − d^2b^2f^2 − d^2e^2c^2
 5. 卡特兰数:`Cat(n)=Comb(2n,n)/(n+1)=Comb(2n,n)-Comb(2n,n+1)=Cat(n-1)*(4n-2)/(n+1)`
<br>6.1. n节点二叉树个数Cat(n)
<br>6.2. 正n边形划分为n-2个三角形的种数Cat(n-2)
<br>6.3. n个矩阵连乘括号化种数Cat(n-1)
<br>6.4. n个元素入栈的出栈顺序种数Cat(n)
<br>6.5. n对括号的合法括号序列个数Cat(n)
 6. Bell数:n元素的集合划分数
<br>7.1 Bell[n+1]=∑comb(n,k)Bell[k]
<br>7.2 Bell[p+n]=B[n]+B[n+1] (mod p) {p是质数}
<br>7.3 Bell[n]=∑Stirling2[n,k]
 7. 第一类Stirling数:将n个物体排成k个非空循环排列的方法数
	`Stirling1[n,k]=(n-1)*Stirling1[n-1,k]+Stirling1[n-1,k-1]`
 8. 第二类Stirling数:将n个物体划分成k个非空的不可辨别的集合的方法数
	`Stirling2[n,k]=k*Stirling2[n-1,k]+Stirling2[n-1,k-1]`
 9. 容斥反演:`g(A)=∑{S⊆A}f(S) <==> f(A)=∑{S⊆A}(-1)^(|A|-|S|)g(S)`
 10. 莫比乌斯反演
 
	`g(n)=∑{d\n}f(d) <==> f(n)=∑{d\n}miu[d]g(n/d)`
	`g(x)=∑{n=1,n<=x}f(x/n) <==> f(x)=∑{n=1,n<=x}miu[n]g(x/n)`
 11. 二项式反演

		     n     k                       n     k
		a_n= ∑ (-1) comb(n,k)b_k <==> b_n= ∑ (-1) comb(n,k)a_k
		    k=0                           k=0                 
		     n                        n     n-k
		a_n= ∑ comb(n,k)b_k <==> b_n= ∑ (-1)   comb(n,k)a_k
		    k=0                      k=0                   

 12. 二次剩余: 奇素数p,x^2==a mod p 有解 <==> a^((p-1)/2)==1 mod p
 13. 阶乘近似 n! 约等于 sqrt(2nPI)(n/e)^n
 14. 枚举集合

			int sub = S;
			do {					//降序枚举任意集合子集
				//TODO
				sub = (sub - 1) &S;
			} while (sub != S);		//0之后 有(-1)&S=S;		
			
			int sub = (1 << k) - 1;
			while (sub < 1 << n) {	//枚举大小为k的子集
				//TODO
				int x = sub & -sub, y = sub + x;
				sub = (sub & ~y) / x >> 1 | y;
			}

 15. f(x)某零点临近点x_0,叠代`x_m=(x*f'[x]-f[x])/f'[x]`,牛顿迭代
 16. Polya:G是集合X上的置换群,X的每个元素可以染成k种颜色,不等价的着色数P,nc(g)为置换g的循环个数
 
		|G|*P=∑{g∈G}k^nc(g)
 17. Burnside:G是集合X上的置换群,对于所有perm∈G,perm(染色方案)不变的个数和/|G|
 18. f(n)=a*f(n-1)+b*f(n-2),求f(n)%p的循环节

		1.对p进行质因数分解，p = p1^a1 * p2^a2 * p3^a3 ... * pn^an
		2.分别求 p1^a1,p2^a2,...,pn^an的循环节，然后取最小公倍数
		2.1 p mod px^ax 的循环节 = G(px) * px^(ax-1) , G(px) 就是 p mod px 的最小循环节
		2.2 对于递推式，我们可以得到特征根方程 x^2=a*x+b ,delta=a*a+4*b
		2.3 对于G(px),如果delta是模px的二次剩余，G(px)是px- 1的因子，否则G(px)是(px-1)*(px+1)的因子,矩阵快乘暴力判断

 19. `for(inv[1]=1,i=2;i<10000;i++)inv[i] = inv[MOD%i]*(MOD-MOD/i) % MOD;` (MOD是质数)
 20. 四边形不等式:

	rep(r,1,n)rep(i,1,n-r){
		if(r==1)K[i][i+r]=i,dp;
		else rep(k,K[i][i+r-1],K[i+1][i+r])if(better)K[i][i+r]=k,dp;
	}