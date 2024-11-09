#include<bits/stdc++.h>
using namespace std;

int main(){
    int a = 13;
    int b=9;
    cout<<a<<" "<<b<<endl;
    a = a^b;
    b = a^b;
    a = a^b;
    cout<<a<<" "<<b;
}