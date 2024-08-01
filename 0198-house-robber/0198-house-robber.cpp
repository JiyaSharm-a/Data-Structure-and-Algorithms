class Solution {
public:
    int solveRec(vector<int> &nums,int index)
    {
        // base case
        if(index >= nums.size())
        return 0;

        // include
        int include = nums[index] + solveRec(nums,index+2);
        // exclude
        int exclude = 0 + solveRec(nums,index+1);
        int cost = max(include,exclude);

        return cost;
    }
    int memo(vector<int> &nums,int index,vector<int> &dp)
    {
        // base case
        if(index >= nums.size())
        return 0;

        // if ans already exist
        if(dp[index] != -1)
        {
            return dp[index];
        }

        // include
        int include = nums[index] + memo(nums,index+2,dp);
        // exclude
        int exclude = 0 + memo(nums,index+1,dp);
        dp[index] = max(include,exclude);

        return dp[index];
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1)
        return memo(nums,0,dp);
    }
};