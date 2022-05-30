#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int sum=0, a, i, j, k, l, m, n;
    vector<int> numbers, answer;
    for (i = 0; i < 7; i++) {
        cin >> a;
        numbers.push_back(a);
        sum = max(numbers[i], sum);
    }
    for(i=0;i<7;i++){
        if(numbers[i]==sum){
            numbers.erase(numbers.begin()+i);
        }
    }
    for(i=0;i<7;i++){
        for(j=i+1;j<7;j++){
            for(k=j+1;k<7;k++){
                for(l=0;l==i || l==j || l==k;l++){}
                for(m=0;m==i || m==j || m==k || m==l;m++){}
                for(n=0;n==i || n==j || n==k || n==l || n==m;n++){}
                if(numbers[i]+numbers[j]+numbers[k]==sum && numbers[l]+numbers[m]+numbers[n]==(2*sum)){
                    answer.push_back(numbers[i]);
                    answer.push_back(numbers[j]);
                    answer.push_back(numbers[k]);
                    sort(answer.begin(),answer.begin()+3);
                    cout<<answer[0]<<" "<<answer[1]<<" "<<answer[2];
                    return 0;
                }
            }
        }
    }
}