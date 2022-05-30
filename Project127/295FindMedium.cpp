//
// Created by Kevin Yang on 1/23/22.
//

#include <iostream>
#include <set>
#include <vector>

using namespace std;

class MedianFinder {
private:
    multiset<int> nums;
//    vector<int> numsVector;

public:
    void addNum(int add) {
        nums.insert(add);
//        numsVector.assign(nums.begin(), nums.end());
    }

    double findMedian() {
//        return numsVector.size() % 2 == 0 ?
//               (double) (numsVector[(numsVector.size() >> 1)] + numsVector[(numsVector.size() >> 1) - 1]) / 2
//                                          : numsVector[(numsVector.size() - 1) >> 1];
        if (nums.size() % 2 == 0) {
            auto it = next(nums.begin(), (nums.size() >> 1) - 1);
            return (double) (*it + *++it) / 2;
        } else {
            return *next(nums.begin(), (nums.size() - 1) >> 1);
        }
    }
};

int main(){
    auto* medianFinder = new MedianFinder();
    medianFinder->addNum(1);
    medianFinder->addNum(5);
    medianFinder->addNum(3);
    medianFinder->addNum(8);
//    medianFinder->addNum(5);
//    medianFinder->addNum(5);
    cout<<medianFinder->findMedian();
}