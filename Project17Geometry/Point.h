#ifndef C___POINT_H
#define C___POINT_H

typedef std::pair<double, double> Point;
typedef std::pair<double, double> Vector;

double distance(Point a, Point b) {
    return sqrt(powf(a.first - b.first, 2) + powf(a.second - b.second, 2));
}

Vector toVector(Point a){
    return Vector{a.first,a.second};
}

Vector toVector(Point a, Point b) {
    return Vector{b.first - a.first, b.second - a.second};
}

Point toPoint(Vector a) {
    return Point{a.first, a.second};
}

Vector operator + (Vector a, Vector b) {
    return Vector{a.first + b.first, a.second + b.second};
}

double cross(Vector a, Vector b) {
    return a.first * b.second - a.second * b.first;
}

double dot(Vector a, Vector b) {
    return a.first * b.first + a.second * b.second;
}

#endif //C___POINT_H
