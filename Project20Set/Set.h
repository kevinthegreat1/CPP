//
// Created by Kevin Yang on 2/6/21.
//

#ifndef C___SET_H
#define C___SET_H
#include <iostream>
#include <set>

std::set<int> In(int n){
    int t;
    std::set<int> a;
    for (int i = 0; i < n; ++i) {
        std::cin>>t;
        a.insert(t);
    }
    return a;
}

void Out(std::set<int> a){
    std::set<int>::iterator it;
    for (it = a.begin(); it != a.end(); it++) {
        std::cout<<*it;
        if(++it!=a.end()){
            std::cout<<", ";
        }
        it--;
    }
    std::cout<<std::endl;
}

std::set<int> Intersection(std::set<int> a, std::set<int> b){
    std::set<int>::iterator it;
    std::set<int> c;
    for (it = a.begin(); it != a.end(); it++) {
        if (b.find(*it) != b.end()) {
            c.insert(*it);
        }
    }
    return c;
}

std::set<int> Union(std::set<int> a, std::set<int> b){
    a.insert(b.begin(),b.end());
    return a;
}

std::set<int> RelativeComplement(std::set<int> a, std::set<int> b) {
    std::set<int>::iterator it;
    std::set<int> c;
    for (it = b.begin(); it != b.end(); it++) {
        if (a.find(*it) == a.end()) {
            c.insert(*it);
        }
    }
    return c;
}

#endif //C___SET_H
