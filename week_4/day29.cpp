class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 || n==1) return 1;  // If there is only one row or one column there is only one way to reach the end
        vector<vector<int>>dp(n+1,vector<int>(m+1)); // Our Dp table
        dp[1][1] = 1;  // There is only one way to enter our starting cell
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i==1 && j==1) continue;   // already handled
                dp[i][j] = dp[i-1][j] + dp[i][j-1];  // sum of ways from the left cell and the upper cell
            }
        }
        return dp[n][m]; // number of ways to reach last cell
    }
};