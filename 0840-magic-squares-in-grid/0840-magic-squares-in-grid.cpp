class Solution {
public:
    bool check(int i,int j,vector<vector<int>>& grid)
    {
       unordered_set<int> uniqueNumbers;
        vector<int> rowSum(3, 0), colSum(3, 0);
        int diag1Sum = 0, diag2Sum = 0;
        for (int k = 0; k < 3; k++) {
            for (int l = 0; l < 3; l++) {
                int num = grid[i + k][j + l];
                if (num < 1 || num > 9) return false;
                if (!uniqueNumbers.insert(num).second) return false;
                rowSum[k] += num;
                colSum[l] += num;
                if (k == l) diag1Sum += num;
                if (k + l == 2) diag2Sum += num;
            }
        }
        for (int k = 0; k < 3; k++) {
            if (rowSum[k] != colSum[k] || rowSum[k] != diag1Sum || rowSum[k] != diag2Sum) return false;
            if (rowSum[k] != colSum[k] || colSum[k] != diag1Sum || colSum[k] != diag2Sum) return false;
        }
        
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;        
        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {
                cnt += check(i, j, grid);
            }
        }
        
        return cnt;
    }
};