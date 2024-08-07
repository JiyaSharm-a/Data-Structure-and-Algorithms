class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sum1s = 0;
        int sum10s = 0;

        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] < 10)
            sum1s += nums[i];
            else
            sum10s += nums[i];
        }

        if(sum1s == sum10s)
        return false;

        return true;
    }
};