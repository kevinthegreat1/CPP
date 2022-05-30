#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(){
    ifstream fin("mixmilk.in");
    ofstream fout("mixmilk.out");
    int buckets[2][3], i;
    fin>>buckets[0][0]>>buckets[1][0]>>buckets[0][1]>>buckets[1][1]>>buckets[0][2]>>buckets[1][2];
    for(i=0;i<33;i++){
        int a=buckets[1][1];
        buckets[1][1]=min(buckets[1][0]+buckets[1][1],buckets[0][1]);
        buckets[1][0]-=buckets[1][1]-a;
        a=buckets[1][2];
        buckets[1][2]=min(buckets[1][1]+buckets[1][2],buckets[0][2]);
        buckets[1][1]-=buckets[1][2]-a;
        a=buckets[1][0];
        buckets[1][0]=min(buckets[1][2]+buckets[1][0],buckets[0][0]);
        buckets[1][2]-=buckets[1][0]-a;
    }
    int a=buckets[1][1];
        buckets[1][1]=min(buckets[1][0]+buckets[1][1],buckets[0][1]);
        buckets[1][0]-=buckets[1][1]-a;
    fout<<buckets[1][0]<<endl<<buckets[1][1]<<endl<<buckets[1][2];
    return 0;
}