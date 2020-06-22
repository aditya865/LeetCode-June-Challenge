/*It is a typical DP question. The only trick is that we need to do search from the bottom right to the top left corner. The reason is that: if we do search in a normal top-left to bottom-right way, then at a middle point (i,j), we can not do local "greedy" decision (i.e. only keep the local optimal path and discard all the other paths) since there are two metrics here: one is the minimum points needed to reach the current point from the top-left corner and the other is the current left points that can be used for future move. We have to consider both to define "optimal path". However, if we do search in a reverse order, we only need to consider only one metric, which is the minimum points needed at (i,j) that enables us to move to the destination. We don't care how many points left at (i,j) when it moves from the top-left point, >=1 is enough.
The recursion relationship is dp[i][j] = max(1, min(dp[i-1][j], dp[i][j+1]) - dungeon[i][j]) (here max(1,) is to guarantee that at least 1 point left when entering into [i][j]). Since dp[i][j] is only related to dp[i-1][j] and dp[i][j+1], so we can reduce dp to a one-dimensional array and do the recursion in a reverse order.
*/
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size(), col= dungeon[0].size(),  i, j;
        vector<int> dp(col+1,INT_MAX);

        for(i=row-1, dp[col-1] = 1; i>=0;--i)
        for(j=col-1; j>=0; --j)
            dp[j] = max(1, min(dp[j], dp[j+1]) - dungeon[i][j]);
        
        return dp[0];    
    }
};