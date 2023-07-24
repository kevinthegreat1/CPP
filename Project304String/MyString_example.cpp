#include <cstdio>
#include <vector>

using namespace std;

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

const int N = 100010, M = 25010;
int a[N], b[M];
int n, m, s;
int nxt[M];
int cntb[M][26];
int cnta[M][26];

void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 25; j++) {
            if (i == 0) cnta[i][j] = 0;
            else cnta[i][j] = cnta[i - 1][j];
        }
        cnta[i][a[i]]++;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= 25; j++) {
            if (i == 0) cntb[i][j] = 0;
            else cntb[i][j] = cntb[i - 1][j];
        }
        cntb[i][b[i]]++;
    }
}

// B[(i-nxt[i])...(i-1)] == B[0...(nxt[i]-1)]
void kmp_nxt() {
    int j = nxt[0] = -1;
    for (int i = 0; i < m;) {
        int small0 = 0, small1 = 0, equal0, equal1;
        for (int x = 1; x < b[i]; x++) {
            small1 += cntb[i][x] - (i > j ? cntb[i - j - 1][x] : 0);
        }
        for (int x = 1; x < b[j]; x++) {
            small0 += cntb[j][x];
        }
        equal0 = cntb[j][b[j]];
        equal1 = cntb[i][b[i]] - (i - j - 1 >= 0 ? cntb[i - j - 1][b[i]] : 0);
        if (j < 0 || (small0 == small1 && equal0 == equal1))
            nxt[++i] = ++j;
        else
            j = nxt[j];
    }
}

vector<int> ans;

int kmp() {
    int j = 0;
    for (int i = 0; i < n;) {
        int small0 = 0, small1 = 0;
        for (int x = 1; x < b[j]; x++) {
            small0 += cntb[j][x];
        }
        for (int x = 1; x < a[i]; x++) {
            small1 += cnta[i][x] - (i > j ? cnta[i - j - 1][x] : 0);
        }
        int equal0, equal1;
        equal0 = cntb[j][b[j]];
        equal1 = cnta[i][a[i]] - (i > j ? cnta[i - j - 1][a[i]] : 0);
        if (j < 0 || (small0 == small1 && equal0 == equal1)) {
            i++;
            j++;
            if (j >= m) {
                //matched
                ans.push_back(i - m + 1);
                j = nxt[j];
            }
        } else j = nxt[j];
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);
    init();
    kmp_nxt();
    for (int i = 0; i <= m; i++) {
        printf("%d%c", nxt[i], i < m ? ' ' : '\n');
    }
    kmp();
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d%c", ans[i], i < ans.size() - 1 ? ' ' : '\n');
    }
    return 0;
}