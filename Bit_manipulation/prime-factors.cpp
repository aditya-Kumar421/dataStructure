#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	vector<int>AllPrimeFactors(int N) {
	    vector<int> ans;
	    for(int i=2;i<=N;i++){
	        if(N%i == 0){
	            ans.push_back(i);
	            while(N%i == 0) N = N/i;
	        }
	    }
        if(N>1) ans.push_back(N);
	    return ans;
	}
};
int main() {
    Solution sol;
    int N = 315;
    vector<int> result = sol.AllPrimeFactors(N);
    cout << "Prime factors of " << N << " are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
