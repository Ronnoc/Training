 1. 矩阵乘法通用优越姿势
 	`for(i)for(j)if(a.x[i][j])for(k)ret.x[i][k]+=a.x[i][j]*b.x[j][k]`
 2. 错排

		一重错排: D[0]=1;D[1]=0;D[n]=(n-1)*(D[n-1]+D[n-2])
		二重错排: U[n] = ∑(-1)^k * (2n)/(2n-k) * comb(2n-k,k)*(n-k)!
 3. 多项式求和
	
		   p^c-1	         phi(p^c)
			 ∑ i^d mod p^c =    ∑ g^(d*i) mod p^c
			i=0				   i=0

	p是非2质数,或1,2,4;g是p的原根(g^(p-1)==1 mod p,g^i构成p的一个模剩余系)<br>
	对于2^c (c>3) 有结论 if(d&1)return 0;else return llpow(2,c-1,2^c);
 4. 格点简单多边形面积S,边上格点数B,内部格点数I满足S=B/2+I-1
 5. 四面体O-ABC体积公式a = AB, b = BC, c = CA, d = OC, e = OA, f = OB<br>
	(12V)^2 = a^2d^2(b^2 + c^2 + e^2 + f^2 − a^2 − d^2) + b^2e^2(c^2 + a^2 + f^2 + d^2 − b^2 − e^2) + c^2f^2(a^2 + b^2 + d^2 + e^2 −c^2 − f^2) − a^2b^2c^2 − a^2e^2f^2 − d^2b^2f^2 − d^2e^2c^2
 6. 卡特兰数:Cat(n)=Comb(2n,n)/(n+1)=Comb(2n,n)-Comb(2n,n+1)=Cat(n-1)*(4n-2)/(n+1)
<br>6.1. n节点二叉树个数Cat(n)
<br>6.2. 正n边形划分为n-2个三角形的种数Cat(n-2)
<br>6.3. n个矩阵连乘括号化种数Cat(n-1)
<br>6.4. n个元素入栈的出栈顺序种数Cat(n)
<br>6.5. n对括号的合法括号序列个数Cat(n)
 7. Bell数:n元素的集合划分数
<br>7.1 Bell[n+1]=∑comb(n,k)Bell[k]
<br>7.2 Bell[p+n]=B[n]+B[n+1] (mod p) {p是质数}
<br>7.3 Bell[n]=∑Stirling2[n,k]
 8. 第一类Stirling数:将n个物体排成k个非空循环排列的方法数
<br>Stirling1[n,k]=(n-1)*Stirling1[n-1,k]+Stirling1[n-1,k-1]
 9. 第二类Stirling数:将n个物体划分成k个非空的不可辨别的集合的方法数
<br>Stirling2[n,k]=k*Stirling2[n-1,k]+Stirling2[n-1,k-1]
 10. 容斥反演:

	g(A)=∑{S⊆A}f(S) <==> f(A)=∑{S⊆A}(-1)^(|A|-|S|)g(S)
 11. 莫比乌斯反演

	miu[n]=0 when n包含平方因子<br>
	miu[n]=(-1)^k n为k个素数的乘积<br>
	g(n)=∑{d\n}f(d) <==> f(n)=∑{d\n}miu[d]g(n/d)<br>
	g(x)=∑{n=1,n<=x}f(x/n) <==> f(x)=∑{n=1,n<=x}miu[n]g(x/n) 
 12. 二项式反演

		     n     k                       n     k
		a_n= ∑ (-1) comb(n,k)b_k <==> b_n= ∑ (-1) comb(n,k)a_k   
		    k=0                           k=0                    
		     n                        n     n-k
		a_n= ∑ comb(n,k)b_k <==> b_n= ∑ (-1)   comb(n,k)a_k   
		    k=0                      k=0                    

 13. 二次剩余: 奇素数p,x^2==a mod p 有解 <==> a^((p-1)/2)==1 mod p
 14. 阶乘近似 n! 约等于 sqrt(2nPI)(n/e)^n
 15. 数值积分:
	∫_a^b f(x)dx = h/3( f(x[0]) + 2∑{j=1~n/2-1}f(x[2j]) + 4∑{j=1~n/2}f(x[2j-1]) + f(x[n]))
 16.	集合位运算

		//降序枚举任意集合子集
			int sub = S;
			do {
				//
				sub = (sub - 1) &S;
			} while (sub != S);							//0之后 有(-1)&S=S;
		//枚举大小为k的子集
			int sub = (1 << k) - 1;
			while (sub < 1 << n) {
				//
				int x = sub & -sub, y = sub + x;
				sub = (sub & ~y) / x >> 1 | y;
			}

 17. 求和公式
	
		1. sum( k ) = n(n+1)/2
		2. sum( 2k-1 ) = n^2
		3. sum( k^2 ) = n(n+1)(2n+1)/6
		4. sum( (2k-1)^2 ) = n(4n^2-1)/3
		5. sum( k^3 ) = (n(n+1)/2)^2
		6. sum( (2k-1)^3 ) = n^2(2n^2-1)
		7. sum( k^4 ) = n(n+1)(2n+1)(3n^2+3n-1)/30
		8. sum( k^5 ) = n^2(n+1)^2(2n^2+2n-1)/12
		9. sum( k(k+1) ) = n(n+1)(n+2)/3
		10. sum( k(k+1)(k+2) ) = n(n+1)(n+2)(n+3)/4
		12. sum( k(k+1)(k+2)(k+3) ) = n(n+1)(n+2)(n+3)(n+4)/5

 18. Young矩阵:Y[1]=1;Y[2]=2;Y[n]=Y[n-1]+(n-1)*Y[n-2];
 19. f(x)某零点临近点x_0,叠代`x_m=(x*f'[x]-f[x])/f'[x]`,牛顿迭代
 20. Polya:G是集合X上的置换群,X的每个元素可以染成k种颜色,不等价的着色数P,nc(g)为置换g的循环个数
 
		|G|*P=∑{g∈G}k^nc(g)
 21. CRT:`x%m_i=a_i,M=∏m_i,M_i=M/m_i,t_i*M_i%m_i=1 => x=∑a_i*t_i*M_i`
 22. f(n)=a*f(n-1)+b*f(n-2),求f(n)%p的循环节

		1.对p进行质因数分解，p = p1^a1 * p2^a2 * p3^a3 ... * pn^an
		2.分别求 p1^a1,p2^a2,...,pn^an的循环节，然后取最小公倍数
		2.1 p mod px^ax 的循环节 = G(px) * px^(ax-1) , G(px) 就是 p mod px 的最小循环节
		2.2 对于递推式，我们可以得到特征根方程 x^2=a*x+b ,delta=a*a+4*b
		2.3 对于G(px),如果delta是模px的二次剩余，G(px)是px-1的因子，否则G(px)是(px-1)*(px+1)的因子,矩阵快乘暴力判断
		2.3.1 iff a^[(p-1)/2]=1 mod p , a是p的二次剩余
		

 23. `for(inv[1]=1,i=2;i<10000;i++)inv[i] = inv[MOD%i]*(MOD-MOD/i) % MOD;` (MOD是质数)
 24. 求原根:t=欧拉函数(n).质因数分解t:p(1),...,p(k).从2开始枚举m,计算m^(t/p(i))%n.如果k个结果都不是1则是原根
 25. 多分数的lcm为分子lcm/分母gcd
 26. 333333333333333331LL 质数17个3