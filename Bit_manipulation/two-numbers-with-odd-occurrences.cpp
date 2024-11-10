#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N) {
        long long xr = 0;
        for(long long i = 0; i < N; i++) {
            xr = xr ^ Arr[i];
        }
        long long rightmost = (xr & (xr - 1)) ^ xr;
        long long b1 = 0, b2 = 0;
        for(long long i = 0; i < N; i++) {
            if(Arr[i] & rightmost) {
                b1 = b1 ^ Arr[i];
            } else {
                b2 = b2 ^ Arr[i];
            }
        }
        if(b1 > b2) return {b1, b2};
        return {b2, b1};
    }
};

int main() {
    Solution sol;
    long long int Arr[] = {3, 4, 3, 4, 8, 4, 4, 32, 7, 7};
    long long int N = sizeof(Arr) / sizeof(Arr[0]);

    vector<long long int> result = sol.twoOddNum(Arr, N);

    cout << "The two odd occurring numbers are: ";
    for (long long int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
