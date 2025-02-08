#include <bits/stdc++.h>
using namespace std;

int* prevSmaller(int* A, int n1, int *len1) {
    stack<int> st;
    
    for(int i=0;i<n1;i++){
        while(!st.empty() && st.top()>A[i]){
            st.pop();
        }
        
        if(st.empty()) A[i] = -1;
        else A[i] = st.top();
        st.push(A[i]);
    }
    *len1 = n1;
    return A;
}

int main(){
    int arr[] = {4, 5, 2, 10, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int len;
    int* res = prevSmaller(arr, n, &len);
    for(int i=0;i<len;i++){
        cout<<res[i]<<" ";
    }
    return 0;
}