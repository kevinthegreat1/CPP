/*
有一个H*W大小的矩形，包括o和*两种字符，o表示空地，*表示一个城市
给每个城市安装wifi，一个wifi最多可以覆盖两座相邻城市，问覆盖所有城市最少需要的wifi的数量
1<=H<=40, 1<=W<=10

最小路径覆盖

2 2
**
*o
Output: 2

7 9
ooo**oooo
**oo*ooo*
o*oo**o**  2+3+2
ooooooooo
*******oo
o*o*oo*oo
*******oo  10
Output: 17

10 1
*
*
*
o
*
*
*
*
*
*
Output: 5


*/

