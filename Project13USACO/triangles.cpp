#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream fin("triangles.in");
    ofstream fout("triangles.out");
    int n, area2=0, i, j;
    fin>>n;
    int cords[2][n];
    for(i=0;i<n;i++){
        fin>>cords[0][i]>>cords[1][i];
    }
    fin.close();
    for(i=0;i<n;i++){
        int distance1=0, distance2=0;
        for(j=0;j<n;j++){
            if(cords[0][j]==cords[0][i]){
                distance1=max(distance1,abs(cords[1][j]-cords[1][i]));
            } else if(cords[1][j]==cords[1][i]){
                distance2=max(distance2,abs(cords[0][j]-cords[0][i]));
            }
        }
        area2=max(area2,distance1*distance2);
    }
    fout<<area2;
    fout.close();
    return 0;
}