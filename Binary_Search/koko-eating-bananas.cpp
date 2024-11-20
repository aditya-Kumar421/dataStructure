#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    long long sumOfT(vector<int>& piles, int mid){
        long long sum= 0;
        for(int i = 0;i<piles.size();i++){
            sum += ceil((double)piles[i]/(double)mid);
        }
        return sum;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = *max_element(piles.begin(), piles.end());
        int low = 1, high = maxi;
        while(low<=high){
            int mid = low + (high-low)/2;
            long long sumOfTime = sumOfT(piles, mid);
            if(sumOfTime <= h){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};

int main(){
    Solution s;
    vector<int> piles = {3,6,7,11};
    int h = 8;
    cout<<s.minEatingSpeed(piles, h);
}