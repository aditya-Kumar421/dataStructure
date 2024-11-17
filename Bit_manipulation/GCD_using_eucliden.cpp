#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<long long> lcmAndGcd(long long a, long long b) {
        long long x = a, y = b;
        while(a != b){
            if(a>b) a = a-b;
            else b = b-a;
        }
        return {(x*y / a), a};
        //More optimized way to find GCD
        while(a>0 && b>0){
            if(a>b) a = a%b;
            else b = b%a;
        }
        if(a == 0) return {(x*y / b), b};
        return {(x*y / a), a};
        
    }
};

int main() {
    Solution sol;
    long long a = 20, b = 15;
    vector<long long> result = sol.lcmAndGcd(a, b);
    cout << "LCM: " << result[0] << ", GCD: " << result[1] << endl;
    return 0;
}