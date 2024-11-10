//Optimal solution:
#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        bool sign = true;
        if(dividend>=0 && divisor<0) sign = false; 
        if(dividend<=0 && divisor>0) sign = false; 
        long ans = 0;
        long n = abs(dividend);
        long d = abs(divisor);
        while(n>=d){
            int cnt=0;
            while(n>= (d<<(cnt+1))){
                cnt+=1;
            } 
            ans += (1<<cnt);
            n -= (d << cnt);
        }
        if(ans == (1<<31) && sign == true) return INT_MAX;
        if(ans == (1<<31) && sign == false) return INT_MIN;
        return sign?ans:(-ans);
    }
};

int main() {
    Solution sol;
    int dividend = 10;
    int divisor = 3;

    int result = sol.divide(dividend, divisor);
    cout << "Result of " << dividend << " / " << divisor << " = " << result << endl;

    // Additional test cases
    cout << "Result of -10 / 3 = " << sol.divide(-10, 3) << endl;
    cout << "Result of 10 / -3 = " << sol.divide(10, -3) << endl;
    cout << "Result of -10 / -3 = " << sol.divide(-10, -3) << endl;

    return 0;
}


//Brute force solution: 
/*class Solution {
public:
    int divide(int dividend, int divisor) {
        long long sum=0, count=0;
        bool sign = false;
        if(dividend>=0 && divisor>0) sign = true;
        else if (dividend<=0 && divisor<0) sign = true;
        else if (dividend>=0 && divisor<0){
            sign = false;
            divisor = abs(divisor);
        } 
        else{
            sign = false;
            dividend = abs(dividend);
        } 
        while((sum+divisor) <= dividend){
            count++;
            sum += divisor;
        }
        if(!sign) return -count;
        return count;
    }
};*/

