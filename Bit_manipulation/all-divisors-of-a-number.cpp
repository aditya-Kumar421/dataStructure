#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    void print_divisors(int n) {
        vector<int> ans;
        for(int i=1;i<=sqrt(n);i++){
            if(n == 1) break;
            if(n%i == 0){
                ans.push_back(i);
                if(i != (n/i)) ans.push_back(n/i);
            } 
        }
        if(n==1) ans.push_back(1);
        sort(ans.begin(), ans.end());
        for(int i = 0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
    }
};

int main() {
    Solution sol;
    int n = 100;
    sol.print_divisors(n);
    return 0;
}