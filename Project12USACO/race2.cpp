#include <iostream>
#include <fstream>

using namespace std;

int dist;

int time(int max){
    int time, speed=0, ldistance, rdistance;
    for(speed=1;;speed++){
        ldistance+=speed;
        time++;
        if(ldistance+rdistance>=dist){
            return time;
        }
        if(speed>=max){
            rdistance+=speed;
            time++;
            if(ldistance+rdistance>=dist){
                return time;
            }
        }
    }
}

int main(){
    ifstream fin("race.in");
    ofstream fout("race.out");
    int n;
    fin>>dist>>n;
    for(int i=0;i<n;i++){
        int a;
        fin>>a;
        fout<<time(a)<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}