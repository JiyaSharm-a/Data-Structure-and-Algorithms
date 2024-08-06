class Solution {
public:
    int rec(vector<vector<int>> &triangle,int ind,int i)
    {
        // base case
        if(ind >= triangle.size() || i >= triangle[ind].size())
        return 0;

        int path1 = triangle[ind][i] + rec(triangle,ind+1,i);
        int path2 = triangle[ind][i] + rec(triangle,ind+1,i+1);

        return min(path1,path2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        return rec(triangle,0,0);
    }
};