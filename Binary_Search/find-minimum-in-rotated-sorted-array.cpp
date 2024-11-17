#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        int mid;
        while(low<high){
            mid = low + (high-low)/2;
            if(nums[mid]<nums[high]){
                high = mid;
            }
            else if(nums[mid]>nums[high]){
                low = mid+1;
            }
            else{
                high = high-1;
            }
        }
        return nums[low];
    }
};

int main() {
    Solution sol;
    vector<int> arr = {3,4,5,1,2};
    cout << sol.findMin(arr);
    return 0;
}