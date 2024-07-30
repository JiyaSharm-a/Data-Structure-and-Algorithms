class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int max_len = 0;
        int zeroes = 0;

        while(right < nums.size())
        {
            if(nums[right] == 0)
            {
                zeroes++;
            }
            if(zeroes > k)
            {
                if(nums[left] == 0)
                {
                    zeroes--;
                }
                left++;
            }
            if(zeroes <= k)
            {
                int len = right - left + 1;
                max_len = max(max_len,len);
            }
            right ++;
        }

        return max_len;
    }
};