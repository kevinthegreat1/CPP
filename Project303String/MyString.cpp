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
*/
const int N = 101;
const int M = 101;
char A[N] = "ababaabaabac";
char B[M] = "abaabac";
int m = 7, n = 12;
int nxt[M];
// B[(i-nxt[i]+1)...i] == B[0...(nxt[i]-1)]
//     abaabac
//nxt: 0011230
//     012345678901
//     abacaabaabac
//     abaabac
//       abaabac
//        xabaabac
//          abaabac
void kmp_nxt(){
    int j = nxt[0] = -1;
    for(int i=0;i<m;){
        while(j >= 0 && B[i] != B[j])
            j = nxt[j];
        nxt[++i] = ++j;
    }
}
int kmp(){
    int cnt = 0, j = 0;
    for(int i=0;i<n;){
        while(j >= 0 && A[i] != B[j]) j = nxt[j];
        i++;
        j++;
        if(j >= m){
            //matched
            cnt++;
            j = nxt[j];
        }
    }
    return cnt;
}

int main(){
    kmp_nxt();
    for(int i=0;i<=m;i++){
        printf("%d%c",nxt[i],i<m?' ':'\n');
    }
    int res = kmp();
    printf("%d\n",res);
    return 0;
}
