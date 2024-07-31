class Solution {
public:
    bool solveRec(vector<int> nums,int index)
    {
        // base case
        if(index >= nums.size() - 1)
        return true;

        if(nums[index] == 0)
        return false;

        bool ans = false;
        for(int i=1; i<nums[index]+1; i++)
        {
            ans = ans || solveRec(nums,index+i);
        }

        return ans;
    }
    bool memo(vector<int> &nums, int index, vector<int> &dp) {
        // base case: reached the end of the array
        if (index >= nums.size() - 1) {
            return true;
        }

        // if current position has zero steps to move, we can't move forward
        if (nums[index] == 0) {
            return false;
        }

        // check if the result is already computed
        if (dp[index] != -1) {
            return dp[index];
        }

        // recursive case
        bool ans = false;
        for (int i = 1; i <= nums[index]; ++i) {
            ans = ans || memo(nums, index + i, dp);
            if (ans) {
                break;
            }
        }

        dp[index] = ans;
        return dp[index];
    }

    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);  // Initialize dp array with -1
        return memo(nums, 0, dp);
    }
};