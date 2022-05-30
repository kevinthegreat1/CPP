#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
    const int INF = 99999999;
    int weight[5][5] = {
        {INF, 4, INF, 2, INF},
        {4, INF, 4, 1, INF},
        {INF, 4, INF, 1, 3},
        {2, 1, 1, INF, 7},
        {INF, INF, 3, 7, INF}
    };

    int i, j, size = (sizeof(weight[0])/sizeof(weight[0][0])), route[size][size];
    string path[5]={"1","1","1","1"};
    copy(weight[0],weight[4],route[0]);
    for(i=1;i<size;i++){
        for(j=0;j<size;j++){
            if(route[i-1][j]>weight[i][j]+route[i-1][i]){
                route[i][j]=weight[i][j]+route[i-1][i];
                path[j]=path[i]+to_string(j);
            }
        }
    }
    cout<<route[size-1][size-1]<<endl<<path[size-1]<<size;
    return 0;
}