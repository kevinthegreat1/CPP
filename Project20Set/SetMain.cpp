//
// Created by Kevin Yang on 2/6/21.
//

#include <set>
#include "Set.h"

int main(){
    std::set<int> a{1,2,3,2,3,23,24,3,2,24,12,3,5,8,9,9,5,45,32,34,53,4,3,23,5,2,5}, b{1,42,4,55,43,23,3,34,54,9,0,5,8,4,5,53,4,42,9,56,5,63,3,4,3,4,31};
    Out(Intersection(a,b));
    Out(Union(a,b));
    Out(RelativeComplement(a,b));
}