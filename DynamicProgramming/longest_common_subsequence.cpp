#include<bits/stdc++.h>

using namespace std;


int lcs_recursive(string x, string y, int m, int n){

    if(m==0||n==0) return 0;
    if(x[m-1] == y[n-1]) return 1+lcs_recursive(x,y,m-1,n-1);
    else return max(lcs_recursive(x,y,m,n-1),lcs_recursive(x,y,m-1,n));
}

int lcs(string x, string y, int m, int n){

    vector<vector<int>> dp(m+1,vector<int>(n+1,0));

    string out;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1] == y[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    cout << out << endl;
    return dp[m][n];
}

int main(){
    string x = "AGGTAB";
    string y = "GXTXAYB";

    int m = x.size();
    int n = y.size();

    // cout << lcs_recursive(x,y,m,n);
    cout << lcs(x,y,m,n);
    cout << endl;

}
