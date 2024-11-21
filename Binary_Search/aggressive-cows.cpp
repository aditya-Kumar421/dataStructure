#include <bits/stdc++.h>
using namespace std;
bool check_possible(vector<int>& arr, int mid, int cows){
    int cntcows = 1, last = arr[0];
    for(int i=0;i<arr.size();i++){
        if(arr[i]-last >= mid){
            cntcows++;
            last = arr[i];
        }
        if(cntcows >= cows){
            return true;
        }
    }
    return false;
}
int main(){
    vector<int> arr = {0, 3, 4, 7, 10, 9};
    int cows = 4;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int maxi = arr[n-1];
    int mini = arr[0];
    int low = 1, high = maxi-mini;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(check_possible(arr, mid, cows)){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    cout<<high;
    return 0;
}
