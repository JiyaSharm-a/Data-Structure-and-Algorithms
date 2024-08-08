class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());

        int mid = nums.size()/2;
        int start = 0;

        vector<int> ans;

        while(start < nums.size()/2 && mid < nums.size())
        {
            ans.push_back(nums[mid]);
            ans.push_back(nums[start]);
            mid++;
            start++;
        }

        // If there are remaining elements
        while (mid < nums.size()) 
        {
            ans.push_back(nums[mid]);
            mid++;
        }


        for(int i=0; i<ans.size(); i++)
        {
            nums[i] = ans[i];
        }
    }
};