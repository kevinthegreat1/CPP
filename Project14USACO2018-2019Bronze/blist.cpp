#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(){
    ifstream fin("blist.in");
    ofstream fout("blist.out");
    int n, maxTime=0, curBucket=0, bucket, i, j, begin[101], end[101], buckets[101];
    fin>>n;
    for(i=0;i<n;i++){
        fin>>begin[i]>>end[i]>>buckets[i];
        maxTime=max(end[i],maxTime);
    }
    for(i=0;i<=maxTime;i++,curBucket=0){
        for(j=0;j<n;j++){
            if(begin[j]<=i && i<=end[j]){
                curBucket+=buckets[j];
            }
        }
        bucket=max(curBucket,bucket);
    }
    fout<<bucket;
    fin.close();
    fout.close();
    return 0;
}