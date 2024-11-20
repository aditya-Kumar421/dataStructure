#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool checkPossible(vector<int>& bloomDay, int i, int k, int m){
        int cnt = 0;
        int grp = 0;
        for(int j = 0;j<bloomDay.size();j++){
            if(i>=bloomDay[j]){
                cnt++;
            }
            else{
                grp += cnt/k;
                cnt = 0;
            }
        }
        grp += cnt/k;
        if(grp >= m) return true;
        return false;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int mini = *min_element(bloomDay.begin(), bloomDay.end());
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());
        long long mult = m*1LL*k*1LL;
        if(mult>bloomDay.size()) return -1;
        while(mini <= maxi){
            int mid = mini + (maxi-mini)/2;
            if(checkPossible(bloomDay, mid,k, m)){
                maxi = mid-1;
            }
            else{
                mini = mid+1;
            }
        }
        return mini;
    }
};

int main(){
    Solution s;
    vector<int> bloomDay = {1,10,3,10,2};
    int m = 3, k = 1;
    cout<<s.minDays(bloomDay, m, k);
}