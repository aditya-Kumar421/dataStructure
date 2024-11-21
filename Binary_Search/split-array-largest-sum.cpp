#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int getSum(vector<int>& nums, int mid){
        int largestSubarr = 1;
        int sumArr = 0;
        for(int i =0;i<nums.size();i++){
            if(nums[i]+sumArr > mid){
                largestSubarr += 1;
                sumArr = nums[i];
            }
            else{
                sumArr += nums[i];
            }
        }
        return largestSubarr;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(), nums.end());
        int sum = 0, n = nums.size();
        if(n<k) return -1;
        for(int i=0;i<n;i++) sum+=nums[i];

        while(maxi<=sum){
            int mid = maxi+(sum-maxi)/2;
            int val = getSum(nums, mid);
            if(val>k){
                maxi = mid+1;
            }
            else{
                sum = mid-1;
            }
        }
        return maxi;
    }
};

int main(){
    Solution s;
    vector<int> nums = {7,2,5,10,8};
    int k = 2;
    cout<<s.splitArray(nums, k);
}