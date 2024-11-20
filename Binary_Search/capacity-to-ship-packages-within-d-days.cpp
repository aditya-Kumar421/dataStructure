#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int req_days(vector<int>& weights, int cap){
        int day =1; 
        long long load = 0;
        for(int i=0;i<weights.size();i++){
            if(load + weights[i] > cap){
                day +=1;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        return day;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int mini = *max_element(weights.begin(), weights.end());
        long long sum = 0;
        for(int i=0;i<weights.size();i++) sum += weights[i];

        while(mini<=sum){
            int mid = mini + (sum-mini)/2;
            int days_req = req_days(weights, mid);
            if(days_req <= days) sum = mid-1;
            else mini = mid+1;
        }
        return mini;
    }
};

int main(){
    Solution s;
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    cout<<s.shipWithinDays(weights, days);
}