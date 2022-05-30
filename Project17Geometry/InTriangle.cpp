#include <iostream>
#include "Point.h"

using namespace std;

bool sameSide(Point p1, Point p2, Point a, Point b) {
    if (cross(toVector(a,b), toVector(a,p1)) * cross(toVector(a,b), toVector(a,p2)) >= 0) {
        return true;
    } else {
        return false;
    }
}

bool inTriangle(Point p, Point a, Point b, Point c){
    return sameSide(p,a,b,c) && sameSide(p,b,c,a) && sameSide(p,c,a,b);
}

int main(){
    Point p{1,1};
    Point a{0,0};
    Point b{2,2};
    Point c{3,0};
    cout<<inTriangle(p,a,b,c);
}