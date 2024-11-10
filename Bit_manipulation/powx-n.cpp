//Brute force solution with O(n) time complexity
/*
class Solution {
public:
    double myPow(double x, int n) {
        double val=1.0;
        if(n>=0){
            while(n--){
                val = val*x;
            }
        }
        else{
            n = abs(n);
            while(n--){
                val = val*x;
            }
            val = 1/val;
        }
        return val;    
    }
};
*/
//Optimized solution with O(logn) time complexity
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double val = 1.0;
        bool flag = false;
        if(n>=0) flag = true;
        n = abs(n);
        while(n>0){
            if(n%2 != 0){
                    val = val * x;
                    n = n-1;
                }
            else{
                    x = x*x;
                    n = n/2;
                }
        }
        return flag ?  val: 1/val;
    }
};

int main() {
    Solution sol;
    double x = 2.00000;
    int n = 10;
    double result = sol.myPow(x, n);
    cout << "Result: " << result << endl;
    return 0;
}