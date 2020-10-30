#include<bits/stdc++.h>

using namespace std;

int min_3(int a, int b, int c){
    return min(min(a,b),c);
}

int edit_distance_recursive(string s1, string s2, int m, int n){

    if(m==0) return n;
    if(n==0) return m;

    if(s1[m-1] == s2[n-1]) return edit_distance_recursive(s1,s2,m-1,n-1);

    return 1 + min_3(edit_distance_recursive(s1,s2,m,n-1), // Insert
                        edit_distance_recursive(s1,s2,m-1,n), // Remove
                        edit_distance_recursive(s1,s2,m-1,n-1) // Replace
                    );
}

int edit_distance(string s1, string s2, int m, int n){

    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i=0;i<=m;i++) dp[i][0] = i;
    for(int i=0;i<=n;i++) dp[0][i] = i;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1+min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
        }
    }

    return dp[m][n];
}

int main(){
    string s1 = "sunday";
    string s2 = "saturday";

    cout << edit_distance_recursive(s1,s2,s1.size(),s2.size()) << endl;
    cout << edit_distance(s1,s2,s1.size(),s2.size()) << endl;

}
