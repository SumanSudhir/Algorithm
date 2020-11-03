#include<bits/stdc++.h>

using namespace std;

// Time complexity O(3^n)
int func_recursive(int n){

    if(n<0) return 0;
    if(n==0) return 1;

    return func_recursive(n-1)+func_recursive(n-2)+func_recursive(n-3);
}

// down to up
int func_dp(int n){
    vector<int> dp(n+1,0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for(int i=3;i<=n;i++) dp[i] = dp[i-1] + dp[i-2] + dp[i-3];

    return dp[n];
}


int main(){

    int n = 4;
    cout << "Recursive Solution " << func_recursive(n) << endl;
    cout << "DP Solution " << func_dp(n) << endl;
}
