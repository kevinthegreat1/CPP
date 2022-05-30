#include <iostream>
#include <fstream>

using namespace std;

int k;

int time(int speedLimit){
    int time, speed=0, distance=0, tim, dis=0;
    for(time=0;;time++,distance+=speed){
        if(distance>=k && speed<=speedLimit){
            return time;
        }
        for(tim=speedLimit,dis=0;tim<=speed;tim++){
            dis+=tim;
        }
        if(dis+tim+distance<=k+speedLimit-1){
            speed++;
        } else if(dis+distance>k+speedLimit-1){
            speed--;
        }
    }
}

int main(){
    ifstream fin("race.in");
    ofstream fout("race.out");
    int n, i;
    fin>>k>>n;
    int speedLimit[n];
    for(i=0;i<n;i++){
        fin>>speedLimit[i];
    }
    fin.close();
    for(i=0;i<n;i++){
        fout<<time(speedLimit[i]);
        if(i<n-1){
            fout<<endl;
        }
    }
    fout.close();
    return 0;
}