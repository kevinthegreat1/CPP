/*
树状数组
x -> x-lowbit(x)
1. 区间查询和单点修改：用树状数组储存原数组即可
2. 单点查询和区间修改：用树状数组储存b[i] = a[i]-a[i-1]差分数组
3. 区间查询和区间修改：用两个树状数组储存差分数组b[i]和b[i]*i，当查询前缀和的时候a[1]+...a[r]=sum(i=1~r: sum(j=1~i: b[j]))=sum(i=1~r, b[i]*(r+1)) - sum(i=1~r, b[i]*i)

线段树
1. 区间查询和单点修改
2. 区间修改：用标记lazy记录父节点的修改情况，只有当查询时需要切开区间了解子节点情况时 才将标记向下传递一次。

*/

/*
Q1最小值问题
1.修改一个区间，将所有值-=x
2.查询一个区间的最小值，并且得到它的位置

Q2 GCD
1. 查询一个区间的GCD
2. 区间修改，所有值+=x
差分数组的单点修改和区间查询（gcd、前缀和）

Q3 SUM
1. 单点修改
2. 区间查询 查询一个区间中最大的“子区间和”
线段树储存：最大子区间和、最大的前缀和、最大的后缀和、区间和

Q4 逆序数
对于数组a[]，如果i<j && a[i]>a[j]那么(i,j)就被称为一个逆序对
所有逆序对的数量即为整个数组的逆序数
对于给定的j、逆序对(i,j)的数量被称为a[j]的逆序数
数组中所有数的逆序数的和就是逆序数

*/