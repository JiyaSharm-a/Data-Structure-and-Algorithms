class Solution {
public:
    int countPairs(const vector<int> &nums,int mid)
    {
        int count = 0;
        int j = 0;

        for(int i=0; i<nums.size(); i++)
        {
            while(j < nums.size() && nums[j]-nums[i] <= mid)
            {
                j++;
            }
            count += (j-i-1);
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int low = 0;
        int high =  nums.back() - nums.front();
        while(low < high)
        {
            int mid = low + (high - low)/2;
            if(countPairs(nums,mid) < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return low;
    }
};