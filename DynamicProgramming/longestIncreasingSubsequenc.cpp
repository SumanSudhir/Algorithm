#include<bits/stdc++.h>

using namespace std;

// int lis_recursive(vector<int> input){
//     int n =
// }


int lcs(vector<int> input){

    int n = input.size();
    vector<int> dp(n,1);

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(input[j] < input[i]) dp[i] = max(dp[i],dp[j]+1);
        }
    }

    return dp[n-1];
}

int main(){
    vector<int> input = {10,22,9,33,21,50,41,60,80};

    cout << lcs(input) << endl;
}
