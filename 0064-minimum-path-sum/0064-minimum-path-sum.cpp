class Solution {
public:
    void rec(vector<vector<int>> &grid,int ind,int i,int sum,int &minSum)
    {
        // base case
        if(ind == grid.size()-1 && i == grid[ind].size()-1)
        {
            minSum = min(sum,minSum);
            return;
        }

        // go left
        if(i+1 < grid[ind].size())
        rec(grid,ind,i+1,sum+grid[ind][i+1],minSum);

        // go down
        if(ind+1 < grid.size())
        rec(grid,ind+1,i,sum+grid[ind+1][i],minSum);
    }
    int memo(vector<vector<int>> &grid,int ind,int i,vector<vector<int>> &dp)
    {
        // base case
        if(ind == grid.size()-1 && i == grid[ind].size()-1)
        {
            return grid[ind][i];
        }

        if(dp[ind][i] != -1)
        return dp[ind][i];
        
        // go left
        int op1 = INT_MAX;
        if(i+1 < grid[ind].size())
        op1 = memo(grid,ind,i+1,dp);

        // go down
        int op2 = INT_MAX;
        if(ind+1 < grid.size())
        op2 = memo(grid,ind+1,i,dp);

        return dp[ind][i] = grid[ind][i] + min(op1,op2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int> (grid[0].size(),-1));
        return memo(grid,0,0,dp);
    }
};