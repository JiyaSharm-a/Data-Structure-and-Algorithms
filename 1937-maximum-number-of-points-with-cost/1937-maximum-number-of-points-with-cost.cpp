class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        
        // dp[i][j] represents the max score at row i, col j
        vector<long long> prevRow(n, 0);
        
        // Initialize the first row
        for (int j = 0; j < n; j++) {
            prevRow[j] = points[0][j];
        }

        // Traverse from the second row to the last row
        for (int i = 1; i < m; i++) {
            vector<long long> currRow(n, 0);
            vector<long long> left(n, 0), right(n, 0);
            
            // Calculate max from left to right
            left[0] = prevRow[0];
            for (int j = 1; j < n; j++) {
                left[j] = max(left[j - 1] - 1, prevRow[j]);
            }
            
            // Calculate max from right to left
            right[n - 1] = prevRow[n - 1];
            for (int j = n - 2; j >= 0; j--) {
                right[j] = max(right[j + 1] - 1, prevRow[j]);
            }
            
            // Fill current row using left and right maxes
            for (int j = 0; j < n; j++) {
                currRow[j] = points[i][j] + max(left[j], right[j]);
            }
            
            prevRow = currRow;
        }
        
        // Get the maximum value from the last row
        return *max_element(prevRow.begin(), prevRow.end());
    }
};
