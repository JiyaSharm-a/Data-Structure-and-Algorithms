class Solution {
public:
    bool stoneGame(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        bool flag = true;

        int alice = 0;
        int bob = 0;

        while(i <= j)
        {
            if(nums[i] >= nums[j] && flag)
            {
                alice += nums[i];
                flag = false;
                i++;
            }
            else if(nums[i] < nums[j] && flag)
            {
                alice += nums[j];
                flag = false;
                j--;
            }
            else if(nums[i] <= nums[j] && !flag)
            {
                bob += nums[i];
                flag = true;
                i++;
            }
            else if(nums[i] > nums[j] && !flag)
            {
                bob += nums[j];
                flag = true;
                j--;
            }
        }
        
        return alice > bob;
    }
};