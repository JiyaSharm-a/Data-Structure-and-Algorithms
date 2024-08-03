class Solution {
public:
    int solveRec(vector<vector<int>> &obstacleGrid,int n,int m,int i,int j)
    {
        // base case
        if(i == n-1 && j == m-1)
        {
            return 1;
        }

        if(i >= n || j >= m || obstacleGrid[i][j] == 1)
        return 0;


        int right = solveRec(obstacleGrid,n,m,i+1,j);
        int left = solveRec(obstacleGrid,n,m,i,j+1);
        return right + left;
    }

    int memo(vector<vector<int>> &obstacleGrid, int n, int m, int i, int j, vector<vector<int>> &dp) {
        // Base case: If we reach the bottom-right corner
        if (i == n - 1 && j == m - 1) {
            return obstacleGrid[i][j] == 0 ? 1 : 0;
        }

        // If out of bounds or we hit an obstacle
        if (i >= n || j >= m || obstacleGrid[i][j] == 1) {
            return 0;
        }

        // Check if result is already computed
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Calculate the number of paths from the current cell to the destination
        int right = memo(obstacleGrid, n, m, i, j + 1, dp);
        int down = memo(obstacleGrid, n, m, i + 1, j, dp);

        return dp[i][j] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(); // Number of rows
        int m = obstacleGrid[0].size(); // Number of columns

        // Check if the start or end is blocked
        if (obstacleGrid[0][0] == 1 || obstacleGrid[n - 1][m - 1] == 1) {
            return 0;
        }

        // Initialize DP table with -1
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return memo(obstacleGrid, n, m, 0, 0, dp);
    }
};