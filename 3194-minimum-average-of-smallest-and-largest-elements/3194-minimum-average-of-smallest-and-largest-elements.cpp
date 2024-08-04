class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int s = 0;
        int e = nums.size()-1;
        double mini = INT_MAX;

        while(s < e)
        {
            double mid = (nums[s] + nums[e])/2.0;
            if(mid < mini)
            {
                mini = mid;
            }
            s++;
            e--;
        }
        return mini;
    }
};