#include <bits/stdc++.h>
using namespace std;


class NumberContainers {
private:
    unordered_map<int, int> indexToNumber; 
    unordered_map<int, set<int>> numberToIndices;
public:
    NumberContainers() {}
    
    void change(int index, int number) {
        if (indexToNumber.find(index) != indexToNumber.end()) {
            int oldNumber = indexToNumber[index];
            numberToIndices[oldNumber].erase(index);
            if (numberToIndices[oldNumber].empty()) {
                numberToIndices.erase(oldNumber);
            }
        }

        indexToNumber[index] = number;
        numberToIndices[number].insert(index);
    }
    
    int find(int number) {
        if (numberToIndices.find(number) != numberToIndices.end() && !numberToIndices[number].empty()) {
            return *numberToIndices[number].begin();
        }
        return -1;
    }
};

int main(){
    NumberContainers nc;
    nc.change(1, 10);
    nc.change(2, 20);
    nc.change(3, 30);
    cout<<nc.find(20)<<endl;
    cout<<nc.find(30)<<endl;
    cout<<nc.find(10)<<endl;
    nc.change(2, 40);
    cout<<nc.find(20)<<endl;
    cout<<nc.find(40)<<endl;
    return 0;
}