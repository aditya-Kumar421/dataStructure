#include <iostream>
using namespace std;

class Solution {
  public:
    int setBit(int n) {
        int num = n;
        int ans = 1;
        while (num != 0) {
            if (!(num & 1)) break;
            ans = ans << 1;
            num = num >> 1;
        }
        return (ans ^ n);
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = sol.setBit(n);
    cout << "Result after setting the rightmost unset bit: " << result << endl;

    return 0;
}
