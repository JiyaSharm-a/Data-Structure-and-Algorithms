class Solution {
public:
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
        int n = nums.size();
        if (n == 1) return nums[0]; // If only one house, return its value
        
        vector<int> dp1(nums.size()+1,-1);
        vector<int> nums1(nums.begin(),nums.end()-1);
        int ans1 = memo(nums1,0,dp1);

        vector<int> dp2(nums.size()+1,-1);
        vector<int> nums2(nums.begin()+1,nums.end());
        int ans2 = memo(nums2,0,dp2);

        return max(ans1,ans2);

    }
};