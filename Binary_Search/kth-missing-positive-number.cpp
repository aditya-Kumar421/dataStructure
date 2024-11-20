#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int missed = arr[mid]-(mid+1);
            if(k<=missed){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        // int missing = arr[high] - (high+1);
        // int remain = k-missing;
        // int ans = arr[high] + remain;
        //low = high + 1;
        return k+low;
    }
};

int main(){
    Solution s;
    vector<int> arr = {2,3,4,7,11};
    int k = 5;
    cout<<s.findKthPositive(arr, k);
}