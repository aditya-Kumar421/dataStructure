//Optimal solution:


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

