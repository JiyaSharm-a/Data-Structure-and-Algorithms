class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int minrow = row;
        int maxrow = -1;
        int mincol = col;
        int maxcol = -1;

        for(int i=0; i<row; i++)
        {
            for(int j = 0; j<col; j++)
            {
                if(grid[i][j] == 1)
                {
                    if(i < minrow) minrow = i;
                    if(i > maxrow) maxrow = i;
                    if(j < mincol) mincol = j;
                    if(j > maxcol) maxcol = j;
                }
            }
        }

        return (maxrow - minrow + 1) * (maxcol - mincol + 1);
    }
};