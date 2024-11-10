#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findPrimeFactors(int N) {
        vector<int> ans;
        vector<bool> prime(N+1, true);
        prime[0] = prime[1] = false;
        for(int i=2;i<=N;i++){
            if(prime[i]){
                while(N%i == 0){
                    ans.push_back(i);
                    N = N/i;
                }
                for(int j = 2*i;j<=N;j = j+i){
                    prime[j] = false;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int N = 315;
    vector<int> result = sol.findPrimeFactors(N);
    cout << "Prime factors of " << N << " are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}