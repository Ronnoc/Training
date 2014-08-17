|**time**|**OJ&ID**|**1st**|**2rd**|**Lv**|**Solution**|**Error**|
|---|:---:|:---:|:---:|:---:|:---|---|
|2014-8-2|hdu4695|dp|ma|6S|O(m^2lgn)处理线性递推第n项|
|2014-8-2|hdu4890|BF|_|4C|枚举拆分矩形和旋转|旋转对应没有处理|
|2014-8-3|hdu4892|cg|gp|7A|cg多边形化为三角剖分的链,图上状压dp|
|2014-8-16|poj1160|dp|_|2A|dp[i][j][k]表示x1~xi放了j个点,最后一个放在了k,储存1~k的答案|没看空间只有10M,MLE*1|
|2014-8-16|poj1180|dp|_|5S|{F,T}为{f,t}的前缀和; Ans=min{r}::FnTn-∑{ F[r[i-1]]\*(S+T[r[i]]-T[r[i-1]])-FnS };对和式构造maxD[i];X[i]=F[i],Y[i]=F[i]T[i]-D[i],下凸包,决策斜率C+T[i]|
|2014-8-16|poj1742|dp|_|2A|二进制多重背包or单调队列:dp[j]@0<=k<=C[i]::max{dp[j-k*A[i]]}|卡常,二进制WAonC++单调TLEonG++|
|2014-8-16|poj1821|dp|_|5S|单调队列优化dp[i][j]@j-L[i]<=k<j,S[i]<=j::max{dp[k]-P[i]*k}斜率优化{X=i,Y=D[i],下凸包,P[i]}:下凸包点首点不是最优解仅当最小斜率不小于决策斜率.}|维护下凸包时由于范围限制去点需要还原被删掉的点;下标写错|
|2014-8-17|Uvalive3315|dp|_|2A|背包字典序最小解,从大到小能更则更|题目中sol的s应为小写|
|2014-8-18|CF319C|dp|_|3A|斜率优化,X=B,Y=D,上凸包,决策-a[i]|
___
|**Abbr.**|**Full**|
|:---:|:---:|
|dp|Dynamic Programming|
|ma|Math|
|nt|Number Theory|
|cg|Computational Geometry|
|ga|Game Theory|
|ds|Data Structure|
|gp|Graph Theory|
|bf|Brute Force|
___
**FAQ**

> What does 7A in Lv mean?
> 
> S>A>B>C>D>E>F,this my evaluation of problem's worth.The number means how hard the problem is.
