#include <cstdio>
using namespace std;


/* KMP算法
A(n): aaacaaab
B(m): aaab
暴力匹配O(n*m)
Dynamic Programming O(n+m)

         i
A(n): aaacaaab
B(m):     aaab
A(n): aaaaaaab
B(m):  aaab
         j

B = ababc
j: 0 -a-> 1 -b-> 2 -a-> 3 -b-> 4 -c-> 5
                        ^      |
                        |-<-a--|
    01234567890
A = cabaabababc
B =       ababc
i = 8, j = 3->1->2
nxt[j][c]
正常的推进： nxt[1]['b'] = 2  (nxt[j][c] = j+1)
回退到[具有相同前缀的]最近的位置k： nxt[4]['a'] = 3 = nxt[2]['a']
                                 nxt[4]['b'] = nxt[2]['b'] = 0
                                 k[4]=2

*/

const int N = 101;
const int M = 101;
int dp[M][256];
char B[M];
int m, n;
char A[N];

void getdp(){
    dp[0][B[0]] = 1;
    int k = 0;
    for(int j=1;j<m;j++){
        for(char c=0;c<256;c++)
            dp[j][c] = dp[k][c];
        dp[j][B[j]] = j+1;
        k = dp[k][B[j]];
    }
}
int match(){
    int j = 0;
    for(int i=0;i<n;i++){
        j = dp[j][A[i]];
        if(j==m) return i-m+1;
    }
    return -1;
}

/*
Example:
A particular subgroup of K (1 <= K <= 25,000) of Farmer John's cows likes to make trouble. When placed in a line, these troublemakers stand together in a particular order. In order to locate these troublemakers, FJ has lined up his N (1 <= N <= 100,000) cows. The cows will file past FJ into the barn, staying in order. FJ needs your help to locate suspicious blocks of K cows within this line that might potentially be the troublemaking cows.
FJ distinguishes his cows by the number of spots 1..S on each cow's coat (1 <= S <= 25). While not a perfect method, it serves his purposes. FJ does not remember the exact number of spots on each cow in the subgroup of troublemakers. He can, however, remember which cows in the group have the same number of spots, and which of any pair of cows has more spots (if the spot counts differ). He describes such a pattern with a sequence of K ranks in the range 1..S. For example, consider this sequence:
      1 4 4 3 2 1
In this example, FJ is seeking a consecutive sequence of 6 cows from among his N cows in a line. Cows #1 and #6 in this sequence have the same number of spots (although this number is not necessarily 1) and they have the smallest number of spots of cows #1..#6 (since they are labeled as '1'). Cow #5 has the second-smallest number of spots, different from all the other cows #1..#6. Cows #2 and #3 have the same number of spots, and this number is the largest of all cows #1..#6.
If the true count of spots for some sequence of cows is:
 5 6 2 10 10 7 3 2 9
then only the subsequence 2 10 10 7 3 2 matches FJ's pattern above.
Please help FJ locate all the length-K subsequences in his line of cows that match his specified pattern.

Sample Input (N, K, S)
9 6 10
5 6 2 10 10 7 3 2 9
1 4 4 3 2 1
Sample Output (number of matching, index of each matching within [1,n])
1
3

*/




