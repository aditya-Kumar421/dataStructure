#include <iostream>
#include <vector>
using namespace std;

//Bit manipulation method:
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = 1 << (nums.size());
        for(int i = 0; i < n; i++) {
            vector<int> output;
            int val = i;
            for(int j = 0; j < nums.size(); j++) {
                if(val & 1) {
                    output.push_back(nums[j]);
                }
                val = val >> 1;
            }
            ans.push_back(output);
        }
        return ans;
    }
};

//Recursive method with backtracking:
/*
class Solution {
private:
    void solve(vector<int> nums, vector<int> output,int index,vector<vector<int>>& ans){
        if(index >= nums.size()){
            ans.push_back(output);
            return ;
        }
        solve(nums, output, index+1, ans); 

        int element = nums[index];
        output.push_back(element);
        solve(nums, output, index+1, ans); 
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index =0;
        solve(nums, output, index, ans);
        return ans;
    }
};
*/

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = sol.subsets(nums);

    cout << "Subsets are:" << endl;
    for (const auto& subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
