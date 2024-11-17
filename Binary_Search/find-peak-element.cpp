#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        int mid;
        while(low<high){
            mid = low+(high-low)/2;
            if(nums[mid]<nums[mid+1]){
                low = mid+1;
            }
            else if(nums[mid]>nums[mid+1]){
                high = mid;
            }
        }
        return low;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1,2,3,1};
    cout << sol.findPeakElement(arr);
    return 0;
}