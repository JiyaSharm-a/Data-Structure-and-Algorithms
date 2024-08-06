class Solution {
public:
    int solveRec(vector<int> nums,int ind,int target,int &min_count,int count)
    {
        // base case
        if(ind >= nums.size())
        {
            return min_count;
        }

        if(target == 0)
        {
            min_count = min(min_count,count);
            return min_count;
        }

        if(target-nums[ind] >= 0)
        {
            solveRec(nums,ind,target-nums[ind],min_count,count+1);
        }

        solveRec(nums,ind+1,target,min_count,count);

        return min_count;
    }
    int solveMemo(const vector<int>& nums, int ind, int target, vector<vector<int>>& memo) {
        // Base case: if target is zero, no more elements are needed
        if (target == 0) {
            return 0;
        }
        // Base case: if we have considered all elements
        if (ind >= nums.size()) {
            return INT_MAX; // No valid solution
        }
        
        // Check if the result is already in the memo table
        if (memo[ind][target] != -1) {
            return memo[ind][target];
        }

        // Skip the current element
        int skip = solveMemo(nums, ind + 1, target, memo);

        // Include the current element, if it's valid
        int take = INT_MAX;
        if (target - nums[ind] >= 0) {
            int result = solveMemo(nums, ind, target - nums[ind], memo);
            if (result != INT_MAX) {
                take = 1 + result; // Include current element
            }
        }

        // Store the result in the memo table and return it
        memo[ind][target] = min(skip, take);
        return memo[ind][target];
    }

    int numSquares(int n) {
        int num = 1;
        vector<int> nums;

        while(num*num <= n)
        {
            nums.push_back(num*num);
            num++;
        }

        vector<vector<int>> dp(nums.size() + 1,vector<int> (n+1,-1));

        int min_count = INT_MAX;
        return solveMemo(nums,0,n,dp);
    }
};